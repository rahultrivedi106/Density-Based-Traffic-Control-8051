# 🚦 Density-Based Traffic Light Control System (AT89S52 – 8051 Microcontroller)

![C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge)
![Keil µVision](https://img.shields.io/badge/IDE-Keil%20µVision5-brightgreen?style=for-the-badge)
![Flash Magic](https://img.shields.io/badge/Programmer-Flash%20Magic-orange?style=for-the-badge)
![Hardware](https://img.shields.io/badge/Hardware-Real%20Electronics-red?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)
![Made With](https://img.shields.io/badge/Made%20With-Embedded%20C%20%7C%208051%20%7C%20Keil-lightgrey?style=for-the-badge)

---

**Author:** Rahul Trivedi, M.Tech  
📧 rahultrivedi106@gmail.com  

---

## 🧠 Project Overview

This project implements a **Density-Based Traffic Signal Controller** using an **AT89S52 (8051)** microcontroller.  
Each of the four lanes in a junction has **two IR sensors** — *Entry* and *Exit* — that detect the presence of vehicles.  
Based on traffic density, the controller dynamically allocates the **green light time**, ensuring efficient traffic flow and minimal idle time.

> 🔬 Designed for **educational and research purposes** using Keil µVision & Flash Magic.

---

## ⚙️ Hardware Components

| Component | Quantity | Description |
|------------|-----------|-------------|
| AT89S52 Microcontroller | 1 | 8051-based 40-pin MCU |
| IR Sensors | 8 | Two per lane (Entry/Exit) |
| LEDs | 12 | 4 sets of R, Y, G lights |
| Resistors & Transistors | As required | LED driving & current limiting |
| USB Power Supply | 1 | 5V regulated |
| Connecting Wires | — | Signal and power lines |
| Flash Magic Tool | 1 | For HEX programming |

---

## 🧩 Working Principle

- The controller reads IR sensor data from **Port 1 (P1.0–P1.7)**.  
- Based on the number of detected vehicles, it determines the **density level** (Low / Medium / High).  
- LEDs connected to **Port 2 (P2.0–P2.7)** display the corresponding signal sequence.  
- The lane with the **highest density** gets the green light first.

| Density Level | Vehicles (approx.) | Green Time |
|:--------------|:------------------:|:----------:|
| Low | 0–2 | 5 sec |
| Medium | 3–6 | 10 sec |
| High | ≥ 7 | 20 sec |

After green: **Yellow = 2 s**, then **All-Red = 1 s**, and cycle repeats.

---

## 🧭 Algorithm (Stepwise)

1. Initialize ports: `P1` as input, `P2` as output  
2. Continuously read IR sensor states  
3. Count active sensors to estimate density per lane  
4. Select the lane with maximum density  
5. Assign corresponding green time  
6. Turn ON green for that lane, others remain red  
7. After green, yellow for 2 sec → all-red for 1 sec  
8. Repeat cycle

---

## 🧱 Block Diagram
![Block Diagram](figures/block_diagram_colored.png)

---

## 💡 Circuit Diagram
![Circuit Diagram](figures/circuit_diagram_colored.png)  

*IR modules send active-low signals to 8051 input pins; LEDs driven by output pins via transistors.*

---

## 🔁 Flowchart
![Flowchart](figures/flowchart_colored.png)

---

## 🛣️ 4-Way Junction with Sensors & Cars
![4-Way Road Layout](figures/road_layout_with_sensors.png)  

*Each lane has two IR sensors (Entry & Exit) placed before and after the stop line.  
Traffic lights are positioned separately at each corner.  
The 8051 controller (center) receives signals from sensors and drives corresponding lights.*

---

## 🚦 Example Output
![LED Output Example](figures/output_leds_colored.png)

*Dynamic control ensures that high-density lanes get longer green durations.*

---

## 🧰 Tools & Dependencies

- **Keil µVision 5** – compile & generate HEX  
- **Flash Magic** – flash AT89S52 via serial/USB  
- **AT89S52 (8051 Family)**  
- **USB 5V Power Source**  
- **IR Sensor Modules**  
- **LEDs (R, Y, G)**  

---

## 🛠️ How to Build & Flash

### 🧩 Using Keil µVision
1. Create new project → Select device `AT89S52`  
2. Add `src/main.c` and `src/traffic.h`  
3. Enable “Create HEX File” in project options  
4. Build → Find HEX in `/hex` folder  

### ⚡ Using Flash Magic
1. Select device = **AT89S52**  
2. Set COM Port & Baud Rate (9600)  
3. Choose HEX file → Erase → Program → Verify  
4. Observe signal changes on LEDs after power-up  

---

## 📂 Directory Structure
```
Density_Based_Traffic_Control_8051_Final/
├── src/
│   ├── main.c
│   └── traffic.h
├── figures/
│   ├── block_diagram_colored.png
│   ├── circuit_diagram_colored.png
│   ├── flowchart_colored.png
│   ├── road_layout_with_sensors.png
│   └── output_leds_colored.png
├── docs/
│   ├── working.txt
│   └── components_list.txt
├── hex/
│   └── traffic.hex
├── README.md
└── LICENSE
```

---

## 📈 Results & Conclusion

- 🚗 Efficient real-time traffic management  
- ⏱️ Reduces unnecessary waiting time  
- 🔄 Automatically adapts to changing density  
- 🧰 Simple, reliable, and low-cost prototype for academic use  

---

## 📜 License
MIT License © 2025 Rahul Trivedi

---

> ⚠️ For **educational and research purposes only** — not intended for industrial deployment.
