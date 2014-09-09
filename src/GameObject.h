
#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

#include "Cartesian.h"
#include "Component.h"
#include "InputEvent.h"

#include <vector>

namespace curry
{

class GameObject
{
public:
   GameObject();
   GameObject(Cartesian position);
   ~GameObject();

   Component * GetComponent(int id);
   void AddComponent(Component * comp);
   bool HasComponent(int id);

   virtual void HandleInput(std::vector<InputEvent> input_events) = 0;
   virtual void Update(std::vector<GameObject *> object_list, float dt) = 0;
   virtual void Render(float dt) = 0;

   // USE COMPONENTS
   enum Id
   {
      IdNone,
      IdGameBoard,
      IdBumper,
      IdPaddle,
      IdBall
   };

   Id id;
   Cartesian position;
   Cartesian size;

private:
   std::vector<Component *> components;
};

};

#endif __GAMEOBJECT_H
