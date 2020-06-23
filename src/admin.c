/**
 * @file.admin.c
 *
 * @brief all admin functionalities of system will be handled, in this file. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */
#include "../include/admin.h"


// this will print all the selling information on a particular date
int display_selling(char* date) {
	char sql_string[500] = "";
	// store the query
	sprintf(sql_string, "select count(*) from movie join seats where movie.id = seats.movie and movie.movie_date = '%s';", date);
	//execute the qury
	mysql_query(con, sql_string);
	//fetch results
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	//fetch row from result
	MYSQL_ROW row = mysql_fetch_row(result);
	if (row) {
		printf("The total no of movie tickets sold on '%s' are %s\n", date, row[0]);
	}

	return 0;
}
// this will print all the earning information on a particular date
int total_earning(char* date) {
	char sql_string[500] = "";
	// store the query
	sprintf(sql_string, "select sum(movie.movie_price) from movie join seats where movie.id = seats.movie and movie.movie_date = '%s';", date);
	// store the query
	mysql_query(con, sql_string);
	//fetch results
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return 0;
	}
	MYSQL_ROW row = mysql_fetch_row(result);
	//fetch row from result
	if (row) {
		double d = stod(row[0]);
		//printf("%s\n",row[0]);
		printf("The total income of movie tickets sold on '%s' are %.2f\n", date, d);
	}
	return 0;
}

double stod(const char* s){
  double rez = 0, fact = 1;
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



//  wraper function for printing ticket info
void display_ticket_info_input() {
	int movie_id=-1;

		display_ticket_info(movie_id);
	
}

// displays the ticket info
void display_ticket_info(int movie_id) {
	char sql_string[500] = "";
	sprintf(sql_string, "select distinct seats.customer,seats.seatnumber,movie.id,movie.name from movie join seats where movie.id = %d;", movie_id);
	if (movie_id == -1)
		sprintf(sql_string, "select distinct seats.customer,seats.seatnumber,movie.id,movie.name from movie join seats on movie.id = seats.movie;");
	mysql_query(con, sql_string);
	MYSQL_RES* result = mysql_store_result(con);
	if (result == NULL)
	{
		printf("%s", mysql_error(con));
		return;
	}
	MYSQL_ROW row;
	printf("|%-15s|%-15s|%-10s|%-24s|\n\n", "CUSTOMER ID", "SEAT NUMBER", "MOVIE ID", "NAME");
	while (row = mysql_fetch_row(result))
	{
		printf("|%-15s|%-15s|%-10s|%-24s|\n", row[0], row[1], row[2], row[3]);
	}
}
