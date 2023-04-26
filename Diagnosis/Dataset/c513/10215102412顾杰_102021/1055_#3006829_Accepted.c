#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
   int n,m,i,j,max=0;
   char  *p=(char*)malloc(1000001),*p0=p,*p1=p,*ans=p0,*tab[200]={0};
   memset(p,0,1000001);
   scanf("%s",p);
   while(*p1)
   {
       while(*p1&&tab[*p1]<p){tab[*p1]=p1;p1++;}//printf("%d",p1-p);}


       //for(char*t=p;t<=p1;t++)printf("%c",*t);printf("\n");
       if(p1-p>max){ans=p;max=p1-p;}
       p=tab[*p1]+1;
       tab[*p1]=p1;p1++;
   }
   *(ans+max)=0;
   printf("%s",ans);
   free(p0);
}
