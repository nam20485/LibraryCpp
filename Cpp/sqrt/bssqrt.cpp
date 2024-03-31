// sqrt.h : Header file for your target.

#pragma once

#include <cmath>
#include "../cpp_export.h"
#include "sqrt.h"

const double precision = get_precision();

double bssqrt(double d)
{
	double left = 0.0, right = d;

	while (true)
	{
		double mid = left + (right - left) / 2;
		double midsquared = mid * mid;
		if (real_equals(midsquared, d, precision))
		//if (std::abs(midsquared - d) <= precision)
		{
			// found answer within +- precision,
			// now throw away everything after "level of precision"
			auto val = mid * (1.0 / precision);
			auto rounded = std::round(val);
			auto m = rounded * precision;
			return (float)m;
			//return static_cast<int>(m / precision) * precision;

		}
		else if (midsquared > d)
		{
			right = mid;
		}
		else if (midsquared < d)
		{
			left = mid;
		}
	}

	// unreachable
	return -1.0;
}
