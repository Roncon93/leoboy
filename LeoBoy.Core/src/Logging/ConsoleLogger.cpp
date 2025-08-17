#include "ILogger.h"
#include <iostream>

class ConsoleLogger : public ILogger
{
public:
	void Log(int level, const std::string& message) const override
	{
		std::cout << "Log Level: " << level << " - " << message << std::endl;
	}
};