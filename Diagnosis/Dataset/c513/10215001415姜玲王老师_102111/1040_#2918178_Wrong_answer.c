#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int read()
{char a[3];
scanf("%s",a);
if(!strcmp(a,"?")) return 0;
if(!strcmp(a,"A")) return 1;
if(!strcmp(a,"AB")) return 2;
if(!strcmp(a,"B")) return 3;
if(!strcmp(a,"O")) return 4;
}
void print1(int a,int b,int c)
{if(a==1) printf("A ");
 if(a==2) printf("AB ");
 if(a==3) printf("B ");
 if(a==4) printf("O ");
 if(a==0) find1(b,c);
}
void find1(int a,int b)
{if(a==1&&b==1) printf("{A,O} ");
if(a==1&&b==2) printf("{B} ");
if(a==1&&b==3) printf("{B} ");
if(a==1&&b==4) printf("{A,B,O} ");
if(a==2&&b==1) printf("{A,AB,B,O} ");
if(a==2&&b==2) printf("{A,AB,B} ");
if(a==2&&b==3) printf("{A,AB,B,O} ");
if(a==2&&b==4) printf("impossible ");
if(a==3&&b==1) printf("{A,AB} ");
if(a==3&&b==2) printf("{A,AB} ");
if(a==3&&b==3) printf("{A,AB,B,O} ");
if(a==3&&b==4) printf("{A,B,O} ");
if(a==4&&b==1) printf("{A,AB} ");
if(a==4&&b==2) printf("impossible ");
if(a==4&&b==3) printf("{AB,B} ");
if(a==4&&b==4) printf("{A,B,O} ");
}

void print2(int a,int b,int c)
{if(a==1) printf("A ");
 if(a==2) printf("AB ");
 if(a==3) printf("B ");
 if(a==4) printf("O ");
 if(a==0) find2(b,c);
}
void find2(int a,int b)
{if(a==1&&b==1) printf("{A,O}");
if(a==1&&b==2) printf("{A,AB}");
if(a==1&&b==3) printf("{A,AB,B,O} ");
if(a==1&&b==4) printf("{A,O} ");
if(a==2&&b==1) printf("{A,AB}");
if(a==2&&b==2) printf("{A,AB,B}");
if(a==2&&b==3) printf("{A,AB,B,O} ");
if(a==2&&b==4) printf("{A,B} ");
if(a==3&&b==1) printf("{A,AB,B,O}");
if(a==3&&b==2) printf("{A,AB,B,O} ");
if(a==3&&b==3) printf("{B,O} ");
if(a==3&&b==4) printf("{B,O} ");
if(a==4&&b==1) printf("{A,O} ");
if(a==4&&b==2) printf("{A,B} ");
if(a==4&&b==3) printf("{B,O} ");
if(a==4&&b==4) printf("{O} ");
}

int main()
{int father,mother,child;
father=read();
mother=read();
child=read();
print1(father,mother,child);
print1(mother,father,child);
print2(child,father,mother);

}
