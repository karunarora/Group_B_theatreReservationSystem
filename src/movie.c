#include "../include/movie.h"
//#include "../include/upcomming.h"



/*This function takes input for the date and pass it to several function.
This function is done by Harashdeep kaur minhas
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

/*This function takes input from the user and pass the arguements into the update_movie() function.
This function is done by Karun Arora
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
	if (0)//movie_exists(movie_id) != 0)
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

/* This function takes input from user and pass it to remove_movie() function
This function is done by Karun Arora
*/
int remove_movie_input()
{
	int movie_id;
	printf("Enter Movie Id : ");
	scanf("%d", &movie_id);
	if (0)//movie_exists(movie_id) != 0)
	{
		return 0;
	}
	remove_movie(movie_id);
	return 0;
}

/* This function takes the arguements from the add_movie_input function add the movie details into the database.
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


/* This function takes arguements from the removie movie input function and make changes into database by removing movie of entered movie id
This function is done by Karun Arora
*/
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

/* This function takes the arguements form the update_movie_input function update the movie details into the database.
This function is done by Karun Arora
*/

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


/* This function display all movie listing
This function is done by Paramveer singh
*/
int display_movie() {
	mysql_query(con, "select *from movie");
	MYSQL_RES* result = mysql_store_result(con);

	if (result == NULL)
	{
		printf("E%s\n\n", mysql_error(con));
		return 0;
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
	return 1;
}