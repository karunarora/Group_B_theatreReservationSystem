#include "../headers/login.h"




// the input is asked from the user for the login
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

// customer login is varified from the database
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



