# Data Acquisition and Supervision System
This project focuses on implementing object-oriented programming practices using the Qt library. It simulates a simple data acquisition and supervision system using TCP/IP communication over a local network. The system consists of three components: a server, a data producer client, and a data supervisor client.

## Overview
The three modules perform the following operations:

- **Server**:
   - Listens for TCP connections on port 1234.
   - Responds to commands sent by connected clients.
- **Data Producer Client**:
   - Connects to a machine running the server on port 1234.
   - Sends timestamped floating-point data using specific commands.
- **Data Supervisor Client**:
   - Connects to a machine running the server on port 1234.
   - Retrieves:
        - A list of connected data producer clients.
        - Data logs produced by a specific client.


## Features
### Data Producer Client
- Allows users to:
   - Specify the server's IP address.
   - Define a range of values (`min` and `max`) for the data being sent.
   - Set the interval between data transmissions.
   - Start and stop data transmission.
- Displays a log of all transmitted data in real-time.
### Data Supervisor Client
- Allows users to:
   - Retrieve a list of connected data producer clients.
   - View data logs produced by a specific data producer.
## Technical Details
### Requirements
- **Qt Framework**: Ensure Qt is installed (version 5.15 or newer recommended).
- **Compiler**: A C++ compiler compatible with Qt (e.g., GCC, Clang, MSVC).
- **Operating System**: Cross-platform (tested on Windows, Linux, and macOS).
### Build Instructions
1. Clone this repository:

```bash
git clone https://github.com/arthur1041/tcp-ip-data-acquisition.git
cd data-acquisition-system
```

2. Open the project in Qt Creator:
   - Launch **Qt Creator**.
   - Open the .pro file in the project directory.
3. Configure the build:
   - Set up a build kit (e.g., Desktop GCC or MSVC).
4. Build the project:
   - Click on **Build** > **Build All** or press Ctrl+B.

### Run Instructions
- **Server**:
   - Ensure the server is running on port 1234 before starting the clients.
- **Data Producer Client**:
   - Run the executable for the producer client.
   - Input the server's IP address, set the data range, and define the transmission interval.
   - Start and stop data transmission using the provided buttons.
- **Data Supervisor Client**:
   - Run the executable for the supervisor client.
   - Connect to the server to retrieve the list of producer clients and their data logs.

## Notes
- The server must be running before attempting to connect with the clients.
- Logs for both clients are displayed in real-time within their respective interfaces.
- Ensure all devices (server and clients) are on the same local network.
