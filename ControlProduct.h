#include"ControlPerson.h"

class ControlProduct
{
private:
	list<Product*>products;


public:

	void add_product(Product* p) { products.push_back(p); }

	void load() {

		ifstream f("products.txt");

		while (!f.eof()) {

			string line;


			getline(f, line);

			if (line != " ") {

				if (line.find("PC") != string::npos) {

					add_product(new PC(line));
				}
				else if (line.find("Car") != string::npos) {

					add_product(new Car(line));
				}
				else if (line.find("Bakery") != string::npos) {

					add_product(new Bakery(line));
				}
				else { add_product(new Product(line)); }

			}

		}
	}

	void save_to_file() {

		ofstream g("products.txt");

		list<Product*>::iterator last = products.end();
		last--;

		list<Product*>::iterator itr;
		for (itr = products.begin(); itr != products.end(); ++itr) {

			if (itr != last) { g << (*itr)->describe_to_file() << "\n"; }
			else { g << (*itr)->describe_to_file(); }
		}

		g.close();
	}

	ControlProduct() { load(); }

	void traverse() {

		list<Product*>::iterator itr;
		for (itr = products.begin(); itr != products.end(); ++itr) {

			cout << (*itr)->describe();
			cout << endl;
		}
	}

	int poz_product(int id) {

		int poz = -1;
		list<Product*>::iterator itr;
		for (itr = products.begin(); itr != products.end(); ++itr) {

			poz++;
			if ((*itr)->get_ID() == id) { return poz; }
		}
	}

	list<Product*>::iterator poz_itr_product(int poz) {

		int p = -1;
		list<Product*>::iterator itr;
		for (itr = products.begin(); itr != products.end(); ++itr) {

			p++;
			if (p == poz) { return itr; }
		}
	}

	void erase_product(int id) {

		int poz = poz_product(id);
		list<Product*>::iterator itr = poz_itr_product(poz);
		products.erase(itr);
	}

	void modify_product(int id, string nm, double pr, double w, string descript) {

		Product* p = GetProductbyID(id);
		p->set_name(nm);
		p->set_price(pr);
		p->set_weight(w);
		p->set_description(descript);
	}

	void modify_car(int id, string nm, double pr, double w, string descript, string mod, int y, string col) {

		Product* p = GetProductbyID(id);
		Car* c = dynamic_cast<Car*>(p);

		c->set_name(nm);
		c->set_price(pr);
		c->set_weight(w);
		c->set_description(descript);
		c->set_model(mod);
		c->set_year(y);
		c->set_color(col);
	}

	void modify_pc(int id, string nm, double pr, double w, string descript, string process, string platf, int mem) {

		Product* p = GetProductbyID(id);
		PC* pc = dynamic_cast<PC*>(p);

		pc->set_name(nm);
		pc->set_price(pr);
		pc->set_weight(w);
		pc->set_description(descript);
		pc->set_processor(process);
		pc->set_platform(platf);
		pc->set_price(pr);
	}

	void modify_bakery(int id, string nm, double pr, double w, string descript) {

		Product* p = GetProductbyID(id);
		Bakery* b = dynamic_cast<Bakery*>(p);

		b->set_name(nm);
		b->set_price(pr);
		b->set_weight(w);
		b->set_description(descript);
	}

	int GetIDbyName(string n) {

		list<Product*>::iterator itr;
		for (itr = products.begin(); itr != products.end(); ++itr) {

			if ((*itr)->get_name() == n) { return (*itr)->get_ID(); }
		}

		return -1;
	}

	Product* GetProductbyID(int id) {

		list<Product*>::iterator itr;
		for (itr = products.begin(); itr != products.end(); ++itr) {

			if ((*itr)->get_ID() == id) { return *itr; }
		}
	}

	void CountCarBakeryPCs() {

		int cars, bakerys, pcs;
		cars = bakerys = pcs = 0;

		list<Product*>::iterator itr;
		for (itr = products.begin(); itr != products.end(); ++itr) {

			if ((*itr)->get_type() == "Car") { cars++; }

			if ((*itr)->get_type() == "Bakery") { bakerys++; }

			if ((*itr)->get_type() == "PC") { pcs++; }
		}

		cout << "\nNumarul de masini din lista este de : " << cars;
		cout << "\nNumarul de panificatii din lista este de : " << bakerys;
		cout << "\nNumarul de PC-uri din lista este de : " << pcs;

	}
};

