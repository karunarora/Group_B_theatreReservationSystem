/**
 * @file.setup.h
 *
 * @brief MYSQL* connection establishment. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */
#ifndef SETUP
#define SETUP
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include <mysql.h>

/** 
* takes in user_name, password, url , database of char type to establish MYSQL*connection
*/
char USER_NAME[100];
char PASSWORD[100];
char URL[100];
char DATABASE[100];
MYSQL* con;
#endif