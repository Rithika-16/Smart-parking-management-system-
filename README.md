# 🚗 Smart Parking Slot Management System  

A real-time **parking slot monitoring system** using **ESP32, infrared sensors, and a web-based dashboard**. The system detects available parking slots and updates the data dynamically on a web interface.  

## 📌 Features  
- 🚦 **Real-time Parking Detection** – Uses **infrared sensors** to monitor parking slots.  
- 🌐 **Web-based Dashboard** – Displays live parking availability using **HTML, CSS, and JavaScript**.  
- 🔄 **ESP32 as a Web Server** – Sends real-time parking data in **JSON format**.  
- 📡 **Wireless Communication** – No external backend, ESP32 handles direct data transmission.  
- ⚡ **Efficient & Scalable** – Low-power consumption and scalable for multiple parking slots.  

## 🛠️ Tech Stack  
- **Hardware:** ESP32, Infrared Sensors  
- **Web Technologies:** HTML, CSS, JavaScript  
- **Communication:** JSON, HTTP Requests  

## 🚀 How It Works  
1. **Infrared sensors** detect whether a parking slot is occupied or free.  
2. **ESP32 processes the sensor data** and acts as a web server.  
3. The **web dashboard fetches live data** from ESP32 and updates the parking status in real-time.  
 
## 🔧 Setup & Installation  
### 1️⃣ Hardware Setup  
- Connect **ESP32** with **infrared sensors** following the circuit diagram.  

### 2️⃣ ESP32 Code Upload  
- Flash the provided Arduino code to ESP32 using the **Arduino IDE**.  

### 3️⃣ Run Web Dashboard  
- Open the **HTML file** in a browser to view real-time updates.  

## 📜 Future Enhancements  
- 📲 Mobile app for remote monitoring.  
- 🚘 Vehicle detection using **camera-based AI**.  
- ☁️ Cloud-based storage for historical parking data.  

