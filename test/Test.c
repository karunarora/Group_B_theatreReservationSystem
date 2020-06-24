
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<mysql.h>
#include<string.h>
#include "..\include\setup.h"
#include "..\include\admin.h"
#include "..\include\customer.h"
#include "..\include\movie.h"
#include "..\include\upcomming.h"
#include "..\include\login.h"
void init_setup(char* user_name, char* password, char* url, char* database);


#define ASSERT_TEST(x)                        \
{                                         \
    if (x)                                \
    {                                     \
        fprintf(fp,"\n\nPASSED\n\n\n");               \
    }                                     \
    else                                  \
    {                                     \
        fprintf(fp,"\n\nFAILED\n\n\n"); \
    }                                     \
}


void init_setup(char* user_name, char* password, char* url, char* database) {
	strcpy(USER_NAME, user_name);
	strcpy(PASSWORD, password);
	strcpy(URL, url);
	strcpy(DATABASE, database);
	con = mysql_init(NULL);
	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(0);
	}
	if (mysql_real_connect(con, URL, USER_NAME, PASSWORD, DATABASE, 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(0);
	}
}





int main(int argc, char** argv)
{
	init_setup("root", "karun9855", "localhost", "theatrereservationsystem");
	FILE *fp = fopen("./test/testresults.txt","w");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
    }
	 else
    {
        fprintf(fp,"*********************************TEST Case 1 for Admin Login**********************************************\n");
        fprintf(fp,"***********************************TEST 1A*****************************************************\n");
        fprintf(fp,"We are first going to login using correct credentials for Admin i.e. Userid=admin and password=admin\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(admin_login("admin", "admin")==0);
		
		fprintf(fp,"*********************************TEST Case 2 for Admin Login**********************************************\n");
        fprintf(fp,"***********************************TEST 1B*****************************************************\n");
        fprintf(fp,"We are first going to login using wrong credentials for Admin i.e. Userid=admin and password=123\n");
        fprintf(fp,"Expected result is it should return -1\n ");
        ASSERT_TEST(admin_login("admin", "123")==-1);
		
		fprintf(fp,"*********************************TEST Case 3 for Customer Login**********************************************\n");
        fprintf(fp,"***********************************TEST 1C*****************************************************\n");
        fprintf(fp,"We are first going to login using correct credentials for Customer named karun i.e. Username=karun and password=karun\n");
        fprintf(fp,"Expected result is it should return userid that is 1 for karun\n ");
        ASSERT_TEST(customer_login("Karun", "karun")==1);
		
		fprintf(fp,"*********************************TEST Case 4 for Customer Login**********************************************\n");
        fprintf(fp,"***********************************TEST 1D*****************************************************\n");
        fprintf(fp,"We are first going to login using wrong credentials for Customer named karun i.e. Username=karun and password=123\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(admin_login("karun", "123")==-1);
       
	    fprintf(fp,"*********************************TEST Case 5 for Logout**********************************************\n");
        fprintf(fp,"***********************************TEST 1E*****************************************************\n");
        fprintf(fp,"we are running the logout function \n");
        fprintf(fp,"Expected result is it should return 0 in case of correctly run\n ");
        ASSERT_TEST(logout()==0);
		
		fprintf(fp,"*********************************TEST Case 6 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 2A*****************************************************\n");
        fprintf(fp,"Display selling on particular date i.e 2020/6/15\n");
        fprintf(fp,"Expected result is it should return 0 and display how much earned on that date\n ");
        ASSERT_TEST(display_selling("2020/6/15")==0);
		
		fprintf(fp,"*********************************TEST Case 7 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 2B*****************************************************\n");
        fprintf(fp,"Display selling with wrong date\n");
        fprintf(fp,"Expected result is it should return 1 and display invalid date message\n ");
        ASSERT_TEST(display_selling("5/6/35")==1);
		
		fprintf(fp,"*********************************TEST Case 8 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 2C*****************************************************\n");
        fprintf(fp,"total earning on particluar date, passing right date\n");
        fprintf(fp,"Expected result is it should return 0 and display total earning\n ");
        ASSERT_TEST(total_earning("2020/6/15")==0);
		
		fprintf(fp,"*********************************TEST Case 9 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 2D*****************************************************\n");
        fprintf(fp,"total earning on particluar date, passing wrong date\n");
        fprintf(fp,"Expected result is it should return 1 and invalid date message\n ");
        ASSERT_TEST(total_earning("4/6/35")==1);
		
		fprintf(fp,"*********************************TEST Case 10 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 2E*****************************************************\n");
        fprintf(fp,"passing -1 will display all the tickets purchased by all the users\n");
        fprintf(fp,"Expected result is it should return 0 and display table of tickets purchased by users\n ");
        ASSERT_TEST(display_ticket_info(-1)==0);
		
		
		fprintf(fp,"*********************************TEST Case 11 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3A*****************************************************\n");
        fprintf(fp,"display customer\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(display_customers()==0);
		
		fprintf(fp,"*********************************TEST Case 12 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3B*****************************************************\n");
        fprintf(fp,"display customer\n");
        fprintf(fp,"Expected result is it should return 1 in case of error\n ");
        ASSERT_TEST(display_customers()==1);
		
		fprintf(fp,"*********************************TEST Case 13 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3C*****************************************************\n");
        fprintf(fp,"username_exists passing existing username\n");
        fprintf(fp,"Expected result is it should return 0 and display that user already exsist\n ");
        ASSERT_TEST(username_exists("karun")==0);
		
		fprintf(fp,"*********************************TEST Case 14 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3D*****************************************************\n");
        fprintf(fp,"username_exists passing new username\n");
        fprintf(fp,"Expected result is it should return 1\n ");
        ASSERT_TEST(username_exists("arsh")==1);
		
		fprintf(fp,"*********************************TEST Case 15 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3E*****************************************************\n");
        fprintf(fp,"add_customer passing right values\n");
        fprintf(fp,"Expected result is it should return 0 and will registeruser\n ");
        ASSERT_TEST(add_customer("tom sin", "tom sin", 'm', "tom111")==0);
		
		fprintf(fp,"*********************************TEST Case 16 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3F*****************************************************\n");
        fprintf(fp,"add_customer passing wrong values, username more than 24 chararcters\n");
        fprintf(fp,"Expected result is it should return 1 and will display error message that data is too long for column username\n ");
        ASSERT_TEST(add_customer("tom sin", "tom sinhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh", 'm', "tom111")==1);
		
		fprintf(fp,"*********************************TEST Case 17 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3A*****************************************************\n");
        fprintf(fp,"add_customer passing wrong values, password more than 24 chararcters\n");
        fprintf(fp,"Expected result is it should return 1 and will display error message that data is too long for column password\n ");
        ASSERT_TEST(add_customer("tom sin2", "tom sin2", 'm', "tom111111111111111111111111111")==1);
		
		fprintf(fp,"*********************************TEST Case 18 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3A*****************************************************\n");
        fprintf(fp,"add_customer passing wrong values, already exsistsing user\n");
        fprintf(fp,"Expected result is it should return 1 and will display error message that username already exsist e0\n ");
        ASSERT_TEST(add_customer("tom sin", "tom sin", 'k', "tom111")==1);
		
		
		fprintf(fp,"*********************************TEST Case 19 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3A*****************************************************\n");
        fprintf(fp,"update_customer passing right values\n");
        fprintf(fp,"Expected result is it should return 0 and will update user\n ");
        ASSERT_TEST(update_customer(12, "tom sinha", 'f', "tom1111")==0);
		
		fprintf(fp,"*********************************TEST Case 20 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3A*****************************************************\n");
        fprintf(fp,"update_customer passing wrong values, name more than 24 chararcters\n");
        fprintf(fp,"Expected result is it should return 1 and will display error message that data is too long for column name\n ");
        ASSERT_TEST(update_customer(12, "tom sinhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh", 'm', "tom111")==1);
		
		fprintf(fp,"*********************************TEST Case 21 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3A*****************************************************\n");
        fprintf(fp,"update_customer passing wrong values, name more than 24 chararcters\n");
        fprintf(fp,"Expected result is it should return 1 and will display error message that data is too long for column password\n");
        ASSERT_TEST(update_customer(12, "tom sin2", 'm', "tom111111111111111111111111111")==1);
		
		fprintf(fp,"*********************************TEST Case 22 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 3A*****************************************************\n");
      fprintf(fp,"update_customer passing wrong values, sex more  chararcters\n");
        fprintf(fp,"Expected result is it should return 1 and will display error message that data is too long for column sex\n");
        ASSERT_TEST(update_customer(12, "tom sin", 'kkkkllklklljl', "tom111")==0);
		
		fprintf(fp,"*********************************TEST Case 23 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"add_movie\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(add_movie("john wick 1","Drama", "2020/5/19", "20:00", 15)==0);
		
		fprintf(fp,"*********************************TEST Case 24 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"add_movie\n");
        fprintf(fp,"Expected result is it should return 1\n ");
        ASSERT_TEST(add_movie("john wickkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk","Drama", "2020/5/19", "20:00", 20)==1);
		
		
		fprintf(fp,"*********************************TEST Case 25 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"update_movie\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(update_movie(3, "Pasafic rim","Action", "2020/8/20", "3:00", 22)==0);
		
		fprintf(fp,"*********************************TEST Case 26 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"update_movie\n");
        fprintf(fp,"Expected result is it should return 1 display error message data too long\n ");
        ASSERT_TEST(update_movie(3, "Pasafic rim","Actionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn", "2020/8/20", "3:00", 22)==1);
		
		fprintf(fp,"*********************************TEST Case 27 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"remove_movie\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(remove_movie(1)==0);
		
		fprintf(fp,"*********************************TEST Case 28 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"remove_movie with wrong movie id\n");
        fprintf(fp,"Expected result is it should return 1 error message display\n ");
        ASSERT_TEST(remove_movie(35)==1);
		
		
		fprintf(fp,"*********************************TEST Case 29 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"movie_exists right value\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(movie_exists(2)==0);
		
		fprintf(fp,"*********************************TEST Case 30 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"movie_exists right value\n");
        fprintf(fp,"Expected result is it should return 1\n ");
        ASSERT_TEST(movie_exists(35)==1);
		
		fprintf(fp,"*********************************TEST Case 31 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"display_movie right value\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(display_movie()==0);
		
		fprintf(fp,"*********************************TEST Case 33 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"display_movie in case of any error\n");
        fprintf(fp,"Expected result is it should return 1\n ");
        ASSERT_TEST(display_movie()==1);
		
		
		
		fprintf(fp,"*********************************TEST Case 34 for book_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are first going to login using correct data i.e. userid=22, movieid=2, seatnumber=37\n");
        fprintf(fp,"Expected result is it should return 0 and will print that movie booked\n ");
        ASSERT_TEST(book_movie(2, 2, 37)==0);
		
		fprintf(fp,"*********************************TEST Case 35 for book_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"next we gave the same input as before i.e. userid=22, movieid=2, seatnumber=37 \n");
        fprintf(fp,"Expected result is it should return 1 and it will print seat already occupied\n ");
        ASSERT_TEST(book_movie(2, 2, 37)==1);
		
		fprintf(fp,"*********************************TEST Case 36 for book_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"Now we are giving out of range seat number i.e. userid=1, movieid=1, seatnumber=55 \n");
        fprintf(fp,"Expected result is it should return 1 and will print invalid seat number\n ");
        ASSERT_TEST(book_movie(1, 1, 55)==1);
		
		fprintf(fp,"*********************************TEST Case 37 for book_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"The user with id=5 does not have balance\n");
        fprintf(fp,"Expected result is it should return 1 and it will print not enough credit\n ");
        ASSERT_TEST(book_movie(5, 5, 37)==1);
		
		
		fprintf(fp,"*********************************TEST Case 39 for book_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are Giving wrong input for movie id i.e. movieId=25 which does not exists\n");
        fprintf(fp,"Expected result is it should return 1 and it will print no movie exists\n ");
        ASSERT_TEST(book_movie(1, 25, 5)==1);
		
		
		
		fprintf(fp,"*********************************TEST Case 40 for seat_number**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are Giving right input for movie id i.e. movieId=2 \n");
        fprintf(fp,"Expected result is it should return 0 \n ");
        ASSERT_TEST(seat_number(2)==0);
		
		fprintf(fp,"*********************************TEST Case 41 for seat_number**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are Giving wrong input for movie id i.e. movieId=25 which does not exists\n");
        fprintf(fp,"Expected result is it should return 1 and it will print no movie exists\n ");
        ASSERT_TEST(seat_number(25)==1);
		
		
		
		
		fprintf(fp,"*********************************TEST Case 42 for add_credit**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are Giving right input to add credit\n");
        fprintf(fp,"Expected result is it should return 0 and it will add credit to users account ");
        ASSERT_TEST(add_credit(1,500,"5478547854785478","545" ,"2020/5/5")==0);
		
		fprintf(fp,"*********************************TEST Case 43 for add_credit**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are Giving wrong input credit card number\n");
        fprintf(fp,"Expected result is it should return 1 and will not add credit to db\n ");
        ASSERT_TEST(add_credit(1,500,"5478547854","545" ,"20202/5/5")==1);
		
		fprintf(fp,"*********************************TEST Case 44 for add_credit**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
       fprintf(fp,"We are Giving wrong input credit card number\n");
        fprintf(fp,"Expected result is it should return 1 and will not add credit to db\n ");
        ASSERT_TEST(add_credit(1,500,"54785478547854788888888888888888888888888888888","545" ,"2020/5/5")==1);
		
		
		
		fprintf(fp,"*********************************TEST Case 45 for add_credit**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
       fprintf(fp,"We are Giving wrong input cvv number\n");
        fprintf(fp,"Expected result is it should return 1 and will not add credit to db\n ");
        ASSERT_TEST(add_credit(1,500,"5478547854785478","54" ,"2020/5/5")==1);
		
		fprintf(fp,"*********************************TEST Case 46 for add_credit**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are Giving wrong input cvv number\n");
        fprintf(fp,"Expected result is it should return 1 and will not add credit to db\n ");
        ASSERT_TEST(add_credit(1,500,"5478547854785478","5455" ,"2020/5/5")==1);
		
		
		fprintf(fp,"*********************************TEST Case 47 for add_credit**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"We are Giving wrong input cfor date\n");
        fprintf(fp,"Expected result is it should return 1 and will not add credit to db error message diplay invalid date\n ");
        ASSERT_TEST(add_credit(1,500,"5478547854785478","5455" ,"20202/5/55")==1);
		
		
		fprintf(fp,"*********************************TEST Case 48 for Display Selling**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"display_transaction()\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(display_transaction()==0);
		
		
		fprintf(fp,"*********************************TEST Case 49 for display_booked_movies**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"display_booked_movies\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(display_booked_movies(2)==0);
		
		
		fprintf(fp,"*********************************TEST Case 50 for add_upcomming_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"add_upcomming_movie\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(add_upcomming_movie("Mulan","2020/10/5")==0);
		
		
		fprintf(fp,"*********************************TEST Case 51 for add_upcomming_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"add_upcomming_movie with wrong date\n");
        fprintf(fp,"Expected result is it should return 1 and it will print invalid date\n ");
        ASSERT_TEST(add_upcomming_movie("Mulan3","20202/10/5")==1);
		
		
		
		fprintf(fp,"*********************************TEST Case 52 for display_upcommig_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"display_upcommig_movie()\n");
        fprintf(fp,"Expected result is it should return 0\n ");
        ASSERT_TEST(display_upcommig_movie()==0);
		
		fprintf(fp,"*********************************TEST Case 53 for display_upcommig_movie**********************************************\n");
        fprintf(fp,"***********************************TEST 4A*****************************************************\n");
        fprintf(fp,"display_upcommig_movie() in case of error\n");
        fprintf(fp,"Expected result is it should return 1 \n ");
        ASSERT_TEST(display_upcommig_movie()==1);
		
		
		
		
}
}
