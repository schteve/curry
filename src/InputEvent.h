
#ifndef __INPUTEVENT_H
#define __INPUTEVENT_H

namespace curry
{

class InputEvent
{
public:
   enum Key
   {
      KeyNone,

      KeyEscape,

      KeyUp,
      KeyDown,
      KeyLeft,
      KeyRight
   };
   
   enum Mouse
   {
      MouseNone,

      MouseLeft,
      MouseMiddle,
      MouseRight
   };

   enum State
   {
      StateNone,

      StateUp,
      StateDown
   };

   InputEvent();
   ~InputEvent();

   Key key;
   Mouse mouse;
   State state;
};

};

#endif __INPUTEVENT_H
