#include <string>

struct attendance{
	int employee_id;
	char employee_status;
};

struct data_attendance{
	std :: string date;
	attendance employees_attendance[100];
};

struct employees{
	int id;
	std :: string name;
	std :: string father_name;
	std :: string address;
	std :: string contact;
};
