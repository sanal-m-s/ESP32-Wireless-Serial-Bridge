import serial
import threading

PORT = "COM5"     # change on each laptop
BAUD = 115200

ser = serial.Serial(PORT, BAUD)

def receive():
    while True:
        try:
            data = ser.readline().decode(errors="ignore")
            if data:
                print("\nRemote:", data)
        except:
            pass

threading.Thread(target=receive, daemon=True).start()

while True:
    msg = input("You: ")
    ser.write((msg + "\n").encode())