#include "rasterization.h"
#define MY_PI 3.1415926


void Rasterization::setModelMat(MATH::Vector3f rota, MATH::Vector3f scale, MATH::Vector3f trans)
{


	MATH::Mat4X4f scaleM(scale.x, 0, 0, 0,
						0, scale.y, 0, 0,
						0, 0, scale.z, 0,
						0, 0, 0, 1.0f);
	MATH::Mat4X4f translateM(1.0f, 0, 0, trans.x,
							0, 1.0f, 0, trans.y,
							0, 0, 1.0f, trans.z,
							0, 0, 0, 1.0f);
	MATH::Mat4X4f rXM(1.0f, 0, 0, 0,
					 0, cos(rota.x), sin(rota.x), 0,
					 0, -sin(rota.x), cos(rota.x), 0,
					 0, 0, 0, 1.0f);
	MATH::Mat4X4f rYM(cos(rota.y), 0, -sin(rota.y), 0,
					 0, 1.0f, 0, 0,
					 sin(rota.y), 0, cos(rota.y), 0,
					 0, 0, 0, 1.0f);
	MATH::Mat4X4f rZM(cos(rota.x), -sin(rota.x), 0, 0,
					 sin(rota.x), cos(rota.x), 0, 0,
					 0, 0, 1.0f, 0,
					 0, 0, 0, 1.0f);
	this->model = MATH::Mat4X4f(1.0f);
	this->model = MATH::multiple(rXM, this->model);
	this->model = MATH::multiple(rYM, this->model);
	this->model = MATH::multiple(rZM, this->model);
	this->model = MATH::multiple(scaleM, this->model);
	this->model = MATH::multiple(translateM, this->model);
}

void Rasterization::setViewMat(Camera camera)
{
	view = camera.getLookAtMat();
}

void Rasterization::setProjectionMat(float cameraFov, float aspectRatio, float near, float far)
{
	this->near = -near;
	this->far = -far;
	float top = tan(cameraFov / 2 * MY_PI / 180) * abs(near);
	float right = top * aspectRatio;
	MATH::Mat4X4f scale(1.0f / right, 0, 0, 0,
						0, 1.0f / top, 0, 0,
						0, 0, 2.0f / abs(far - near), 0,
						0, 0, 0, 1.0f);
	MATH::Mat4X4f translate(1.0f, 0, 0, 0,
							0, 1.0f, 0, 0,
							0, 0, 1.0f, -(near + far) / 2.0f,
							0, 0, 0, 1.0f);
	MATH::Mat4X4f projection(near, 0, 0, 0,
							 0, near, 0, 0,
							 0, 0, near + far, -near * far,
							 0, 0, 1.0f, 0);
	this->projection = MATH::Mat4X4f(1.0f);
	this->projection = MATH::multiple(projection, this->projection);
	this->projection = MATH::multiple(translate, this->projection);
	this->projection = MATH::multiple(scale, this->projection);
}

MATH::Mat4X4f Rasterization::getMVPMat()
{
	MATH::Mat4X4f result(1.0f);
	result = MATH::multiple(this->model, result);
	result = MATH::multiple(this->view, result);
	result = MATH::multiple(this->projection, result);
	return result;
}
