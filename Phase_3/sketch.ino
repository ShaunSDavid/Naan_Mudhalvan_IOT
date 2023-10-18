const int NUM_PARKING_SPACES = 3;

const int ECHO_PINS[NUM_PARKING_SPACES] = {15, 5, 26};
const int TRIG_PINS[NUM_PARKING_SPACES] = {2, 18, 27};
const int LED_PINS[NUM_PARKING_SPACES] = {13, 12, 14};

bool parkingSpaces[NUM_PARKING_SPACES] = {false, false, false};

void setup()
{
    Serial.begin(115200);

    for (int i = 0; i < NUM_PARKING_SPACES; i++)
    {
        pinMode(ECHO_PINS[i], INPUT);
        pinMode(TRIG_PINS[i], OUTPUT);
        pinMode(LED_PINS[i], OUTPUT);
    }
}

float readDistanceCM(int TRIG_PIN, int ECHO_PIN)
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    int duration = pulseIn(ECHO_PIN, HIGH);
    return duration * 0.034 / 2;
}

// Data structure to keep track of the parking space status
void updateParkingStatus()
{
    for (int i = 0; i < NUM_PARKING_SPACES; i++)
    {
        int distance = readDistanceCM(TRIG_PINS[i], ECHO_PINS[i]);
        parkingSpaces[i] = (distance < 200.0);
        digitalWrite(LED_PINS[i], parkingSpaces[i]);
    }
}

void loop()
{
    updateParkingStatus();

    Serial.println("Parking Space Status:");

    for (int i = 0; i < NUM_PARKING_SPACES; i++)
    {
        Serial.print("Space ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.println(parkingSpaces[i] ? "Occupied" : "Available");
    }

    delay(1000);
}
