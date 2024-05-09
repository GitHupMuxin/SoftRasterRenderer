#include <iostream>
#include "render.h"
#include "../Tool/Tool.h"

#define EPS 1e-3

VertexShaderData::VertexShaderData() { }

Render::Render() 
{ 
	init();
}

void Render::mapToScreen(Triangle& triangle)
{
	for (auto& it : triangle.point)
	{
		this->screen.mapToScreen(it.position.x, it.position.y);
		it.position.z = (it.position.z) * 0.5f * (this->rasterization.far - this->rasterization.near) + this->rasterization.near;
	}
}

void Render::init()
{
	this->vShader = [&](VertexShaderData data) -> void
	{
		MATH::Mat4X4f M = rasterization.model;
		std::vector<MATH::Vector3f> logicTriangle(3);
		for (int i = 0; i < 3; i++)
			logicTriangle[i] = MATH::multiple(M, MATH::Vector4f(data.triangle.point[i].position, 1.0f)).toVector3();

		MATH::Mat4X4f MVP = rasterization.getMVPMat();
		for (auto& it : data.triangle.point)
			it.position = MATH::multiple(MVP, MATH::Vector4f(it.position, 1.0f)).toVector3();
		this->mapToScreen(data.triangle);

		float xMax = 0, xMin = this->screen.width - 1;
		float yMax = 0, yMin = this->screen.height - 1;
		for (auto& it : data.triangle.point)
		{
			xMax = std::max(xMax, it.position.x);
			xMin = std::min(xMin, it.position.x);
			yMax = std::max(yMax, it.position.y);
			yMin = std::min(yMin, it.position.y);
		}
		xMax = std::min(static_cast<int>(xMax), this->screen.width - 1);
		xMin = std::max(static_cast<int>(xMin), 0);
		yMax = std::min(static_cast<int>(yMax), this->screen.height - 1);
		yMin = std::max(static_cast<int>(yMin), 0);

		for (float i = xMin; i <= xMax; i++)
		{
			for (float j = yMin; j <= yMax; j++)
			{
				static int num = 1;
				if (Tool::inTriangle(MATH::Vector2f(i + 0.5f, j + 0.5f), data.triangle))
				{
					auto [alpha, beta, gamma] = Tool::computeArealCoord2D(MATH::Vector2f(i + 0.5f, j + 0.5f), data.triangle);
					float inv = alpha / data.triangle.point[0].position.z + beta / data.triangle.point[1].position.z + gamma / data.triangle.point[2].position.z;
					float Z = 1.0f / inv;
					float Zp = Tool::interpolation(alpha, beta, gamma, data.triangle.point[0].position.z, data.triangle.point[1].position.z, data.triangle.point[2].position.z);
					int index = screen.getIndex(i, j);
					Z = Z * Zp;
					if (Z < screen.depthBuffer[index])
					{
						fragmentShaderData fragmentData;
						fragmentData.light = data.light;
						fragmentData.cameraPos = camera.position;
						fragmentData.fagPos = Tool::interpolation(alpha, beta, gamma, logicTriangle[0], logicTriangle[1], logicTriangle[2]);
						fragmentData.Normal = Tool::interpolation(alpha, beta, gamma, data.triangle.point[0].Normal, data.triangle.point[1].Normal, data.triangle.point[2].Normal);
						fragmentData.Normal = MATH::multiple(rasterization.transposeAndInverseMatrix, MATH::Vector4f(fragmentData.Normal, 1.0f)).toVector3();
						MATH::Vector2f TexCoord = Tool::interpolation(alpha, beta, gamma, data.triangle.point[0].TexCoord, data.triangle.point[1].TexCoord, data.triangle.point[2].TexCoord);
						fragmentData.diffuseColor = MATH::Vector3f(data.texture.getColor(TexCoord));
						screen.frameBuffer[index] = this->fShader(fragmentData);
						screen.depthBuffer[index] = Z;
					}
				}
			}
		}
	};

	this->fShader = [&](fragmentShaderData data) -> MATH::Vector3f
	{
		MATH::Vector3f ka(0.0f), kd(0.0f), ks(0.0f);
		for (auto& light : data.light)
		{
			MATH::Vector3f LightDir = MATH::normalize(light.lightPos - data.fagPos);
			MATH::Vector3f viewDir = data.cameraPos - data.fagPos;
			float r2 = MATH::dotProduction(viewDir, viewDir);
			viewDir = MATH::normalize(viewDir);
			MATH::Vector3f halfVec = MATH::normalize(LightDir + viewDir);
			MATH::Vector3f normal = MATH::normalize(data.Normal);
			ka += 0.1 * data.diffuseColor;
			kd += light.lightInstensity / r2 * data.diffuseColor * std::max(MATH::dotProduction(LightDir, normal), 0.0f);
			ks += light.lightInstensity / r2 * data.diffuseColor * std::pow(std::max(MATH::dotProduction(halfVec, normal), 0.0f), 32.0f);
		}
		return ka + kd + ks;
	};
}

void Render::Rendering(MODEL::Model& model)
{
	VertexShaderData data;
	data.cameraPos = this->camera.position;
	data.light.resize(2);
	data.light[0].lightPos = MATH::Vector3f(5.0f, 5.0f, 5.0f);
	data.light[0].lightInstensity = MATH::Vector3f(100.0f);
	data.light[1].lightPos = MATH::Vector3f(-10.0f, -10.0f, -0.0f);
	data.light[1].lightInstensity = MATH::Vector3f(100.0f);

	for (MODEL::Mesh& it : model.getMeshArray())
	{
		static int countMesh = 1;
		std::cout << "Draw a mesh. Num : " << countMesh++ << "\n";
		for (auto& tex : it.textures)
		{
			if (tex.type == "texture_diffuse")
				data.texture = tex;
		}
		for (int i = 0; i < it.indices.size(); i += 3)
		{
			static int countTriangle = 1;
			std::cout << "Draw a triangle. Num : " << countTriangle++ << "\n";
			for (int j = 0; j < 3; j++)
				data.triangle.point[j] = it.vertices[it.indices[i + j]];
			this->vShader(data);
		}
	}
}

