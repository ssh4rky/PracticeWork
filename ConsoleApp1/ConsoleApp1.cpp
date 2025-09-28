#include <iostream>
#include <string>

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
	bool visa;
	string visatype;
public:
	ForeignPassport(bool visa, const string& visatype,
		const string& nationality = "Uzbek")
		: Passport(), visa(visa), visatype(visatype) {
		this->nationality = nationality;
	}

	bool CheckInfo() {
		return visa;
	}

	void PrintInfo() override {
		Passport::PrintInfo();
		cout << "Visa: " << (visa ? "Yes" : "No") << endl;
		if (visa)
			cout << "Visa type: " << visatype << endl;
	}

	void GetForeignerInfo() {
		if (!CheckInfo()) {
			cout << "The foreigner is illegal" << endl;
		}
		else {
			cout << "The foreigner is legal with visa type: " << visatype << endl;
		}
	}
};

int main()
{
	Passport passport1;
	passport1.PrintInfo();

	cout << endl;

	ForeignPassport passport2(true, "Business");
	passport2.PrintInfo();
}

