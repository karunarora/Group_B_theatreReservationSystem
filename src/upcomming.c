#include "..\include\upcomming.h"

int add_upcomming_movie(char* name, char* date)
{
    char sql_string[500] = "";
    sprintf(sql_string, "insert into upcommingmovie(name, movie_date) value ('%s','%s');",name,date);

    if (mysql_query(con, sql_string)) {
        printf("%s\n", mysql_error(con));
        return 0;
    }
    return 0;
}

int add_upcomming_movie_input()
{
    char name[50];
    char date[50];
    printf("Enter Movie Name : ");		
	scanf("%*c%[^\n]%*c", name);
	printf("Enter Release date\n");
    if(input_date(date)==0)
    add_upcomming_movie(name,date);
    return 0;
}
