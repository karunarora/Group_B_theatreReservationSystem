#ifndef _ADMIN_
#define _ADMIN_

#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
//#include <conio.h>
#include "setup.h"
#include "movie.h"

int display_selling(char* date);
int total_earning(char* date);

double stod(const char* s);
#endif // !_ADMIN_
