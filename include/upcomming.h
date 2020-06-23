#ifndef  _upcommig_
#define  _upcommig_
#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include "..\include\setup.h"
#include "..\include\movie.h"



int add_upcomming_movie(char *name,char *date);
int add_upcomming_movie_input();
int display_upcommig_movie();




#endif


