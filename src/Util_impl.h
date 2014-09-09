
#ifndef __UTIL_IMPL_H
#define __UTIL_IMPL_H

namespace curry
{

template <typename T>
int Util::Sgn(T val)
{
   return (T(0) < val) - (val < T(0));
}

};

#endif __UTIL_IMPL_H
