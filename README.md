# 🛢️ Intelligent SCADA & Level Measurement System for Technological Tanks

## 📸 System Previews & Snapshots
<details>
  <summary><b>🖥️ 1. Operational Statuses (Click to expand SCADA HMI)</b></summary>

  <br>
  Demonstrating the dynamic UI logic, color-coded safety zones, and real-time mathematical calculations:
  
  * **Normal Operation (Safe Zone):**
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/50.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/50i.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/50k.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/51.jpeg)



  
  * **Warning State (Approaching Limit):**
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/25.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/25i.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/25k.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/70.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/70i.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/70k.jpeg)
  
  * **Critical State (Overfill / Empty):**
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/11.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/11i.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/11k.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/90.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/90i.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/90k.jpeg)

</details>

<details>
  <summary><b>⚙️ 2. Physical Simulation & Hardware Layout (Click to expand)</b></summary>

**
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/s.jpeg)
    > ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/sr.jpeg)

</details>

<details>
  <summary><b>📊 3. Commercial Data Logging (Click to expand)</b></summary>
  
**
    ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/90k.jpeg)
    ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/data.png)
    ![Normal Status](https://github.com/Senann05/Industrial-Tank-SCADA-System/blob/main/Images%20(2)/60sec.png)

</details>
  
## 📌 Project Overview
This project is a scaled-down, fully functional prototype of an industrial tank monitoring and commercial accounting system. It integrates field-level sensor data acquisition with a custom-developed Supervisory Control and Data Acquisition (SCADA) interface. Designed with global energy industry standards in mind, the system performs real-time edge computing, fluid mass calculation based on thermodynamic principles, and automated data logging for retrospective analysis.

## ✨ Core Features
* **Real-Time Edge Computing:** The microcontroller autonomously processes raw microsecond wave data into liquid level percentages and executes local safety protocols (LEDs & Sirens) even if the central server disconnects.
* **Bi-Directional Communication:** Seamless serial communication allows the SCADA interface to send manual override commands (e.g., muting physical alarms) directly to the field devices.
* **Commercial Mass Accounting:** Unlike standard level monitors, this system calculates exact fluid mass by applying:
  * Non-linear volumetric formulas for frustum (truncated cone) geometries.
  * Thermodynamic density corrections (adjusting base density at 20°C to real-time operational temperatures like 35°C).
* **Data Logging & Trending:** A multi-threaded background process records timestamped level and precise mass data into a CSV database every minute, generating historical trend visualizations.
* **Industrial HMI Design:** The Python-based UI features a dark-mode industrial layout, dynamic color-coded tank animations, and clear operational status indicators.

## 🏗️ System Architecture

### 1. Hardware (Field Level)
* **Processing Unit:** Arduino Uno (C++)
* **Primary Sensor:** HC-SR04 Ultrasonic Distance Sensor (Simulating 80 GHz FMCW radar functionality)
* **Visual Indicators:** Green (Normal), Yellow (Warning), Red (Critical Overfill/Empty) LEDs
* **Auditory Alarm:** Piezo Buzzer for critical alerts
* **Physical Tank:** Custom frustum (truncated cone) vessel

### 2. Software (Supervisory Level)
* **Language:** Python 3.x
* **GUI Framework:** `tkinter`
* **Data Handling:** `csv`, `datetime`, `threading`
* **Communication:** `pyserial` (Serial Protocol)

## 🧮 Mathematical Modeling
The commercial accounting module relies on precise physical formulas embedded in the Python script:

1. **Volume of a Frustum:** `V = (1/3) * π * h * (R_bottom² + R_bottom * R_current + R_current²)`
2. **Temperature-Corrected Density:** `ρ_t = ρ_20 - β * (T - 20)`
3. **Absolute Mass Calculation:** `Mass (kg) = (V / 1,000,000) * ρ_t`

## 🚀 Getting Started

### Prerequisites
* Arduino IDE (for C++ firmware)
* Python 3.8+ 
* Required Python libraries: `pip install pyserial`

### Installation & Usage
1. **Hardware Setup:** Wire the HC-SR04, LEDs, and Buzzer to the Arduino via a breadboard (Refer to the circuit diagram).
2. **Upload Firmware:** Open `firmware/tank_level_controller.ino` in Arduino IDE, select your COM port, and upload it to the board.
3. **Launch SCADA:** Navigate to the `scada/` directory and run the main Python script:
   ```bash
   python main_hmi.py
