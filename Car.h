#include"Product.h"

class Car: public Product
{
private:
	string model;
	int year;
	string color;

public:

	string get_model() { return model; }
	int get_year() { return year; }
	string get_color() { return color; }

	void set_model(string m) { model = m; }
	void set_year(int y) { year = y; }
	void set_color(string col) { color = col; }

	Car(int ID, string name, double price, double weight, string descript, string ty, string mod, int y, string col): Product(ID, name, price, weight, descript, "Car"), model{mod}, year{y}, color{col}{}

	Car(string prp) {

		string v[9];
		int i = -1;
		int poz = prp.find(',');

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}

		v[8] = prp;

		set_ID(stoi(v[0]));
		set_name(v[1]);
		set_price(stod(v[2]));
		set_weight(stod(v[3]));
		set_description(v[4]);
		set_type("Car");
		model = v[6];
		year = stoi(v[7]);
		color = v[8];
	}

	string describe() override{

		string text = "";

		text += "\nID : " + to_string(get_ID());
		text += "\nName : " + get_name();
		text += "\nPrice : " + to_string(get_price()) + "euro";
		text += "\nWeight : " + to_string(get_weight()) + " kg";
		text += "\nDescription : " + get_description();
		text += "\nType : " + get_type();
		text += "\nModel : " + model;
		text += "\nYear : " + to_string(year);
		text += "\nColor : " + color;
		text += "\n";

		return text;
	}

	string describe_to_file() {

		string text = to_string(get_ID()) + "," + get_name() + "," + to_string(get_price()) + "," + to_string(get_weight()) + "," + get_description() + "," + get_type() + "," + model + "," + to_string(year) +"," + color;
		return text;
	}

};

