Student Record Manager
A console-based C++ project for managing student records using
structures, functions, arrays, and file handling.
Features
- Add student records
- Display all student records
- Search for a student by ID
- Update a student's marks
- Delete a student record
- Calculate the average marks
- Find the student with the highest marks
- Save records to a text file when the program exits
- Load saved records when the program starts
- Validate user input
- Handle invalid numeric data during file loading with try-catch
Concepts Practised
- C++ structures (struct)
- Functions and function parameters
- Arrays and pointers
- Input validation with getline() and stringstream
- String parsing with stringstream
- File handling with ifstream and ofstream
- Exception handling with try-catch
- Searching and basic array operations
Note: This project uses procedural programming and a struct. It
does not yet implement classes or object-oriented design.

Storage
Student records are stored in Student.txt.

Each record follows this comma-separated format:
ID,Name,Age,Course,Marks
Example:
101,Rex,16,BCA,89
102,Ren,17,BCom,78
The program loads records from the file at startup and saves the current
records when the user exits.
Storage Limit
The program currently uses a fixed-size array with a maximum capacity of
50 student records.
Build and Run
Compile with a C++ compiler:
g++ Student_Record_System.cpp -o StudentRecordManager
Run on Windows:
StudentRecordManager.exe
Run on Linux/macOS:
./StudentRecordManager
Learning Outcome
This project was built to practise procedural C++ and apply file
persistence, input parsing, validation, and exception handling in a
working program. It is a learning project, not a production-grade
student management system.
