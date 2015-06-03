#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "structure.h"

int const SIZE = 100;

//view page functions
extern int header();
extern int main_navbar(std::string);
extern int add_attendance();
extern int view_attendance();
extern int add_employee();
extern int view_employee();
extern int search();

//function page functions
extern int load_menu();
extern int get_add_employee();
extern int modify();
extern int select_modify();
extern int edit_employee();
extern int redirect();


//file page functions
extern int save_employee(employees);
extern int get_employees(employees[]);
extern int save_edit(employees[],int);

