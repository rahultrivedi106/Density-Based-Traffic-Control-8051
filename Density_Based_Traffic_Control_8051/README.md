# 🚦 Density-Based Traffic Light Control System (8051 Microcontroller)

**Author:** Rahul Trivedi, M.Tech  
📘 *Educational and Research Purpose Only*  

---

## 🧠 Overview
This project implements a **Priority-Based Density Traffic Light Control System** using the **AT89S52 (8051)** microcontroller.  
It dynamically assigns green time to the lane with the highest detected density (2 sensors per lane), using step-wise timing.

---

## 🔁 Key Features
- 4-way intersection (N, S, E, W) with **2 IR sensors per lane** (Entry & Exit)  
- **Priority-based** green assignment: lane with highest density gets green first  
- **Step-wise timing:** Low=5s, Medium=10s, High=20s (Yellow=2s)  
- USB 5V powered, Keil + Flash Magic compatible

---

## 📂 Directory Structure
```
Density_Based_Traffic_Control_8051_Priority/
├── src/
│   ├── main.c
│   └── traffic.h
├── figures/
├── docs/
├── hex/
│   └── traffic.hex (placeholder)
├── README.md
└── LICENSE
```

---

## ⚙️ Keil & Flash Magic
(See full Keil and Flash Magic setup instructions in README in packaged ZIP.)

---

> 📘 This project is developed for educational and research purposes.
