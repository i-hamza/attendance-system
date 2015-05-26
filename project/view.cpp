//This file load views of pages

#include "functions.h"

int header(){
	system("CLS");
	std::cout << "  Attendance System\n\n  ";
	return 0;
}
int main_navbar(std::string message){
	header();//load project heading
	std::cout << "Press following no. to perform task : \n";
	std::cout << "   1 - Add Attendance \n";
	std::cout << "   2 - View Attendance \n";
	std::cout << "   3 - Add Employee \n";
	std::cout << "   4 - View Employees \n";
	std::cout << "   5 - Search \n";
	std::cout << message;
	load_menu();
	return 0;
}

int add_attendance(){
	header();//load project heading
	std::cout << "Add Attendance\n";
	return 0;
}

int view_attendance(){
	header();//load project heading
	std::cout << "View Attendance\n";

	return 0;
}

int add_employee(){
	header();//load project heading
	std::cout << "Add Employee\n";
	get_add_employee();

	return 0;
}

int view_employee(){
	header();//load project heading
	std::cout << "View Employees\n";
	view_employees();
	return 0;
}

int search(){
	header();//load project heading
	std::cout << "Search\n";
	std::cout << "  Press following no. to perform task : \n";
	std::cout << "   1 - By Date \n";
	std::cout << "   2 - By Employee \n";

	return 0;
}