#include "../headers/admin.h"



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
		double d = atof(row[0]);
		printf("The total income of movie tickets sold on '%s' are %.2f\n", date, d);
	}
	return 0;
}
