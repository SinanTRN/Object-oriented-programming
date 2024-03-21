
#include <iostream>
using namespace std;
class Person
{
	string personName;
public:
	Person(string name) { personName = name; }
	string getName()const { return personName; }

	virtual string getMilliyet() { return " "; }
	virtual void Merhaba( Person& oth) {
		cout << personName << " Say Hi! " << oth.personName << endl;
	}
};

class AlmanPerson:public Person
{
public:
	AlmanPerson(string name) :Person(name) {};
	string getMilliyet() { return "Alman "; }
	void Merhaba( Person& oth)  {
		if (this->getMilliyet() == oth.getMilliyet()) {
			cout << this->getName() << " Say Hallo! " << oth.getName() << endl;
		}
		else 		cout << this->getName() << " Say Hi! " << oth.getName() << endl;

	}
};
class TurkPerson :public Person
{
public:
	TurkPerson(string name) :Person(name) {};
	string getMilliyet() { return "Turk"; }
	void Merhaba(Person& oth) {
		if (this->getMilliyet() == oth.getMilliyet()) {
			cout << this->getName() << " Say Merhaba! " << oth.getName() << endl;
		}
		else 		cout << this->getName() << " Say Hi! " << oth.getName() << endl;
		
	}
};


