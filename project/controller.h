#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "structure.h"

int const SIZE = 100;

//view page functions
extern int header();//load base header view
extern int main_navbar(std::string);//load main menu and take message as argument
extern int add_attendance();
extern int view_attendance();
extern int add_employee();
extern int view_employee();
extern int search();

//function page functions
extern int load_menu();//get value and load function
extern int get_add_employee();//get employee of a date
extern int view_all_attendance();//get attendance and view
extern int get_add_attendance();//add employee
extern int modify();//edit or delete
extern int select_modify();//selectedit or delete 
extern int delete_employee();//delete employee
extern int edit_employee();//edit employee
extern int search_record();//search record by date or id
extern int search_data();//get record by date
extern int search_id();//get record by id
extern int redirect();//return to main menu or exit function

//file page functions
extern int save_attendance(attendance [],int,std::string);//save attendance into file
extern int get_attendance(data_attendance []);//get array attendance from file
extern int save_employee(employees);//save employee into file
extern int get_employees(employees[]);//get array of attandance fro file
extern bool delete_record(int);//delete record from file
extern int save_edit(employees[],int);//save edit into file