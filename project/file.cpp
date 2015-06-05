#include "functions.h"

int save_attendance(attendance save_data[],int count,std::string get_date){
	std::ofstream attendance_data;
	attendance_data.open ("attendance.txt" , std::ios::app);

	attendance_data << get_date << "~"; 
	for (int i = 0; i < count; ++i){
		attendance_data << save_data[i].employee_id << ":"; 	
		attendance_data << save_data[i].employee_attendance << "|";
	}
	attendance_data << "\n"; 

	attendance_data.close();
	return 0;
}

int get_attendance(data_attendance attendance_records[]){
	std :: fstream attendance_data;
	std :: string attendance_record;
	int count = 0;
	int i = 0;
	attendance_data.open ("attendance.txt");

	if(attendance_data.is_open()){
		while(std :: getline(attendance_data,attendance_record)){
			std :: istringstream dd(attendance_record);
			std :: string token;
			int n = 0;

			while(std::getline(dd, token, '~')) {
				if(n == 0){
					attendance_records[count].date = token;
				}else if(n == 1){
					
					std :: string recordss;
					recordss = token;
					std :: string sub_token;
					std :: istringstream rr(recordss);
					int i = 0;
					while(std::getline(rr, sub_token, '|')){
						std :: string record;
						record = sub_token;
						std :: string employee_token;
						std :: istringstream ee(record);
						int j = 0;
						
						while(std::getline(ee, employee_token, ':')){
							if(j == 0){
							attendance_records[count].employees_attendance[i].employee_id = std :: stoi (employee_token);
							}else if(j == 1){
								attendance_records[count].employees_attendance[i].employee_attendance = employee_token[0];	
							}
							j++;
						}
						i++;
					}	
				}
				n++;
			}
			count++;
		}
	}
	
	return count;
}

int save_employee(employees add){
	std::ofstream employee_data;
	employee_data.open ("employees.txt" , std::ios::app);
	employee_data << add.id << ","
	<< add.name << ","
	<< add.father_name << ","
	<< add.address << ","
	<< add.contact << std :: endl;
	employee_data.close();
	return 0;
}

int save_edit(employees get_data[] ,int count){
	std::fstream employee_data;
	std::ofstream("employees.txt", std::ios::out).close();//remove data from file
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

int delete_record(int id){
	int count;
	employees get_data[SIZE];
	count = get_employees(get_data);

	std::fstream employee_data;
	std::ofstream("employees.txt", std::ios::out).close();//remove data from file
	employee_data.open ("employees.txt");
	for (int i = 0; i < count; ++i){
		if (get_data[i].id != id){
			
			employee_data << get_data[i].id << ","
			<< get_data[i].name << ","
			<< get_data[i].father_name << ","
			<< get_data[i].address << ","
			<< get_data[i].contact << std :: endl;
		
		}
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