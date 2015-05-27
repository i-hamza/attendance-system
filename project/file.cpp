#include "functions.h"

int save_employee(employees add){
	  std::fstream employee_data;
	  employee_data.open ("employees.txt" , std::ios::app);
	  employee_data << add.id << " , "
		<< add.name << " , "
		<< add.father_name << " , "
		<< add.address << " , "
		<< add.contact << "\n";
	  employee_data.close();
	  std :: string message = "\n  Record Has Been Added.\n";
	  main_navbar(message);
	return 0;
}

int view_employees(){
	std :: string employee_record;
	employees get_data[10]; 

	std :: fstream employee_data;
	employee_data.open ("employees.txt");

	if(employee_data.is_open()){
		int i = 0;
		while(std :: getline(employee_data,employee_record)){
			std :: istringstream ss(employee_record);
			std :: string token;
			int n = 0;
			while(std::getline(ss, token, ',')) {
				if(n == 0){
					get_data[i].id = std::stoi(token);
				}else if(n == 1){
					get_data[i].name = token;
				}else if(n == 2){
					get_data[i].father_name = token;;
				}else if(n == 3){
					get_data[i].address = token;;
				}else if(n == 4){
					get_data[i].contact = token;;
				}
				n++;
			}
			i++;
		}
		for (int i = 0; i < 10; ++i){
			if (get_data[i].id == 21){
				std :: cout << "  " << get_data[i].name << " , ";
				std :: cout << "  " << get_data[i].father_name << " , ";
				std :: cout << "  " << get_data[i].address << " , ";
				std :: cout << "  " << get_data[i].contact << " \n";
			}
		}
	}
	return 0;
}