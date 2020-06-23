#include "../include/customer.h"


// display all the customers
int display_customers() {
	mysql_query(con, "SELECT * FROM CUSTOMER");
	MYSQL_RES* result = mysql_store_result(con);

	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	printf("\n\n\n***************************************CUSTOMERS*****************************************\n");

	printf("|%-4s", "ID");
	printf("|");
	printf("%-24s", "USERNAME");
	printf("|");
	printf("%-24s", "NAME");
	printf("|");
	printf("%-5s", "SEX");
	printf("|");
	printf("%-7s", "BALANCE");
	printf("|");
	printf("\n\n");

	while ((row = mysql_fetch_row(result)))
	{
		printf("|%-4s", row[0] ? row[0] : "NULL");
		printf("|");
		printf("%-24s", row[1] ? row[1] : "NULL");
		printf("|");
		printf("%-24s", row[2] ? row[2] : "NULL");
		printf("|");
		printf("%-5s", row[3] ? row[3] : "NULL");
		printf("|");
		printf("%-7s", row[4] ? row[4] : "NULL");
		printf("|\n");
	}
	mysql_free_result(result);
	return 1;
}
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



int seat_number(int movie_id)
{
	char sql_string[500] = "";
	sprintf(sql_string, "select distinct seatnumber from seats where movie = %d;", movie_id);
	mysql_query(con, sql_string);
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}

	MYSQL_ROW row;
	printf("UTILIZED SEAT NUMBERS (0-50) FOR MOVIE ID %d\n",movie_id);
	while ((row = mysql_fetch_row(result)))
	{
		printf("%s\n", row[0]);
	}
	int num_fields = mysql_num_fields(result);
	return 0;
}

void display_current_customer()
{
	
}


// ask the user to for account info
int add_credit_input()
{
	float amount;
	char number[50];
	char cvv[50];
	char expdate[100];
	
	printf("Enter Credit To Add : ");
	scanf("%f", &amount);
	printf("Enter Credit Card number : ");
	
	scanf("%s", number);
	//scanf("%s", number);
	
	
		printf("Enter CVV : ");
		scanf("%s", cvv);
		if (input_date(expdate) == 0)
		{
			if (strlen(cvv) == 3 && strlen(number) == 16) {
				return add_credit(userid, amount, number, cvv, expdate);
			}
			printf("Invalid CVV or Credit Card Number\n");
		}
	
	return -1;
}

// that input and store it in the database
int add_credit(int id, float amount,char *number,char *cvv ,char *expdate)
{
	char sql_string[500] = "";
	sprintf(sql_string, "insert into creditcard value (%d,%.2f,'%s','%s','%s',now());", id, amount, number, cvv, expdate);
	mysql_query(con, sql_string);
	printf("Balance Updated\n");
	sprintf(sql_string, "update customer set balance = balance + %f where id = %d;", amount, id);
	mysql_query(con, sql_string);
	return 0;

}

// display all the transaction done
int display_transaction()
{
	char buf[100];
	sprintf(buf, "SELECT * FROM creditcard");
	mysql_query(con, buf);
	MYSQL_RES* result = mysql_store_result(con);

	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	printf("|%-4s", "ID");
	printf("|");
	printf("%-10s", "AMOUNT");
	printf("|");
	printf("%-20s", "Number");
	printf("|");
	printf("%-12s", "EXP DATE");
	printf("|");
	printf("%-12s", "TRANS DATE");
	printf("|");
	printf("\n\n");

	while ((row = mysql_fetch_row(result)))
	{
		printf("|%-4s", row[0] ? row[0] : "NULL");
		printf("|");
		printf("%-10s", row[1] ? row[1] : "NULL");
		printf("|");
		printf("%-20s", row[2] ? row[2] : "NULL");
		printf("|");
		printf("%-12s", row[4] ? row[4] : "NULL");
		printf("|");
		printf("%-12s", row[5] ? row[5] : "NULL");
		printf("|\n");
	}
	mysql_free_result(result);
	return 0;
}

// displays booked movie info 
int display_booked_movies(int id)
{
	char buf[1000];
	sprintf(buf,"select movie.*,seats.seatNumber  from movie join seats on movie.id = seats.movie where seats.customer = %d;", id);
	mysql_query(con, buf);
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("E%s\n\n", mysql_error(con));
		return 0;
	}
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	printf("|%-4s", "ID");
	printf("|");
	printf("%-24s", "NAME");
	printf("|");
	printf("%-10s", "TYPE");
	printf("|");
	printf("%-10s", "DATE");
	printf("|");
	printf("%-10s", "TIME");
	printf("|");
	printf("%-5s", "PRICE");
	printf("|");
	printf("%-10s|", "SEAT NO");
	printf("\n\n");
	while ((row = mysql_fetch_row(result)))
	{
		printf("|%-4s", row[0] ? row[0] : "NULL");
		printf("|");
		printf("%-24s", row[1] ? row[1] : "NULL");
		printf("|");
		printf("%-10s", row[2] ? row[2] : "NULL");
		printf("|");
		printf("%-10s", row[3] ? row[3] : "NULL");
		printf("|");
		printf("%-10s", row[4] ? row[4] : "NULL");
		printf("|");
		printf("%-5s", row[5] ? row[5] : "NULL");
		printf("|");
		printf("%-10s", row[6] ? row[6] : "NULL");
		printf("|\n");
	}
	mysql_free_result(result);
	return 1;
}

// display customer on id
int display_customer(int id)
{
	char buf[100];
	sprintf(buf, "SELECT * FROM CUSTOMER where id = %d",id);
	mysql_query(con,buf );
	MYSQL_RES* result = mysql_store_result(con);

	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	printf("|%-4s", "ID");
	printf("|");
	printf("%-24s", "USERNAME");
	printf("|");
	printf("%-24s", "NAME");
	printf("|");
	printf("%-5s", "SEX");
	printf("|");
	printf("%-7s", "BALANCE");
	printf("|");
	printf("\n");

	while ((row = mysql_fetch_row(result)))
	{
		printf("|%-4s", row[0] ? row[0] : "NULL");
		printf("|");
		printf("%-24s", row[1] ? row[1] : "NULL");
		printf("|");
		printf("%-24s", row[2] ? row[2] : "NULL");
		printf("|");
		printf("%-5s", row[3] ? row[3] : "NULL");
		printf("|");
		printf("%-7s", row[4] ? row[4] : "NULL");
		printf("|\n");
	}
	mysql_free_result(result);
	return 0;
}


