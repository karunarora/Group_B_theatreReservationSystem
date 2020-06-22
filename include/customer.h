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
void display_current_customer();
int display_customer(int id);

float stof(const char* s);

#endif // !struct_object









