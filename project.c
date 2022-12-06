#include <stdio.h>  //project login system
#include<conio.h>
#include<windows.h>221
2
#include <stdlib.h>
#define Enter 13
#define TAB 9
#define BKSPC 8

struct user{
        char fullName[50];
        char email[50];
        char password[50];
        char username[50];
        char phone[50];
};

void takeinput(char ch[50]){
        fgets(ch,50,stdin);
        ch[strlen(ch) - 1] = 0;
}

char generateUsername(char email[50],char username[50]){
     //tasrifnurhimel@gmail.com
     for(int i=0; i<strlen(email); i++ )
     {
         if(email[i] == '@') break;
         else username[i] = email[i];
     }
}
void takepassword(char pwd[50]){

int i;
char ch;
while(1)
{
    ch = getch();
    if(ch == Enter || ch == TAB)
    {
        pwd[i] = '\0';
        break;
    }
    else if(ch == BKSPC)
    {
        if(i>0)
        {
            i--;
            printf("\b \b");
        }
    }
    else{
        pwd[i++] = ch;
        printf("* \b");
    }
}
}

int main()
{
    system("color 0a");
    FILE *fp;
    int opt,usrFound = 0;
    struct user user;
    char password2[50];
    //char username[50],pword[50];
    //struct user usr;

    printf("\n\t\t\t\t----------Welcome to authentication system----------");
    printf("\n Please choose your operation");
    printf("\n 1. Singup");
    printf("\n 2. Login");
    printf("\n 3. Exit");

    printf("\n\n Your choice: \t");
    scanf("%d",&opt);
    printf("\n");
    fgetc(stdin);

    switch(opt)
    {
    case 1:
        system("cls");
        printf(" Enter your full name: \t");
        takeinput(user.fullName);
        printf("\n");
        printf(" Enter your email:  \t");
        takeinput(user.email);
        printf("\n");
        printf(" Enter your contact number:\t");
        takeinput(user.phone);
        printf("\n");
        printf(" Enter your password: \t");
        takepassword(user.password);
        printf(" %s ",user.password);  //eta project er somoy dekhaba
        printf("\n");
        printf(" Confirm your password: ");
        takepassword(password2);
        printf("\n");
        if(!strcmp(user.password,password2))
        {
            printf(" Your password matched!!!\n");
            generateUsername(user.email,user.username);
            //printf("\n Your username is %s",user.username);
            fp = fopen("Users.dat","a+");
            fwrite(&user,sizeof(struct user),1,fp);
            if(fwrite != 0)
            {
                printf("\n User registration is success!\n \nYour user name is: %s",user.username);
            }
            else
            {
                printf("\n Sorry! Something went wrong.");
            }
            fclose(fp);
        }
        else{
            printf("XXX---Your password doesn't matched!!!---XXX\n");
            Beep(750,300);
        }
        break;
    case 2:
    	system("cls");
        char username[50],pword[50];
        struct user usr;

        printf(" Enter your username:\t");
        takeinput(username);
        printf(" Enter your password:\t");
        takepassword(pword);
        system("cls");

        fp = fopen("Users.dat","r");
        while(fread(&usr,sizeof(struct user),1,fp))
        {
            if(!strcmp(usr.username,username))
            {
                if(!strcasecmp(usr.password,pword))
                {
                    printf("\n\t\t\t\t*-----WELCOME %s-----*",usr.fullName);
                    printf("\n\n| Full Name: \t%s",usr.fullName);
                    printf("\n\n| Email: \t%s",usr.email);
                    printf("\n\n| Username: \t%s",usr.username);
                    printf("\n\n| Contact no: \t%s",usr.phone);
                }
                else
                {
                    printf("\n\nInvalid Password!");
                    Beep(800,300);
                }
                usrFound = 1;
            }
        }
        if(!usrFound)
        {
            printf("\n\nUser is not registered!\n");
            Beep(800,300);
        }
        fclose(fp);
        break;
    case 3:
    	system("cls");
        printf("\t\tBYE BYE!! :)");
        return 0;
    }

    return 0;
}
