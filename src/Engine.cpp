
#include "GameBoard.h" // nope

#include "Debug.h"
#include "Engine.h"
#include "Graphics.h"
#include "ObjectFactory.h"
#include "UI.h"

#include <string>
#include <time.h>
#include <vector>

using namespace curry;

Engine::Engine()
{
   this->debug = new Debug("dbg.txt");

   this->graphics = new Graphics();
   this->ui = new UI();

   this->object_factory = new ObjectFactory();
}


Engine::~Engine()
{
   delete this->object_factory;
   delete this->ui;
   delete this->graphics;
   delete this->debug;
}


void Engine::Init(void)
{
   // general SDL init here? or do that in graphics / ui / audio / whatever?
   this->graphics->Init();
   this->ui->Init();

   this->object_factory->AddObject(new GameBoard(this->object_factory)); // nope. probably want a resource loader or at least a way to add a root object from outside of the engine
}


void Engine::Update(float dt)
{
   auto obj_list = this->object_factory->GetObjectList();
   for (GameObject * obj : obj_list)
      obj->Update(obj_list, dt);
}


void Engine::MainLoop(void)
{
   /*int count = 0;
   time_t last_time = time(NULL);*/

   while (this->HandleInput())
   {
      float dt = 1.0;

      /*count++;
      if (count >= 60)
      {
         count = 0;

         time_t this_time = time(NULL);
         time_t dtime = this_time - last_time;

         this->debug->Write("time=" + std::to_string(dtime) + " frames=" + std::to_string(count) + "\n"); // this doesn't print unless there's a print outside this block?!?!?!??????

         last_time = this_time;
      }*/

      this->Update(dt);
      this->Render(dt);
   }
}


bool Engine::HandleInput(void)
{
   bool running = this->ui->Update();

   for (GameObject * obj : this->object_factory->GetObjectList())
      obj->HandleInput(this->ui->GetInputEvents());

   return running;
}


void Engine::Render(float dt)
{
   this->graphics->Update(dt, this->object_factory->GetObjectList());
}
