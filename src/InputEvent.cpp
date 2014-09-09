
#include "InputEvent.h"

using namespace curry;

InputEvent::InputEvent()
{
   this->key   = InputEvent::KeyNone;
   this->mouse = InputEvent::MouseNone;
   this->state = InputEvent::StateNone;
}


InputEvent::~InputEvent()
{

}
