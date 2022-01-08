#include"Bakery.h"
class Person
{
private:

	int ID;
	string name;
	string type;
	string mail;

public:

	int get_ID() { return ID; }
	void set_ID(int id) { ID = id; }

	string get_name() { return name; }
	void set_name(string nume) { name = nume; }

	string get_mail() { return mail; }
	void set_mail(string m) { mail = m; }

	void set_type(string t) { type = t; }
	string get_type() { return type; }


	Person(){}

	Person(int id, string n, string t, string m):ID{id}, name{n}, type{t}, mail{m}{}

	Person(string prp) {

		string v[4];

		int poz = prp.find(',');
		int i = -1;

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[3] = prp;

		ID = stoi(v[0]);
		name = v[1];
		type = v[2];
		mail = v[3];

	}

	Person(const Person& p):ID{ p.ID }, name{ p.name }, type{ p.type }, mail{ p.mail }{}


	virtual string describe() {

		string text = "";

		text += "\nID : " + to_string(ID);
		text += "\nName : " + name;
		text += "\nType : " + type;
		text += "\nMail : " + mail;
		text += "\n";

		return text;
	}

	virtual string describe_to_file() {

		string text = "";

		text += to_string(ID) + "," + name + "," + type + "," + mail;

		return text;
	}



};

