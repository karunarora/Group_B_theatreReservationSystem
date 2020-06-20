#include "../include/customer.h"


// add customer to the list
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



