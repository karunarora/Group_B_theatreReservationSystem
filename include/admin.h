/**
 * @file.admin.h
 *
 * @brief all admin functionalities of system will be handled, in this file. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */
#ifndef _ADMIN_
#define _ADMIN_

#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
//#include <conio.h>
#include "../include/setup.h"
#include "../include/movie.h"

/**
 * @brief This function is used to display total number of movie tickets sold on that paricular date.
 *
 * @param[in] date - This is of char type and is used to enter date.
 *
 * @description With help of date parameter listed above, it displays total number of tickets sold on particular date. 
 * 
 * @return int type value for functuion.
 *
 */

int display_selling(char* date);

/**
 * @brief This function is used to display total income from movie tickets sold on that paricular date.
 *
 * @param[in] date - This is of char type and is used to enter date.
 *
 * @description With help of date parameter listed above, it displays total income earned by selling movie tickets on that particular date. 
 * 
 * @return int type value for function.
 *
 */
int total_earning(char* date);

/**
 * @brief Wrapper function is being used.
 *
 * @description In this function wrapper function is used for printing ticket information. 
 * 
 * @return Return value for this function is void.
 *
 */
void display_ticket_info_input();


/**
 * @brief This function is used to display ticket information and details.
 *
 * @param[in] movie_id - This is of int type and this parameter gives away particular id to movie.
 *
 * @description By using above listed parameter, this function is used to display ticket information such as customer id, movie name and id, seat number. 
 * 
 * @return integer type value.
 *
 */
int display_ticket_info(int movie_id);


/**
 * @brief This function is used for conversion of string variable to double.
 *
 * @description With help of this function string type variable is converted to double. 
 *
 */
double stod(const char* s);
#endif // !_ADMIN_
