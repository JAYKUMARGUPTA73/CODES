# ground_station.py

import socket

# Set up socket
host = '0.0.0.0'  # Listen on all network interfaces
port = 12345
buffer_size = 1024

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the address and port
server_socket.bind((host, port))

# Listen for incoming connections
server_socket.listen(1)
print("Ground station waiting for connection...")

# Accept a connection
client_socket, client_address = server_socket.accept()
print("Connected to:", client_address)

try:
    while True:
        # Receive telemetry data
        data = client_socket.recv(buffer_size)
        if not data:
            break
        print("Received telemetry data:", data.decode())

except KeyboardInterrupt:
    print("\nClosing connection...")
    client_socket.close()
    server_socket.close()
