
#ifndef __UTIL_H
#define __UTIL_H

namespace curry
{

class Util
{
public:
   template <typename T>
   static int Sgn(T val);
};

};

#include "Util_impl.h"

#endif __UTIL_H
