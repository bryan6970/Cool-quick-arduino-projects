/* Simple voltage meter by Bryan
Github: https://github.com/bryan6970

How to use:
- Follow the wiring in the README.
- Use a resistor of 130Ω or higher, although the closer the better.

Troubleshooting:
- Try fliping your LED. The longer lead should be connected to the Red wire, or + ive terminal

*/

const int LED_pin = 9;  //pin 9 has PWM funtion
const int POT_pin = A0; //pin A0 to read analog input




int value;

void setup(){
    Serial.begin(9600);

    pinMode(LED_pin, OUTPUT);

}


void loop(){
    value = analogRead(POT_pin);          //Read and save analog value from potentiometer
    value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
    analogWrite(LED_pin, value);          //Send PWM value to led

}