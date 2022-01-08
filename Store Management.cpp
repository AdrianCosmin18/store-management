#include"ViewUser.h"

int main() {

	Customer* cosmin = new Customer("2,Nedelcu Adrian Cosmin,Customer,cosmin_ndlc@yahoo.com,1234dec,Callatis 12,Timisul de sus 3,0773941106");
	ViewUser* vu = new ViewUser(cosmin);

	vu->play();



}
