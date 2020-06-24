/**
 * @file.customer.h
 *
 * @brief all customer functionalities of system will be handled, in this file. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */

#ifndef _CUSTOMER_
#define _CUSTOMER_
#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
//#include <conio.h>
#include "../include/setup.h"
#include "../include/login.h"
#include "../include/movie.h"

/**
*
* @brief This function display all customers.
*
* This function takes no parameter
*
* @return It returns int type value.
*
*/

int display_customers();

/**
*
* @brief This function takes input value for add_customer_input()
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/

int add_customer_input();


/**
*
*\fn int add_customer( char* name,char *username, char sex,char *password)
*@brief This function takes name, balance, sex, password as its input parameters for signing up
new customer
*
*@param[in] char *name name provided by customer
*@param[in] char *username username provided by the customer
*@param[in] char *sex sex provided by the customer
*@param[in] char *password password provided by the customer
*
*@return It returns 0 for succesfully adding customer and 1 for error
*
*/
int add_customer( char* name,char *username, char sex,char *password);


int update_customer_input();


/**
* @brief A function to update the personal data (name, login, password, gender) of a customer in Database who is already logged in.
*
* @param[in] id –--This parameter gives the customer id (unique in nature).
* @param[in] name--- This parameter returns the name of the customer. This is of varchar type of length 28
* @param[in] password--- This gives the password.This is of varchar type of length 8
* @param[in] sex--- Gives the gender of the customer which is of character type
*
*@description of function A function will be called when CUSTOMER wants to update his/her *username, password, and gender by entering 1 in his portal which will call the update function.
*
*@return int type value
*
*/
int update_customer( int id, char* name, char sex, char *password);

/**
*
* @brief This function takes input value for book_movie
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int book_movie_input();

/**
* @brief A function to book movie.
*
* @param[in] customer_id –--This parameter gives the customer id (unique in nature).
* @param[in]  movie_id--- This parameter gives movie id for particular movie
* @param[in] seat_number-- This is of int type and gives away seat number.
*
*@description This function takes in customer and movie id, seat number to book movie.
*
*@return int type value.
*
*/
int book_movie(int customer_id, int movie_id, int seat_number);

/**
 * @brief This function is used to check seats booked.
 *
 * @param[in] movie_id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function check the seats that has been booked for movie with that particular movie id. 
 * 
 * @return returns int type value for this functuion.
 *
 */
int seat_number(int movie_id);

/**
 * @brief This function is of void type and used to display current customer details.
 *
 * takes no parameters.
 *
 * @description This function diaplays the details of current logged in customer in system . 
 * 
 * @return No return value for this functuion.
 *
 */
void display_current_customer();

/**
*
* @brief This function takes input value for add_credit function. 
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int add_credit_input();

/**
*
*@brief This function is used to add credit to customers account balance.
*
*@param[in] int id - this takes integer type value for customer id.
*@param[in] float amount - amount customer wanted to add to his account.
*@param[in] number - it is of int type and takes in credit card number.
*@param[in] cvv - takes in cvv number for authentication purposes.
*@param[in] expdate - takes in expiry date for card.
*
*\return It returns integer type value.
*
*/
int add_credit(int id, float amount,char *number ,char *cvv,char * expdate);


/**
*
*\fn int display_customer(int id)
*@parameter id - takes in customer id.
*@brief This function takes customer id as input and will print the details of the customer 
*
*@return It returns 0 in case of error and 1 for successful query
*
*/
int display_customer(int id);

/**
 * @brief This function is of int type and used to display tansactions to customers.
 *
 * takes no parameters.
 *
 * @description This function displays all the transaction of customer account to customer. 
 * 
 * @return No return value for this function.
 *
 */
int display_transaction();


/**
 * @brief This function displays movies that has been booked.
 *
 * @param[in] id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function uses above listed parameters displays the movies that has been booked. 
 * 
 * @return returns int type value for this functuion.
 *
 */
int display_booked_movies(int id);



float stof(const char* s);

#endif // !struct_object
