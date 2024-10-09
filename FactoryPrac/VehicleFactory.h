#pragma once
#include"Car.h"
#include"Bike.h"
#include<iostream>
#include<string>

using namespace std;

class VehicleFactory {
public:
	static Vehicle* CreateVehicle(string str);
};
