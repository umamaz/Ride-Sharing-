# Ride Sharing System Using Smalltalk and C++

## Author
**Umama Azhar**  
MS Computer Science  
University of the Cumberlands 
---

## Project Description

This project implements a Ride Sharing System in both Smalltalk and C++ to demonstrate the core principles of Object-Oriented Programming (OOP). The system models rides, drivers, and riders while applying encapsulation, inheritance, and polymorphism.

The Ride class serves as the base class containing common ride information. StandardRide and PremiumRide inherit from Ride and provide different fare calculations. Driver and Rider classes manage ride assignments and ride requests. The system also demonstrates polymorphism by storing different ride types in a collection and invoking methods through a common interface.

---

## OOP Concepts Demonstrated

### Encapsulation
Data is stored within classes and accessed through methods rather than direct manipulation.

Examples:
- Driver class stores assigned rides.
- Rider class stores requested rides.
- Internal data is managed through methods such as `addRide()` and `requestRide()`.

### Inheritance
The classes `StandardRide` and `PremiumRide` inherit from the `Ride` base class and reuse its attributes and functionality.

### Polymorphism
Different ride types override the fare calculation method. A collection of Ride objects is used to invoke methods polymorphically at runtime.

---

## Classes Implemented

### Ride
Base class containing:
- rideID
- pickupLocation
- dropoffLocation
- distance

Methods:
- fare()
- rideDetails()

### StandardRide
Derived from Ride.

Methods:
- fare()

### PremiumRide
Derived from Ride.

Methods:
- fare()

### Driver
Stores:
- driverID
- name
- rating
- assignedRides

Methods:
- addRide()
- getDriverInfo()

### Rider
Stores:
- riderID
- name
- requestedRides

Methods:
- requestRide()
- viewRides()

---

## File Structure

```
RideSharingSystem
│
├── RideSharing.cpp
├── RideSharing.st
├── README.md
└── Report.pdf
```

---

## Running the C++ Program

Compile:

```bash
g++ RideSharing.cpp -o RideSharing
```

Run:

```bash
./RideSharing
```

Windows:

```bash
RideSharing.exe
```

---

## Running the Smalltalk Program

1. Open Pharo Smalltalk.
2. Create the classes in the System Browser.
3. Compile all methods.
4. Open a Workspace.
5. Execute the demonstration code.
6. View results in the Transcript window.

---

## Sample Output

```text
=== Polymorphism Demo ===

Ride ID: 101
Pickup: UTA
Dropoff: Dallas
Distance: 10
Fare: $20

Ride ID: 102
Pickup: Irving
Dropoff: Fort Worth
Distance: 15
Fare: $60

Driver Info
ID: 1
Name: John
Rating: 4.9
Total Rides: 2
```

---



---

## Conclusion

This project demonstrates how object-oriented programming principles can be applied to design Ride Sharing System
