#ifndef _MOVIE_
#define _MOVIE_

#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
#include <conio.h>
#include "setup.h"



int add_movie_input();

int add_movie(char* movie_name, char* type, char* movie_date, char* movie_time, float movie_price);

#endif // !_MOVIE_
