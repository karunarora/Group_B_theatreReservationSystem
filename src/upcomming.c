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



int display_upcommig_movie()
{
	mysql_query(con, "select *from upcommingmovie");
	MYSQL_RES* result = mysql_store_result(con);

	if (result == NULL)
	{
		printf("E%s\n\n", mysql_error(con));
		return 0;
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	printf("***************************************UPCOMMING MOVIES*****************************************\n");
	printf("|%-4s", "ID");
	printf("|");
	printf("%-24s", "NAME");
	printf("|");
	printf("%-10s", "DATE");
	printf("|");
	printf("\n\n");
	while ((row = mysql_fetch_row(result)))
	{
		printf("|%-4s", row[0] ? row[0] : "NULL");
		printf("|");
		printf("%-24s", row[1] ? row[1] : "NULL");
		printf("|");
		printf("%-5s", row[2] ? row[2] : "NULL");
		printf("|\n");
	}
	mysql_free_result(result);
	return 1;
    return 0;
}
