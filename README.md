# **Student Database Manager**

A **console-based program written in C** that allows **creating**, **viewing**, **editing**, and **deleting student accounts**.  
Each account stores essential details like **Name**, **CGPA**, **Branch**, **Password**, and an **auto-generated SRN (Student Registration Number)**.  
The program features a **menu-driven interface** and supports **multiple operations** in a single session.

---

## **Features**

### **Account Operations**
- **Create Account** – Add a new student with details like **name**, **CGPA**, **branch**, and **password**. Generates a **unique SRN** automatically.  
- **Edit Account** – Modify an existing student’s **name**, **CGPA**, **branch**, or **password** after verifying **SRN** and **password**.  
- **View Account** – Display all details of a student account after **password verification**.  
- **Delete Account** – Permanently delete a student account with confirmation.  
- **Exit** – Close the program safely.

---

## **Account Fields**

| **Field** | **Description** |
|-----------|-----------------|
| **Name**  | **Student’s name** (string input) |
| **CGPA**  | **Floating-point value** (0.0 – 10.0 range) |
| **Branch**| **One of CSE, ECE, MECH, or EEE** |
| **Password** | **Alphanumeric string** (maximum **10 characters**) |
| **SRN**   | **Automatically generated** (example: `25CSE101`) |

---

## **Built-in Admin Access**

- **Admin Password:** `orangecake007`  
- Reserved for future use (**Admin mode not yet implemented**)

---

## **Preloaded Sample Accounts**

| **Name**  | **Branch** | **CGPA** | **Password**            | **SRN**     |
|-----------|------------|----------|-------------------------|-------------|
| **Sid**   | **ECE**    | **9.0**  | **chocolate**           | **25ECE101**|
| **Aman**  | **MECH**   | **8.5**  | **body_builder983**     | **25MECH102**|
| **Suman** | **ECE**    | **8.0**  | **Minecraft_player091** | **25ECE103**|
| **Sachit**| **CSE**    | **9.0**  | **no_password**         | **25CSE104**|

---

## **SRN Format**

The **SRN (Student Registration Number)** is automatically generated in the format:

<Year><Branch><Number>


**Example:**  
`25CSE101` → **Year = 25**, **Branch = CSE**, **Number = 101**

---

## **Input Validation**

- **CGPA** cannot exceed **10.0**  
- **Password length** limited to **10 characters**  
- Only valid branches (**CSE**, **ECE**, **MECH**, **EEE**) are accepted  
- **SRN** must match an existing account for **Edit**, **View**, or **Delete** operations  

---

## **How to Use**

1. **Compile the code** using a C compiler (for example, GCC):  
   ```bash
   gcc student_database_manager.c -o studentdb
2. **Run the program:**
   ./studentdb

3. **Choose an option** from the menu and follow on-screen instructions.

**Example Menu Output**
  ---------------------------------------
Welcome to the Student Database Manager
---------------------------------------
- **Choose from the following options:**
- **Create**  - Create a new account
- **Edit**    - Edit an existing account
- **View**    - View data from an existing account
- **Delete**  - Delete an existing account
- **Exit**    - Exit the program

---

## **Future Improvements**

- **Implement Admin Mode** for viewing/editing all accounts  
- **Add file storage** to make data persistent  
- **Improve password and input validation**  
- **Support more branches** and **year-based SRNs**

---

## **Language and Tools**

Written in **C language** using the following standard libraries:

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
```
## **License**

Open-source project created for **educational purposes** and demonstration of **structure-based programming** in C.


