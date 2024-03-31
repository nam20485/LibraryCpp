#pragma once

#ifdef Cpp_EXPORTS
#	define CPP_API __declspec(dllexport)
#else
#	define CPP_API __declspec(dllimport)
#endif // !