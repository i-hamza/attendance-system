#include "functions.h"

int save_employee(employees add){
	  std::fstream employee_data;
	  employee_data.open ("employees.txt" , std::ios::app);
	  employee_data << add.id << ","
		<< add.name << " , "
		<< add.father_name << ","
		<< add.address << ","
		<< add.contact << std :: endl;
	  employee_data.close();
	  std :: string message = "\n  Record Has Been Added.\n";
	  main_navbar(message);
	return 0;
}

int save_edit(employees get_data[] ,int count){
	std::fstream employee_data;
	employee_data.open ("employees.txt");
	for (int i = 0; i < count; ++i){
		employee_data << get_data[i].id << ","
		<< get_data[i].name << ","
		<< get_data[i].father_name << ","
		<< get_data[i].address << ","
		<< get_data[i].contact << std :: endl;
	}
	employee_data.close();
	return 0;
}

int get_employees(employees get_data[]){
	
	std :: fstream employee_data;
	std :: string employee_record;
	int count = 0;
	employee_data.open ("employees.txt");

	if(employee_data.is_open()){
		while(std :: getline(employee_data,employee_record)){
			std :: istringstream ss(employee_record);
			std :: string token;
			int n = 0;
			while(std::getline(ss, token, ',')) {
				if(n == 0){
					get_data[count].id = std::stoi(token);
				}else if(n == 1){
					get_data[count].name = token;
				}else if(n == 2){
					get_data[count].father_name = token;
				}else if(n == 3){
					get_data[count].address = token;
				}else if(n == 4){
					get_data[count].contact = token;
				}
				n++;
			}
			count++;
		}
	}
	return count;
}