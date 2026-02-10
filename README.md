# 🏥 Hospital Management System (C Programming)

A comprehensive command-line interface (CLI) application designed to manage hospital operations efficiently. This project demonstrates the practical application of **Nested Structures**, **Modular Functions**, and **Binary File Handling** to manage patient and doctor records.

---

## 🚀 Key Features
* **Patient Registration:** Store patient details including Name, Age, Disease, and Assigned Ward.
* **Doctor Database:** Maintain a record of available doctors and their specializations.
* **Appointment Scheduling:** Link patients to specific doctors.
* **Persistent Storage:** All records are saved in `.dat` files, allowing the system to reload data after a restart.
* **Record Search:** Quickly find patient history using a unique Patient ID.

---

## 🛠️ Technical Overview
This system is architected using:

1. **Structures:** To handle complex data types (e.g., a `Patient` struct containing a `Date` struct for admission).
2. **File I/O:** Using `rb+`, `ab+`, and `wb` modes to ensure data is updated without overwriting the entire database.
3. **Search & Sort:** Simple algorithms to organize records by ID or Name.

---

## 📂 File Structure
```bash
.
├── hospital_main.c   # Main menu and execution flow
├── records.dat       # Binary file containing encrypted/raw data
├── patient_logs.txt  # Human-readable logs (optional)
└── README.md         # Project documentation