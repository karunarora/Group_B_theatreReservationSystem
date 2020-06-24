#include "..\include\upcomming.h"
/**
* @fn int add_upcomming_movie(char *name,char *date);
* @brief A function to take arguments by the admin to add the upcoming movies in the system.
*
* @param[in] char*name--- Name of the Movie which is of character type
* @param[in] char*date--- date on which movie is going to display in the theatre and the argument is of character type.
*
* @description of function A function will be called when ADMIN adds the upcomming movies by loggedin in his account which will be displayed to the customers.
*
* @return It returns the value of int type.
*/
int add_upcomming_movie(char* name, char* date)
{
    char sql_string[500] = "";
    sprintf(sql_string, "insert into upcommingmovie(name, movie_date) value ('%s','%s');",name,date);

    if (mysql_query(con, sql_string)) {
        printf("%s\n", mysql_error(con));
        return 1;
    }
    return 0;
}
/**
*
* @brief This function takes input values for add_upcoming_movie()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
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
/**
* @fn int display_upcomming_movie();
* @brief A function to to display the upcomming movies to the customers in their accounts that are updated by the admin.
*
*@description of function A function will be called ADMIN updates the upcomming movies by using his account to display it to the customers.
*
*@return It returns Value of int type.
*
*/
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
