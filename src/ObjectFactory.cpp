
#include "GameObject.h"
#include "ObjectFactory.h"

using namespace curry;

ObjectFactory::ObjectFactory()
{

}


ObjectFactory::~ObjectFactory()
{
   for (int i = 0; i < this->objects.size(); i++)
      delete this->objects[i];
}


void ObjectFactory::AddObject(GameObject * object)
{
   this->objects.push_back(object);
}


std::vector<GameObject *> ObjectFactory::GetObjectList(void)
{
   return this->objects;
}
