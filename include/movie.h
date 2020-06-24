/**
 * @file.movie.h
 *
 * @brief all the functionalities related with addidtion, updation, remove of movies by customer and admin. 
 *
 * @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
 * @author Karun Arora - karunarora@cmail.carleton.ca
 * @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
 * @author Paramveer Singh - paramveersingh3@cmail.carleton.ca
 */
#ifndef _MOVIE_
#define _MOVIE_

#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <stdio.h>
//#include <conio.h>
#include "../include/setup.h"

/**
* @fn int input_date(char *tempBuffer);
* @brief A function to input the date of movie from the customer.
*
* @param[in] char *tempbuffer---This parameter gives the date and store it.
*
*@description of function A function will be called when CUSTOMER wants to enter the date which will be saved in tempbuffer.
*@return It will return value of int type.
*
*/
int input_date(char *tempBuffer);

/**
 * @brief This function checks whether movie exists or not.
 *
 * @param[in] movie_id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function uses above listed parameters displays the movies that movie with that particular id exists or not. 
 * 
 * @return returns int type value for this functuion.
 *
 */
int movie_exists(int movie_id);

/**
*
* @brief This function takes input values for add_movie() function.
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int add_movie_input();

/**
*
* @brief This function takes input values for update_movie() function.
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int update_movie_input();

/**
*
* @brief This function takes input values for remove_movie() function.
*
*  This function takes no parameter
*
* @return It returns int type value.
*
*/
int remove_movie_input();


int add_movie(char* movie_name, char* type, char* movie_date, char* movie_time, float movie_price);

/**
*
*\fn int display_movie()
*\brief This function takes no input value and will print list of all movies that are showcased in theatre
*
*\return It returns 0 for error and 1 for succesfully displaying movies
*
*/
int display_movie();

/**
 * @brief This function is used to remove movie from system.
 *
 * @param[in] id - This is of int type and this parameter takes particular movie id.
 *
 * @description This function uses above listed parameters to remove that movie with particular id from system. 
 * 
 * @return returns int type value for this functuion.
 *
 */
int remove_movie(int id);

/**
*
*@brief This function is used to update particular movie information and details.
*
*@param[in] int id - takes in movie id.
*@param[in] char movie_name - takes in name of that particular movie.
*@param[in] char type - takes in type or genre of movie.
*@param[in] char movie_time - takes in show timings for movie. 
*@param[in] float movie_price - takes in price for movie show.
*
*@description- using all the parameters listed above, this function is used to update movie deatails.
*
*@return returns int value for this function.
*
*/
int update_movie(int id,char* movie_name, char * type,char* movie_date, char* movie_time, float movie_price);

#endif // !_MOVIE_
