#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
	string fname;
	string lname;
};

int main() {
	ifstream fin("StudentData.txt");
	vector<STUDENT_DATA> students;
	string fname, lname;

	if (fin.is_open()) {
		cout << "Operation successfully performed\n";

		while (getline(fin, fname, ',') && getline(fin, lname)) { // Directly split the line
			students.push_back({ fname, lname }); // Add to vector in one step
		}

		fin.close();

		/*for (const auto& student : students) {
			cout << "First Name: " << student.fname << ", Last Name: " << student.lname << endl;
		}*/
	}
	else {
		cout << "Error opening file";
	}

	return 0;
}