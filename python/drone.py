# drone.py

import socket
import time

# Set up socket
host = '192.168.1.10' # Replace with the ground station's IP address
port = 12345

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the ground station
client_socket.connect((host, port))
print("Connected to ground station")

try:
    while True:
        # Generate telemetry data (example: altitude)
        altitude = 100  # Example value
        
        # Send telemetry data to the ground station
        client_socket.send(str(altitude).encode())
        print("Sent telemetry data:", altitude)
        
        # Wait for some time before sending the next telemetry data
        time.sleep(1)

except KeyboardInterrupt:
    print("\nClosing connection...")
    client_socket.close()
