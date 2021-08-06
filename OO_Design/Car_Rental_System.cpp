#include <iostream>
#include <list>
using namespace std;

class User;

class Interval {
public:
    int startTime;
    int endTime;

    Interval(int start, int end) {
        startTime = start;
        endTime = end;
    }
};

enum VehicleType {
    CAR, SUV
};

class User {
private:
	 string email;
	 string name;
public:
	User(string name, string email) {
		this->name = name;
		this->email = email;
	}
};

class Vehicle {
public:
    string vehicleNo;
    VehicleType vehicleType;
    string barCode;
    int parkingLotNumber;
    int chargePerHr;
    list<Interval*> bookedTimeFrame;

    Vehicle(string vehicleNo, VehicleType vehicleType, string barCode, int chargePerHr, int parkingLotNumber) {
        this->vehicleNo = vehicleNo;
        this->vehicleType = vehicleType;
        this->barCode = barCode;
        this->chargePerHr = chargePerHr;
        this->parkingLotNumber = parkingLotNumber;
    }
    virtual float countRentMoney(int duration) { return 0.0; };
    virtual void reserveTimeSlot(int startTime, int duration) { };
};

class Car : public Vehicle {
public:
    Car(string carNo, VehicleType vehicleType, string barCode, int chargePerHr, int parkingLotNumber):
    Vehicle(carNo, vehicleType, barCode, chargePerHr, parkingLotNumber)
    {   }
    float countRentMoney(int duration) {
        return chargePerHr * duration;
    }
    void reserveTimeSlot(int startTime, int duration) {
        bookedTimeFrame.push_back(new Interval(startTime, startTime + duration));
    }
};

class Suv : public Vehicle {
public:
    Suv(string carNo, VehicleType vehicleType, string barCode, int chargePerHr, int parkingLotNumber):
    Vehicle(carNo, vehicleType, barCode, chargePerHr, parkingLotNumber)
    {    }
    float countRentMoney(int duration) {
        return chargePerHr * duration;
    }
    void reserveTimeSlot(int startTime, int duration) {
        bookedTimeFrame.push_back(new Interval(startTime, startTime + duration));
    }
};

class VehicleRentalSystem {
public:
    list<Vehicle*> vehicleList;

    void init(VehicleRentalSystem *vehicleRentalSystem);
    void addNewVehicle(Vehicle *vehicle) {
        vehicleList.push_back(vehicle);
    }

    list<Vehicle*> getAvailableVehicles(VehicleType type, int startTime, int duration) {
        list<Vehicle*> allAvailableVehicles;
        // logic to check available vehicle based on startTime and endTime

        // for now returning whole list
        return vehicleList;
    }

    Vehicle* bookVehicle(VehicleType &type, int startTime, int duration) {
        list<Vehicle*>::iterator it;
        for (it = vehicleList.begin(); it != vehicleList.end(); it++) {
            if ((*it)->vehicleType == type) {
                if ((*it)->bookedTimeFrame.size() == 0) {
                    // first time booking
                    //cout << "first time booking \n";
                    return *it;
                }

                list<Interval*>::iterator itrInterval = (*it)->bookedTimeFrame.begin();
                for (; itrInterval != (*it)->bookedTimeFrame.end(); itrInterval++) {
                    if ((*itrInterval)->endTime < startTime) {
                        // this vehicle can be booked
                        return *it;
                    }
                }
            }
        }

        return NULL;
    }

    bool returnVehicle(Vehicle &vehicle) {

        return true;
    }

    Vehicle* getStaus(Vehicle &vehicle) {
        return NULL;
    }
};

int main() {
    VehicleType type;
    int startTime;
    int duration;
    VehicleRentalSystem *vehicleRentalSystem = new VehicleRentalSystem();

    vehicleRentalSystem->init(vehicleRentalSystem);
    list<Vehicle*> allAvailableVehicles = vehicleRentalSystem->getAvailableVehicles(CAR, 10, 25);
    cout << "Vehicle Rental System" << endl;
    cout << "All available vehicle:" << endl;
    for (auto vehicle : allAvailableVehicles) {
        switch(vehicle->vehicleType) {
            case CAR:
                cout << "Car " << vehicle->vehicleNo << " Avaliable in parking: " << vehicle->parkingLotNumber << endl;
                break;
            case SUV:
                cout << "SUV " << vehicle->vehicleNo << " Avaliable in parking: " << vehicle->parkingLotNumber << endl;
                break;
            default:
                // handle other vehicleType
                break;
        }
    }

    cout << "Selected the vehicle to book: Car" << endl;
    type = CAR;
    cout << "Start time: 10 and duration: 2" << endl;
    startTime = 10;
    duration = 2;

    switch (type) {
        case CAR:
        {
            Vehicle *vehicleCar = vehicleRentalSystem->bookVehicle(type, startTime, duration);
            if (vehicleCar != NULL) {
                cout << "Booking Successful " << "Vehicle: " << vehicleCar->vehicleNo << " parking lot: " << vehicleCar->parkingLotNumber << endl;
                float amtTopay = vehicleCar->countRentMoney(duration);
                vehicleCar->reserveTimeSlot(startTime, duration);
                cout << "Amount to pay : " << amtTopay << endl;
            }
            else {
                cout << "Booking Failed " << endl;
            }

            cout << endl;

            vehicleCar = vehicleRentalSystem->bookVehicle(type, startTime, duration);
            if (vehicleCar != NULL) {
                cout << "Booking Successful " << "Vehicle: " << vehicleCar->vehicleNo << " parking lot: " << vehicleCar->parkingLotNumber << endl;
                float amtTopay = vehicleCar->countRentMoney(duration);
                vehicleCar->reserveTimeSlot(startTime, duration);
                cout << "Amount to pay : " << amtTopay << endl;
            }
            else {
                cout << "Booking Failed " << endl;
            }
            break;
        }
        case SUV:
        {
            Vehicle *vehicleSUV = vehicleRentalSystem->bookVehicle(type, startTime, duration);
            if (vehicleSUV != NULL) {
                cout << "Booking Successful " << vehicleSUV->vehicleNo << " " << vehicleSUV->parkingLotNumber << endl;
                float amtTopay = vehicleSUV->countRentMoney(duration);
                vehicleSUV->reserveTimeSlot(startTime, duration);
                cout << "Amount to pay : " << amtTopay << endl;
            }
            else {
                cout << "Booking Failed " << endl;
            }
            break;
        }
        default:
            // handle other vehicleType
            break;
    }

    // return vehicle
    // get list of rented vehicle
    // locate a vehicle
    return 0;

}

void VehicleRentalSystem :: init(VehicleRentalSystem *vehicleRentalSystem) {
    vehicleRentalSystem->addNewVehicle(new Car("abc1", CAR, "######", 10, 1));
    vehicleRentalSystem->addNewVehicle(new Car("abc2", CAR, "######", 9, 2));
    vehicleRentalSystem->addNewVehicle(new Car("abc3", CAR, "######", 11, 3));
    vehicleRentalSystem->addNewVehicle(new Car("abc4", CAR, "######", 7, 4));
    vehicleRentalSystem->addNewVehicle(new Car("abc5", CAR, "######", 4, 5));
    vehicleRentalSystem->addNewVehicle(new Suv("xyz1", SUV, "######", 18, 6));
    vehicleRentalSystem->addNewVehicle(new Suv("xyz2", SUV, "######", 22, 7));
    vehicleRentalSystem->addNewVehicle(new Suv("xyz3", SUV, "######", 25, 8));
    vehicleRentalSystem->addNewVehicle(new Suv("xyz4", SUV, "######", 14, 9));
}


/*
o/p:
Vehicle Rental System
All available vehicle:
Car abc1 Avaliable in parking: 1
Car abc2 Avaliable in parking: 2
Car abc3 Avaliable in parking: 3
Car abc4 Avaliable in parking: 4
Car abc5 Avaliable in parking: 5
SUV xyz1 Avaliable in parking: 6
SUV xyz2 Avaliable in parking: 7
SUV xyz3 Avaliable in parking: 8
SUV xyz4 Avaliable in parking: 9
Selected the vehicle to book: Car
Start time: 10 and duration: 2
Booking Successful Vehicle: abc1 parking lot: 1
Amount to pay : 20

Booking Successful Vehicle: abc2 parking lot: 2
Amount to pay : 18

*/
