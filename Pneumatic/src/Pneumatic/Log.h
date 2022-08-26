#pragma once

#include "spdlog/spdlog.h"
#include <memory>
#include "Core.h"

namespace Pneumatic {
	class PNEUMATIC_API Log {
	public: 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//CORE
#define PNEU_CORE_TRACE(...)   ::Pneumatic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PNEU_CORE_INFO(...)    ::Pneumatic::Log::GetCoreLogger()->info (__VA_ARGS__)
#define PNEU_CORE_WARN(...)    ::Pneumatic::Log::GetCoreLogger()->warn (__VA_ARGS__)
#define PNEU_CORE_ERROR(...)   ::Pneumatic::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PNEU_CORE_FATAL(...)   ::Pneumatic::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//CLIENT
#define PNEU_TRACE(...)   ::Pneumatic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PNEU_INFO(...)    ::Pneumatic::Log::GetClientLogger()->info (__VA_ARGS__)
#define PNEU_WARN(...)    ::Pneumatic::Log::GetClientLogger()->warn (__VA_ARGS__)
#define PNEU_ERROR(...)   ::Pneumatic::Log::GetClientLogger()->error(__VA_ARGS__)
#define PNEU_FATAL(...)   ::Pneumatic::Log::GetClientLogger()->fatal(__VA_ARGS__)
