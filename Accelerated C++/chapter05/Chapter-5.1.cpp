#include<iomanip>
#include<istream>
#include<iostream>
#include<ios>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::sort;
using std::setprecision;
using std::streamsize;
using std::domain_error;
using std::istream;

struct Student_info
{
	string name;
	double midterm, final;
	vector<double> homework;
}; // not the semicolon here. It's required.

   // compute the median of a vector<double>
   // note that calling this function copies the entire argument vector

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

//compute a student's overall grade from midterm and final exam grades
// and vector of homework grades
// this function does not copy its argument, because median does so for us

double grade(double midterm, double final, double homework) {
	return 0.2*midterm + 0.4*final + 0.4*homework;
}

// compute a studnet's overall grade from midterm and final exam grades and homework
double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("Student has done no homework.");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

bool compare(const Student_info&x, const Student_info& y) {
	return x.name < y.name;
}

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		vector<Student_info> pass, fail;
		if (fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);
		students = pass;
		return fail;
	}
}

vector<Student_info> extract_fails1(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	//invariant: elements [0,i) of students represent passing grades
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
		{
			++i;
		}
	}
	return fail;
}

//VERSION 3: interators but no indexing; still potentially slow
vector<Student_info> extract_fails3(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	return fail;
}

//VERSION 4: use list instead of vector
list<Student_info> extract_fails(list<Student_info> & students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}



// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
	// we must fill in this part
	if (in) {
		//get ride of previous contents, ready for next student's homework record
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		//clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}


istream& read(istream& is, Student_info& s) {
	//read adn store the student's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework); // read and store the student's homework
	return is;
}

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	//read and store all the records, and find the length of the longest name
	while (read(cin, record)) {
		maxlen = std::max(maxlen, record.name.size());
		//maxlen gets the maximum length of the record.

		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		// write the name, padded on the right to maxlen+1 characters
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}
