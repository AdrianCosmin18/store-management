#include"Staff.h"
#include<list>
#include<fstream>

class ControlPerson
{
private:

	list<Person*>persons;

public:

	void load() {

		ifstream f("persons.txt");

		while (!f.eof()) {

			string line;

			getline(f, line);

			if (line.find("Customer") != string::npos) {

				persons.push_back(new Customer(line));
			}
			else if (line.find("Staff") != string::npos) {

				persons.push_back(new Staff(line));
			}
		}
	}

	void save() {

		ofstream g("persons.txt");

		list<Person*>::iterator last = persons.end();
		last--;

		list<Person*>::iterator itr;
		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			if (itr != last) { g << (*itr)->describe_to_file() << "\n"; }
			else { g << (*itr)->describe_to_file(); }
		}

		g.close();
	}


	ControlPerson() { load(); }

	//CRUDE

	void traverse() {

		list<Person*>::iterator itr;
		for (itr = persons.begin(); itr != persons.end(); ++itr) {
			cout << (*itr)->describe() << endl;
			cout << endl;
		}
	}

	void add_person(Person* p) { persons.push_back(p); }

	int poz_person(int id) {

		int i = -1;
		list<Person*>::iterator itr;

		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			i++;
			if ((*itr)->get_ID() == id) { return i; }

		}
		return -1;
	}

	list<Person*>::iterator poz_itr_person(int poz) {

		list<Person*>::iterator itr;
		int p = -1;

		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			p++;
			if (p == poz) { return itr; }
		}
	}

	void erase(int id) {

		int poz = poz_person(id);
		list<Person*>::iterator itr = poz_itr_person(poz);
		persons.erase(itr);
	}

	void modify_person(int id, string nm, string m) {

		int poz = poz_person(id);
		list<Person*>::iterator itr = poz_itr_person(poz);

		(*itr)->set_name(nm);
		(*itr)->set_mail(m);

		cout << "Modificare de persoana reusita \n\n";
	}

	void modify_staff(int id, string nm, string m, string depart, int sal, string ph) {


		int poz = poz_person(id);
		list<Person*>::iterator itr = poz_itr_person(poz);


		Person* p = *itr;
		Staff* s = dynamic_cast<Staff*>(p);

		if (s->get_type() == "Staff member") {

			s->set_name(nm);
			s->set_mail(m);
			s->set_department(depart);
			s->set_salary(sal);
			s->set_phone(ph);

			cout << "Modificare de staff reusita \n\n";
		}

		else
			cout << "\nNu exista aceasta persoana in staff\n";
	}

	void modify_customer(int id, string nm, string m, string pass, string bill, string shipp, string ph) {

		Person* p = GetPersonByID(id);
		Customer* c = dynamic_cast<Customer*>(p);

		if (c->get_type() == "Customer") {

			c->set_name(nm);
			c->set_mail(m);
			c->set_password(pass);
			c->set_billing_address(bill);
			c->set_shipping_address(shipp);
			c->set_phone(ph);

			cout << "\nModificare de customer reusita\n\n";
		}
		else
			cout << "\nNu exista aceasta persoana in customer";
	}



	Person* GetPersonByID(int id) {

		int poz = poz_person(id);
		list<Person*>::iterator itr = poz_itr_person(poz);
		return *itr;
	}


	Person* GetPersonByName(string name) {

		list<Person*>::iterator itr;
		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			if ((*itr)->get_name() == name) { return *itr; }
		}
	}
	


};

