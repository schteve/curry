
#ifndef __PADDLE_H
#define __PADDLE_H

#include "Cartesian.h"

#include "GameObject.h"
#include "InputEvent.h"
#include "ObjectFactory.h"

#include <vector>

namespace curry
{

class Paddle : public GameObject
{
public:
   Paddle(ObjectFactory * factory, Cartesian position, Cartesian velocity, Cartesian size);
   ~Paddle();

   void HandleInput(std::vector<InputEvent> input_events);
   void Update(std::vector<GameObject *> object_list, float dt);
   void Render(float dt);

private:
   Cartesian velocity; // components!

   bool motionUp;
   bool motionDown;
};

};

#endif __PADDLE_H
