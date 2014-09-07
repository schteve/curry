
#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include "GameObject.h"

#include <GL/GLU.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <vector>


class Graphics
{
public:
   Graphics();
   ~Graphics();

   void Init(void);
   void Update(float dt, std::vector<GameObject* > object_list);

private:
   SDL_Window * sdl_window;
   SDL_GLContext gl_context;
};

#endif // __GRAPHICS_H
