
#include "GameObject.h"
#include "InputEvent.h"
#include "UI.h"

#include <SDL2/SDL.h>

#include <vector>


UI::UI()
{

}

UI::~UI()
{

}


void UI::Init(void)
{
   this->input_events.clear();

   SDL_StartTextInput();
}


bool UI::Update(void)
{
   bool running = true;

   this->input_events.clear();

   SDL_Event event;
   while (SDL_PollEvent(&event))
   {
      switch (event.type)
      {
         case SDL_QUIT:
            running = false;
            break;

         case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
               case SDLK_ESCAPE:
                  running = false;
                  break;

               case SDLK_UP:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyUp;
                  ie.state = InputEvent::StateDown;
                  this->input_events.push_back(ie);
                  break;
               }

               case SDLK_DOWN:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyDown;
                  ie.state = InputEvent::StateDown;
                  this->input_events.push_back(ie);
                  break;
               }

               case SDLK_LEFT:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyLeft;
                  ie.state = InputEvent::StateDown;
                  this->input_events.push_back(ie);
                  break;
               }

               case SDLK_RIGHT:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyRight;
                  ie.state = InputEvent::StateDown;
                  this->input_events.push_back(ie);
                  break;
               }
            }
            break;

         case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
               case SDLK_ESCAPE:
                  //running = false;
                  break;

               case SDLK_UP:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyUp;
                  ie.state = InputEvent::StateUp;
                  this->input_events.push_back(ie);
                  break;
               }

               case SDLK_DOWN:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyDown;
                  ie.state = InputEvent::StateUp;
                  this->input_events.push_back(ie);
                  break;
               }

               case SDLK_LEFT:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyLeft;
                  ie.state = InputEvent::StateUp;
                  this->input_events.push_back(ie);
                  break;
               }

               case SDLK_RIGHT:
               {
                  InputEvent ie;
                  ie.key = InputEvent::KeyRight;
                  ie.state = InputEvent::StateUp;
                  this->input_events.push_back(ie);
                  break;
               }
            }
            break;

         default:
            break;
      }
   }

   return running;
}


std::vector<InputEvent> UI::GetInputEvents(void)
{
   return this->input_events;
}
