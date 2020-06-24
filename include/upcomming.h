#ifndef  _upcommig_
#define  _upcommig_
#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include "../include/setup.h"
#include "../include/movie.h"

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

int add_upcomming_movie(char *name,char *date);

/**
*
* @brief This function takes input values for add_upcoming_movie()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int add_upcomming_movie_input();

/**
* @fn int display_upcomming_movie();
* @brief A function to to display the upcomming movies to the customers in their accounts that are updated by the admin.
*
*@description of function A function will be called ADMIN updates the upcomming movies by using his account to display it to the customers.
*
*@return It returns Value of int type.
*
*/
int display_upcommig_movie();




#endif
