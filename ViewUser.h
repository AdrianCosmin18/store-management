#include"ControlOrder_Details.h"

class ViewUser
{
private:
	ControlProduct* controlproduct;
	ControlOrder* controlorder;
	ControlOrder_Details* controlorderdetails;
	Customer* customer;

	Order* order;



public:


	ViewUser(Customer* c) {


		controlproduct = new ControlProduct();
		controlorder = new ControlOrder();
		controlorderdetails = new ControlOrder_Details();
		this->customer = c;


		this->order = new Order(controlorder->NextAvailableID(),
							0,
							this->customer->get_ID(),
							"Shipping Address");
		
	}

	void meniu() {

		cout << "\n\n\nContul Meu ";
		cout << "\nNume : " << customer->get_name();
		cout << "\nEmail :" << customer->get_mail();
		cout << "\nShipping Address : " << customer->get_shipping_address();

		cout << endl;

		cout << "\nPentru a afisa lista de produse disponibile, apasati 1 ";
		cout << "\nPentru a adauga un produs in cos, apasati 2";
		cout << "\nPentru a vedea produsele din cos apasati 3";
		cout << "\nPentru a sterge un produs din cos apasati 4";
		cout << "\nPentru a golii cosul apasati 5";
		cout << "\nPentru a plasa comanda apasati 6";

		//istoric comenzile mele
	}

	void play() {

		bool oprire;
		oprire = false;

		while (oprire == false) {

			meniu();
			int choice;
			string c;
			cout << "\nChoice : ";
			getline(cin, c);
			choice = stoi(c);

			switch (choice) {

			case 1: controlproduct->traverse();
				break;

			case 2: add_product_to_cart();
				break;

			case 3: view_cart();
				break;
			case 4: delete_from_cart();
				break;

			case 5: place_order();
				break;

			}

		}
	}

	//merge ok
	void add_product_to_cart() {

		cout << "\nIntroduceti numele produsului pe care doriti sa-l adaugati in cos : ";
		string name;
		getline(cin, name);
		int id = controlproduct->GetIDbyName(name);

		if (id != -1) {

			Product* p = controlproduct->GetProductbyID(id);

			cout << "\nCantitatea : ";
			int quantity;
			string q;
			getline(cin, q);
			quantity = stoi(q);
		}

	}

	//merge ok
	void view_cart() {


	}

	//nu merge ok
	void delete_from_cart() {

		//check if the cart is empty
		list<Order_Details*> lista;
		lista = controlorderdetails->GetListByOrderID(this->order->get_ID());

		if (lista.begin() == lista.end()) { cout << "Nu poti sterge produse din cos, cosul este gol\n"; }
		else {

			string nume;
			cout << "\nNumele produsului pe care doriti sa-l stergeti : ";
			getline(cin, nume);


			int product_id = controlproduct->GetIDbyName(nume);
			Order_Details* od = controlorderdetails->GetOrderDetailsByProductIDAndOrderID(this->order->get_ID(), product_id);



			controlorder->modify_order(
				this->order->get_ID(),
				controlorderdetails->GetTotalPriceByOrderID(this->order->get_ID()) - od->get_price());

			cout << "\nProdusul a fost sters din cos";

			controlorderdetails->erase(od->get_ID());
			
		}

	}

	void place_order() {



	}

};

