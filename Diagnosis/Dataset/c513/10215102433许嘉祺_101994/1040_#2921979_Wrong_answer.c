#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char a[2],b[2],c[2];
    int a1=0,b1=0,c1=0,count=0,possible[10];

    scanf("%s%s%s",a,b,c);
    if (c[0]=='?'){

        if (strcmp(a,"A")==0&&strcmp(b,"A")==0) printf("%s %s {A,O}\n",a,b);
        if (strcmp(a,"B")==0&&strcmp(b,"B")==0) printf("%s %s {B,O}\n",a,b);
        if (strcmp(a,"O")==0&&strcmp(b,"O")==0) printf("%s %s {O}\n",a,b);
        if (strcmp(a,"AB")==0&&strcmp(b,"AB")==0) printf("%s %s {A,AB,B}\n",a,b);
        if ((strcmp(a,"AB")==0&&strcmp(b,"B")==0)||(strcmp(b,"AB")==0&&strcmp(a,"B")==0) )printf("%s %s {A,AB,B}",a,b);
        if ((strcmp(a,"A")==0&&strcmp(b,"B")==0)||(strcmp(b,"A")==0&&strcmp(a,"B")==0)) printf("%s %s {A,AB,B,O}\n",a,b);
        if ((strcmp(a,"A")==0&&strcmp(b,"O")==0)||(strcmp(b,"A")==0&&strcmp(a,"O")==0)) printf("%s %s {A,O}\n",a,b);
        if ((strcmp(a,"B")==0&&strcmp(b,"O")==0)||(strcmp(b,"B")==0&&strcmp(a,"O")==0)) printf("%s %s {B,O}\n",a,b);
        if ((strcmp(a,"AB")==0&&strcmp(b,"O")==0)||(strcmp(b,"AB")==0&&strcmp(a,"O")==0)) printf("%s %s {A,B}\n",a,b);
        if ((strcmp(a,"AB")==0&&strcmp(b,"A")==0)||(strcmp(b,"AB")==0&&strcmp(a,"A")==0))printf("%s %s {A,AB,B}",a,b);
    }
    else if(a[0]=='?'){
        if (strcmp(c,"A")==0&&strcmp(b,"A")==0) printf("{A,AB,B,O} %s %s\n",b,c);
        if (strcmp(c,"B")==0&&strcmp(b,"B")==0) printf("%s %s {B,O}\n",b,c);
        if (strcmp(c,"O")==0&&strcmp(b,"O")==0) printf("{O} %s %s\n",b,c);
        if (strcmp(c,"AB")==0&&strcmp(b,"AB")==0) printf("%s %s {A,AB,B}\n",a,b);
        if ((strcmp(c,"AB")==0&&strcmp(b,"B")==0)||(strcmp(b,"AB")==0&&strcmp(c,"B")==0) )printf("%s %s {A,AB,B}",a,b);
        if ((strcmp(c,"A")==0&&strcmp(b,"B")==0)||(strcmp(b,"A")==0&&strcmp(c,"B")==0)) printf("%s %s {A,AB,B,O}\n",a,b);
        if ((strcmp(c,"A")==0&&strcmp(b,"O")==0)||(strcmp(b,"A")==0&&strcmp(c,"O")==0)) printf("%s %s {A,O}\n",a,b);
        if ((strcmp(c,"B")==0&&strcmp(b,"O")==0)||(strcmp(b,"B")==0&&strcmp(c,"O")==0)) printf("%s %s {B,O}\n",a,b);
        if ((strcmp(c,"AB")==0&&strcmp(b,"O")==0)||(strcmp(b,"AB")==0&&strcmp(a,"O")==0)) printf("%s %s {A,B}\n",a,b);
        if ((strcmp(c,"AB")==0&&strcmp(b,"A")==0)||(strcmp(b,"AB")==0&&strcmp(a,"A")==0))printf("%s %s {A,AB,B}",a,b);
    }
    else{

    }
    return 0;
}
