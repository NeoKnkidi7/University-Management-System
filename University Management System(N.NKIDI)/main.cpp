//N.K NKIDI 45979278
// University Student Management System


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>


using namespace std;

//Defining structures
struct Student {
    //Initiating the name and declaring it as a string
    string name;
    //Initiating the student number and declaring it as a integer
    int studentNum;
    //Initiating the student fees and declaring it as a double
    double studentFees;
};

//Declaring the class
class StudentLecturer {
private:
    //having the array of students stored in a pointer
    Student* students;
    //Initializing the number of students and declaring it to an integer
    int numOfStudents;
    //Initializing the maximum number of students and declaring it to an integer
    int maxNumOfStudents;

public:
    // Declaring a constructor to initialize the the lectures students with a maximum number of students
    StudentLecturer(int max) {
        maxNumOfStudents = max;
        numOfStudents = 0;
        //Placing the memory for students
        students = new Student[maxNumOfStudents];
    }

    //Declaring a destructor to release the allocated memory
    ~StudentLecturer() {
        delete[] students;
    }

    //Initializing a AddStudent fuction with pointers
    void AddStudent(const Student& student) {
        //Implementing if and else statements for decision making about the adding of number  of students and limit
        if (numOfStudents < maxNumOfStudents) {
            students[numOfStudents] = student;
            //Implementing incremetion
            numOfStudents++;
        } else {
            cout << "Maximum number of students is reached." << endl;
        }
    }

    // Declaring fuction ListStudents to determine if there is any student's data in the system
    void ListStudents() {
        if (numOfStudents == 0) {
                //Displaying the message if the system is empty
            cout << "No students in the system." << endl;
        } else { //Displaying the students list if the system has data
            cout << "Student List:" << endl;
            for (int i = 0; i < numOfStudents; i++) {
                cout << "\nName: " << students[i].name << "\nStudent Number: " << students[i].studentNum << "\nStudent Fees: R " << students[i].studentFees << endl;
            }
        }
    }

    //Declaring The SaveToFile function for storing of data that the user required to store
    void SaveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
                //Implementing  FOR loop
            for (int i = 0; i < numOfStudents; i++) {//Initializing , limitations or conditions , incremation
                outFile << students[i].name << "," << students[i].studentNum << "," << students[i].studentFees << endl;
            }
            outFile.close();
        //Message displayed if data is successfully saved
            cout << "Student data saved to file successfully." << endl;
        } else {
            cout << "Error" << endl;
        }
    }
};

int main() {
    //Displaying Heading
    cout << "\nUniversity Student Management System" << endl;
    cout<< " " << endl;
    //Initializing the maxNumOfStudents and declaring it to an integer
    int maxNumOfStudents;
    //Prompting the user for input
    cout << "Enter the maximum number of students: ";
    cin >> maxNumOfStudents;

    //Creating an instance for the StudentLecturer
    StudentLecturer studentLecturer(maxNumOfStudents);
    //Initializing the choice variable to an integer
    int choice;

    //Implementing do-while loop for post-testing
    do {
            //Displaying Heading and Menu
        cout << "\nUniversity Student Management System Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. List Students" << endl;
        cout << "3. Save Student Data to File (refer to name of the student/student number/student fees)" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        //Implementing switch statement for various decision making
        switch (choice) {
            case 1: {
                //Displaying conditions for choice 1
                Student student;
                cin.ignore();
                //Prompting the user for input
                cout << "Enter student name: ";
                getline(cin, student.name);
                //Prompting the user for input
                cout << "Enter student number: ";
                cin >> student.studentNum;
                //Prompting the user for input
                cout << "Enter student Fees: R ";
                cin >> student.studentFees;
                studentLecturer.AddStudent(student);
                break;
            }
            case 2:
                studentLecturer.ListStudents();
                break;
            case 3: {
                //Declaring filname to a string variable
                string filename;
                //Prompting the user for inpugt
                cout << "Enter filename to save: ";
                cin >> filename;
                studentLecturer.SaveToFile(filename);
                break;
            }
            case 4:
                //Exiting program
                cout << "Exiting the program , Hope you enjoyed your experience....." << endl;
                break;
            default:
                //Default for invalid input/choice
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4 && choice > 0);//Conditions that need to be met for every iteration to be successsfull

    return 0;
}
