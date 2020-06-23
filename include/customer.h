#ifndef _CUSTOMER_
#define _CUSTOMER_
#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
//#include <conio.h>
#include "setup.h"
#include "login.h"
#include "movie.h"


int display_customers();
int add_customer_input();
int add_customer( char* name,char *username, char sex,char *password);
int update_customer_input();
int update_customer( int id, char* name, char sex, char *password);
int book_movie_input();
int book_movie(int customer_id, int movie_id, int seat_number);
int seat_number(int movie_id);
void display_current_customer();
int add_credit_input();

int add_credit(int id, float amount,char *number ,char *cvv,char * expdate);
int display_customer(int id);
int display_transaction();
int display_booked_movies(int id);
float stof(const char* s);

#endif // !struct_object









