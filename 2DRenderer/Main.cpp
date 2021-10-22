#include "Renderer.h"
#include "Framebuffer.h"
#include "PostProcess.h"
#include "Image.h"
#include "Tracer.h"

#include <iostream>
#include <SDL.h>

int main(int, char**)
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
	renderer->Initialize(WIDTH, HEIGHT);
	
	std::unique_ptr<Framebuffer> framebuffer = std::make_unique<Framebuffer>(renderer.get(), renderer->width, renderer->height);

	Tracer tracer;

	bool quit = false;
	SDL_Event event;
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
		framebuffer->Clear({ 0,0,0,0 });
		tracer.Trace(framebuffer->colorBuffer);
		/*std::unique_ptr<Image> image = std::make_unique<Image>();
		image->Load("../Resources/flower.bmp");
		image->Flip();
		framebuffer->DrawImage(300, 50, image.get())*/;

		/*std::unique_ptr<Image> image1 = std::make_unique<Image>(*image.get());
		PostProcess::BoxBlur(image1->colorBuffer);
		framebuffer->DrawImage(0, 300, image1.get());

		std::unique_ptr<Image> image2 = std::make_unique<Image>(*image.get());
		PostProcess::GaussianBlur(image2->colorBuffer);
		framebuffer->DrawImage(300, 300, image2.get());

		std::unique_ptr<Image> image3 = std::make_unique<Image>(*image.get());
		PostProcess::Sharpen(image3->colorBuffer);
		framebuffer->DrawImage(200, 200, image3.get());*/


			/*framebuffer->DrawTriangle(200, 200, 300, 200, 300, 250, { 255,0,0,0 });
			framebuffer->DrawCircle(400, 400, 100, {255,255,255,255});
			for (int i = 0; i < 10; i++)
		{
			framebuffer->DrawPoint(rand() % framebuffer->width, rand() % framebuffer->height, { 0, 255, 0, 255 });
		}
		for (int i = 0; i < 20; i++)
		{
			framebuffer->DrawRect(rand() % framebuffer->width, rand() % framebuffer->height, 20, 20, { 0, 0, 255, 255 });
		}
		for (int i = 0; i < 5; i++)
		{
			framebuffer->DrawLine(framebuffer->width >> 1, framebuffer->height >> 1, rand() % framebuffer->width, rand() % framebuffer->height, { 255, 255, 255, 0 });
		}
		for (int i = 0; i < 5; i++)
		{
			framebuffer->DrawQuadraticCurve(
				rand() % framebuffer->width, rand() % framebuffer->height,
				rand() % framebuffer->width, rand() % framebuffer->height,
				rand() % framebuffer->width, rand() % framebuffer->height, 30, { 255, 255, 0, 255 });
		}
		for (int i = 0; i < 5; i++)
		{
			framebuffer->DrawCubicCurve(
				rand() % framebuffer->width, rand() % framebuffer->height,
				rand() % framebuffer->width, rand() % framebuffer->height,
				rand() % framebuffer->width, rand() % framebuffer->height,
				rand() % framebuffer->width, rand() % framebuffer->height,
				30, { 255, 0, 255, 255 });
		}*/

		//PostProcess::Invert(framebuffer->colorBuffer);
		//PostProcess::Noise(framebuffer->colorBuffer, 100);
		//PostProcess::Brightness(framebuffer->colorBuffer, 100);
		//PostProcess::Brightness(framebuffer->colorBuffer, -100);
		//PostProcess::ColorBalance(framebuffer->colorBuffer, 0, 0, 100);
		//PostProcess::Threshold(framebuffer->colorBuffer, 200);
		framebuffer->Update();

		renderer->CopyBuffer(framebuffer.get());
		renderer->Present();
	}

	SDL_Quit();

	return 0;
}
