Object subclass: #Ride
    instanceVariableNames: 'rideID pickupLocation dropoffLocation distance'
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

Ride >> initialize: id pickup: p dropoff: d distance: dist
    rideID := id.
    pickupLocation := p.
    dropoffLocation := d.
    distance := dist.
    ^ self

Ride >> fare
    ^ distance * 2.0.

Ride >> rideDetails
    ^ 'RideID: ', rideID asString,
      ' | From: ', pickupLocation,
      ' | To: ', dropoffLocation,
      ' | Distance: ', distance asString,
      ' | Fare: ', self fare asString.



Ride subclass: #StandardRide
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

StandardRide >> fare
    ^ distance * 2.0.



Ride subclass: #PremiumRide
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

PremiumRide >> fare
    ^ distance * 4.0.



Object subclass: #Driver
    instanceVariableNames: 'driverID name rating assignedRides'
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

Driver >> initialize: id name: n rating: r
    driverID := id.
    name := n.
    rating := r.
    assignedRides := OrderedCollection new.

Driver >> addRide: ride
    assignedRides add: ride.

Driver >> getDriverInfo
    ^ 'Driver: ', name,
      ' | Rating: ', rating asString,
      ' | Total Rides: ', assignedRides size asString.



Object subclass: #Rider
    instanceVariableNames: 'riderID name requestedRides'
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

Rider >> initialize: id name: n
    riderID := id.
    name := n.
    requestedRides := OrderedCollection new.

Rider >> requestRide: ride
    requestedRides add: ride.

Rider >> viewRides
    ^ requestedRides collect: [ :r | r rideDetails ].



"========================
 DEMO (Polymorphism)
========================"

| r1 r2 r3 rides |

r1 := StandardRide new.
r1 initialize: 1 pickup: 'A' dropoff: 'B' distance: 10.

r2 := PremiumRide new.
r2 initialize: 2 pickup: 'C' dropoff: 'D' distance: 5.

r3 := StandardRide new.
r3 initialize: 3 pickup: 'E' dropoff: 'F' distance: 20.

rides := OrderedCollection with: r1 with: r2 with: r3.

rides do: [ :r |
    Transcript show: r rideDetails; cr.
].

rides do: [ :r |
    Transcript show: r fare asString; cr.
].