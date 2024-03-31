#include "sqrt.h"
#include <cmath>

constexpr double PRECISION = 1.0E-5;

constexpr double get_precision()
{
	return PRECISION;
}

double truncate(double d)
{
	return static_cast<int>(d / get_precision()) * get_precision();
}

bool real_equals(double d1, double d2, double precision)
{
	auto diff = d2 - d1;
	auto abs_diff = std::abs(diff);
	return  abs_diff <= precision;
}
