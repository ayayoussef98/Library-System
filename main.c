#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"

int main();



book bookarray[100];
member memberarray[100];
borrow borrowarray[100];
int bookn=0,membern=0,borrown=0,i,flag=0,res;

void load_bookfiles()
{
    FILE*bf;
    bf=fopen("books.txt","r");
    if(bf != NULL)
    {
        while (!feof(bf))
        {
            fscanf(bf,"%[^,],%[^,],%[^,],%[^,],%d/%d/%d,%d,%d,%[^,],%d",bookarray[bookn].title,bookarray[bookn].author,
                   bookarray[bookn].publisher,bookarray[bookn].ISBN,
                   &bookarray[bookn].publ.day,&bookarray[bookn].publ.month,&bookarray[bookn].publ.year,
                   &bookarray[bookn].n_copies,&bookarray[bookn].available_copies,bookarray[bookn].category,&bookarray[bookn].nob);
            fscanf(bf,"\n");
            bookn++;
        }
        fclose(bf);
    }
    else printf("File Not Found");
}

void write_bookfile()
{
    FILE* bf;

    bf=fopen("books.txt","w");

    if(bf!=NULL)
    {
        for(i=0;i<bookn;i++)
    {
        fprintf(bf,"%s,%s,%s,%s,%d/%d/%d,%d,%d,%s,%d\n",bookarray[i].title,bookarray[i].author,
                bookarray[i].publisher,bookarray[i].ISBN,
                bookarray[i].publ.day,bookarray[i].publ.month,bookarray[i].publ.year,
                bookarray[i].n_copies,bookarray[i].available_copies,bookarray[i].category,bookarray[i].nob);
    }
    fclose(bf);
    }

    else  printf("\nFile not found");
}


void load_memberfiles()
{
    FILE* mf;
    mf=fopen("members.txt","r");
    if(mf != NULL)
    {
        while (!feof(mf))
        {
            fscanf(mf,"%[^,],%[^,],%d,%d,%[^,],%[^,],%[^,],%d,%[^\n] ",memberarray[membern].last_name,memberarray[membern].first_name,
                   &memberarray[membern].ID,&memberarray[membern].adrss.buliding,memberarray[membern].adrss.street,memberarray[membern].adrss.city,
                   memberarray[membern].phone_number,&memberarray[membern].age,memberarray[membern].email);

            membern++;
        }
        fclose(mf);
    }
    else printf("File Not Found");
}

void write_membersfile()
{
    FILE* mf;

    mf=fopen("members.txt","w");

    if(mf!=NULL)
    {
        for(i=0;i<membern;i++)
    {
        fprintf(mf,"%s,%s,%d,%d,%s,%s,%s,%d,%s\n",memberarray[i].last_name,memberarray[i].first_name,
                memberarray[i].ID,memberarray[i].adrss.buliding,memberarray[i].adrss.street,memberarray[i].adrss.city,
                memberarray[i].phone_number,memberarray[i].age,memberarray[i].email);
    }
    fclose(mf);
    }
  else printf("\nFile not found");
}



void load_borrowfiles()
{
    FILE*rf;
    rf=fopen("borrow.txt","r");
    if(rf!=NULL)
    {
        while(!feof(rf))
        {
            fscanf(rf,"%[^,],%d,%d/%d/%d,%d/%d/%d,%d/%d/%d ",borrowarray[borrown].ISBN,&borrowarray[borrown].ID,&borrowarray[borrown].borrowed.day,
                   &borrowarray[borrown].borrowed.month,&borrowarray[borrown].borrowed.year,
                   &borrowarray[borrown].due.day,&borrowarray[borrown].due.month,&borrowarray[borrown].due.year,
                   &borrowarray[borrown].returned.day,&borrowarray[borrown].returned.month,&borrowarray[borrown].returned.year);

            borrown++;
        }
        fclose(rf);
    }
    else printf("File Not Found");
}

void write_borrowfiles()
{
    FILE* rf;

    rf=fopen("borrow.txt","w");

    if(rf!=NULL)
    {
        for(i=0;i<borrown;i++)
    {
        fprintf(rf, "%s,%d,%d/%d/%d,%d/%d/%d,%d/%d/%d\n", borrowarray[i].ISBN,borrowarray[i].ID,borrowarray[i].borrowed.day,
                borrowarray[i].borrowed.month,borrowarray[i].borrowed.year
                ,borrowarray[i].due.day,borrowarray[i].due.month,borrowarray[i].due.year,
                borrowarray[i].returned.day,borrowarray[i].returned.month,borrowarray[i].returned.year);
    }
    fclose(rf);

    }

     else printf("\nFile not found");
}

void print_a_book (book c)
{
    printf("\n%s,", c.title);
    printf("%s,", c.author);
    printf("%s,", c.publisher);
    printf("%s,", c.ISBN);
    printf("%d,", c.n_copies);
    printf("%d,", c.available_copies);
    printf("%d,",c.nob);
    printf("%s,", c.category);
    printf("%d/%d/%d", c.publ.day,c.publ.month,c.publ.year);

}
void print_books()
{
    for(i=0; i<bookn; i++)
        print_a_book(bookarray[i]);
}

void print_members()
{
 for(i=0;i<membern;i++)
 {
     printf("\n%s,%s,%d,%d,%s,%s,%d,%d,%s",memberarray[i].last_name,memberarray[i].first_name,
                   memberarray[i].ID,memberarray[i].adrss.buliding,memberarray[i].adrss.street,memberarray[i].adrss.city,
                   memberarray[i].phone_number,memberarray[i].age,memberarray[i].email);
 }
}
void register_member()
{
    member m;
    fflush(stdin);
    printf("\nEnter first name of member:");
    scanf("%s",memberarray[membern].first_name);
    printf("\nEnter last name of member:");
    scanf("%s",memberarray[membern].last_name);
    printf("\nEnter ID of member:");
    scanf("%d",&m.ID);
    for(i=0;i<membern;i++)
        {if (m.ID==memberarray[i].ID){
           printf("\nA member with the same ID exists! \n Re-enter correct ID:");
           scanf("%s",&memberarray[i].ID);}
       }
    printf("\nEnter address of member; ");
    printf("Building:");
    scanf("%d",&memberarray[membern].adrss.buliding);
    printf("Street:");
    scanf("%s",memberarray[membern].adrss.street);
    printf("City:");
    scanf("%s",memberarray[membern].adrss.city);
    do{
        printf("\nEnter valid phone number of member:");
        scanf("%s",m.phone_number);
        }while(strlen(m.phone_number)!=11);

    printf("\nEnter age of member:");
    scanf("%d", &memberarray[membern].age);
    printf("\nEnter email of member:");
    scanf("%s",memberarray[membern].email);
    membern++;
}
void insert_book()
{
    book b;
    fflush(stdin);
    printf("Enter title:");
    gets(bookarray[bookn].title);
    printf("\nEnter author:");
    gets(bookarray[bookn].author);
    printf("\nEnter publisher:");
    gets(bookarray[bookn].publisher);
    printf("\nEnter ISBN:");
    scanf("%s",b.ISBN);
       for(i=0;i<bookn;i++)
        {res=strcmp(b.ISBN,bookarray[i].ISBN);
        if (res==0){
           printf("\nA book with the same ISBN exists! \n Re-enter correct ISBN:");
           scanf("%s",bookarray[bookn].ISBN);}}
    printf("\nEnter date of publication:");
    scanf("%d/%d/%d",&bookarray[bookn].publ.day,&bookarray[bookn].publ.month,&bookarray[bookn].publ.year);
    printf("\nEnter number of copies:");
    scanf("%d",&bookarray[bookn].n_copies);
    printf("\nEnter available number of copies: ");
    scanf("%d",&bookarray[bookn].available_copies);
    printf("\nEnter category:");
    scanf("%s",bookarray[bookn].category);
    printf("\nEnter no of borrowed times:");
    scanf("%d",&bookarray[bookn].nob);
    bookn++;
}
void add_new_copy()
    {
        book b;
        int nc;
        int k=-1;
        printf("\nEnter ISBN and no of copies");
        scanf("%s%d",b.ISBN,&nc);
        if(nc>0)
        {
            for(i=0; i<bookn; i++)
            {
                res=strcmp(b.ISBN, bookarray[i].ISBN);
                if (res==0)
                    k=i;
                else insert_book();
            }
            bookarray[k].n_copies+=nc;
            bookarray[k].available_copies+=nc;
        }
        else printf("Error");
    }

void search_ISBN()
{
    int location=-1;
    char isbn[20];
    printf("\nEnter ISBN:");
    scanf("%s",isbn);
    for(i=0;i<bookn;i++)
    {
        res=strcmp(isbn,bookarray[i].ISBN);
        if (res==0)
           {
        location=i;
        break;
    }}
    if(location==-1)
        printf("ISBN not found");
    else
        printf("Found Book:%s",bookarray[location].title);

}
void search_author()
{
    book b;
    int location;
    printf("\nEnter author:");
    scanf("%[^\n]",b.author);
    printf("\nBooks with this author:");
    for(i=0; i<bookn; i++)
    {
        res=strcasecmp(b.author,bookarray[i].author);
        if (res==0)
           {
               location=i;
       printf("%s\n",bookarray[location].title);
            }}
}

void search_category()
{
    book b; int location;
    printf("\nEnter category:");
    scanf("%[^\n]",b.category);
    printf("\nBooks in this category:");
    for(i=0;i<bookn;i++)
    {
        res=strcasecmp(b.category, bookarray[i].category);
        if (res==0)
            {location=i;
            printf("%s\n",bookarray[location].title);}
    }}

 void search_title()
    {
        int i,location=-1;
        char target[50];
        fflush(stdin);
        printf("\nEnter book title:");
        scanf("%[^\n]",target);
        for(i=0;i<bookn;i++)
        {
            res=strcasecmp(target,bookarray[i].title);
        if (res==0)
           {
        location=i;
        break;
    }}
    if(location==-1)
        printf("Book not found");
    else
        printf("Book Found");
    }

     void search_bypart()
    {
        char booktitle[50];
        int i;
        printf("\nEnter book name:");
        scanf("%s",booktitle);
        for(i=0; i<bookn; i++)
        {
            if(strstr(bookarray[i].title,booktitle))
            {
                print_a_book(bookarray[i]);
            }
            else continue;
        }
    }

    void edit()
    {
        int loc;
        book b;
        res=1;
        printf("Please enter ISBN:");
        scanf("%s",b.ISBN);
        for(i=0;i<bookn;i++)
        {
            if(strcmp(b.ISBN,bookarray[i].ISBN)==0)
            {
                res=0;
                loc=i;
            }}
        if (res==0)
              {

    printf("\nEnter new info");
    printf("\nEnter title:");
    getchar();
    gets(bookarray[loc].title);
    printf("\nEnter author:");
    gets(bookarray[loc].author);
    printf("\nEnter publisher:");
    gets(bookarray[loc].publisher);
    printf("\nEnter date of publication:");
    scanf("%d/%d/%d",&bookarray[loc].publ.day,&bookarray[loc].publ.month,&bookarray[loc].publ.year);
    printf("\nEnter number of copies:");
    scanf("%d",&bookarray[loc].n_copies);
    printf("\nEnter available number of copies: ");
    scanf("%d",&bookarray[loc].available_copies);
    printf("\nEnter category:");
    scanf("%s",bookarray[loc].category);
    printf("\nEnter no of borrowed times:");
    scanf("%d",&bookarray[loc].nob);}

    else if (res==1)
        printf("Book doesn't exist");
    }
    void search()
   { int z;
        printf("\n1]Search by title");
        printf("\n2]Search by part of title");
        printf("\n3]Search by ISBN");
        printf("\n4]Search by category");
        printf("\n5]Search by author");
        printf("\nEnter your choice:");
         scanf("%d",&z);
        if(z==1)
            search_title();
        if(z==2)
            search_bypart();
        if(z==3)
            search_ISBN();
        if(z==4)
            search_category();
        if(z==5)
            search_author();
    }


void delete_book()
    {
    char target[20];
    int k,j;
        printf("\nEnter ISBN of book to be deleted: ");
        scanf("%s",target);
        for(i=0;i<bookn;i++)
        {
            res=strcmp(bookarray[i].ISBN,target);
            if (res==0)
                k=i;
        }

        for(j=k;j<=bookn-2;j++)
          {
            bookarray[j]=bookarray[j+1];
          }
bookn--;
    }

    int noofborrow()
{
    int key;
    int counter=0;
    printf("\nRe-enter ID of borrower to continue process:");
    scanf("%d",&key);
    for(i=0; i<borrown; i++)
    {
        if(key==borrowarray[i].ID)
        {
            if(borrowarray[i].returned.day==0  && borrowarray[i].returned.month==0 && borrowarray[i].returned.year==0)
            {counter++;}
}
    }
    return counter;
}

void borrow1()
{
    int x,res2,counter;
    char b1[30];
    printf("\n Enter member ID:");
    scanf("%d",&borrowarray[borrown].ID);
    counter=noofborrow();
    if(counter<3)
    {
        printf("\nEnter ISBN:");
        scanf("%s",b1);
        strcpy(borrowarray[borrown].ISBN,b1);
        for(i=0; i<bookn; i++)
        {res2=strcmp(b1, bookarray[i].ISBN);
            if (res2==0)
                {x=i;
                break;}
        } if(res2==1)
        {printf("Not found\n");
        main();}
        bookarray[x].available_copies--;
        time_t currentTime;
        time(&currentTime);
        struct tm *myTime=localtime(&currentTime);
        printf("Enter due date: \n");
        borrowarray[borrown].borrowed.day=myTime->tm_mday;
        borrowarray[borrown].borrowed.month=myTime->tm_mon+1;
        borrowarray[borrown].borrowed.year=myTime->tm_year+1900;
        scanf("%d/%d/%d",&borrowarray[borrown].due.day,&borrowarray[borrown].due.month,&borrowarray[borrown].due.year);
        borrown++;
        bookarray[x].nob++;
    }
    else printf("Member can't borrow due to many current borrowings");
    }

int compare_dates(date due,date returned)
{
    int flag=0;
    if(due.year<returned.year)
        flag=1;
    else if(due.year>returned.year)
        flag=0;
    if(due.year==returned.year)
    {
        if(due.month<returned.month)
            flag=1;
        else if(due.month>returned.month)
            flag=0;
        else if(due.day>returned.day)
            flag=0;
        else if(due.day<returned.day)
            flag=1;
        else
            flag=0;
    }
    return flag;
}

     void overdue_books()
    {
        int i;

        printf("\nOverdue books:");
        for(i=0;i<borrown;i++)
        {
            res=compare_dates((borrowarray[i].due),(borrowarray[i].returned));
            if(res==1)
            {
                printf("\nISBN:%s\nID of borrower:%d",borrowarray[i].ISBN,borrowarray[i].ID);
            }
        }
    }

       void return_book()
    {
        int targetID,j;
        char targetISBN[20];
        printf("\nEnter ID of borrower:");
        scanf("%d",&targetID);
        printf("\nEnter ISBN:");
        scanf("%s",targetISBN);
        for(i=0;i<borrown;i++)
        {
            if(targetID==borrowarray[i].ID)
            {
             res=strcmp(targetISBN,borrowarray[i].ISBN);
              if (res==0)
            { printf("\nReturned date:");
              scanf("%d/%d/%d",&borrowarray[i].returned.day,&borrowarray[i].returned.month,&borrowarray[i].returned.year);
              for(j=0;j<bookn;j++)
              {
                if((!strcmp(targetISBN,bookarray[j].ISBN)))
                {
                    bookarray[j].available_copies++;
                    printf("%d",bookarray[j].available_copies);
                }
    }}
}}
}
void remove_member()
    {
        int key,k,j,m;
        k=0;
        printf("\nEnter ID of member to be removed:");
        scanf("%d",&key);
        for(i=0; i<borrown; i++)
        {
            if(borrowarray[i].ID==key)
            {
                if(borrowarray[i].returned.day==0  && borrowarray[i].returned.month==0 && borrowarray[i].returned.year==0)
                    printf("\nThis member cannot be removed due to unreturned books!");
                else
                {
                    for(j=0; j<membern; j++)
                    {
                        if(key==memberarray[i].ID)
                            k=i;
                        break;
                    }
                }
                for(m=k;m<=membern-2;m++)
                {
                    memberarray[m]=memberarray[m+1];
                }

            }

        }
        membern--; //assuming no duplication in members
    }


void most_popular_books()
{
    int j,l;
    book b;
    for(i=0;i<bookn;i++)
        {for(j=0;j<bookn;j++)
        {
            if(bookarray[j].nob<bookarray[j+1].nob)
            {
                b=bookarray[j];
                bookarray[j]=bookarray[j+1];
                bookarray[j+1]=b;
            }
        }
        }
    for(l=0;l<5;l++)

        printf("  %s\n",bookarray[l].title);
}

int main()
   {
       load_bookfiles();
       load_borrowfiles();
       load_memberfiles();



        int choice,z,x,y,w;
        while(1)
        {
        printf("\n\t\t\tLIBRARY SYSTEM\n");
        printf("\nMOST POPULAR BOOKS:\n");
        most_popular_books();
        printf("\n\n");
        printf("1]Book Management\n");
        printf("2]Member management \n");
        printf("3]Borrow Management\n");
        printf("4]Administrative actions\n");
        printf("5]Save changes\n");
        printf("6]Exit Without saving\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            printf("\n1]Insert new book");
            printf("\n2]Search for a book");
            printf("\n3]Add new copies");
            printf("\n4]Delete a book");
            printf("\n5]Edit a new book");
            printf("\nEnter your choice:");
            scanf("%d",&x);
            if(x==1)
                insert_book();
            if(x==2)
            search();
            if(x==3)
                add_new_copy();
            if(x==4)
                delete_book();
            if(x==5)
                edit();

            break;
        case 2:
             printf("\n1]Register a member");
              printf("\n2]Remove a member");
              printf("\nEnter your choice:");
              scanf("%d",&y);
              if(y==1)
                    register_member();
              if(y==2)
                    remove_member();
              break;

        case 3:
           printf("\n1]Borrow book");
            printf("\n2]Return book");
            printf("\nEnter your choice:");
            scanf("%d",&z);
            if(z==1)
                borrow1();
            if(z==2)
                return_book();
            break;

        case 4:
           printf("\n1]Overdue books");
            printf("\n2]Most popular books");
            printf("\nEnter your choice:");
            scanf("%d",&w);
            if(w==1)
                overdue_books();
            if(w==2)
                most_popular_books();
          break;
        case 5:
            write_membersfile();
            write_bookfile();
            write_borrowfiles();


            break;
        case 6:
            exit(0);
            break;
            }}
            return 0;
        }
