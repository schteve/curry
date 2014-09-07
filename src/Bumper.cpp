
#include "Bumper.h"

#include "Cartesian.h"
#include "InputEvent.h"
#include "ObjectFactory.h"

#include <GL/GLU.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <vector>


Bumper::Bumper(ObjectFactory * factory, Cartesian position, Cartesian size)
   : GameObject(position)
{
   factory->AddObject(this);
   this->id = GameObject::IdBumper;
   this->size = size;
}


Bumper::~Bumper()
{

}


void Bumper::HandleInput(std::vector<InputEvent> input_events)
{
   // Doesn't react to input
}


void Bumper::Update(std::vector<GameObject *> object_list, float dt)
{

}


void Bumper::Render(float dt)
{
   glBegin(GL_QUADS);
      glColor3f(0.0, 1.0, 0.0);
      glVertex2f(this->position.x - this->size.x/2, this->position.y - this->size.y/2);
      glVertex2f(this->position.x + this->size.x/2, this->position.y - this->size.y/2);
      glVertex2f(this->position.x + this->size.x/2, this->position.y + this->size.y/2);
      glVertex2f(this->position.x - this->size.x/2, this->position.y + this->size.y/2);
   glEnd();
}
