drop database if exists TheatreReservationSystem;
create database TheatreReservationSystem;
use TheatreReservationSystem;
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'theone';
create table admin(
    name varchar(24),
    password varchar(24)
);
create table customer(
    id int auto_increment primary key ,
    username varchar(24),
    name varchar(24),
    sex char,
    balance double default 0,
    password varchar(8)
);

create table movie(
    id int auto_increment primary key,
    name varchar(25),
    type varchar(25),
    movie_date date,
    movie_time time,
    movie_price float
);

create table upcommingmovie(
    id int auto_increment primary key,
    name varchar(25),
    movie_date date
);

create table seats(
    seatNumber int,
    movie int,
    customer int
);

create table creditcard(
    id int,
    amount float,
    cardnumber varchar(20),
    csv varchar(10),
    expdate date,
    transedate date
);

insert into admin value ('admin','admin');






