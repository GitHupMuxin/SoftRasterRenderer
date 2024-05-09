#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include "screen.h"

void Screen::init(int width, int height)
{
	this->frameBuffer.resize(width * height);
	this->depthBuffer.resize(width * height);
	for (auto& it : this->depthBuffer)
		it = FLT_MAX;
}

void Screen::mapToScreen(float& x, float& y)
{
	x = (x + 1) * width * 0.5;
	y = (y + 1) * height * 0.5;
}

int Screen::getIndex(int x, int y)
{
	return x + y * width;
}

Screen::Screen() { }

Screen::Screen(int width, int height)
{
	init(width, height);
	this->width = width;
	this->height = height;
}

void Screen::Draw(const char* path)
{
	std::reverse(this->frameBuffer.begin(), this->frameBuffer.end());
	cv::Mat image(width, height, CV_32FC3, this->frameBuffer.data());
	image.convertTo(image, CV_8UC3, 1.0f);
	cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
	cv::imwrite(path, image);
}
