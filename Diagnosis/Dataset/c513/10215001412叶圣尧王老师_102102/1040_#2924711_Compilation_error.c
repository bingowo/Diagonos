#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st 
{
    char b[3];
}

void output(char*a,char*b,int k)
{
    if(k==2)
    {
        printf("%s %s ")
        if(strcmp(a,'A')==0&&strcmp(b,'A')==0)
            printf("{A,O}");
        else if(strcmp(a,'A')==0&&strcmp(b,'B')==0)
            printf("{B,O}");
        else if(strcmp(a,'A')==0&&strcmp(b,'AB')==0)
            printf("{A,AB,B}");
        else if(strcmp(a,'A')==0&&strcmp(b,'O')==0)
            printf("{A,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,'A')==0)
            printf("{B,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,'B')==0)
            printf("{B,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,'AB')==0)
            printf("{A,AB,B}");
        else if(strcmp(a,'B')==0&&strcmp(b,'O')==0)
            printf("{B,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,'A')==0)
            printf("{A,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,'B')==0)
            printf("{B,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,'AB')==0)
            printf("{A,B}");
    }
}

int main()
{
    struct st q[3];
    scanf("%s %s %s",q[0].b,q[1].b,q[2].b);
    for(int k=0;k<3;k++)
       if(q[k].b[0]=='?')break;
    
    
}