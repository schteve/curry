
#include "Debug.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace curry;

Debug::Debug(std::string filename)
{
   this->fout.open(filename);
}


Debug::~Debug()
{
   this->fout.close();
}


void Debug::Write(std::string message)
{
   this->fout << message;
}
