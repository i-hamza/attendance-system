#include "functions.h"

int load_menu(){
	int value;
	std :: cout << " Value: ";
	std :: cin >> value;
	if (value == 1){
		add_attendance();
	}else if (value == 2){
		view_attendance();
	}else if (value == 3){
		add_employee();
	}else if (value == 4){
		view_employee();	
	}else if (value == 5){
		search();
	}else{
		std :: cout <<  "Please Enter Valid no : \n";
		load_menu();
	}
	return 0;
}

int get_add_employee(){
	employees new_user;
	new_user.id = 21;
	std :: cin.ignore();
	std :: cout << "   Enter Name : " ;
	std :: getline (std :: cin , new_user.name);
	std :: cout << "   Enter Father Name : " ;
	std :: getline (std :: cin , new_user.father_name);
	std :: cout << "   Enter Address : " ;
	std :: getline (std :: cin , new_user.address);
	std :: cout << "   Enter Contact : " ;
	std :: getline (std ::cin , new_user.contact);
	save_employee(new_user);
	return 0;
}