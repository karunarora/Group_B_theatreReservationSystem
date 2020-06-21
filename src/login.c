#include "../include/login.h"


/* This function takes the input from user and send them to admin login function
This function is done by Harashdeep Kaur Minhas
*/
int admin_login_input()
{
	char name[50];
	char password[50];
	printf("Enter Username : ");
	scanf("%s", name);
	printf("Enter password : ");
	scanf("%s", password);
	return admin_login(name, password);
}

/* This function takes arguements from admin input function and verify credentials from db
This function is done by Harashdeep Kaur Minhas
*/
int admin_login(char* name, char* password) {
	char sql_string[500] = "";
	sprintf(sql_string, "select * from admin where name='%s' and password = '%s'", name, password);
	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 0;
	}
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	int rows = mysql_num_rows(result);
	if (rows == 0) {
		printf("WRONG USERNAME OR PASSWORD\n");
		return -1;
	}
	else {
		printf("ADMIN LOGGED IN\n");
		admin = 1;
		userid = -1;
	}
	return 0;
}

/* This function takes the input from user and send them to customer login function
This function is done by Paramveer Singh
*/
int customer_login_input()
{
	char username[50];
	char password[50];
	printf("Enter username : ");
	scanf("%s", username);
	printf("Enter Password : ");
	scanf("%s", password);
	customer_login(username, password);
	return 0;
}

/* This function takes arguements from customer input function and verify credentials from db
This function is done by Paramveer singh
*/
int customer_login(char * username, char* password) {
	char sql_string[500] = "";
	sprintf(sql_string, "select * from customer where username='%s' and password = '%s'", username, password);
	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 0;
	}
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	int rows = mysql_num_rows(result);
	if (rows == 0) {
		printf("WRONG USERNAME OR PASSWORD\n\n");
		return -1;
	}
	else {
		MYSQL_ROW row = mysql_fetch_row(result);
		printf("LOGGED IN\n\n");

		userid = atoi(row[0]);
		admin = -1;
	}

	return userid;
}


/* This function logouts the user
This function is done by Paramveer singh
*/
int logout()
{
	admin = -1;
	userid = -1;
	return 0;
}
