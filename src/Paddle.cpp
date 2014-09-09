
#include "Paddle.h"

#include "Cartesian.h"
#include "InputEvent.h"
#include "ObjectFactory.h"

#include <GL/GLU.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <cmath>
#include <vector>

using namespace curry;

Paddle::Paddle(ObjectFactory * factory, Cartesian position, Cartesian velocity, Cartesian size)
   : GameObject(position),
     velocity(velocity)
{
   factory->AddObject(this);
   this->id = GameObject::IdPaddle;
   this->size = size;

   this->motionUp   = false;
   this->motionDown = false;
}


Paddle::~Paddle()
{

}


void Paddle::HandleInput(std::vector<InputEvent> input_events)
{
   for (InputEvent ie : input_events)
   {
      switch (ie.key)
      {
         case InputEvent::KeyUp:
            this->motionUp = (ie.state == InputEvent::StateDown);
            break;

         case InputEvent::KeyDown:
            this->motionDown = (ie.state == InputEvent::StateDown);
            break;

         default:
            break;
      }
   }
}


void Paddle::Update(std::vector<GameObject *> object_list, float dt)
{
   Cartesian newpos = this->position;
   bool calc_collision = false;

   if (this->motionUp)
   {
      if (this->motionDown)
      {
         // Both directions are fighting each other -- do nothing
      }
      else
      {
         newpos.x = this->position.x;
         newpos.y = this->position.y - this->velocity.y / dt;
         calc_collision = true;
      }
   }
   else
   {
      if (this->motionDown)
      {
         newpos.x = this->position.x;
         newpos.y = this->position.y + this->velocity.y / dt;
         calc_collision = true;
      }
      else
      {
         // Do nothing
      }
   }

   // Check for collisions - use components
   if (calc_collision)
   {
      for (GameObject * obj : object_list)
      {
         switch (obj->id)
         {
            default:
            case GameObject::IdNone:
               break;

            case GameObject::IdGameBoard:
               break;

            case GameObject::IdBumper:
               // when having a collideable component, that component will contain an aabb which will replace size here
               if ( (std::abs(newpos.x - obj->position.x) < (this->size.x/2 + obj->size.x/2)) &&
                    (std::abs(newpos.y - obj->position.y) < (this->size.y/2 + obj->size.y/2)) )
               {
                  if (newpos.y > obj->position.y)
                     newpos.y = obj->position.y + (obj->size.y/2 + this->size.y/2);
                  else
                     newpos.y = obj->position.y - (obj->size.y/2 + this->size.y/2);
               }
               break;

            case GameObject::IdPaddle:
               break;

            case GameObject::IdBall:
               break;
         }
      }
   }

   this->position = newpos;
}


void Paddle::Render(float dt)
{
   glBegin(GL_QUADS);
      glColor3f(1.0, 1.0, 1.0);
      glVertex2f(this->position.x - this->size.x/2, this->position.y - this->size.y/2);
      glVertex2f(this->position.x + this->size.x/2, this->position.y - this->size.y/2);
      glVertex2f(this->position.x + this->size.x/2, this->position.y + this->size.y/2);
      glVertex2f(this->position.x - this->size.x/2, this->position.y + this->size.y/2);
   glEnd();
}
