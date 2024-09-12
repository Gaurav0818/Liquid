#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace lqd
{
	class LQD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define LQD_CORE_TRACE(...)		lqd::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LQD_CORE_INFO(...)		lqd::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LQD_CORE_WARN(...)		lqd::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LQD_CORE_ERROR(...)		lqd::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LQD_CORE_CRITICAL(...)	lqd::Log::GetCoreLogger()->critical(__VA_ARGS__)


// Client Log Macros
#define LQD_CLIENT_TRACE(...)	lqd::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LQD_CLIENT_INFO(...)	lqd::Log::GetClientLogger()->info(__VA_ARGS__)
#define LQD_CLIENT_WARN(...)	lqd::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LQD_CLIENT_ERROR(...)	lqd::Log::GetClientLogger()->error(__VA_ARGS__)
#define LQD_CLIENT_CRITICAL(...)lqd::Log::GetClientLogger()->critical(__VA_ARGS__)