// SingletonPrac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Singleton.h"
#include<thread>

using namespace std;

void fun1() {
    Logger* myinst1 = Logger::getLogger();
    myinst1->LogMessage("First User Instance Logging");
}

void fun2() {
    Logger* myinst2 = Logger::getLogger();
    myinst2->LogMessage("Second User Instance Logging");
}

int main()
{
    thread t1(fun1), t2(fun2);

    t1.join();
    t2.join();

    return 0;
    
}

