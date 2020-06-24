/**
 * @file.login.h
 *
 * @brief Validations of credentials by admin and customer. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */
#ifndef _LOGIN_
#define _LOGIN_
#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
//#include <conio.h>
#include "../include/setup.h"

int userid;
int admin;

/**
*
* @brief This function takes input values for admin_login()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int admin_login_input();

/**
*
* @brief This function takes input value for customer_login()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int customer_login_input();

/**
* @fn int admin_login(char* name, char* password);
* @brief A function to take arguments from the admin to login to the system and verify credentials from the database.
*
* @param[in] char*name--- username of the admin
* @param[in] char*password--- Password provided by the admin.
*
*@description of function A function will be called when ADMIN wants to login in his account by entering his username and password.
*@return It returns adminid.
*
*/
int admin_login(char* name, char* password);

/**
*
*\fn int customer_login(char * username, char* password)
*\brief This function takes arguements from customer input function and verify credentials from db
*
*@param[in] char *username username provided by the customer
*@param[in] char *password password provided by the customer
*
*\return It returns usereid
*
*/

int customer_login(char *username, char* password);

/**
*
*\fn int logout()
*\brief This function logsout the customer and admin out of the system
*
*/
int logout();
#endif // !_LOGIN_
