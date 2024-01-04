#pragma once

#ifdef PNEU_PLATFORM_WINDOWS
	#ifdef  PNEU_BUILD_DLL
		#define PNEUMATIC_API __declspec(dllexport)
	#else
		#define PNEUMATIC_API __declspec(dllimport)
	#endif //  PNEU_BUILD_DLL
#else
	#error Pneumatic only supports windows!
#endif // PNEU_PLATFORM_WINDOWS'


#ifdef PNEU_ENABLE_ASSERTS
	#define PNEU_ASSERT(x, ...) {if(!(x)){PNEU_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PNEU_CORE_ASSERT(x, ...) {if(!(x)){PNEU_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PNEU_ASSERT(x, ...)
	#define PNEU_CORE_ASSERT(x, ...)
#endif 

#define BIT(x) (1 << x)
