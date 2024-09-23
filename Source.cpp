#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct STUDENT_DATA
{
	string fname;
	string lname;
	string email;
};

int main() {

#ifdef PRE_RELEASE
	cout << "Running pre-release version\n";
	ifstream fin("StudentData_Emails.txt");
#else
	cout << "Running standard version\n";
	ifstream fin("StudentData.txt");
#endif

	vector<STUDENT_DATA> students;

	if (fin.is_open()) {
		cout << "Operation successfully performed\n";
		string line;

		while (getline(fin, line)) { // Read each line
			stringstream ss(line);
			STUDENT_DATA student;

			getline(ss, student.fname, ','); // Get first name
			getline(ss, student.lname, ','); // Get last name

#ifdef PRE_RELEASE
			getline(ss, student.email); // Get email if in pre-release mode
#endif

			students.push_back(student); // Add to vector
		}

		fin.close();

		for (const auto& student : students) {
			cout << "First Name: " << student.fname
				<< ", Last Name: " << student.lname;
#ifdef PRE_RELEASE
			cout << ", Email: " << student.email;
#endif
			cout << endl;
		}
	}
	else {
		cout << "Error opening file";
	}

	return 0;
}