#include"ControlProduct.h"

class Order
{
private:
	int ID;
	double price;
	int customer_ID;
	string shipping_address;

public:

	int get_ID() { return ID; }
	double get_price() { return price; }
	int get_customer_ID() { return customer_ID; }
	string get_shipping_address() { return shipping_address; }

	void set_ID(int id) { ID = id; }
	void set_price(double prc) { price = prc; }
	void set_customer_id(int c_id) { customer_ID = c_id; }
	void set_shipping_address(string add) { shipping_address = add; }

	Order(){}

	Order(int id, double prc, int c_id, string address):ID{id}, price{prc}, customer_ID{c_id},shipping_address{address}{}

	Order(string prp) {

		if(prp != ""){
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
			price = stod(v[1]);
			customer_ID = stoi(v[2]);
			shipping_address = v[3];
		}
	}


	string describe_to_file() {

		string text = to_string(ID) + "," + to_string(ID) + "," + to_string(price) + "," + to_string(customer_ID) + "," + shipping_address;
		return text;
	}


	string describe() {

		string text = "";

		text += "\nOrder ID : " + to_string(ID);
		text += "\nPrice  : " + to_string(price);
		text += "\nCustomer ID : " + to_string(customer_ID);
		text += "\nShipping address : " + shipping_address;
		text += "\n";

		return text;
	}


};

