// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#define NOMINMAX // delete macro MIN, MAX in windows header for using local variable min, max

// Windows Header Files:
#include <windows.h>

// stl headers
#include <cassert>

// boost headers
#include <boost/algorithm/clamp.hpp>
#include <boost/math/constants/constants.hpp>
