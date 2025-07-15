# ESP32-Radiation-Detection-Drone-Payload

Autonomous drone payload system for radiation monitoring, built using ESP32, Geiger counter, GPS, SD card logging, and real-time Wi-Fi data transmission.

## Subsystems Included
- [ESP32 code (.ino)](./ESP32_code.ino): Microcontroller code for interfacing Geiger counter, GPS module, SD card, and Wi-Fi.<br>
- [Live Processing (.m)](./live_processing.m): MATLAB scripts for real-time data acquisition via ESP32 Wi-Fi.<br>
- [Post Processing (.m)](./post_processing.m): MATLAB scripts for analyzing logged CSV data to generate radiation heatmaps.<br>
- [Final Project Report (.pdf)](./Project_Phase_III_Report.pdf): Full Phase III Systems Engineering report (Toronto Metropolitan University - Fall 2024).<br>

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
