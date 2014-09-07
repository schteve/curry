
#ifndef __DEBUG_H
#define __DEBUG_H

#include <fstream>
#include <iostream>
#include <string>


class Debug
{
public:
   Debug(std::string filename);
   ~Debug();

   void Write(std::string message);

private:
   std::ofstream fout;
};

#endif __DEBUG_H
