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

int get_add_attendance(){
	std :: string attendance_date;
	employees get_data[SIZE];
	attendance get_attendance_record[SIZE];
	int count = 0;

	std :: cout << "  Enter Date (dd-mm-yyyy) : ";
	std :: cin.ignore();
	std :: getline(std::cin,attendance_date);
	count = get_employees(get_data);

	for (int i = 0; i < count; ++i){
		get_attendance_record[i].employee_id = get_data[i].id;
		std :: cout << "  " <<  get_data[i].name << " : " ;
		std :: cin >> get_attendance_record[i].employee_attendance;
	}
	save_attendance(get_attendance_record,count,attendance_date);
	return 0;
}

int get_add_employee(){
	employees new_user;
	
	std :: cout << "   Enter Id : " ;
	std :: cin >> new_user.id;
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
	
	std :: string message = "\n  Record Has Been Added.\n";
	main_navbar(message);
	return 0;
}

int modify(){
	char value;
	std :: cout << "\n\n  Press m/M to Modify Record or Press 1 to goto Main menu : ";
	std :: cin >> value;
	if (value == 'm' || value == 'M'){
		select_modify();
	}else if (value == '1'){
		std :: string message = "";
		main_navbar(message);//load main menu
	}else{
		modify();
	}
	return 0;
}

int select_modify(){
	char value;
	std :: cout << "\n  For Go to main menu press 1\n"
				<< "  For edit record press e/E and to delete record press d/D : ";
	std :: cin >> value;
	if (value == 'e' || value == 'E'){
		edit_employee();
	}else if(value == 'd' || value == 'D'){
		delete_employee();
	}else if(value == '1'){
		std :: string message = "";
		main_navbar(message);//load main menu
	}else{
		std :: cout << "\n  Enter Wrong Value try again : \n";
		select_modify();
	}
	return 0;
}

int edit_employee(){
	int value;
	int count; 
	std :: cout << "  Enter id of employee to edit : ";
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
	save_edit(get_data,count);
	std :: string message = "\n  Record has been Modified\n";
	main_navbar(message);
	return 0;
}

int delete_employee(){
	int id; 
	std :: cout << "  Enter id of employee to Delete : ";
	std :: cin >> id;
	
	char test;
	std :: cout << "  Do you really want delete this record(y/n) : ";
	std :: cin >> test;

	if (test == 'y' || test == 'Y'){
		delete_record(id);
		std :: string message = "\n  Record has been Deleted\n";
		main_navbar(message);
	}else if(test == 'n' || test == 'N'){
		std :: string message = "\n  Record has not been Deleted\n";
		main_navbar(message);
	}else{
		std :: cout << "\n  Enter Wrong Value try again : \n"; 
	}
	return 0;
}

int redirect(){
	int value;
	std :: cout << "\n\n  Press 1 to return main menu or Press 0 to exit : ";
	std :: cin >> value;
	if (value == 1){
		std :: string message = "";
		main_navbar(message);//load main menu
	}else if (value == 0){
		exit(1);
	}
	return 0;
}