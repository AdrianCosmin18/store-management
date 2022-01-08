#include<iostream>
#include<string>
using namespace std;

class Product
{
private:
	int ID;
	string name;
	double price;
	double weight;
	string description;
	string type;

public:

	Product(){}

	Product(int id, string nm, double p, double wght, string descript, string ty): ID{id}, name{nm}, price{p}, weight{wght}, description{descript}, type{ty}{}

	Product(const Product& p): ID{ p.ID }, name{ p.name }, price{ p.price }, weight{ p.weight }, description{ p.description }, type{p.type}{}

	Product(string prp) {

		string v[6];
		int i = -1;
		int poz = prp.find(',');

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}

		v[5] = prp;

		ID = stoi(v[0]);
		name = v[1];
		price = stod(v[2]);
		weight = stod(v[3]);
		description = v[4];
		type = v[5];

	}

	virtual string describe() {

		string text = "";

		text += "\nID : " + to_string(ID);
		text += "\nName : " + name;
		text += "\nPrice : " + to_string(price) + " euro";
		text += "\nWeight : " + to_string(weight) + " kg";
		text += "\nDescription : " + description;
		text += "\nType : " + type;
		text += "\n";

		return text;
	}

	virtual string describe_to_file() {

		string text = to_string(ID) + "," + name + "," + to_string(price) + "," + to_string(weight) + "," + description + "," + type;
		return text;
	}

	int get_ID() { return ID; }
	string get_name() { return name; }
	double get_price() { return price; }
	double get_weight() { return weight; }
	string get_description() { return description; }
	string get_type() { return type; }

	void set_ID(int id) { ID = id; }
	void set_name(string nume) { name = nume; }
	void set_price(double p) { price = p;}
	void set_weight(double w) { weight = w; }
	void set_description(string d) { description = d; }
	void set_type(string ty) { type = ty; }


	bool operator==(const Product& p) {

		cout << "\nEqual by price";
		return this->price == p.price;
	}






};

