#include "controller.h"

int load_menu(){
	int value;//get value to load function
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
		load_menu();//reload if value does not match
	}
	return 0;
}

int get_add_attendance(){
	std :: string attendance_date;//intial string
	employees get_data[SIZE];//intial array
	attendance get_attendance_record[SIZE];//intial array
	int count = 0;

	//get date
	std :: cout << "  Enter Date (dd-mm-yyyy) : ";
	std :: cin.ignore();
	std :: getline(std::cin,attendance_date);
	count = get_employees(get_data);//load employee record

	for (int i = 0; i < count; ++i){
		get_attendance_record[i].employee_id = get_data[i].id;//set id = attendence id as forigen key 
		std :: cout << "  " <<  get_data[i].name << " : " ;//show name of user
		std :: cin >> get_attendance_record[i].employee_status;//get status
	}
	save_attendance(get_attendance_record,count,attendance_date);//pass data to save attendance
	return 0;
}

int view_all_attendance(){
	int count = 0;
	data_attendance attendance_records[365];
	employees get_data[SIZE];
	count = get_attendance(attendance_records);//get array of attendance

	for (int i = 0; i < count; ++i){
		std :: cout << "  "<< attendance_records[i].date << "  \n";
		int count_employee = 0;
		count_employee = get_employees(get_data);//get array of employee

		for (int k = 0 ; k < count_employee ; k++){
			//show record if id match in attendance and employee array 
			if(attendance_records[i].employees_attendance[k].employee_id == get_data[k].id){
				std :: cout << "  "<<  get_data[k].name << "  ";
				std :: cout << attendance_records[i].employees_attendance[k].employee_status << " | ";
			}
		}
		std :: cout << "  \n";
	}
	return 0;
}

int get_add_employee(){
	//get employee data 
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
	save_employee(new_user);//save employee into file
	
	std :: string message = "\n  Record Has Been Added.\n";
	main_navbar(message);//load main menu and display message
	return 0;
}

int modify(){
	char value;
	std :: cout << "\n\n  Press m/M to Modify Record or Press 1 to goto Main menu : ";
	std :: cin >> value;
	//load edit , delete or load main menu
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
	char value;//select edit or delete

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
	bool found = false;
	std :: cout << "  Enter id of employee to edit : ";
	std :: cin >> value;//get id for edit
	employees get_data[SIZE];
	count = get_employees(get_data);//get employee employee array
	for (int i = 0; i < count; ++i){
		//get value if id match
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
			found = true;
		}
	}
	//if record not found recall function
	if(!found){
		std :: cout << "  Record was not found\n"; 	
		edit_employee();
	}else{
		save_edit(get_data,count);
		//success messange if record not found
		std :: string message = "\n  Record has been Modified\n";
		main_navbar(message);
	}
	return 0;
}

int delete_employee(){
	int id; 
	std :: cout << "  Enter id of employee to Delete : ";
	std :: cin >> id; //get id 
	
	char test;
	std :: cout << "  Do you really want delete this record(y/n) : ";
	std :: cin >> test;

	if (test == 'y' || test == 'Y'){
		bool found;
		found = delete_record(id);
		if(!found){
			//function recall if record not found
			std ::  cout << "\n  Record has not been found\n";
			delete_employee();
		}else{
			//success message
			std :: string message = "\n  Record has been Deleted\n";
			main_navbar(message);
		}
	}else if(test == 'n' || test == 'N'){
		std :: string message = "\n  Record has not been Deleted\n";
		main_navbar(message);
	}else{
		std :: cout << "\n  Enter Wrong Value try again : \n"; 
	}
	return 0;
}

int search_record(){
	int value;
	std :: cout << "\n  Value : ";
	std :: cin  >> value;
	if (value == 1){
		search_data();//call search by date
	}else if (value == 2){
		search_id();//call search by id
	}
	return 0;
}

int search_data(){
	std :: string date;
	std :: cout << "\n  Enter Date : ";
	std :: cin.ignore();
	std :: getline(std::cin,date);

	int count = 0;
	bool found = false;
	data_attendance attendance_records[365];
	employees get_data[SIZE];
	count = get_attendance(attendance_records);//get attendance array
	int count_employee = 0;
	for (int i = 0; i < count; ++i){
		if(attendance_records[i].date == date){
			std :: cout << "  "<< attendance_records[i].date << "  \n";
			count_employee = get_employees(get_data);//get employee array

			for (int k = 0 ; k < count_employee ; k++){
				//view if if id is found
				if(attendance_records[i].employees_attendance[k].employee_id == get_data[k].id){
					std :: cout << "  "<<  get_data[k].name << "  ";
					std :: cout << attendance_records[i].employees_attendance[k].employee_status << " | ";
				}
			}
			found = true;
		}
	}
	//if result not found show error
	if(!found){
		std :: cout << "  Result was not found\n"; 
	}
	return 0;
}

int search_id(){
	int id;
	std :: cout << "\n  Enter Id : ";
	std :: cin >> id;//get id

	int count = 0;
	data_attendance attendance_records[365];
	employees get_data[SIZE];
	count = get_attendance(attendance_records);//get attendance array
	int count_employee = 0;
	count_employee = get_employees(get_data);
	bool found = false;
	for (int i = 0; i < count; ++i){
		//show id if id ws found 
		if (get_data[i].id == id){
			std :: cout << "  " << get_data[i].name << " , ";
			std :: cout << "  " << get_data[i].father_name << " , ";
			std :: cout << "  " << get_data[i].address << " , ";
			std :: cout << "  " << get_data[i].contact << " \n\n";
			found = true;
		}
	}

	if(found){
		for (int i = 0; i < count; ++i){
			std :: cout << "  "<< attendance_records[i].date << "  \t";

			for (int k = 0 ; k < count_employee ; k++){
				if(attendance_records[i].employees_attendance[k].employee_id == id){
					std :: cout << attendance_records[i].employees_attendance[k].employee_status << " ";
				}
			}
			std :: cout << "  \n";
		}
	}else{
		std :: cout << "  Result was not found\n"; 
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