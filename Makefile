	
# ------------------------------------------------
# Generic Makefile
#  @author Karun Arora - karunarora@cmail.carleton.ca
#  @author Jasvir Kaur - jasvirkaur@cmail.carleton.ca
#  @author Harashdeep Kaur Minhas - harashdeepkaurminhas@cmail.carleton.ca
#  @author Paramveer Singh - paramveersingh3@cmail.carleton.ca

# Date  : 2020-06-01
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = theatre_reservation_system

# change these to proper directories where each file should be


SRCDIR     	 = src
SRCTESTDIR	 = test
OBJDIR    	 = obj
BINDIR    	 = bin
INCDIR	  	 = include

CC       = gcc
INC      := -I$(INCDIR)
#starting of compilation of all source files...........
theatre_reservation_system:
	
	$(CC) -g -O -c $(SRCDIR)/main.c -fPIC -DPIC -o $(OBJDIR)/main.o

	$(CC) -g -O -c $(SRCDIR)/login.c -fPIC -DPIC -o $(OBJDIR)/login.o
	
	$(CC) -g -O -c $(SRCDIR)/admin.c -fPIC -DPIC -o $(OBJDIR)/admin.o
	
	$(CC) -g -O -c $(SRCDIR)/customer.c -fPIC -DPIC -o $(OBJDIR)/customer.o
	
	$(CC) -g -O -c $(SRCDIR)/movie.c -fPIC -DPIC -o $(OBJDIR)/movie.o

	$(CC) -g -O -c $(SRCDIR)/upcomming.c -fPIC -DPIC -o $(OBJDIR)/upcomming.o
	
#	$(CC) -g -O -c $(SRCTESTDIR)/test.c -fPIC -DPIC -o $(OBJDIR)/objtest/test.o
	

	
#	$(CC) -o $(BINDIR)/$(TARGET) $(OBJDIR)/*.o libmysql.dll
	
	$(CC) -o bin/theatre_reservation_system $(OBJDIR)/main.o $(OBJDIR)/login.o $(OBJDIR)/admin.o $(OBJDIR)/customer.o $(OBJDIR)/movie.o $(OBJDIR)/upcomming.o libmysql.dll
	


	@echo "Now you can run theatre_reservation_system file from bin directory by using following command"
	@echo "bin/./theatre_reservation_system"
#	@echo "bin/./test"
.PHONY: clean
clean:
	@$(rm) $(BINDIR)/$(TARGET)
	@$(rm) theatre_reservation_system.txt
	@echo "Cleanup complete!"
