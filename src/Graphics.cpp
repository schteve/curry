
#include "GameObject.h"
#include "Graphics.h"

#include <GL/GLU.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <vector>


Graphics::Graphics()
{

}


Graphics::~Graphics()
{
   SDL_DestroyWindow(this->sdl_window);
   SDL_Quit();
}


void Graphics::Init(void)
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // i feel like sdl initialization should be in engine
      return;

   // Use OpenGL 2.1
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

   // Create window
   #define SCREEN_WIDTH  640
   #define SCREEN_HEIGHT 480
   this->sdl_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
   if (this->sdl_window == NULL)
      return;

   // Create context
   this->gl_context = SDL_GL_CreateContext(this->sdl_window);
   if (this->gl_context == NULL)
      return;

   // Use Vsync
   if (SDL_GL_SetSwapInterval(1) < 0)
      return;

   // Initialize OpenGL

	// Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
   glOrtho(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f);

	// Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);
}


void Graphics::Update(float dt, std::vector<GameObject *> object_list)
{
   glClear(GL_COLOR_BUFFER_BIT);

   for (GameObject * obj : object_list)
      obj->Render(dt);

   SDL_GL_SwapWindow(this->sdl_window);
}
