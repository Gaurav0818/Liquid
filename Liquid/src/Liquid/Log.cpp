#include "pch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


std::shared_ptr<spdlog::logger> LqD::Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> LqD::Log::s_ClientLogger;

void LqD::Log::Init()
{
	// Set the log format.
	spdlog::set_pattern("%^[%T] %n: %v%$");

	// Create the core logger.
	s_CoreLogger = spdlog::stdout_color_mt("LIQUID");
	// Set the level of the core logger.
	s_CoreLogger->set_level(spdlog::level::trace);

	// Create the client logger.
	s_ClientLogger = spdlog::stdout_color_mt("APP");
	// Set the level of the client logger.
	s_ClientLogger->set_level(spdlog::level::trace);
}



