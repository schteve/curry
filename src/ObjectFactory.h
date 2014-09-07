
#ifndef __OBJECTFACTORY_H
#define __OBJECTFACTORY_H

#include "GameObject.h"

#include <vector>

class ObjectFactory
{
public:
   ObjectFactory();
   ~ObjectFactory();

   void AddObject(GameObject * object);
   std::vector<GameObject *> GetObjectList(void);

private:
   std::vector<GameObject *> objects;
};

#endif // __OBJECTFACTORY_H
