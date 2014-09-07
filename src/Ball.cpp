
#include "Ball.h"

#include "Cartesian.h"
#include "InputEvent.h"
#include "ObjectFactory.h"
#include "Util.h"

#include <GL/GLU.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <cmath>
#include <vector>


Ball::Ball(ObjectFactory * factory, Cartesian position, Cartesian velocity, Cartesian size)
   : GameObject(position),
     velocity(velocity)
{
   factory->AddObject(this);
   this->id = GameObject::IdBall;
   this->size = size;

   this->speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
}


Ball::~Ball()
{

}


void Ball::HandleInput(std::vector<InputEvent> input_events)
{
   // Doesn't react to input
}


void Ball::Update(std::vector<GameObject *> object_list, float dt)
{
   Cartesian newpos = this->position;
   Cartesian newvel = this->velocity;;

   newpos.x += this->velocity.x / dt;
   newpos.y += this->velocity.y / dt;

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
               newvel.y = -newvel.y;
            }
            break;

         case GameObject::IdPaddle:
            // when having a collideable component, that component will contain an aabb which will replace size here
            if ( (std::abs(newpos.x - obj->position.x) < (this->size.x/2 + obj->size.x/2)) &&
                 (std::abs(newpos.y - obj->position.y) < (this->size.y/2 + obj->size.y/2)) )
            {
               if (newpos.x > obj->position.x) // someone draw a line between the two points and figure out the intersection with the aabb?
                  newpos.x = obj->position.x + (obj->size.x/2 + this->size.x/2);
               else
                  newpos.x = obj->position.x - (obj->size.x/2 + this->size.x/2);

               Cartesian diff;
               diff.x = (newpos.x - obj->position.x);
               diff.y = (newpos.y - obj->position.y);

               const float max_angle = 75;
               float angle = (diff.y / (obj->size.y/2)) * max_angle;
               newvel.x = this->speed * std::cos(angle/180 * M_PI) * Util::Sgn(diff.x);
               newvel.y = this->speed * std::sin(angle/180 * M_PI);
            }
            break;

         case GameObject::IdBall:
            break;
      }
   }

   this->position = newpos;
   this->velocity = newvel;
}


void Ball::Render(float dt)
{
   glBegin(GL_QUADS);
      glColor3f(1.0, 0.0, 0.0);
      glVertex2f(this->position.x - this->size.x/2, this->position.y - this->size.y/2);
      glVertex2f(this->position.x + this->size.x/2, this->position.y - this->size.y/2);
      glVertex2f(this->position.x + this->size.x/2, this->position.y + this->size.y/2);
      glVertex2f(this->position.x - this->size.x/2, this->position.y + this->size.y/2);
   glEnd();
}
