#pragma once
#include <vector>
#include "Production.h"
#include "camera.h"

class Rasterization
{
public:
	float near, far;
	MATH::Mat4X4f model;
	MATH::Mat4X4f view;
	MATH::Mat4X4f projection;
	MATH::Mat4X4f transposeAndInverseMatrix;
	void setModelMat(MATH::Vector3f rota, MATH::Vector3f scale, MATH::Vector3f trans);
	void setViewMat(Camera camera);
	void setProjectionMat(float cameraFov, float aspectRatio, float near, float far);	

	MATH::Mat4X4f getMVPMat();
};



 
