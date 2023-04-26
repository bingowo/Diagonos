#include<stdio.h>

void readpoly(char *s, int* co)
{  while (*s)
   {  int sign=1,a=0,i=0;
      if (*s=='+' ) s++;
      else if (*s=='-') sign=-1,s++;
      while (isdigit(*s)) {  a=a*10+*s-'0'; s++; }
      if (a==0) a=1;
      if (*s!='x') { co[0]=a*sign; return; } else s++;
      if (*s=='^') s++;
      while (isdigit(*s)) {  i=i*10+*s-'0'; s++; }
      if (i==0) i=1;
      co[i]=a*sign;
    }
}

int main()
{ int a,b,c,a1,c1,co[10]={0},t;char s[80]; scanf("%s",s);
   readpoly(s, co);a=co[2],b=co[1],c=co[0];
   for (a1=1;a1<=a;a1++)
   if (a%a1==0)
     if (c)
     { for (c1=-200;c1<=200;c1++)
        if (c1&&c%c1==0&&a1*c/c1+a/a1*c1==b) 
          printf("%d %d %d %d\n",a1,c1,a/a1,c/c1),a1=c1=300;
     } else printf("%d %d %d %d\n",1,0,a,b),a1=300;
   if (a1<300) printf("No Answer!\n");
  return 0;
}