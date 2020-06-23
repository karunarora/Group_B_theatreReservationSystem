#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include <mysql.h>
#include "../include/login.h"
#include "../include/admin.h"
#include "../include/movie.h"
#include "../include/customer.h"
#include "../include/upcomming.h"

/* Function's declaration for initializes the connection 
This function is done by Jasvir Kaur
*/

void init_setup(char* user_name, char* password, char* url, char* database);
char tempBuffer[500];


// the main program with the menu system
int main(int argc, char** argv)
{
	init_setup("root", "karun9855", "localhost", "theatrereservationsystem");
	logout();
	char option[50] = "";
	while (strcmp(option, "e") != 0)
	{
		printf("\n\n1 for admin login\n");
		printf("2 for customer login\n");
		printf("3 for register customer\n");
		printf("e for exit\n");
		printf("Enter Your Option : ");
		scanf("%s", option);
		if (strcmp(option, "1") == 0)
		{
			admin_login_input();
			if (admin == 1)
			{
				while (strcmp(option, "o") != 0) {
					printf("\n\n1 for display selling on a date\n");
					printf("2 for display total earning on a date\n");
					printf("3 for displaying all movies\n");
					printf("4 for adding a movie\n");
					printf("5 for updating a movie\n");
					printf("6 for removing a movie\n");
					printf("7 for displaying all customer\n");
					printf("8 display ticketing info\n");
					printf("9 display upcoming movies\n");
					printf("10 add upcoming movies\n");
					printf("11 display all transaction\n");
					printf("o for exit logout\n");
					printf("Enter Your Option : ");
					scanf("%s", option);

					if (strcmp(option, "1") == 0)
					{
						if (input_date(tempBuffer) == 0)
						{
							display_selling(tempBuffer);
						}
					}
					else if (strcmp(option, "2") == 0)
					{
						if (input_date(tempBuffer) == 0)
						{
							total_earning(tempBuffer);
						}
					}
					else if (strcmp(option, "3") == 0)
					{
						display_movie();
					}
					else if (strcmp(option, "4") == 0)
					{
						add_movie_input();
					}
					else if (strcmp(option, "5") == 0)
					{
						update_movie_input();
					}
					else if (strcmp(option, "6") == 0)
					{
						remove_movie_input();
					}
					else if (strcmp(option, "7") == 0)
					{
						display_customers();
					}
					else if (strcmp(option, "8") == 0)
					{
						display_ticket_info_input();
					}
					else if (strcmp(option, "9") == 0)
					{
						display_upcommig_movie();
					}
					else if (strcmp(option, "10") == 0)
					{
						add_upcomming_movie_input();
					}else if (strcmp(option, "11") == 0)
					{
						display_transaction();
					}
					else if (strcmp(option, "o") == 0)
					{
						logout();
					}
				}
			}
		}
		else if (strcmp(option, "2") == 0)
		{
			customer_login_input();
		
			if (userid >= 1) {
				while (strcmp(option, "o") != 0) {
					printf("\n\n");
					display_customer(userid);
					printf("\n\n");
					printf("1 to update\n");
					printf("2 to list movies\n");
					printf("3 to book movies\n");
					printf("4 to add credit\n");
					printf("5 to display upcoming movies\n");
					printf("6 to display booked movies\n");
					printf("o to logout \n");
					scanf("%s", option);
					if (strcmp(option, "1") == 0)
					{
						update_customer_input();
					}
					else if (strcmp(option, "2") == 0)
					{
						display_movie();
					}
					else  if (strcmp(option, "3") == 0)
					{
						book_movie_input();
					}
					else  if (strcmp(option, "4") == 0)
					{
						add_credit_input();
					}
					else  if (strcmp(option, "5") == 0)
					{
						display_upcommig_movie();
					}
					else  if (strcmp(option, "6") == 0)
					{
						display_booked_movies(userid);
					}
					else if (strcmp(option, "o") == 0)
					{
						logout();
						break;
					}
				}
			}
		}
		else if (strcmp(option, "3") == 0) {
			add_customer_input();
			
		} 
		else if (strcmp(option, "e") == 0)
		{
			printf("Program Exit");
		}
		else
		{
			printf("Invalid Option\n");
		}
	}
	return 0;
}
/* This function setup and validate the connection with the sql database 
This function is done by Jasvir Kaur
*/

void init_setup(char* user_name, char* password, char* url, char* database) {
	strcpy(USER_NAME, user_name);
	strcpy(PASSWORD, password);
	strcpy(URL, url);
	strcpy(DATABASE, database);
	con = mysql_init(NULL);
	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(0);
	}
	if (mysql_real_connect(con, URL, USER_NAME, PASSWORD, DATABASE, 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(0);
	}
}



