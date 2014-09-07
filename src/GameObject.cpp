
#include "Cartesian.h"
#include "Component.h"
#include "GameObject.h"

#include <cstdlib>
#include <vector>


GameObject::GameObject()
   : id(IdNone)
{

}


GameObject::GameObject(Cartesian position)
   : id(IdNone),
     position(position)
{

}


GameObject::~GameObject()
{

}


Component * GameObject::GetComponent(int id)
{

   return NULL;
}


void GameObject::AddComponent(Component * comp)
{


}


bool GameObject::HasComponent(int id)
{
   return false;
}
