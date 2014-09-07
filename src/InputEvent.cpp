
#include "InputEvent.h"


InputEvent::InputEvent()
{
   this->key   = InputEvent::KeyNone;
   this->mouse = InputEvent::MouseNone;
   this->state = InputEvent::StateNone;
}


InputEvent::~InputEvent()
{

}
