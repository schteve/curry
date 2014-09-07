
#ifndef __ENGINE_H
#define __ENGINE_H

#include "Debug.h"
#include "Graphics.h"
#include "ObjectFactory.h"
#include "UI.h"

#include <vector>


class Engine
{
public:
   Engine();
   ~Engine();

   void Init(void);

   void Update(float dt);
   void MainLoop(void);

private:
   Debug * debug;

   ObjectFactory * object_factory;
   Graphics * graphics;
   UI * ui;

   bool HandleInput(void);
   void Render(float dt);
};

#endif // __ENGINE_H
