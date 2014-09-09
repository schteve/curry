
#ifndef __UI_H
#define __UI_H

#include "GameObject.h"
#include "InputEvent.h"

#include <vector>

namespace curry
{

class UI
{
public:
   UI();
   ~UI();

   void Init(void);
   bool Update(void);
   std::vector<InputEvent> GetInputEvents(void);

private:
   std::vector<InputEvent> input_events;
};

};

#endif __UI_H
