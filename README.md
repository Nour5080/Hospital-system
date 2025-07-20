# 🏥 Simple Clinic Queue Management System

A simple command-line based hospital queue management system written in **C++**.  
It handles patients across **multiple specializations**, supports both **regular and urgent** cases, and maintains a **fixed-size queue** for each specialization.

---

## 📌 Features

- ✅ Add new patient (urgent or regular)
- 📋 View all patients in all specializations
- 👨‍⚕️ Call the next patient to the doctor
- ❌ Prevent queue overflow (max 5 patients per specialization)
- 🎯 Prioritize urgent patients by placing them at the front of the queue

---

## 🧠 How It Works

- The system supports up to **20 specializations**, each with a queue size of **5 patients** max.
- Each patient has:
  - a **name**
  - a **status** (0 = regular, 1 = urgent)
- **Urgent patients** are added at the front of the queue using a right shift.
- **Regular patients** are added at the end.
- Patients are served **in order**, with urgent cases prioritized.

---

## 💻 Technologies

- Language: **C++**
- Platform: **Terminal / Console**
- No external libraries used

---

## 🚀 Running the Program

1. Open any C++ IDE or terminal.
2. Compile and run the file:
   ```bash
   g++ main.cpp -o clinic_system
   ./clinic_system
📸 Sample Menu

Enter Your Choice
1) Add new patient
2) Print all patients
3) Get next patient
4) Exit
📂 File Structure
clinic_system.cpp – Main source code file

README.md – Project documentation

🧪 Future Improvements (Ideas)
Add input validation and better error handling

Support dynamic queue sizes

Add GUI using Qt or connect to a database for patient records

🙋 Author
Created by Nour Mohamed
Faculty of Science – Statistics & Computer Science Department – Ain Shams University

🪪 License
This project is open-source and available for educational use.
