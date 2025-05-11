# ⚽🏀 CourtMate: Online Sports Stadium Booking System

CourtMate is a C++ console application that streamlines the process of **searching** and **booking football and basketball stadiums**. It provides a simple yet powerful interface for managing users, stadiums, and bookings — all while saving data persistently across sessions.

---

## 📌 Project Goal

The goal of CourtMate is to **automate the search and booking process** for sports venues, allowing users to view details, make reservations, and manage their bookings with ease.

---

## 🧩 Core Components

| Class / File              | Purpose                                                 |
|---------------------------|---------------------------------------------------------|
| `User`, `UserManager`     | User registration, login, and session tracking          |
| `Stadium`, `FootballStadium`, `BasketballStadium` | Abstract and specific stadium types       |
| `StadiumManager`          | Manages the list of stadiums                            |
| `Booking`, `BookingManager` | Booking logic and availability check                  |
| `MenuSystem`              | User interface and main menu                            |
| `CustomExceptions`        | Custom exception handling (optional)                    |

---

## 💾 Data Storage

| File          | Description                                      |
|---------------|--------------------------------------------------|
| `users.txt`   | List of users in `username,password` format      |
| `session.txt` | Last logged-in user                              |
| `stadiums.txt`| All saved stadiums                               |
| `bookings.txt`| All saved bookings                               |

---

## 🛠 Build & Run Instructions

Compile the project using:

```bash
g++ main.cpp MenuSystem.cpp BookingManager.cpp Booking.cpp StadiumManager.cpp FootballStadium.cpp BasketballStadium.cpp user.cpp -o stadium_app
./stadium_app
