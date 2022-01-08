#include"Order_Details.h"

class ControlOrder_Details
{
private:
	list<Order_Details*>details;

public:

	void add_detail(Order_Details* od) { details.push_back(od); } 

	void traverse() {

		list<Order_Details*>::iterator itr;

		for (itr = details.begin(); itr != details.end(); ++itr) {

			cout << (*itr)->describe() << endl;

		}
	}

	void load() {

		ifstream f("order_details.txt");

		string line;

		while(!f.eof()){
		
			getline(f, line);
			if (line == "") { break; }

			details.push_back(new Order_Details(line));
		}
	}

	void save_to_file() {

		ofstream g("order_details.txt");

		list<Order_Details*>::iterator last = details.end();
		last--;

		list<Order_Details*>::iterator itr;
		for (itr = details.begin(); itr != details.end(); ++itr) {

			if (itr != last) { g << (*itr)->describe_to_file() << "\n"; }
			else { g << (*itr)->describe_to_file(); }
		}

		g.close();
	}

	int poz(int id) {

		list<Order_Details*> ::iterator itr;
		int p = -1;
		for (itr = details.begin(); itr != details.end(); ++itr) {

			p++;
			if ((*itr)->get_ID() == id) { return p; }
			
		}

		return -1;
	}

	list<Order_Details*>::iterator poz_itr(int poz) {

		list<Order_Details*> ::iterator itr;
		int p = -1;
		for (itr = details.begin(); itr != details.end(); ++itr) {
			p++;
			if (p == poz) { return itr; }
		}
	}

	void erase(int id) {

		int p = poz(id);
		list<Order_Details*> ::iterator itr = poz_itr(p);
		details.erase(itr);
	}

	ControlOrder_Details() { load(); }


	int GetLastOrderID() {

		if (details.begin() == details.end()) {
			list<Order_Details*>::iterator itr = details.end();
			itr--;
			return (*itr)->get_ID();
		}
		else { return 0; }
	}

	int NextAvailableID() {

		list<Order_Details*>::iterator itr;
		if (details.size() != 0) { return GetLastOrderID() + 1; }
		else { return 1; }
	}

	list<Order_Details*> GetListByOrderID(int id) {

		list<Order_Details*> ::iterator itr;
		list<Order_Details*> lista;

		for (itr = details.begin(); itr != details.end(); ++itr) {

			if ((*itr)->get_order_ID() == id) { lista.push_back(*itr); }
		}

		return lista;
	}

	int GetPozByOrderID(int ID) {

		list<Order_Details*> ::iterator itr;

		int p = -1;
		for (itr = details.begin(); itr != details.end(); ++itr) {

			p++;
			if ((*itr)->get_order_ID() == ID) { return p; }

		}

		return -1;
	}

	list<Order_Details*>::iterator GetPozItrByPozOrder(int poz) {

		list<Order_Details*> ::iterator itr;
		int p = -1;
		for (itr = details.begin(); itr != details.end(); ++itr) {			
			p++;
			if (p == poz) { return itr; }
		}
	}

	void eraseByOrderID(int id) {

		int p = GetPozByOrderID(id);
		list<Order_Details*> ::iterator itr = GetPozItrByPozOrder(p);
		details.erase(itr);
	}

	Order_Details* GetOrderDetailsByProductIDAndOrderID(int order_id, int product_id) {

		for (auto itr : details) {

			if (itr->get_order_ID() == order_id && itr->get_product_ID() == product_id) {
				return itr;
			}
		}
		return NULL;
	}

	//order Id =>pret total

	double GetTotalPriceByOrderID(int order_id) {

		int sum = 0;

		for (auto itr : details) {

			if (itr->get_order_ID() == order_id) { sum += itr->get_price(); }
		}

		return sum;
	}



};

