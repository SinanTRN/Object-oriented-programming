#include "Person.h"

int main()
{
	Person *p1 = new AlmanPerson("max");
	Person *p2 = new TurkPerson("Sinan");
	Person *p4 = new TurkPerson("Ahmet");
	Person *p3 = new Person("suzy");

	p1->Merhaba(*p2);
	p4->Merhaba(*p2);

	p3->Merhaba(*p4);

}
