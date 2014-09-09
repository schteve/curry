
#include "Engine.h"

#include <stdio.h>

using namespace curry;

int main(int argc, char* args[])
{
   Engine * engine = new Engine();
   engine->Init();

   engine->MainLoop();

   return 0;
}
