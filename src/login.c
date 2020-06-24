/**
 * @file.login.c
 *
 * @brief Validations of credentials by admin and customer. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */

#include "../include/login.h"


/**
*
* @brief This function takes input values for admin_login()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
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

/**
* @fn int admin_login(char* name, char* password);
* @brief A function to take arguments from the admin to login to the system and verify credentials from the database.
*
* @param[in] char*name--- username of the admin
* @param[in] char*password--- Password provided by the admin.
*
*@description of function A function will be called when ADMIN wants to login in his account by entering his username and password.
*@return It returns adminid.
*
*/
int admin_login(char* name, char* password) {
	char sql_string[500] = "";
	sprintf(sql_string, "select * from admin where name='%s' and password = '%s'", name, password);
	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 1;
	}
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 1;
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

/**
*
* @brief This function takes input value for customer_login()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
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

/**
*
*\fn int customer_login(char * username, char* password)
*\brief This function takes arguements from customer input function and verify credentials from db
*
*@param[in] char *username username provided by the customer
*@param[in] char *password password provided by the customer
*
*\return It returns usereid
*
*/
int customer_login(char * username, char* password) {
	char sql_string[500] = "";
	sprintf(sql_string, "select * from customer where username='%s' and password = '%s'", username, password);
	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 1;
	}
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 1;
	}
	int rows = mysql_num_rows(result);
	if (rows == 0) {
		printf("WRONG USERNAME OR PASSWORD\n\n");
		return -1;
	}
	else {
		MYSQL_ROW row = mysql_fetch_row(result);
		printf("LOGGED IN\n");

		userid = atoi(row[0]);
		admin = -1;
	}

	return userid;
}


/**
*
*\fn int logout()
*\brief This function logsout the customer and admin out of the system
*
*/
int logout()
{
	admin = -1;
	userid = -1;
	printf("Logged out\n");
	return 0;
}
