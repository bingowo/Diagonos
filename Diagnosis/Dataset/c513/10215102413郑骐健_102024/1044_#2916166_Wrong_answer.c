#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned int *p = (unsigned int*)malloc(sizeof(unsigned int)*1e5);
    unsigned long long a =0;
    unsigned long long b =1;
    char c,d;
    char last =0 ;
    int judge =0;
    int num=0 ;
   while((c=getchar())!='\n')
   {

       if(last == '0'&&c=='x')
       {
        if(judge == 1)
        {
        if(a>0)
        {p[num] = a;
        num +=1;
        a=0;
        }
        }
        judge = 1;
        continue;
       }
        if(c>='f')
       {
           if(judge == 1)
           {
               if(a!=0)
               {
                p[num] = a;
               num++;
               a=0;
               }
           }
           judge = 0;
       }
       if(judge)
       {
        a*=16;
        if('0'<=c&&c<'9')a+=c-'0';
        else a+=c-'a'+10;
        if(a>=(b<<32))
        {
            a= 0;
            judge = 0;
        }
       }
        last = c;
   }
   if(judge ==1&&a>0)
   {
       p[num] = a;
       num++;
   }
   for(int i =0;i<num;i++)
   {
       printf("%u ",p[i]);
   }
   if(num == 0)
    printf("-1");
   free(p);
    return 0;
}
