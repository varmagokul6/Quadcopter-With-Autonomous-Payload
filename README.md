# Quadcopter with Autonomous Payload Delivery

This project was part of one of the very first engineering courses I took in college. The course, Engineering 7B at UCI, emphasized hands-on learning through the development of the quadcopter, and also taught the essentials of presentation skills and entrepreneurship.
In summary, my team, Team MAEhem, was required to design and develop a quadcopter that would be able to fly, recognize distance and color, and drop a ball based on the sensor readings. To do this, we incorporated an Arduino microcontroller, an ultrasonic sensor, a PIXY2 camera, and servo motors for the dropping mechanism.

I was the lead programmer on the team. My job entailed getting readings from the ultrasonic sensor and the PIXY2 cameras. If the sensor read a distance within our set constraints and the PIXY2 camera recognized one of two colors, it would trigger the respective servo motor, which would release a ball.


### Functions:

```ultrasonicReadings() ```- Reads ultrasonic sensor values and determines distance from surrounding objects

pixyReadings() - Reads image color and compares it with known calibrated color values
