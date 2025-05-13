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

Requires a C++ compiler supporting C++20 (e.g., g++, clang++)

✅ Features
🔐 User Registration and Login

🏟 Add and View Stadiums

📆 Book Stadiums with Availability Check

📋 View All Bookings

🔁 Logout and Session Switching

💾 Persistent Data Saved to Files

📈 Future Enhancements
⭐ Add user reviews and stadium ratings

🛠 Edit or delete existing stadiums and bookings

🖥 Build a GUI version using Qt or another framework

🔁 Import/Export data via CSV or JSON

👨‍💻 Developer Guide
Start from MenuSystem.cpp to modify application flow

Add new fields by updating corresponding .h files

Data is saved and loaded via .serialize() / .deserialize()

Integrate new entities into relevant managers

📄 License
This project is currently for academic and personal learning purposes.



