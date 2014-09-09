
#ifndef __BUMPER_H
#define __BUMPER_H

#include "Cartesian.h"

#include "GameObject.h"
#include "InputEvent.h"
#include "ObjectFactory.h"

#include <vector>

namespace curry
{

class Bumper : public GameObject
{
public:
   Bumper(ObjectFactory * factory, Cartesian position, Cartesian size);
   ~Bumper();

   void HandleInput(std::vector<InputEvent> input_events);
   void Update(std::vector<GameObject *> object_list, float dt);
   void Render(float dt);
};

};

#endif __BUMPER_H
