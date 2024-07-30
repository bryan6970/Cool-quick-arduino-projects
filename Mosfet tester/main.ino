int drain = A0, gate = A1, source = A2;
float acceptable_leakage = 0.5; // Voltage threshold for leakage
int dead_time = 500; // Time before next step of the test (in ms)
int series_resistance = 100; // Resistors used in series with the transistor

bool debug = true;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set pin modes
  pinMode(drain, INPUT);
  pinMode(gate, INPUT);
  pinMode(source, INPUT);
}

// Function to read analog value and map it to voltage
float read(int pin) {
  int rawValue = analogRead(pin);
  return map(rawValue, 0, 1023, 0, 5);
}

// Function to calculate Vth using PWM and a capacitor
float calculate_Vth() {
  float voltage;
  _debug("In Vth calculation");
  for (int i = 0; i < 255; i++) { // pwm goes up to 255
    analogWrite(9, i); // Output PWM signal on pin 9

    // Debug
      _debug("trying voltage");
      _debug(i);
      _debug(map(i, 0, 255, 0, 5000.0) /1000.0);



    delay(dead_time); // Allow some time before next measurement

    if (read(source) < acceptable_leakage) {
      voltage = map(i, 0, 255, 0, 5000.0) / 1000.0;
      _debug("Out of Vth calculation");
      _debug(voltage);
        digitalWrite(9, LOW);
      return voltage;
    }
  }
   voltage = read(source);
  _debug("Out of Vth calculation. End of cycle reached");
    digitalWrite(9, LOW);
  return false;
}


void _debug(String text){
  if (debug){
    Serial.println(text);
  } 
}

void _debug(float text){
  if (debug){
    Serial.println(text);
  } 
}

void loop() {
  float VDS, VGS, RDS, VOV, Vth, I;
  bool saturation, linear, cutoff;

  // Calculate Vth
  Vth = calculate_Vth();

  // Turn voltage high for measurements
  digitalWrite(9, HIGH);

  delay(dead_time * 3);

  // Read voltages
  VDS = read(drain) - read(source);
  VGS = read(gate) - read(source);

  // Calculate current assuming a 100 ohm resistor for simplicity
  I = read(source) / series_resistance;

  // Calculate RDS
  RDS = VDS / I;

  // Print values to the serial monitor
  Serial.print("Resistance (RDS): ");
  Serial.println(RDS);

  Serial.print("VGS: ");
  Serial.println(VGS);

  Serial.print("VDS: ");
  Serial.println(VDS);

  // If we have a value for Vth
  if (Vth || debug) {
    VOV = VGS - Vth;

    Serial.print("Vth (cutoff voltage): ");
    Serial.println(Vth);

    Serial.print("VOV (overdrive voltage): ");
    Serial.println(VOV);
  }

  if (debug) {
    // Help to print all analog read values
    Serial.print("Drain (A0) voltage: ");
    Serial.println(read(drain));
    
    Serial.print("Gate (A1) voltage: ");
    Serial.println(read(gate));
    
    Serial.print("Source (A2) voltage: ");
    Serial.println(read(source));
  }


  Serial.println(" ");

  digitalWrite(9,LOW);

  delay(1000); // Wait for 1 second before repeating
}

