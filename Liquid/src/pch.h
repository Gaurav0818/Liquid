// This is a precompiled header file.
// It contains all of the standard library headers that are used by the Liquid Engine.
// This file should be included at the top of all Liquid Engine source files.
// This will improve compilation times by caching the results of compiling the standard library headers.
#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Liquid/Log.h"

#ifdef LQD_PLATFORM_WINDOWS
	#include <Windows.h>
#endif 

