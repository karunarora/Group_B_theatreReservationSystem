#ifndef _LOGIN_
#define _LOGIN_
#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
//#include <conio.h>
#include "setup.h"

int userid;
int admin;


int admin_login_input();
int customer_login_input();
int admin_login(char* name, char* password);
int customer_login(char *username, char* password);
int logout();
#endif // !_LOGIN_
