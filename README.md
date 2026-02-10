
🏥 Hospital Management System (C Programming)
A comprehensive command-line interface (CLI) application designed to manage hospital operations efficiently. This project demonstrates the practical application of Nested Structures, Modular Functions, and Binary File Handling to manage patient and doctor records.

🚀 Key Features
Patient Registration: Store patient details including Name, Age, Disease, and Assigned Ward.

Doctor Database: Maintain a record of available doctors and their specializations.

Appointment Scheduling: Link patients to specific doctors.

Persistent Storage: All records are saved in .dat files, allowing the system to reload data after a restart.

Record Search: Quickly find patient history using a unique Patient ID.

🛠️ Technical Overview
This system is architected using:

Structures: To handle complex data types (e.g., a Patient struct containing a Date struct for admission).

File I/O: Using rb+, ab+, and wb modes to ensure data is updated without overwriting the entire database.

Search & Sort: Simple algorithms to organize records by ID or Name.

📂 File Structure
Bash
.
├── hospital_main.c   # Main menu and execution flow
├── records.dat       # Binary file containing encrypted/raw data
├── patient_logs.txt  # Human-readable logs (optional)
└── README.md         # Project documentation
💻 Setup and Usage
Prerequisites
GCC Compiler (MinGW for Windows or default GCC for Linux/Mac).

How to Run
Clone this repo:

Bash
git clone https://github.com/yourusername/hospital-management-c.git
Compile:

Bash
gcc hospital_main.c -o hospital_app
Run:

Bash
./hospital_app
📋 Data Structure Example
The project is built around the following structure logic:

C
struct Patient {
    int id;
    char name[50];
    char disease[30];
    int cabin_no;
};
🤝 Contributing
Feel free to fork this project, report bugs, or submit pull requests for new features like "Billing Systems" or "Pharmacy Inventory."