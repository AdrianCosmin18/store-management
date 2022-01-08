#include"ControlOrder.h"

class Order_Details
{
private:

	int ID;
	int order_ID;
	int product_ID;
	int quantity;
	double price;

public:

	int get_ID() { return ID; }
	int get_order_ID() { return order_ID; }
	int get_product_ID() { return product_ID; }
	int get_quantity() { return quantity; }
	double get_price() { return price; }

	void set_ID(int id) { ID = id; }
	void set_order_ID(int id) { order_ID = id; }
	void set_product_ID(int id) { product_ID = id; }
	void set_quantity(int nr) { quantity = nr; }
	void set_price(double pr) { price = pr; }

	Order_Details(){}

	Order_Details(int id, int order_id, int product_id, int quant, double pr) :ID{ id }, order_ID{ order_id }, product_ID{ product_id }, quantity{ quant }, price{ pr }{}

	Order_Details(string prp) {

		if (prp != "") {
			string v[5];
			int poz = prp.find(',');
			int i = -1;

			while (poz != string::npos) {

				i++;
				v[i] = prp.substr(0, poz);
				prp.erase(0, poz + 1);
				poz = prp.find(',');

			}

			v[4] = prp;

			ID = stoi(v[0]);
			order_ID = stoi(v[1]);
			product_ID = stoi(v[2]);
			quantity = stoi(v[3]);
			price = stod(v[4]);
		}
	}




	string describe_to_file() {

		string text = to_string(ID) + "," + to_string(order_ID) + "," + to_string(product_ID) + "," + to_string(quantity) + "," + to_string(price);
		return text;
	}


	string describe() {

		string text = "";

		text += "\nID : " + to_string(ID);
		text += "\nOrder ID : " + to_string(order_ID);
		text += "\nProduct ID : " + to_string(product_ID);
		text += "\nQuantity : " + to_string(quantity);
		text += "\nPrice : " + to_string(price) + " euro";
		text += "\n";

		return text;
	}

};

