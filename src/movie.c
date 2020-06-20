#include "../include/movie.h"
//#include "../include/upcomming.h"

// inputs date
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


/*This function takes input from the user and pass the arguements into the add_movie() function.
This function is done by Karun Arora
*/
// aks the user to input moveie details
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

// updates the movie
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

// removes move
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

// add the movie int the datebase
int add_movie(char* movie_name, char *  type,char* movie_date, char* movie_time, float movie_price) {
	char sql_string[500] = "";
	sprintf(sql_string, "insert into movie(name,type, movie_date, movie_time,movie_price) value ('%s','%s','%s','%s',%.2f);", movie_name,type, movie_date, movie_time, movie_price);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 0;
	}
	return 0;
}


// removes moveie on id
int remove_movie(int id)
{
	char sql_string[500] = "";
	sprintf(sql_string, "delete from movie where id = %d", id);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 0;
	}
	return 0;
}

// updates the movie
int update_movie(int id, char* movie_name,char *type ,char* movie_date, char* movie_time, float movie_price)
{
	char sql_string[500] = "";
	sprintf(sql_string, "update movie set name = '%s',type='%s',movie_date ='%s',movie_time='%s',movie_price=%.2f where id = %d;", movie_name,type, movie_date, movie_time, movie_price, id);

	if (mysql_query(con, sql_string)) {
		printf("%s\n", mysql_error(con));
		return 0;
	}
	return 0;
}
