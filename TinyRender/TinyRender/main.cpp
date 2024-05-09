#include <iostream>
#include <limits>
#include <opencv2/opencv.hpp>
#include <vector>
#include "MathH/Production.h"
#include "Renderer/screen/screen.h"
#include "Renderer/camera/camera.h"
#include "Renderer/rasterization/rasterization.h"
#include "Renderer/Model/Model.h"
#include "Renderer/Tool/Tool.h"
#include "Renderer/render/render.h"

int main()
{
	Render render;
	render.screen = Screen(2000, 2000);
	MATH::Vector3f cameraPos(0.0f, 0.0f, 10.0f);
	MATH::Vector3f cameraTargetPos(0.0f);
	MATH::Vector3f cameraUp(0.0f, 1.0f, 0.0f);
	render.camera = Camera(cameraPos, cameraTargetPos, cameraUp);
	MATH::Vector3f modelRota(0.0f);
	MATH::Vector3f modelScale(2.0f);
	MATH::Vector3f modelTrans(0.0f, -3.5f, 0.0f);
	render.rasterization.setModelMat(modelRota, modelScale, modelTrans);
	render.rasterization.setViewMat(render.camera);
	render.rasterization.setProjectionMat(45.0, 4 / 3, 0.01, 100);


	char path[] = "Prefab/mary/Marry.obj";
	MODEL::Model model(path);
	render.Rendering(model);
	char outPutPath[] = "outPut/mary.png";
	render.screen.Draw(outPutPath);
	return 0;
}
