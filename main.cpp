//Alexander Ray
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// Find and return file
void loadDataStructure(vector<string>& courses, const string& fileName) {
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        string course;
        while (getline(inputFile, course)) {
            courses.push_back(course);
        }
        inputFile.close();
        cout << "Loading data...\n";
    } else {
        cout << "File not found. Please re-enter.\n";
    }
}

// Print course list
void printCourseList(const vector<string>& courses) {
    vector<string> sortedCourses = courses;
    sort(sortedCourses.begin(), sortedCourses.end());

    cout << "Displaying alphanumeric Course List:\n";
    for (const string& course : sortedCourses) {
        cout << course << endl;
    }
}

// Print course information
void printCourseInfo(const vector<string>& courses, const string& courseCode) {
    cout << "Printing course Information " << courseCode << ":\n";
    auto it = find_if(courses.begin(), courses.end(),
                      [courseCode](const string& course) {
                          return course.find(courseCode) != string::npos;
                      });

    if (it != courses.end()) {
        cout << *it << endl;
    } else {
        cout << "No course returned, please make sure your input matches list options.\n";
    }
}

int main() {
    cout << "Course Planner.\n";

    vector<string> courses;

    string fileName;
    cout << "Enter the file name containing course data: ";
    getline(cin, fileName);
//Create menu
    while (true) {
        int choice;
        cout<< "\n******************************";
        cout << "\nOptions:\n";
        cout << "1. Load Data Structure\n";
        cout << "2. Print Course List\n";
        cout << "3. Print Course Information\n";
        cout << "4. Exit program\n";
        cout << "Enter number to select option (must load data structure before other options become available): ";
        cin >> choice;
        cin.ignore();
//Create menu outputs
        switch (choice) {
            case 1:
                loadDataStructure(courses, fileName);
                break;
            case 2:
                printCourseList(courses);
                break;
            case 3:
            {
                string courseCode;
                cout << "\nEnter corresponding course code: ";
                cin >> courseCode;
                transform(courseCode.begin(), courseCode.end(), courseCode.begin(), ::toupper);
                printCourseInfo(courses, courseCode);
            }
                break;
            case 4:
                cout << "Goodbye.\n";
                return 0;
            default:
                cout << "\nOption not fond, please ensure your input is correct.\n";
        }
    }

    return 0;
}