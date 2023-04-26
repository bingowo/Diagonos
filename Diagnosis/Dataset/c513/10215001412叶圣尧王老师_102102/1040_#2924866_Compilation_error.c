#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st 
{
    char b[3];
}

void output2(char*a,char*b)
{
        printf("%s %s ",q[0].b,q[1].b);
        if(strcmp(a,'A')==0&&strcmp(b,'A')==0)
            printf("{A,O}");
        else if(strcmp(a,'A')==0&&strcmp(b,'B')==0)
            printf("{B,O}");
        else if(strcmp(a,'A')==0&&strcmp(b,"AB")==0)
            printf("{A,AB,B}");
        else if(strcmp(a,'A')==0&&strcmp(b,'O')==0)
            printf("{A,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,'A')==0)
            printf("{B,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,'B')==0)
            printf("{B,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,"AB")==0)
            printf("{A,AB,B}");
        else if(strcmp(a,'B')==0&&strcmp(b,'O')==0)
            printf("{B,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,'A')==0)
            printf("{A,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,'B')==0)
            printf("{B,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,"AB")==0)
            printf("{A,B}");
        else if(strcmp(a,'O')==0&&strcmp(b,'O')==0)
            printf("{O}");
        else if(strcmp(a,"AB")==0&&strcmp(b,"AB")==0)
            printf("{A,B}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'A')==0)
            printf("{A,B}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'B')==0)
            printf("{A,B}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'O')==0)
            printf("{A,B}");
}
void output0(char*a,char*b)
{
        if(strcmp(a,'A')==0&&strcmp(b,'A')==0)
            printf("{A,O}");
        else if(strcmp(a,'A')==0&&strcmp(b,'B')==0)
            printf("{AB,B}");
        else if(strcmp(a,'A')==0&&strcmp(b,"AB")==0)
            printf("{AB,B}");
        else if(strcmp(a,'A')==0&&strcmp(b,'O')==0)
            printf("{A,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,'A')==0)
            printf("{AB,A}");
        else if(strcmp(a,'B')==0&&strcmp(b,'B')==0)
            printf("{AB,B,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,"AB")==0)
            printf("{A,AB}");
        else if(strcmp(a,'B')==0&&strcmp(b,'O')==0)
            printf("{A,B,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,'A')==0)
            printf("{AB,A}");
        else if(strcmp(a,'O')==0&&strcmp(b,'B')==0)
            printf("{AB,B}");
        else if(strcmp(a,'O')==0&&strcmp(b,"AB")==0)
            printf("impossible");
        else if(strcmp(a,'O')==0&&strcmp(b,'O')==0)
            printf("{A,B,O}");
        else if(strcmp(a,"AB")==0&&strcmp(b,"AB")==0)
            printf("{A,B,AB}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'A')==0)
            printf("{AB,A,B,O}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'B')==0)
            printf("{A,B,O}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'O')==0)
            printf("impossible");
        printf(" %s %s",q[1].b,q[2].b);
}
void output0(char*a,char*b)
{
        printf("%s ",q[0].b);
        if(strcmp(a,'A')==0&&strcmp(b,'A')==0)
            printf("{A,O}");
        else if(strcmp(a,'A')==0&&strcmp(b,'B')==0)
            printf("{AB,B}");
        else if(strcmp(a,'A')==0&&strcmp(b,"AB")==0)
            printf("{AB,B}");
        else if(strcmp(a,'A')==0&&strcmp(b,'O')==0)
            printf("{A,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,'A')==0)
            printf("{AB,A}");
        else if(strcmp(a,'B')==0&&strcmp(b,'B')==0)
            printf("{AB,B,O}");
        else if(strcmp(a,'B')==0&&strcmp(b,"AB")==0)
            printf("{A,AB}");
        else if(strcmp(a,'B')==0&&strcmp(b,'O')==0)
            printf("{A,B,O}");
        else if(strcmp(a,'O')==0&&strcmp(b,'A')==0)
            printf("{AB,A}");
        else if(strcmp(a,'O')==0&&strcmp(b,'B')==0)
            printf("{AB,B}");
        else if(strcmp(a,'O')==0&&strcmp(b,"AB")==0)
            printf("impossible");
        else if(strcmp(a,'O')==0&&strcmp(b,'O')==0)
            printf("{A,B,O}");
        else if(strcmp(a,"AB")==0&&strcmp(b,"AB")==0)
            printf("{A,B,AB}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'A')==0)
            printf("{AB,A,B,O}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'B')==0)
            printf("{A,B,O}");
        else if(strcmp(a,"AB")==0&&strcmp(b,'O')==0)
            printf("impossible");
        printf(" %s",q[2].b);
}

int main()
{
    struct st q[3];
    scanf("%s %s %s",q[0].b,q[1].b,q[2].b);
    for(int k=0;k<3;k++)
       if(q[k].b[0]=='?')break;
    if(k==2)output2(q[0].b,q[1].b);
    else if(k==0)output0(q[1].b,q[2].b);
    else output1(q[0].b,q[2].b);
    
}