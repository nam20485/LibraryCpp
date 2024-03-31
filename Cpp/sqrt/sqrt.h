#pragma once

#include "../cpp_export.h"

CPP_API constexpr double get_precision();

CPP_API bool real_equals(double d1, double d2, double precision);

CPP_API double bssqrt(double d);

double truncate(double d);

