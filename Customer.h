#include"Person.h"

class Customer:public Person
{
private:
	
	string password;
	string billing_address;
	string shipping_address;
	string phone;

public:

	
	string get_password() { return password; }
	string get_billing_address() { return billing_address; }
	string get_shipping_address() { return shipping_address; }
	string get_phone() { return phone; }

	void set_password(string pass) { password = pass; }
	void set_billing_address(string bill) { billing_address = bill; }
	void set_shipping_address(string ship) { shipping_address = ship; }
	void set_phone(string ph) { phone = ph; }


	Customer(int id, string nm, string typ, string m, string pass, string bill, string shipp, string phn):Person(id, nm, "Customer", m), password{pass}, billing_address{bill}, phone{phn}{}

	Customer(string prp) {

		string v[8];

		int poz = prp.find(',');
		int i = -1;

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[7] = prp;

		set_ID(stoi(v[0]));
		set_name(v[1]);
		set_type("Customer");
		set_mail(v[3]);
		password = v[4];
		billing_address = v[5];
		shipping_address = v[6];
		phone = v[7];

	}

	string describe() override{

		string text = "";

		text += "\nID : " + to_string(get_ID());
		text += "\nName : " + get_name();
		text += "\nType : " + get_type();
		text += "\nMail : " + get_mail();
		text += "\nPassword : " + password;
		text += "\nBilling address : " + billing_address;
		text += "\nShipping address : " + shipping_address;
		text += "\nPhone Number : " + phone;
		text += "\n";

		return text;
	}

	string describe_to_file() override {

		string text = to_string(get_ID()) + "," + get_name() + "," + get_type() + "," + get_mail() + "," + password + "," + billing_address + "," + shipping_address + "," + phone;
		return text;
	}

};

