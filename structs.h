#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct
{
    int day,month,year;
} date;

typedef struct
{
    char title[200];
    char author[200];
    char publisher[200];
    char ISBN[200];
    int n_copies;
    int available_copies;
    char category[200];
    date publ;
    int nob;
} book;

typedef struct
{
    int buliding;
    char city[200];
    char street[200];
} address;

typedef struct
{
    char first_name[200];
    char last_name[200];
    int ID;
    char phone_number[20];
    int age;
    char email[200];
    address adrss;
} member;


typedef struct
{
    date borrowed;
    date returned;
    date due;
    int ID;
    char ISBN[200];
} borrow;

#endif // STRUCTS_H_INCLUDED
