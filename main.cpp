#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <fstream>
#include "grade.h"
#include "Student_info.h"

using std::list;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::fixed;
using std::left;
using std::setw;
using std::setprecision;

list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    for (auto it = students.begin(); it != students.end(); ) {
        if (fgrade(*it)) {
            fail.push_back(*it);
            it = students.erase(it);
        } else {
            ++it;
        }
    }
    return fail;
}

int main() 
{
    list<Student_info> students;
    Student_info record;
    ifstream inFile("hw2_input.txt");
    while (read(inFile, record)) {
        students.push_back(record);
    }
    inFile.close();
    list<Student_info> fails = extract_fails(students);
    fails.sort();
    ofstream outFile("hw2_output.txt");
    for (auto it:fails) {
        outFile << left << setw(10) << it.name 
                << "Your final grade is " 
                << fixed << setprecision(1) << grade(it) << endl;
    }
    outFile.close();

    return 0;
}
