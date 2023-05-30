#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace LqD {

	class LIQUID_API Log
	{
	public:

		// This static method initializes the Log class.
		static void Init();

		// This inline static method returns a reference to the core logger.
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		// This inline static method returns a reference to the client logger.
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:

		// This static member variable stores a reference to the Core logger.
		static std::shared_ptr<spdlog::logger> s_CoreLogger;

		// This static member variable stores a reference to the client logger.
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros 
#define LQD_CORE_TRACE(...)	::LqD::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LQD_CORE_INFO(...)  ::LqD::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LQD_CORE_WARN(...)  ::LqD::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LQD_CORE_ERROR(...) ::LqD::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LQD_CORE_FATAL(...) ::LqD::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros 
#define LQD_TRACE(...) ::LqD::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LQD_INFO(...)  ::LqD::Log::GetClientLogger()->info(__VA_ARGS__)
#define LQD_WARN(...)  ::LqD::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LQD_ERROR(...) ::LqD::Log::GetClientLogger()->error(__VA_ARGS__)
#define LQD_FATAL(...) ::LqD::Log::GetClientLogger()->critical(__VA_ARGS__)

