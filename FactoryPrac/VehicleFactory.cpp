#include"VehicleFactory.h"

using namespace std;

Vehicle * VehicleFactory::CreateVehicle(string str) {
	if (str == "Car")
	{
		Vehicle* obj = new Car();
		return obj;
	}
	else if (str == "Bike")
	{
		Vehicle* obj = new Bike();
		return obj;
	}
}