#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

struct Student {
    string studentID;
    string yearLevel;
    string department;
    string program;  
    string lastName;
    string firstName;
    string middleInitial;
    string contactNo; 
    string sex;
};

vector<Student> students;

string toUpperCase(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

bool isDuplicateID(const string& id) {
    string upperID = toUpperCase(id);
    for (const auto& student : students) {
        if (toUpperCase(student.studentID) == upperID) {
            return true; 
        }
    }
    return false; 
}

bool isValidContactNo(const string& contactNo) {
    return contactNo.length() == 11 && all_of(contactNo.begin(), contactNo.end(), ::isdigit);
}

bool isValidYearLevel(const string& year) {
    return year == "1" || year == "2" || year == "3" || year == "4";
}

bool isValidSex(const string& sex) {
    return sex == "M" || sex == "m" || sex == "F" || sex == "f";
}

template<typename T>
void getInput(const string& prompt, T& value, bool (*validationFunc)(const T&) = nullptr) {
    while (true) {
        cout << prompt;
        getline(cin, value);
        if (validationFunc == nullptr || validationFunc(value)) {
            break; 
        }
        cout << "Error: Invalid input. Please try again.\n";
    }
}

bool isDuplicateContactNo(const string& contactNo) {
    for (const auto& student : students) {
        if (student.contactNo == contactNo) {
            return true; 
        }
    }
    return false; 
}

void insertRecord() {
    Student newStudent;

    cout << "\n= = = Add New Student Record = = =\n";

    getInput("Enter Student ID: ", newStudent.studentID);
    while (newStudent.studentID.empty() || isDuplicateID(newStudent.studentID)) {
        cout << "Error: Student ID already exists or is empty. Please enter a unique ID.\n";
        getInput("Enter Student ID: ", newStudent.studentID);
    }

    newStudent.studentID = toUpperCase(newStudent.studentID);

    getInput("Enter Year Level (1-4): ", newStudent.yearLevel, isValidYearLevel);

    getInput("Enter Department: ", newStudent.department);
    while (newStudent.department.empty()) {
        cout << "Error: Department cannot be empty. Please enter again:\n";
        getInput("Enter Department: ", newStudent.department);
    }

    getInput("Enter Program: ", newStudent.program);
    while (newStudent.program.empty()) {
        cout << "Error: Program cannot be empty. Please enter again:\n";
        getInput("Enter Program: ", newStudent.program);
    }

    getInput("Enter Last Name: ", newStudent.lastName);
    while (newStudent.lastName.empty()) {
        cout << "Error: Last Name cannot be empty. Please enter again:\n";
        getInput("Enter Last Name: ", newStudent.lastName);
    }

    getInput("Enter First Name: ", newStudent.firstName);
    while (newStudent.firstName.empty()) {
        cout << "Error: First Name cannot be empty. Please enter again:\n";
        getInput("Enter First Name: ", newStudent.firstName);
    }

    getInput("Enter Middle Initial: ", newStudent.middleInitial);
    while (newStudent.middleInitial.empty()) {
        cout << "Error: Middle Initial cannot be empty. Please enter again:\n";
        getInput("Enter Middle Initial: ", newStudent.middleInitial);
    }

    getInput("Enter Contact Number: ", newStudent.contactNo, isValidContactNo);
    while (isDuplicateContactNo(newStudent.contactNo)) {
        cout << "Error: Contact Number already exists. Please enter a unique Contact Number:\n";
        getInput("Enter Contact Number: ", newStudent.contactNo, isValidContactNo);
    }

    getInput("Enter Sex (M/F): ", newStudent.sex, isValidSex);

    students.push_back(newStudent);
    cout << "\nStudent record added successfully!\n";
}

void viewRecords() {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n= = = Student Records = = =\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\nRecord " << i + 1 << ":\n";
        cout << "Student ID: " << students[i].studentID << endl;
        cout << "Year Level: " << students[i].yearLevel << endl;
        cout << "Department: " << students[i].department << endl;
        cout << "Program: " << students[i].program << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Middle Initial: " << students[i].middleInitial << endl;
        cout << "Contact Number: " << students[i].contactNo << endl; 
        cout << "Sex: " << students[i].sex << endl;
    }
}

void updateRecord() {
    string studentID;
    cout << "\n= = = Update Student Record = = =\n";
    cout << "Enter Student ID to update: ";
    getline(cin, studentID);
    
    studentID = toUpperCase(studentID);
    
    bool found = false;
    for (auto& student : students) {
        if (toUpperCase(student.studentID) == studentID) {
            found = true;
            int editChoice;

            do {
                cout << "\nWhich record would you like to edit?\n";
                cout << "1. Year Level\n";
                cout << "2. Department\n";
                cout << "3. Program\n";
                cout << "4. Last Name\n";
                cout << "5. First Name\n";
                cout << "6. Middle Initial\n";
                cout << "7. Contact Number\n";
                cout << "8. Sex\n";
                cout << "9. Finish Editing\n";
                cout << "Enter your choice: ";
                cin >> editChoice;
                cin.ignore(); // Clear the newline character from the buffer

                switch (editChoice) {
                    case 1:
                        getInput("Enter New Year Level (1-4): ", student.yearLevel, isValidYearLevel);
                        break;
                    case 2:
                        getInput("Enter New Department: ", student.department);
                        while (student.department.empty()) {
                            cout << "Error: Department cannot be empty. Please enter again: ";
                            getInput("", student.department);
                        }
                        break;
                    case 3:
                        getInput("Enter New Program: ", student.program);
                        while (student.program.empty()) {
                            cout << "Error: Program cannot be empty. Please enter again: ";
                            getInput("", student.program);
                        }
                        break;
                    case 4:
                        getInput("Enter New Last Name: ", student.lastName);
                        while (student.lastName.empty()) {
                            cout << "Error: Last Name cannot be empty. Please enter again: ";
                            getInput("", student.lastName);
                        }
                        break;
                    case 5:
                        getInput("Enter New First Name: ", student.firstName);
                        while (student.firstName.empty()) {
                            cout << "Error: First Name cannot be empty. Please enter again: ";
                            getInput("", student.firstName);
                        }
                        break;
                    case 6:
                        getInput("Enter New Middle Initial: ", student.middleInitial);
                        while (student.middleInitial.empty()) {
                            cout << "Error: Middle Initial cannot be empty. Please enter again: ";
                            getInput("", student.middleInitial);
                        }
                        break;
                    case 7:
                        getInput("Enter New Contact Number: ", student.contactNo, isValidContactNo);
                        while (isDuplicateContactNo(student.contactNo)) {
                            cout << "Error: Contact Number already exists. Please enter a unique Contact Number: ";
                            getInput("", student.contactNo, isValidContactNo);
                        }
                        break;
                    case 8:
                        getInput("Enter New Sex (M/F): ", student.sex, isValidSex);
                        break;
                    case 9:
                        cout << "\nFinishing editing.\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                }

            } while (editChoice != 9);

            cout << "\nStudent record updated successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "\nStudent record not found.\n";
    }
}

void deleteRecord() {
    string studentID;
    cout << "\n= = = Delete Student Record = = =\n";
    cout << "Enter Student ID to delete: ";
    getline(cin, studentID);
    
    studentID = toUpperCase(studentID);

    auto it = remove_if(students.begin(), students.end(),
        [&studentID](const Student& student) {
            return toUpperCase(student.studentID) == studentID;
        });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "\nStudent record deleted successfully!\n";
    } else {
        cout << "\nStudent record not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n= = = Student Information System = = =\n";
        cout << "1. Add Student Record\n";
        cout << "2. View Student Records\n";
        cout << "3. Update Student Record\n";
        cout << "4. Delete Student Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                insertRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                cout << "\nExiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
