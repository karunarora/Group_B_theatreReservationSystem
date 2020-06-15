#include "../headers/movie.h"



/*This function takes input from the user and pass the arguements into the add_movie() function.
This function is done by Karun Arora
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



/* This function takes the arguements form the add movie inout function add the movie details into the database.
This function is done by Karun Arora
*/
int add_movie(char* movie_name, char *  type,char* movie_date, char* movie_time, float movie_price) {
	char sql_string[500] = "";
	sprintf(sql_string, "insert into movie(name,type, movie_date, movie_time,movie_price) value ('%s','%s','%s','%s',%.2f);", movie_name,type, movie_date, movie_time, movie_price);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 0;
	}
	return 0;
}

