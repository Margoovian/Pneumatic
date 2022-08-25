#pragma once

#ifdef PNEU_PLATFORM_WINDOWS
	#ifdef  PNEU_BUILD_DLL
		#define PNEUMATIC_API __declspec(dllexport)
	#else
		#define PNEUMATIC_API __declspec(dllimport)
	#endif //  PNEU_BUILD_DLL
#else
	#error Pneumatic only supports windows!
#endif // PNEU_PLATFORM_WINDOWS
