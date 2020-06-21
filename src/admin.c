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
		printf("%s\n",row[0]);
		printf("The total income of movie tickets sold on '%s' are %.2f\n", date, d);
	}
	return 0;
}
//covert string to double
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





