
#ifndef __BALL_H
#define __BALL_H

#include "Cartesian.h"

#include "GameObject.h"
#include "InputEvent.h"
#include "ObjectFactory.h"

#include <vector>


class Ball : public GameObject
{
public:
   Ball(ObjectFactory * factory, Cartesian position, Cartesian velocity, Cartesian size);
   ~Ball();

   void HandleInput(std::vector<InputEvent> input_events);
   void Update(std::vector<GameObject *> object_list, float dt);
   void Render(float dt);

private:
   Cartesian velocity; // components!
   float speed;
};

#endif __BALL_H
