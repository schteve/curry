
#include "Engine.h"

#include <stdio.h>


int main(int argc, char* args[])
{
   Engine * engine = new Engine();
   engine->Init();

   engine->MainLoop();

   return 0;
}
