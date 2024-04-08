# How to wire the circuit

![alt text](<main circuit.png>)

# How does this work?

Step 1: A potentionmeter has a piece of resistive material in it, and when the knob is turned, a brush is swept along the resistive material.

Step 2: This splits the resistive material into 2, which forms a [voltage divider.](#how-do-voltage-dividers-work)

Step 3: This causes there to be a voltage on the A0 pin that is between 0v and 5v.

Step 4: The Arduino reconiges this, and outputs a PWM signal that controls the brightness of the LED.

# How do voltage dividers work?
A voltage divider is a simple circuit that allows you to reduce voltage. It distributes the input voltage among the components in the circuit. The most common example of a voltage divider consists of two resistors connected in series. 

## Example circuit

Here is an example circuit to demonstrate the voltage dividers. Make sure to load the Arduino up with the [Voltage meter code.](https://github.com/bryan6970/Cool-quick-arduino-projects/blob/main/Voltage%20meter/Voltage%20meter.ino){:target="_blank"}


![alt text](<Voltage divider circuit.png>)

## Explaination of circuit

The voltage that you measure here is the voltage drop across R2, or the resistor on the right. Try changing the resistor on the left, and witness the change in voltage.

The fomula to calculate the voltage drop across a resistor is `Resistance of resistor / Total resistance in the circuit × Input voltage`


# How does PWM work?

- Pulse Width Modulation (PWM) is a technique used to control the average power delivered to electrical devices.
- It involves rapidly switching an electrical signal on and off at a high frequency.
- By adjusting the relative duration of the “on” and “off” states, PWM effectively changes the average voltage supplied to the load.

This means that if I have a 5v input voltage at a duty cycle of 30%, or if the signal is on a third of the time, the average voltage that will be supplied to the appliance will be `5v × 30%`. 

