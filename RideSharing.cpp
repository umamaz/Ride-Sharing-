#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ================= BASE CLASS =================
class Ride {
protected:
    int rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(int id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup),
          dropoffLocation(dropoff), distance(dist) {}

    virtual double fare() const {
        return distance * 1.5;
    }

    virtual void rideDetails() const {
        cout << "Ride ID: " << rideID << endl;
        cout << "Pickup: " << pickupLocation << endl;
        cout << "Dropoff: " << dropoffLocation << endl;
        cout << "Distance: " << distance << endl;
        cout << "Fare: $" << fare() << endl;
    }

    virtual ~Ride() {}
};

// ================= STANDARD RIDE =================
class StandardRide : public Ride {
public:
    StandardRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 2.0;
    }
};

// ================= PREMIUM RIDE =================
class PremiumRide : public Ride {
public:
    PremiumRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 4.0;
    }
};

// ================= DRIVER =================
class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides;

public:
    Driver(int id, string n, double r)
        : driverID(id), name(n), rating(r) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() const {
        cout << "\nDriver Info\n";
        cout << "ID: " << driverID << endl;
        cout << "Name: " << name << endl;
        cout << "Rating: " << rating << endl;
        cout << "Total Rides: " << assignedRides.size() << endl;
    }
};

// ================= RIDER =================
class Rider {
private:
    int riderID;
    string name;
    vector<Ride*> requestedRides;

public:
    Rider(int id, string n)
        : riderID(id), name(n) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() const {
        cout << "\nRide History for " << name << endl;

        for (auto ride : requestedRides) {
            ride->rideDetails();
            cout << "------------------\n";
        }
    }
};

// ================= MAIN =================
int main() {

    Ride* r1 = new StandardRide(101, "UTA", "Dallas", 10);
    Ride* r2 = new PremiumRide(102, "Irving", "Fort Worth", 15);
    Ride* r3 = new StandardRide(103, "Arlington", "Plano", 20);

    vector<Ride*> rides = {r1, r2, r3};

    cout << "=== Polymorphism Demo ===\n";

    for (Ride* ride : rides) {
        ride->rideDetails();
        cout << "------------------\n";
    }

    for (Ride* ride : rides) {
        cout << "Fare: $" << ride->fare() << endl;
    }

    Driver d1(1, "John", 4.9);
    d1.addRide(r1);
    d1.addRide(r2);

    d1.getDriverInfo();

    Rider rider1(201, "Alice");
    rider1.requestRide(r1);
    rider1.requestRide(r2);

    rider1.viewRides();

    for (Ride* r : rides) {
        delete r;
    }

    return 0;
}