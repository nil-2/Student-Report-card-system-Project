# Student-Report-card-system-Project
This is a simple Student Report Card Project developed in C++ using the Code::Blocks IDE. The program allows users to input student details, including name, roll number, and marks in various subjects. It then calculates the total marks, average marks, and assigns a grade based on the average score.

## Features

-> Input student details like name, roll number, and marks.
-> Display the student’s details and marks.
-> Calculate total marks and average marks.
-> Display the grade based on the average score.
-> Support for multiple students (you can extend the program to handle more than one student).

## Requirements

- Code::Blocks IDE / Visual Studio Code (or any C++ compiler).
- Basic knowledge of C++ programming concepts such as functions, loops, conditionals, and arrays.

## How to Run

1. Download and install [Code::Blocks IDE](http://www.codeblocks.org/downloads/26) (if not already installed).
2. Open the `StudentReportCard.cpp` file in Code::Blocks.
3. Build and run the project by pressing the `Build and Run` button in Code::Blocks or pressing `F9`.
4. The program will prompt you to input the student details. Enter the student name, roll number, and marks.
5. The program will display the student report card with the total marks, average, and grade.

## Example Output

```
Enter student name: John Doe
Enter roll number: 12345
Enter marks for Subject 1: 85
Enter marks for Subject 2: 78
Enter marks for Subject 3: 92
Enter marks for Subject 4: 88

Student Report Card:
--------------------------------------
Name: John Doe
Roll Number: 12345
Total Marks: 343
Average Marks: 85.75
Grade: A
--------------------------------------
```

## Code Structure

- `main()` – The entry point where the program starts.
- `inputStudentDetails()` – Function to input student details.
- `calculateGrade()` – Function to calculate the grade based on the average.
- `displayReportCard()` – Function to display the report card.

## Modifications

You can easily modify this program to:

- Handle multiple students.
- Add more subjects.
- Implement more complex grading systems.

## License

This project is open source and free to use for educational purposes.

