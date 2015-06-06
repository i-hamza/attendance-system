#include <string>
//save id and status of employee
struct attendance{
	int employee_id;
	char employee_status;
};
//save date and Attendance of all employee
struct data_attendance{
	std :: string date;
	attendance employees_attendance[100];
};
//employee structure
struct employees{
	int id;
	std :: string name;
	std :: string father_name;
	std :: string address;
	std :: string contact;
};
