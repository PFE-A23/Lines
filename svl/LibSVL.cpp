/*
    File:       LibSVL.cpp

    Purpose:    Compiles all code necessary for SVL.h.

    Author:     Andrew Willmott
*/

#define __SVL__

#ifdef VL_DEBUG
#define VL_CHECKING
#endif

#include <iomanip>
#include <iostream>

using namespace std;

#include "Basics.h"
#include "Constants.h"
#include "Utils.h"

#include "Vec.cpp"
#include "Vec2.cpp"
#include "Vec3.cpp"
#include "Vec4.cpp"

#include "Mat.cpp"
#include "Mat2.cpp"
#include "Mat3.cpp"
#include "Mat4.cpp"
