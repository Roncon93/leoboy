#pragma once

#include <cstdint>
#include <string>

class ILogger
{
public:
	/// <summary>
	/// Logs a message with the specified severity level.
	/// </summary>
	/// <param name="level">The severity level of the log message.</param>
	/// <param name="message">The message to log.</param>
	virtual void Log(int level, const std::string& message) const;
};