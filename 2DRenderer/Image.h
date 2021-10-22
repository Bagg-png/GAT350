#pragma once
#include "Renderer.h"
#include "ColorBuffer.h"
#include <string>

class Image { 
	friend class Framebuffer;
public:
	//~Image();
	bool Load(const std::string& filename, uint8_t alpha = 255); 
	void Flip();

	ColorBuffer colorBuffer;
private:
	//uint8_t* buffer{ nullptr };

	//int width;
	//int height;
};