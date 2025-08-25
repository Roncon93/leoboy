#include <iostream>
#include "ILogger.h"

namespace Logging
{
	class ConsoleLogger : public ILogger
	{
	public:
		void Log(int level, const std::string& message) const override
		{
			std::cout << "Log Level: " << level << " - " << message << std::endl;
		}
	};
}