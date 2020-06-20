Main: src/main.c

	gcc -g -O -c src/main.c -fPIC -DPIC -o obj/main.o
	
	gcc -g -O -c src/login.c -fPIC -DPIC -o obj/login.o
	
	gcc -g -O -c src/admin.c -fPIC -DPIC -o obj/admin.o
	
	gcc -g -O -c src/customer.c -fPIC -DPIC -o obj/customer.o
	
	gcc -g -O -c src/movie.c -fPIC -DPIC -o obj/movie.o
	
	
	
	gcc -o bin/Main obj/main.o obj/login.o obj/admin.o obj/customer.o obj/movie.o libmysql.dll 

	./bin/Main
