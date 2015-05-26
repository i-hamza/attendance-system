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
	std :: fstream employee_data;
	employee_data.open ("employees.txt");
	if(employee_data.is_open()){
		while(std :: getline(employee_data,employee_record)){
			std :: istringstream ss(employee_record);
			std :: string token;
			int n = 0;
			while(std::getline(ss, token, ',')) {
				if(n == 0){
					std :: cout << "Id : ";
					std::cout << token << "  \n";
				}else if(n == 1){
					std :: cout << "Name : ";
					std::cout << token << "  \n";
				}else if(n == 2){
					std :: cout << "Father Name : ";
					std::cout << token << "  \n";
				}else if(n == 3){
					std :: cout << "Address : ";
					std::cout << token << "  \n";
				}else if(n == 4){
					std :: cout << "Contact : ";
					std::cout << token << "  \n\n";
				}
				n++;
			}
		}
	}
	return 0;
}
