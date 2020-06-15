#ifndef _LOGIN_
#define _LOGIN_
#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
#include <conio.h>
#include "setup.h"

int userid;




int customer_login_input();

int customer_login(char *username, char* password);

#endif // !_LOGIN_
