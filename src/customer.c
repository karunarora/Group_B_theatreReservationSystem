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


int book_movie_input()
{
	int movie_id;
	int seat_num;
	printf("Enter Movie ID   : ");
	scanf("%d", &movie_id);
	printf("AVALIBLE SEATS\n");
	seat_number(movie_id);
	printf("Enter Seatnumber : ");
	scanf("%d", &seat_num);
	book_movie(userid, movie_id, seat_num);
	return 0;
}


int book_movie(int customer_id,int movie_id,int seat_number) {
	if (seat_number < 0 || seat_number> 50)
	{
		fprintf(stderr, "%s\n", "INVALID SEAT NUMBER");
		return 0;
	}

	char sql_string[500] = "";
	sprintf(sql_string, "select *from movie where id = %d;", movie_id);
	mysql_query(con, sql_string);
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	int num_rows = mysql_num_rows(result);
	if (num_rows == 0) {
		printf("%s\n", "NO MOVIE EXIST");
		return 1;
	}

	sprintf(sql_string, "select *from seats where seatnumber = %d and movie = %d;", seat_number,movie_id);
	mysql_query(con, sql_string);
	result = mysql_store_result(con);
	num_rows = mysql_num_rows(result);
	if (num_rows != 0) {
		printf("%s\n", "SEAT NUMBER OCCUPIED");
		return 1;
	}
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	
	sprintf(sql_string, "select movie_price from movie where id = %d ;", movie_id);
	mysql_query(con, sql_string);
	result = mysql_store_result(con);
	num_rows == mysql_num_rows(result);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	MYSQL_ROW row = mysql_fetch_row(result);
	float movie_price = 0;
	if (row)
	{
		printf("Movie Price : %s\n", row[0]);
		movie_price = stof(row[0]);
	}
	else {
		return -1;
	}


	sprintf(sql_string, "select balance from customer where id = %d ;", customer_id);
	mysql_query(con, sql_string);
	result = mysql_store_result(con);
	num_rows == mysql_num_rows(result);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	row = mysql_fetch_row(result);
	float customer_balance = 0;
	if (row)
	{
		printf("BALANCE  :  %s\n", row[0]);
		customer_balance = stof(row[0]);
		printf("Movie booked");
		
	}
	else {
		return -1;
	}
	if (customer_balance < movie_price) {
		printf("NOT ENOUGHT CREDIT\n");
		return -1;
	}
	customer_balance = customer_balance - movie_price;
	
	sprintf(sql_string, "update customer set  balance = %.2f  where id = %d;",customer_balance ,customer_id);
	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 1;
	}

	sprintf(sql_string, "insert into seats(customer,movie,seatNumber) value (%d,%d,%d)", customer_id,movie_id,seat_number);
	if (mysql_query(con, sql_string)) {
		printf("%s", mysql_error(con));
		return 1;
	}
	return 0;
}

float stof(const char* s){
  float rez = 0, fact = 1;
  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++){
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};
