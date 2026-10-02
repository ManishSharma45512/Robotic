# Project Ultron: Arduino & Raspberry Pi Robot

Building a real-world, multi-joint robot inspired by Ultron. 

The build starts with an Arduino Uno controlling servo motors and simple sensors. Next, a Raspberry Pi will be added as the main computer for camera vision, smart decision-making, and automation.

---

## How It Works

* **Brain (Phase 2):** Raspberry Pi handles camera tracking, logic, and high-level commands.
* **Controller (Phase 1):** Arduino Uno receives commands and directly controls motors and reads sensors.
* **Action:** Servo motors move the joints; sensors detect obstacles; LEDs show status.

---

## Parts List

### Controllers
* **Arduino Uno:** Controls motors and handles timing.
* **Raspberry Pi (4 or 5):** Will handle the camera, vision, and advanced code.

### Motors & Drivers
* **MG996R Servos (Black):** High-torque motors used for heavy lifting (Base and Shoulder).
* **SG90 Servos (Blue):** Small, lightweight motors used for light movement (Elbow and Gripper).

### Sensors & Display
* **Ultrasonic Sensor (HC-SR04):** Measures distance and avoids obstacles.
* **RGB LEDs:** Visual status indicators.
* **External Power Supply:** Batteries or a 5V power adapter (servos need more current than a laptop USB can safely supply).

---

## Current Pin Connections (Arduino Prototype)

| Part | Type | Arduino Pin | Power Source |
| :--- | :--- | :--- | :--- |
| **Base Motor** | MG996R (Black) | Pin D6 | 5V Power Rail |
| **Shoulder Motor** | MG996R (Black) | Pin D9 | 5V Power Rail |
| **Elbow Motor** | SG90 (Blue) | Pin D10 | 5V Power Rail |
| **Gripper Motor** | SG90 (Blue) | Pin D11 | 5V Power Rail |
| **Ground** | Common Ground | GND | Connected to Power Ground |

---

## Project Roadmap

- [x] Set up Arduino IDE and board connection.
- [x] Wire 4-motor robotic arm on a breadboard.
- [x] Write basic test code to move all motors safely.
- [ ] Add an ultrasonic sensor for distance measurement.
- [ ] Connect external battery power with common ground.
- [ ] Connect Raspberry Pi to Arduino using USB/Serial.
- [ ] Add a camera module for object detection.

---

## How to Run the Code

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Clone this repository:
   ```bash
   git clone [https://github.com/](https://github.com/)<your-username>/Project-Ultron.git
