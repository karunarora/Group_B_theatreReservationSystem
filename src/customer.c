#include "../include/customer.h"

/* This function takes the input from user for registering new customer and send details to add_customer() function
This function is done by Paramveer singh
*/

int add_customer_input()
{
	char name[50];
	char password[50];
	char sex;
	float balance;
	char username[50];
	printf("Enter Name : ");
	scanf("%*c%[^\n]%*c",name);
	printf("Enter Username : ");
	scanf("%s", username);
	printf("Enter Password : ");
	scanf("%*c%[^\n]%*c", password);
	printf("Enter Gender (m/f): ");
	scanf("%c%*c", &sex);
	if (sex == 'm' || sex == 'f' || sex == 'M' || sex == 'F')
	{
		add_customer(name, username, sex, password);
		return 0;
	}
	printf("Wrong input for Gender");
	return 0;
}

/* This function checks if the username already exists
This function is done by Paramveer singh
*/
int username_exists(char *username) {
		char sql_string[500] = "";
		sprintf(sql_string, "select *from customer where username = '%s';", username);
		mysql_query(con, sql_string);
		MYSQL_RES* result = mysql_store_result(con);
		if (result == NULL)
		{
			printf("%s", mysql_error(con));
			return 1;
		}
		int num_rows = mysql_num_rows(result);
		if (num_rows == 0) {
			//printf("%s\n", "Username exists");
			return 1;
		}
		return 0;
}

/* This function takes the input from user for updating customer's data and send details to update_customer() function
This function is done by Harashdeep Kaur Minhas
*/
int update_customer_input()
{
	char name[50];
	char password[50];
	char sex;
	printf("Enter Name : ");
	scanf("%*c%[^\n]%*c",name);
	printf("Enter Password : ");
	scanf("%[^\n]%*c", password);
	printf("Enter Gender (m/f): ");

	scanf("%c", &sex);
	if (sex == 'm' || sex == 'f' || sex == 'M' || sex == 'F')
	{
		update_customer(userid, name, sex, password);
		return 0;
	}
	printf("Wrong input for Gender");
	return 0;
}

/* This function takes the arguements from add_customer_input() function and add new customer data to database
This function is done by Paramveer singh
*/

int add_customer( char* name,char *username, char sex,char *password) {

	char sql_string[500] = "";
	
	int i =username_exists(username);
	
	if(i==1){
	sprintf(sql_string, "insert into customer(name,username, sex,password) value ('%s','%s','%c','%s');", name,username, sex,password);

	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 1;
	}
	
	
	printf("Customer Registered");
	}
	else{printf("%s\n", "Username exists");}
	return 0;
}
/* This function takes the arguements from update_customer_input() function and update customer data to database
This function is done by Harashdeep Kaur Minhas
*/
int update_customer(int id, char* name, char sex,char *password) {
	char sql_string[500] = "";
	sprintf(sql_string, "update customer set name = '%s',  sex = '%c' ,password = '%s' where id = %d;", name, sex,password, id);
	printf("Data Updated");
	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 1;
	}
	return 0;
}

