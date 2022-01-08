#include"PC.h"

class Bakery:public Product
{
private:
	list<string> vitamins;

public:

	Bakery(int id, string nm, double p, double wght, string descript) : Product(id, nm, p, wght,descript, "Bakery") {

		vitamins.push_back("A");
		vitamins.push_back("B");
		vitamins.push_back("C");
		vitamins.push_back("E");
	}


	Bakery(string prp) {
	
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

		set_ID(stoi(v[0]));
		set_name(v[1]);
		set_price(stod(v[2]));
		set_weight(stod(v[3]));
		set_description(v[4]);
		set_type("Bakery");
	
	
	}


	void traverse_vitamins() {

		list<string>::iterator itr;
		string text = "";
		for (itr = vitamins.begin(); itr != vitamins.end(); ++itr) {

			text += *itr + ", ";
		}
	
		cout << text.substr(0, text.size() - 2);
	}

	void add_vitamin(string v) { vitamins.push_back(v); }

	int get_poz_vit(string v) {

		int poz = -1;
		list<string>::iterator itr;
		for (itr = vitamins.begin(); itr != vitamins.end(); ++itr) {

			poz++;
			if (*itr == v)
				return poz;
		}

		return -1;
	}

	list<string>::iterator get_itr_vit(int poz) {

		int p = -1;

		list<string>::iterator itr;
		for (itr = vitamins.begin(); itr != vitamins.end(); ++itr) {

			p++;
			if (p == poz)return itr;
		}
	}

	void erase_vitamin(string v) {
		int poz = get_poz_vit(v);
		list<string>::iterator itr = get_itr_vit(poz);
		vitamins.erase(itr);
	}

	

};

