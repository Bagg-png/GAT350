#pragma once
#include "Renderer.h"

struct ColorBuffer{
    ColorBuffer() = default;
    ColorBuffer(const ColorBuffer & other)
    {
        width = other.width;
        height = other.height;

        if (other.data)
        {
            data = new uint8_t[width * height * sizeof(color_t)];
            memcpy(data, other.data, width * height * sizeof(color_t));
        }
    }

	~ColorBuffer() { delete[] data; }

   inline void SetColor(int x, int u, const color_t& color)const;

	uint8_t* data{ nullptr };

	int width = 0;
	int height = 0;
	int pitch = 0;
    //include glm library in raytrace
    //in raytracer source add Types.h
    /*
#include <glm/glm.hpp>
#include <glm/gtx/compatibility.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/color_space.hpp>



#include <sdl.h>



    using color_t = SDL_Color;



    inline color_t Vec3ToColor(const glm::vec3& vec3)
    {
        color_t color;



        color.r = static_cast<std::uint8_t>(glm::clamp(vec3[0], 0.0f, 1.0f) * 255);
        color.g = static_cast<std::uint8_t>(glm::clamp(vec3[1], 0.0f, 1.0f) * 255);
        color.b = static_cast<std::uint8_t>(glm::clamp(vec3[2], 0.0f, 1.0f) * 255);
        color.a = 0;



        return color;
    }*/

    // Add another class Ray.h
    //#inclulde "Types.h"
    //struct Ray{};
    //glm::vec3 origin;
    //glm::vec3 direction;
    //Ray() = default;
    //Ray(const glm::vec3 origin, const glm::vec3 direction) : origin{origin}, direction{direction} {}
    //glmvec3 pointAt(float t) const {return origin + (direction * t)}

    //Add new class Tracer.h
    //#include "Types.h"
    //#include "ColorBuffer.h"
    //class Tracer{}
    // public:
    // void Trace(const ColorBuffer colorBuffer);
    
    //Add new class Tracer.cpp
    // #include 
    //void Tracer::Trace(const ColorBuffer colorBuffer){}
    /*for(int y = 0; y < colorBuffer.height; y++){
        for(int x = 0; x < colorbuffer.width; x++){
        glm::vec2 point;
        point.x = x / (float)colorBuffer.width;
        point.y = y / (float)colorBuffer.height;

        glm::vec3 direction = glm::vec3{point, 1};
        direction = normalize(direction);
        colorBuffer.setColor(x, y, color);
            }
        }*/

};

inline void ColorBuffer::SetColor(int x, int y, const color_t& color) const
{
    if (x < 0 || x >= width || y < 0 || y >= height) return;

    ((color_t*)(data))[x + y * width] = color;
}