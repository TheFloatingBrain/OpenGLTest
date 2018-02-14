#include "Utility.h"

#ifndef GL_TEST_GL_DEBUG_LOG_H
#define GL_TEST_GL_DEBUG_LOG_H
	struct GLDebugLog
	{
		GLint GetResult();
		int GetLogLength();
		std::string GetLog();
		protected:
		GLint result, logLength;
		std::string log;
	};
#endif