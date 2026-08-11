# ⚡ Automatic Load Sharing of Transformer Using Arduino

A B.Tech final year minor project (Electrical Engineering) that automates load sharing between a primary and a backup transformer using an Arduino microcontroller — preventing overload damage and ensuring uninterrupted power supply.

[![Platform](https://img.shields.io/badge/Platform-Arduino-00979D?logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-blue)]()
[![Status](https://img.shields.io/badge/Status-Completed-brightgreen)]()
[![License](https://img.shields.io/badge/License-MIT-yellow)]()

---

## 📖 About the Project

Transformers are essential but expensive components of any power distribution system, and they are highly susceptible to damage when overloaded — leading to winding overheating, insulation failure, and costly downtime.

This project implements an **Automatic Load Sharing Transformer (ALST)** system that:

- Continuously monitors the current load on the **primary transformer** using a current sensor.
- Automatically switches in a **backup transformer** via a relay when the load exceeds a safe threshold.
- Displays real-time load status on an **LCD screen**.
- Enables load to be shared between two transformers in parallel, reducing thermal stress and extending equipment lifespan.
- Supports **priority-based load shedding** when demand exceeds the combined capacity of both transformers, ensuring critical loads (e.g., hospitals) stay powered.

## ✨ Features

- 🔌 Real-time current monitoring using an ACS712/ACS713 current sensor
- 🖥️ Live load status displayed on a 20x4 LCD
- 🔁 Automatic relay-based switching between primary and backup transformer
- 🌡️ Temperature monitoring support (added in the latest firmware revision)
- ⚙️ Simple, low-cost, Arduino UNO–based hardware design
- 🛡️ Prevents transformer overload, reduces maintenance downtime, and improves system reliability

## 🧰 Hardware Components Used

| Component | Purpose |
|---|---|
| Arduino UNO (ATmega328P) | Core microcontroller controlling sensing and switching logic |
| Current Sensor (ACS712/ACS713) | Measures real-time load current on the transformer |
| Relay Module | Switches the backup transformer in/out of the circuit |
| 20x4 LCD Display | Displays live current/load readings and system status |
| Capacitor | Signal filtering/stabilization |
| Switches | Simulate variable consumer load for testing |

## 📁 Repository Structure

```
B.Tech Final Year Project - Load Shedding System/
├── Documents/
│   ├── Major Project Report - Final.pdf     # Complete project report
│   ├── Research Paper.pdf                    # Published research paper
│   └── Certificate - National Conference.pdf # Conference presentation certificate
│
├── Source Code/
│   ├── load_shedding_v1.ino                          # Initial working version
│   ├── load_shedding_v2_update.ino                   # Improved sensitivity & timing logic
│   └── load_shedding_v3_update_with_temp_sensor.ino  # Final version with temperature sensor
│
├── Simulation Files/
│   ├── Load Shedding Simulation - TF1.pdsprj  # Proteus simulation (Scenario 1)
│   └── Load Shedding Simulation - TF2.pdsprj  # Proteus simulation (Scenario 2)
│
└── README.md
```

## 🚀 Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Proteus Design Suite](https://www.labcenter.com/) (to open `.pdsprj` simulation files)

### Running the Code
1. Open the `Source Code/` folder in the Arduino IDE — use `load_shedding_v3_update_with_temp_sensor.ino` for the latest version.
2. Connect the hardware as per the circuit connections detailed in the project report (`Documents/`).
3. Upload the sketch to an Arduino UNO board.
4. Power on the circuit — load readings will appear on the LCD, and the relay will automatically engage the backup transformer on overload.

### Running the Simulation
1. Open Proteus Design Suite.
2. Load either `.pdsprj` file from `Simulation Files/` to view the pre-built circuit simulation.

## 📄 Documentation

- **Project Report** — full methodology, literature review, circuit design, and results (`Documents/Minor Project Report - Final.docx`)
- **Research Paper** — presented at the *2nd National Conference on Emerging Trends in Science & Technology* (`Documents/Research Paper.pdf`)
- **Certificate** — proof of presentation at the national conference (`Documents/Certificate - National Conference.pdf`)

## 🔮 Future Scope

- IoT integration for remote, real-time monitoring
- Advanced sensors for more precise load management
- Energy storage integration to buffer peak loads
- Machine learning–based predictive maintenance
- Scalability into smart-grid power distribution systems

## 👥 Team

Department of Electrical Engineering, Government Engineering College, Banka

## 📜 License

This project is intended for academic and educational purposes.
