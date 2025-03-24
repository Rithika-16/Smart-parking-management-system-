const ESP32_IP = "http://192.168.0.120"; // Replace with your ESP32 IP

function updateParkingStatus() {
    fetch(`${ESP32_IP}/getData`) // Corrected: Added backticks
    .then(response => response.json())
    .then(data => {
        console.log("Received Data:", data); // Check if data is received
        
        // Debugging: Ensure element IDs exist
        ["slot1", "slot2", "slot3"].forEach(slot => {
            if (!document.getElementById(slot)) console.error(`Element ${slot} not found!`);
        });

        // Update slots
        document.getElementById("slot1").className = data.slot1 ? "slot free" : "slot occupied";
        document.getElementById("slot2").className = data.slot2 ? "slot free" : "slot occupied";
        document.getElementById("slot3").className = data.slot3 ? "slot free" : "slot occupied";
        
    })
    .catch(error => console.error("Error fetching data:", error));
}

// Refresh every 3 seconds
setInterval(updateParkingStatus, 3000);
