#include <string>

struct employees{
	int id;
	std :: string name;
	std :: string father_name;
	std :: string address;
	std :: string contact;
};

struct attendance{
	int employee_id;
	char employee_attendance;
};

struct data_attendance{
	std :: string date;
	attendance employees_attendance[100];
};