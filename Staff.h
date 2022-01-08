#include"Customer.h"

class Staff:public Person
{
private:

	string department;
	int salary;
	string phone;

public:

	string get_department() { return department; }
	int get_salary() { return salary; }
	string get_phone() { return phone; }

	void set_department(string dep) { department = dep; }
	void set_salary(int sal) { salary = sal; }
	void set_phone(string ph) { phone = ph; }


	Staff(int id, string nm, string typ, string m, string dep, int sal, string phn) : Person(id, nm, "Staff member", m), department{dep}, salary{sal}, phone{phn}{}

	Staff(string prp){

		string v[7];

		int poz = prp.find(',');
		int i = -1;

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[6] = prp;

		set_ID(stoi(v[0]));
		set_name(v[1]);
		set_type("Staff member");
		set_mail(v[3]);
		department = v[4];
		salary = stoi(v[5]);
		phone = v[6];
	}

	string describe() override {

		string text = "";

		text += "\nID : " + to_string(get_ID());
		text += "\nName : " + get_name();
		text += "\nType : " + get_type();
		text += "\nMail : " + get_mail();
		text += "\nDepartment : " + department;
		text += "\nSalary : " + to_string(salary) + " euro";
		text += "\nPhone Number : " + phone;
		text += "\n";

		return text;
	}

	string describe_to_file() override {

		string text = to_string(get_ID()) + "," + get_name() + "," + get_type() + "," + get_mail() + "," + department + "," + to_string(salary) + "," + phone;
		return text;
	}
};

