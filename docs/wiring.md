# Wiring Guide

## Laptop A

```text
Laptop A
   │
USB Cable
   │
ESP32-A
```

No additional wiring is required.

The USB cable provides:

* Power
* Serial communication

---

## Laptop B

```text
Laptop B
   │
USB Cable
   │
ESP32-B
```

No additional wiring is required.

The USB cable provides:

* Power
* Serial communication

---

## Network

Both ESP32 boards must be connected to the same Wi-Fi network.

Example:

```text
ESP32-A  ---> Wi-Fi Router <--- ESP32-B
```

---

## Verify Connection

Open Arduino Serial Monitor.

ESP32-A should display:

```text
WiFi Connected
IP Address: 192.168.1.100
Server Started
```

ESP32-B should display:

```text
WiFi Connected
Connected To Server
```
