/**
 * @file.movie.h
 *
 * @brief all the functionalities related with addidtion, updation, remove of movies by customer and admin. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */
#include "../include/movie.h"
#include "../include/upcomming.h"

/**
* @fn int input_date(char *tempBuffer);
* @brief A function to input the date of movie from the customer.
*
* @param[in] char *tempbuffer---This parameter gives the date and store it.
*
*@description of function A function will be called when CUSTOMER wants to enter the date which will be saved in tempbuffer.
*@return It will return value of int type.
*
*/
int input_date(char* tempBuffer)
{
	printf("ENTER DATE\n");
	int day = 0, month = 0, year = 0;
	printf("Enter day : ");
	scanf("%d", &day);
	printf("Enter month : ");
	scanf("%d", &month);
	printf("Enter year : ");
	scanf("%d", &year);
	if (day > 0 && day < 32)
	{
		if (month > 0 && month < 13)
		{
			if (year > 1950 && year < 3000)
			{
				sprintf(tempBuffer, "%d/%d/%d", year, month, day);
				return 0;
			}
		}
	}
	printf("Invalid Date");
	return 1;
}

/**
 * @brief This function checks whether movie exists or not.
 *
 * @param[in] movie_id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function uses above listed parameters displays the movies that movie with that particular id exists or not. 
 * 
 * @return returns int type value for this functuion.
 *
 */
int movie_exists(int movie_id)
{
	char sql_string[500] = "";
	sprintf(sql_string, "select *from movie where id = %d;", movie_id);
	mysql_query(con, sql_string);
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 1;
	}
	int num_rows = mysql_num_rows(result);
	if (num_rows == 0) {
		printf("%s\n", "NO MOVIE EXIST");
		return 1;
	}
	return 0;
}

/**
*
* @brief This function takes input values for add_movie() function.
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int add_movie_input()
{
	char name[50];
	char date[50];
	char time[50];
	char type[50];
	float price = 0;
	int hours = 0;
	int mins = 0;
	printf("Enter Movie Name : ");
	scanf("%*c%[^\n]%*c", name);
	printf("Enter Movie Type : ");
	scanf("%s", type);
	if (input_date(date) == 0)
	{
		printf("Enter Time\n");
		printf("Enter Hours(0-23) : ");
		scanf("%d", &hours);
		printf("Enter Minutes(0-59) : ");
		scanf("%d", &mins);
		sprintf(time, "%d:%d", hours, mins);
		printf("Enter Movie Price : ");
		scanf("%f", &price);
		add_movie(name,type, date, time, price);
	}
	return 0;
}

/**
*
* @brief This function takes input values for update_movie() function.
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int update_movie_input()
{
	int movie_id;
	char name[50];
	char date[50];
	char time[50];
	char type[50];
	float price = 0;
	int hours = 0;
	int mins = 0;
	printf("Enter Movie Id : ");
	scanf("%d", &movie_id);
	if (movie_exists(movie_id) != 0)
	{
		return 0;
	}
	printf("Enter Movie Name : ");
	scanf("%*c%[^\n]%*c", name);
	printf("Enter Movie Type : ");
	scanf("%s", type);
	if(input_date(date) == 0)
	{
		printf("Enter Time\n");
		printf("Enter Hours(0-23) : ");
		scanf("%d", &hours);
		printf("Enter Minutes(0-59) : ");
		scanf("%d", &mins);
		sprintf(time, "%d:%d", hours, mins);
		printf("Enter Movie Price : ");
		scanf("%f", &price);
		update_movie(movie_id, name,type ,date, time, price);
	}
	return 0;
}

/**
*
* @brief This function takes input values for remove_movie() function.
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int remove_movie_input()
{
	int movie_id;
	printf("Enter Movie Id : ");
	scanf("%d", &movie_id);
	if (movie_exists(movie_id) != 0)
	{
		return 0;
	}
	remove_movie(movie_id);
	return 0;
}

/**
*
*\fn int add_movie()
*\brief This function takes input value from add_movie_input function and add ovie into database
*@param[in] char* movie_name
*@param[in] char *  type
*@param[in] char* movie_date
*@param[in] char* movie_time
*@param[in] float movie_price
*\return It returns 1 for error and 0 for succesfully displaying movies
*
*/
int add_movie(char* movie_name, char *  type,char* movie_date, char* movie_time, float movie_price) {
	char sql_string[500] = "";
	sprintf(sql_string, "insert into movie(name,type, movie_date, movie_time,movie_price) value ('%s','%s','%s','%s',%.2f);", movie_name,type, movie_date, movie_time, movie_price);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 1;
	}
	return 0;
}

/**
*
*\fn int display_movie()
*\brief This function takes no input value and will print list of all movies that are showcased in theatre
*
*\return It returns 0 for error and 1 for succesfully displaying movies
*
*/
int display_movie() {
	mysql_query(con, "select *from movie");
	MYSQL_RES* result = mysql_store_result(con);

	if (result == NULL)
	{
		printf("E%s\n\n", mysql_error(con));
		return 1;
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	printf("***************************************MOVIES*****************************************\n");
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
	printf("%-5s|", "PRICE");
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
		printf("|\n");
	}
	mysql_free_result(result);
	return 0;
}

/**
 * @brief This function is used to remove movie from system.
 *
 * @param[in] id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function uses above listed parameters to remove that movie with particular id from system. 
 * 
 * @return returns int type value for this functuion.
 *
 */
int remove_movie(int id)
{
	char sql_string[500] = "";
	sprintf(sql_string, "delete from movie where id = %d", id);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 1;
	}
	return 0;
}

/**
*
*@brief This function is used to update particular movie information and details.
*
*@param[in] int id - takes in movie id.
*@param[in] char movie_name - takes in name of that particular movie.
*@param[in] char type - takes in type or genre of movie.
*@param[in] char movie_time - takes in show timings for movie. 
*@param[in] float movie_price - takes in price for movie show.
*
*@description- using all the parameters listed above, this function is used to update movie deatails.
*
*@return returns int value for this function.
*
*/
int update_movie(int id, char* movie_name,char *type ,char* movie_date, char* movie_time, float movie_price)
{
	char sql_string[500] = "";
	sprintf(sql_string, "update movie set name = '%s',type='%s',movie_date ='%s',movie_time='%s',movie_price=%.2f where id = %d;", movie_name,type, movie_date, movie_time, movie_price, id);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 1;
	}
	return 0;
}
