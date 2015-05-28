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

int edit_employee(){
	int value;
	int count; 
	std :: cout << "Enter id of employee to edit : ";
	std :: cin >> value;
	employees get_data[SIZE];
	count = get_employees(get_data);
	for (int i = 0; i < count; ++i){
		if(get_data[i].id == value){
			std :: cin.ignore();
			std :: cout << "  Enter Name : " ;
			getline(std :: cin,get_data[i].name);
			std :: cout << "  Enter Father Name : " ;
			getline(std :: cin,get_data[i].father_name);
			std :: cout << "  Enter Address : " ;
			getline(std :: cin,get_data[i].address);			
			std :: cout << "  Enter Contact : " ;
			getline(std :: cin,get_data[i].contact);			

		}
	}
	std::fstream employee_data;
	employee_data.open ("employees.txt");
	for (int i = 0; i < count; ++i){
		employee_data << get_data[i].id << " , "
		<< get_data[i].name << " , "
		<< get_data[i].father_name << " , "
		<< get_data[i].address << " , "
		<< get_data[i].contact << std :: endl;
	}
	employee_data.close();
	std :: string message = "";
	main_navbar(message);
	return 0;
}

int redirect(){
	int value;
	std :: cout << "\n\nPress 1 to return main menu or Press 0 to exit : ";
	std :: cin >> value;
	if (value == 1){
		std :: string message = "";
		main_navbar(message);//load main menu
	}else if (value == 0){
		exit(1);
	}
	return 0;
}