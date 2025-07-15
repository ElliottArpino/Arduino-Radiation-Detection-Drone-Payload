# ESP32-Radiation-Detection-Drone-Payload

Autonomous drone payload system for radiation monitoring, built using ESP32, Geiger counter, GPS, SD card logging, and real-time Wi-Fi data transmission.

## Subsystems Included
- **ESP32_Code**: Microcontroller code for interfacing Geiger counter, GPS module, SD card, and Wi-Fi.
[View ESP32 code (.ino)](./)
- **live_processing**: MATLAB scripts for real-time data acquisition via ESP32 Wi-Fi.
[View Full Project Report (PDF)](./report.pdf)
- **post_processing**: MATLAB scripts for analyzing logged CSV data to generate radiation heatmaps.
- **Hardware_Docs**: Payload block diagrams, BOM, and optional CAD/structural design info.
- **Final_Project_Report**: Full Phase III Systems Engineering report (Toronto Metropolitan University - Fall 2024).

## Technologies Used
- **Microcontroller**: ESP32
- **Software**: Arduino IDE, MATLAB
- **Sensors**: Geiger-Müller counter, GPS (ATGM336H)
- **Storage**: SD Card (SPI interface)

## Features
- Real-time Wi-Fi streaming of radiation and GPS data
- Redundant SD card logging for post-flight data recovery
- MATLAB visualization of radiation intensity over geolocation
- Lightweight and low-cost design (under 300g and $50)

## Authors
- Elliott Arpino  
- Khadeeja Azizi  
- Maia Elizabeth Gorham  
- Abigail Marsella  
- Fadia Matti

## License
This project is for educational use and research demonstration only.
