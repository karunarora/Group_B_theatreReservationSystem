/**
 * @file.customer.c
 *
 * @brief all customer functionalities of system will be handled, in this file. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */
#include "../include/customer.h"


/**
*
* @brief This function display all customers.
*
* This function takes no parameter
*
* @return It returns int type value.
*
*/

int display_customers() {
	mysql_query(con, "SELECT * FROM CUSTOMER");
	MYSQL_RES* result = mysql_store_result(con);

	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 1;
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
	return 0;
}
/**
*
* @brief This function takes input value for add_customer_input()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
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
			//printf("%s Username already exists\n", username);
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


/**
*
*\fn int add_customer( char* name,char *username, char sex,char *password)
*@brief This function takes name, balance, sex, password as its input parameters for signing up
new customer
*
*@param[in] char *name name provided by customer
*@param[in] char *username username provided by the customer
*@param[in] char *sex sex provided by the customer
*@param[in] char *password password provided by the customer
*
*@return It returns 0 for succesfully adding customer and 1 for error
*
*/
int add_customer( char* name,char *username, char sex,char *password) {

	char sql_string[500] = "";
	
	int i =username_exists(username);
	
	if(i==1){
	sprintf(sql_string, "insert into customer(name,username, sex,password) value ('%s','%s','%c','%s');", name,username, sex,password);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 1;
	}
	
	
	printf("Customer Registered");
	}
	else{printf("%s\n", "Username exists");}
	return 0;
}
/**
* @brief A function to update the personal data (name, login, password, gender) of a customer in Database who is already logged in.
*
* @param[in] id –--This parameter gives the customer id (unique in nature).
* @param[in] name--- This parameter returns the name of the customer. This is of varchar type of length 28
* @param[in] password--- This gives the password.This is of varchar type of length 8
* @param[in] sex--- Gives the gender of the customer which is of character type
*
*@description of function A function will be called when CUSTOMER wants to update his/her *username, password, and gender by entering 1 in his portal which will call the update function.
*
*@return int type value
*
*/
int update_customer(int id, char* name, char sex,char *password) {
	char sql_string[500] = "";
	sprintf(sql_string, "update customer set name = '%s',  sex = '%c' ,password = '%s' where id = %d;", name, sex,password, id);
	
	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 1;
	}
	printf("Data Updated\n");
	return 0;
}
/**
*
* @brief This function takes input value for book_movie
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
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
/**
* @brief A function to book movie.
*
* @param[in] customer_id –--This parameter gives the customer id (unique in nature).
* @param[in]  movie_id--- This parameter gives movie id for particular movie
* @param[in] seat_number-- This is of int type and gives away seat number.
*
*@description This function takes in customer and movie id, seat number to book movie.
*
*@return int type value.
*
*/
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
		if (customer_balance < movie_price) {
		printf("NOT ENOUGHT CREDIT\n");
		return -1;
	    }else{
		printf("Movie booked\n");
		}
	}
	else {
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


/**
 * @brief This function is used to check seats booked.
 *
 * @param[in] movie_id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function check the seats that has been booked for movie with that particular movie id. 
 * 
 * @return returns int type value for this functuion.
 *
 */
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
/**
 * @brief This function is of void type and used to display current customer details.
 *
 * takes no parameters.
 *
 * @description This function diaplays the details of current logged in customer in system . 
 * 
 * @return No return value for this functuion.
 *
 */
void display_current_customer()
{
	
}


/**
*
* @brief This function takes input value for add_credit function. 
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
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

/**
*
*@brief This function is used to add credit to customers account balance.
*
*@param[in] int id - this takes integer type value for customer id.
*@param[in] float amount - amount customer wanted to add to his account.
*@param[in] number - it is of int type and takes in credit card number.
*@param[in] cvv - takes in cvv number for authentication purposes.
*@param[in] expdate - takes in expiry date for card.
*
*\return It returns integer type value.
*
*/
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

/**
 * @brief This function is of int type and used to display tansactions to customers.
 *
 * takes no parameters.
 *
 * @description This function displays all the transaction of customer account to customer. 
 * 
 * @return No return value for this function.
 *
 */
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

/**
 * @brief This function displays movies that has been booked.
 *
 * @param[in] id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function uses above listed parameters displays the movies that has been booked. 
 * 
 * @return returns int type value for this functuion.
 *
 */
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

/**
*
*\fn int display_customer(int id)
*@parameter id - takes in customer id.
*@brief This function takes customer id as input and will print the details of the customer 
*
*@return It returns 0 in case of error and 1 for successful query
*
*/
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


