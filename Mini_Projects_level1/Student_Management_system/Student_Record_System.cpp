#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>
#include <cstdio>
#include <fstream>
using namespace std;

struct Student
{
    int ID;
    string name;
    int age;
    string course;
    float marks;
};
int find_student(int id, Student *sd, int count);

// Verification Section Verifying Id, Age, Name, Marks, Course;
int getValidId()
{
    int id;
    string input;
    while (true)
    {
        cout << " Enter Student Id: ";
        getline(cin, input);
        stringstream ss(input);
        if (!(ss >> id) || (ss >> ws, !ss.eof()) || id < 1)
        {
            cout << " Invalid id!\n Try Again.";
        }
        else
        {
            break;
        }
    }
    return id;
}

float getValidMarks()
{
    float marks;
    string input;
    while (true)
    {
        cout << " \nEnter the marks: ";
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> marks) || (ss >> ws, ss.peek() != EOF) || marks > 100 || marks < 0)
        {
            cout << " Invalid Marks! Try Again.";
        }
        else
        {
            break;
        }
    }
    return marks;
}

int getValidAge()
{
    string input;
    int age;
    while (true)
    {
        cout << " Enter your Age: ";
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> age) || !ss.eof() || age < 1 || age > 100)
        {
            cout << " Invalid Age! \n Try Again\n";
        }
        else
        {
            break;
        }
    }
    return age;
}

string getValidName()
{
    string name;
    bool correctName;
    while (true)
    {
        correctName = true;
        cout << " Enter Studetn's Name: ";
        getline(cin, name);

        if (name.empty())
        {
            correctName = false;
        }

        for (char ch : name)
        {
            unsigned char uch = static_cast<unsigned char>(ch);

            if (!isalpha(uch) && ch != ' ' && ch != '-' && ch != '\'')
            {
                correctName = false;
                break;
            }
        }

        if (correctName)
        {
            return name;
        }
        cout << " Invalid name! Try again.\n";
    }
}

string getValidCourse()
{
    string select;
    string courses[] = {
        "BSc-IT",
        "BCA",
        "BTech",
        "MCA",
        "MSc-IT",
        "BCom"};
    int courseCount = 6;

    bool correctCourse;
    while (true)
    {
        correctCourse = false;
        cout << " Select Your Course.\n";
        for (string course : courses)
        {
            cout << course << ", ";
        }
        cout << ": ";
        getline(cin, select);
        for (int i = 0; i < courseCount; i++)
        {
            if (select == courses[i])
            {
                correctCourse = true;
                break;
            }
        }

        if (!correctCourse)
        {
            cout << " Please Enter the correct Course! \n";
        }
        else
        {
            break;
        }
    }
    return select;
}

int getValidCount(int count)
{
    int Ecount;
    string input;
    while (true)
    {
        getline(cin, input);
        stringstream ss(input);
        if (!(ss >> Ecount) || (ss >> ws, ss.peek() != EOF) || Ecount < 1 || Ecount + count > 50)
        {
            cout << " Invalid input! Try Again!\n";
        }
        else
        {
            break;
        }
    }
    return Ecount;
}

// Students Entry Function
void studentsEntry(Student *sd, int *count)
{
    int dublicateCheck;
    int numberOfEntry;
    numberOfEntry = getValidCount(*count);
    int id;
    if (*count + numberOfEntry <= 50)
    {
        for (int i = *count; i < *count + numberOfEntry; i++)
        {
            while (true)
            {
                id = getValidId();
                dublicateCheck = find_student(id, sd, i);

                if (dublicateCheck != -1)
                {
                    cout << " Student id exists!! \n Enter a different id.";
                }
                else
                {
                    sd[i].ID = id;
                    break;
                }
            }
            sd[i].name = getValidName();
            sd[i].age = getValidAge();
            sd[i].course = getValidCourse();
            sd[i].marks = getValidMarks();
        }

        *count += numberOfEntry;
    }
    else
    {
        cout << " Storage is not Available!!" << endl;
    }
}

// Students Data Retriving Function
void viewStudentsData(Student *sd, int count)
{
    if (count == 0)
    {
        cout << " 0 student record exists!" << endl;
    }
    else
    {
        cout << " Students Data" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << " ID:" << sd[i].ID << endl
                 << " Name: " << sd[i].name << endl
                 << " Age: " << sd[i].age << endl
                 << " Course: " << sd[i].course << endl
                 << " Marks: " << sd[i].marks << endl;
            cout << endl;
        }
    }
}

// //Finding section
// finding students
int find_student(int id, Student *sd, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (id == sd[i].ID)
        {
            return i;
        }
    }
    return -1;
}

//

// data of searched student
void searchedStudent(Student *sd, int count)
{
    int id;

    if (count != 0)
    {

        cout << " Enter the id: ";
        id = getValidId();
        int index = find_student(id, sd, count);

        if (index != -1)
        {
            cout << " ID:" << sd[index].ID << endl
                 << " Name: " << sd[index].name << endl
                 << " Age: " << sd[index].age << endl
                 << " Course: " << sd[index].course << endl
                 << " Marks: " << sd[index].marks << endl;
        }
        else
        {
            cout << " Student Not found!!" << endl;
        }
    }
    else
    {
        cout << " No student records available!!\n";
    }
}

// Finding Heighest Marks
void heighestMarkStudent(Student *sd, int count)
{
    if (count != 0)
    {
        float maxMarks = sd[0].marks;
        int index = 0;
        for (int i = 1; i < count; i++)
        {
            if (maxMarks < sd[i].marks)
            {
                maxMarks = sd[i].marks;
                index = i;
            }
        }
        cout << " Student With the Heightes Marks.\n";
        cout << " ID:" << sd[index].ID << endl
             << " Name: " << sd[index].name << endl
             << " Age: " << sd[index].age << endl
             << " Course: " << sd[index].course << endl
             << " Marks: " << sd[index].marks << endl;
    }
    else
        cout << " No student records available!!\n";
}
// Average Marsk
void averageMarks(Student *sd, int count)
{
    if (count != 0)
    {
        float sum = 0;
        for (int i = 0; i < count; i++)
        {
            sum += sd[i].marks;
        }

        cout << " Average Marks Of the Students is: " << sum / count << endl;
    }
    else
        cout << " No student records available!!\n";
}

// Update marks
void updatedMarks(Student *sd, int count)
{
    int index;
    int id;
    if (count != 0)
    {
        id = getValidId();
        index = find_student(id, sd, count);

        if (index != -1)
        {
            float newMarks = getValidMarks();
            sd[index].marks = newMarks;
        }
        else
        {
            cout << " Student not found.\n";
        }
    }
    else
        cout << " No student records available!!\n";
}

// Deleting student
void deleteStudent(Student *sd, int *count)
{
    int index;
    int id;
    if (*count != 0)
    {
        id = getValidId();
        index = find_student(id, sd, *count);

        if (index != -1)
        {
            for (int i = index; i < *count - 1; i++)
            {
                sd[i] = sd[i + 1];
            }
            *count -= 1;
            cout << " Student deleted successfully!\n";
        }
        else
        {
            cout << " Student not found.\n";
        }
    }
    else
        cout << " No student records available!!\n";
}

void operationCenter(Student *sd, int *count)
{
    int choice = 0;
    string input;
    while (choice != 8)
    {
        while (true)
        {
            cout << "\n--------------Menu--------------\n"
                 << " 1. Register or Add student data.\n"
                 << " 2. Search for a student.\n"
                 << " 3. Update a student Marks.\n"
                 << " 4. Delete a student data.\n"
                 << " 5. Find Average Marks of the students.\n"
                 << " 6. Find the student with heighest marks.\n"
                 << " 7. View All students Data.\n"
                 << "8. Exit.\n";

            choice = 0;
            getline(cin, input);
            stringstream ss(input);

            if (!(ss >> choice) || (ss >> ws, ss.peek() != EOF) || choice < 1 || choice > 8)
            {
                cout << " Invalid choice!\n Try Again!" << endl;
            }
            else
            {
                break;
            }
        }

        switch (choice)
        {
        case 1:
            studentsEntry(sd, count);
            break;
        case 2:
            searchedStudent(sd, *count);
            break;
        case 3:
            updatedMarks(sd, *count);
            break;
        case 4:
            // Delete
            deleteStudent(sd, count);
            break;
        case 5:
            // Average Marks
            averageMarks(sd, *count);
            break;
        case 6:
            heighestMarkStudent(sd, *count);
            break;
        case 7:
            // View all students
            viewStudentsData(sd, *count);
            break;
        case 8:
            break;
        }
    }
}

// Storing and Retreiving functions

// Saving Data
void saveData(Student sd[], int count)
{
    ofstream file;
    file.open("Student.txt");

    if (!file.is_open())
    {
        cout << " Unable to open file!\n";
        return;
    }
    // file << count << ",\n";
    for (int i = 0; i < count; i++)
    {
        file << sd[i].ID << ","
             << sd[i].name << ","
             << sd[i].age << ","
             << sd[i].course << ","
             << sd[i].marks << "\n";
    }
    file.close();
    cout << " Data saved!\n";
}

// Retreiving Data
void loadData(Student sd[], int &count)
{
    ifstream file;
    file.open("Student.txt");

    if (!file.is_open())
    {
        cout << " File not found!\n";
        return;
    }

    string line;
    while (getline(file, line) && count < 50)
    {
        stringstream ss(line);
        string ID, name, age, course, marks;

        getline(ss, ID, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, course, ',');
        getline(ss, marks, ',');

        try
        {
            sd[count].ID = stoi(ID);
            sd[count].name = name;
            sd[count].age = stoi(age);
            sd[count].course = course;
            sd[count].marks = stof(marks);
            count++;
        }
        catch (const exception &e)
        {
            cout << "Invalid record skipped: " << e.what() << '\n';
        }
    }
}

int main()
{
    Student studentsData[50];
    int studentEntryCount = 0;

    // LoadData
    loadData(studentsData, studentEntryCount);
    operationCenter(studentsData, &studentEntryCount);

    // savedata
    saveData(studentsData, studentEntryCount);

    return 0;
}
