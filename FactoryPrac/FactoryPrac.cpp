// FactoryPrac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"VehicleFactory.h"

int main()
{
    string VehicleType;
    cin >> VehicleType;

    Vehicle* vehicle = VehicleFactory::CreateVehicle(VehicleType);
    vehicle->CreateVehicle();

    return 0;
}


