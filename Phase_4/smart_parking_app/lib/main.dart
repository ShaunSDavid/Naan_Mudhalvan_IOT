import 'package:flutter/material.dart';

void main() {
  runApp(SmartParkingApp());
}

class SmartParkingApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Smart Parking App',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: ParkingAvailabilityScreen(),
    );
  }
}

class ParkingAvailabilityScreen extends StatefulWidget {
  @override
  _ParkingAvailabilityScreenState createState() =>
      _ParkingAvailabilityScreenState();
}

class _ParkingAvailabilityScreenState extends State<ParkingAvailabilityScreen> {
  List<bool> parkingSpaces = [false, false, false]; // Initialize with default values

  // This function simulates the data received from your Raspberry Pi
  void simulateDataReceived() {
    List<bool> newData = [true, false, true]; // Simulated new data
    setState(() {
      parkingSpaces = newData;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Parking Availability'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            for (int i = 0; i < parkingSpaces.length; i++)
              Text(
                'Parking Space ${i + 1}: ${parkingSpaces[i] ? 'Occupied' : 'Available'}',
                style: TextStyle(fontSize: 24),
              ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: simulateDataReceived, // Call the function when button is pressed
        child: Icon(Icons.refresh),
      ),
    );
  }
}
