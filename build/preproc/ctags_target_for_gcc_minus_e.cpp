# 1 "C:\\Users\\thacu\\Coding Projects\\Cool quick arduino projects\\Cool quick arduino projects.ino"
# 1 "C:\\Users\\thacu\\Coding Projects\\Cool quick arduino projects\\Voltage meter.ino"
# 2 "C:\\Users\\thacu\\Coding Projects\\Cool quick arduino projects\\Voltage meter.ino" 2
# 3 "C:\\Users\\thacu\\Coding Projects\\Cool quick arduino projects\\Voltage meter.ino" 2
# 4 "C:\\Users\\thacu\\Coding Projects\\Cool quick arduino projects\\Voltage meter.ino" 2


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
