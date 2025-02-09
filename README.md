# Student Management System

## Description
This is a simple Student Information Management System implemented in C. It allows users to add, update, search, and display student records. The data is stored in a text file to maintain persistence between program executions.

## Features
- **Login Authentication**: A basic login system for security.
- **Add Student**: Add a new student's information.
- **Update Student Info**: Modify existing student details.
- **Find Student Info**: Retrieve details of a student by their ID.
- **Count Students**: Display the total number of students.
- **Print Database**: List all students in a formatted manner.
- **Persistent Storage**: Reads from and writes to a text file (`StudentManagement.txt`).

## Compilation & Execution
### Compile:
```sh
gcc student_management.c -o student_management
```

### Run:
```sh
./student_management
```

## Usage
1. **Login**: Enter username and password (`student`/`student`).
2. **Choose an option** from the menu to perform operations.
3. **Exit** to save data to the file.

## File Structure
- `student_management.c` - Main program file.
- `StudentManagement.txt` - Stores student records.
- `README.md` - Documentation.

## Future Enhancements
- Implement a graphical user interface (GUI).
- Add more security features.
- Support database integration.

## Author
Md. Zubayer Hossain Patowari

