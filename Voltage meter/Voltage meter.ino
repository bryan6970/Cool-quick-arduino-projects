/* Simple voltage meter by Bryan
Github: https://github.com/bryan6970

How to use
- Turn on Serial monitor, and set the baud rate to the Serial baud rate set below (Default: 9600)
- Put a jumper wire in GND, and one in A0.
- Connect the wires to the points which voltage you want to measure

Troubleshooting

This circuit can only measure ranges from 0v - 5v.

This means that it cannot measure negative voltages, so if only 0v is measured when a voltage is expected, put your wires the other way.

*/


int update_rate = 120; // update rate in hertz
const int Serial_baud_rate = 9600; // Board update frequency


int a,b = 0;
const int mapped_update_rate = 1000 / update_rate;

double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void setup()
{
    Serial.begin(Serial_baud_rate);

    Serial.println("Activated");
    
}

void loop()
{
    a = analogRead(A0);

    if (a != b){
        Serial.println(mapf(a, 0, 1023, 0, 5));
        b = a;
    }

    delay(mapped_update_rate);
}
