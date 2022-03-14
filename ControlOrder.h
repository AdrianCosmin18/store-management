#include"Order.h"

class ControlOrder
{
private:
	list<Order*>orders;

public:

	void add_order(Order* o) { orders.push_back(o); }

	void load() {

		ifstream f("orders.txt");
		string line;

		while (!f.eof()) {

			getline(f, line);
			if (line == "") { break; }

			orders.push_back(new Order(line));
		}
	}

	void save_to_file() {

		ofstream g("orders.txt");

		list<Order*>::iterator last = orders.end();
		last--;

		list<Order*>::iterator itr;
		for (itr = orders.begin(); itr != orders.end(); ++itr) {

			if (itr != last) { g << (*itr)->describe_to_file() << "\n"; }
			else { g << (*itr)->describe_to_file(); }
		}

		g.close();
	}

	ControlOrder() { load(); }

	void traverse() {

		list <Order*>::iterator itr;
		for (itr = orders.begin(); itr != orders.end(); ++itr) {

			cout << (*itr)->describe();
			cout << endl;
		}
	}

	void tr() {cout << (*orders.begin())->describe(); }



	int poz_order(int id) {

		int poz = -1;
		list<Order*>::iterator itr;
		for (itr = orders.begin(); itr != orders.end(); ++itr) {

			poz++;
			if ((*itr)->get_ID() == id) { return poz; }
		}
	}

	list<Order*>::iterator poz_itr_order(int poz) {

		int p = -1;
		list<Order*>::iterator itr;
		for (itr = orders.begin(); itr != orders.end(); ++itr) {

			p++;
			if (p == poz) { return itr; }
		}
	}

	void erase_order(int id) {

		int poz = poz_order(id);
		list<Order*>::iterator itr = poz_itr_order(poz);
		orders.erase(itr);
	}

	void modify_order(int id, double price) {

		Order* o = GetOrderbyID(id);
		o->set_price(price);
	}

	Order* GetOrderbyID(int id) {

		list<Order*>::iterator itr;
		for (itr = orders.begin(); itr != orders.end(); ++itr) {

			if ((*itr)->get_ID() == id) { return *itr; }
		}
	}

	int GetLastOrderID() {

		if (orders.begin() != orders.end()) {
			list <Order*>::iterator itr = orders.end();
			itr--;
			return (*itr)->get_ID();

		}
		else { return 0; }

	}

	int NextAvailableID() {

		list <Order*>::iterator itr;
		if (orders.size() != 0) {

			return GetLastOrderID() + 1;
		}
		else {
			return 1;
		}
	}
};

