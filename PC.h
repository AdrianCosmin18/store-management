#include"Car.h"
#include<list>

class PC:public Product
{
private:
	string processor;
	string platform;
	int memory;

public:

	string get_processor() { return processor; }
	int get_memory() { return memory; }
	string get_platform() { return platform; }

	void set_processor(string p) { processor = p; }
	void set_memory(int m) { memory = m; }
	void set_platform(string pl) { platform = pl; }

	PC(int ID, string name, double price, double weight, string descript, string ty, string process, string platf, int memo) : Product(ID, name, price, weight, descript, "PC"), processor{process}, platform{platf}, memory{memo}{}



	PC(string prp) {

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
		set_type("PC");
		processor = v[6];
		platform = v[7];
		memory = stoi(v[8]);
	}
	


	string describe() override {

		string text = "";

		text += "\nID : " + to_string(get_ID());
		text += "\nName : " + get_name();
		text += "\nPrice : " + to_string(get_price()) + " euro";
		text += "\nWeight : " + to_string(get_weight()) + " kg";
		text += "\nDescription : " + get_description();
		text += "\nType : " + get_type();
		text += "\nProcessor : " + processor;
		text += "\nMemory : " + to_string(memory) + " gb";
		text += "\nPlatform : " + platform;
		text += "\n";

		return text;
	}

	string describe_to_file() override{

		string text = to_string(get_ID()) + "," + get_name() + "," + to_string(get_price()) + "," + to_string(get_weight()) + "," + get_description() + "," + get_type() +","+ processor +"," + platform +"," + to_string(memory);
		return text;

	}
};

