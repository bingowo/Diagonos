#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int solveint(int n)
{int c=sizeof(n);
 unsigned char* p=(unsigned char*) &n;
 while(c--)
 printf("02x ",*p++);
 printf("\n")  ; 
}

int solvedouble(double d)
{ int c=sizeof(n);
  unsigned char* p=(unsigned char*)&d;
  while (c--)
  printf("%02x ",*p++);
  printf("\n");
    
}

int main()
{char s[10]; double d; int n;
 while(scanf("%s",s))
 { if (strchr(s,'.'))
     { d=atof(s);
       solvedouble(d);
         
     }
   else {n=atoi(s); solveint(n);}
     
     
 }
 return 0;   
}