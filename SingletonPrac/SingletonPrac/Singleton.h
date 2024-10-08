#pragma once

#include<mutex>
#include <string>

using namespace std;

class Logger {
private:
	static int ctr;
	static mutex mtx;
	Logger();
	//making copy ctor private
	Logger(const Logger&);
	//making assignment ctor private
	//you can also delete this using = delete
	Logger& operator=(const Logger&);

	static Logger* LoggerInstance;

public:
	static Logger* getLogger();

	void LogMessage(string msg);

};