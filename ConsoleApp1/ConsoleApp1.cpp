#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
	int day;
	int month;
	int year;

	friend ostream& operator<<(ostream& os, const Date& d) {
		os << d.day << "." << d.month << "." << d.year;
		return os;
	}
};

struct Record {
	string firstpart;
	string secondpart;

	friend ostream& operator<<(ostream& os, const Record& r) {
		os << r.firstpart << "-" << r.secondpart;
		return os;
	}
};

class Passport {
protected:
	string name;
	string surname;
	string patronymic;
	string nationality;

	char sex;
	Date birthdate;
	Date duedate;
	Record record;
	string idnumber;

public:
	Passport()
		: name("Mariana"), surname("Tkachenko"),
		patronymic("Ivanivna"), nationality("Ukrainian"),
		sex('W'),
		birthdate{ 24, 8, 1991 }, duedate{ 13, 12, 2025 },
		record{ "19910824", "00026" }, idnumber("000000000") {
	}

	virtual void PrintInfo() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Patronymic: " << patronymic << endl;
		cout << "Nationality: " << nationality << endl;

		cout << "Sex: " << sex << endl;
		cout << "Birth Date: " << birthdate << endl;
		cout << "Due Date: " << duedate << endl;
		cout << "Record: " << record << endl;
		cout << "Document number: " << idnumber << endl;
	}
};

class ForeignPassport : public Passport {
private:
	vector<vector<string>> visaCountries;
	vector<string> visaTypes;

public:
	ForeignPassport() : Passport() {
		visaCountries.push_back({ "USA", "Canada" });
		visaTypes.push_back("Business");

		visaCountries.push_back({ "Singapore", "France" });
		visaTypes.push_back("Common");
	}

	void AddVisa(const vector<string>& countries, const string& type) {
		visaCountries.push_back(countries);
		visaTypes.push_back(type);
	}

	void ClearVisas() {

	}

	void PrintVisas() const {
		cout << "Visas:\n";
		for (size_t i = 0; i < visaCountries.size(); ++i) {
			cout << visaTypes[i] << ": ";
			for (const auto& c : visaCountries[i]) {
				cout << c << " ";
			}
			cout << endl;
		}
	}

	void PrintForeignInfo() {
		PrintInfo();
		PrintVisas();
	}
};

int main()
{
	Passport passport1;
	passport1.PrintInfo();

	cout << endl;

	ForeignPassport passport2;
	passport2.PrintForeignInfo();
}

