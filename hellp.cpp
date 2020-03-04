#include<stdio.h>
int main()
{
    char passwd[3]="it";
    char username[3];

    printf("username=%x,password=%x\n",&username,&passwd);

    scanf("%s",&username);
    printf("username=%s,passwd=%s\n",username,passwd);
    return 0;
}