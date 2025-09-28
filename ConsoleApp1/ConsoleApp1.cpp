#include <iostream>
#include <string>
#include <vector>

using namespace std;

//1

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

//3
class Square {
protected:
	int size;

public:
	Square(int s) : size(s) {}

	void drawSquare() const {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << "#";
			}
			cout << endl;
		}
	}

	int getSize() const { return size; }
};

class Circle : public Square {
private:
	int r;

public:
	Circle(int s, int radius) : Square(s), r(radius) {}

	void drawCircleInSquare() const {
		int center = size / 2;
		for (int y = 0; y < size; y++) {
			for (int x = 0; x < size; x++) {
				if (y == 0 || y == size - 1 || x == 0 || x == size - 1) {
					cout << "#";
				}
				else {
					int dx = x - center;
					int dy = y - center;
					double dist = sqrt(dx * dx + dy * dy);

					if (dist >= r - 0.5 && dist <= r + 0.5) {
						cout << "$";
					}
					else {
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}
};


int main()
{
	Passport passport1;
	passport1.PrintInfo();

	cout << endl;

	ForeignPassport passport2;
	passport2.PrintForeignInfo();

	Circle c(50, 20);
	c.drawCircleInSquare();
}

