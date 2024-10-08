#include<iostream>
#include "Singleton.h"
#include<thread>

using namespace std;

int Logger::ctr = 0;
mutex Logger::mtx;

Logger* Logger::LoggerInstance = nullptr;

Logger::Logger() {
	ctr++;
	cout << "Logger instance has been created! and instance number is : " << ctr << endl;
}

void Logger::LogMessage(string msg) {

	cout << msg << endl;

}

Logger* Logger::getLogger() {

	//why are we usign double - checked lock here ? 
	//bcoz we dont need to check the lock and unlock everytime to instantiate it so we place it out to avoid the overhead
	if (LoggerInstance == nullptr)
	{
		mtx.lock();
		if (LoggerInstance == nullptr) {
				LoggerInstance = new Logger();
		}
		mtx.unlock();
	}
	//behaviour was different when multithreading was introduced
	
	return LoggerInstance;
}