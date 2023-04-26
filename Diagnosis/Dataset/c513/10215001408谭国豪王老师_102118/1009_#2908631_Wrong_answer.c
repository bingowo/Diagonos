#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{   int total(int k);
    int zi(char* c);
    int mu(char* c);
    int n,i,j,yue;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

   char a[100]={'\0'};
   gets(a);
  
   for(j=zi(a);j>=1;j--)
   {
       if(zi(a)%j==0&&mu(a)%j==0)
       {
           yue=j;
           break;
       }
   }
   printf("%d/%d\n",zi(a)/yue,mu(a)/yue);
    }
   return 0;

}



int zi(char* c)
{   int total(int k);
   int fenzi=0,fenmu=0;

    int i;
    for(i=0;*(c+i)!='\0';i++)
    {
        fenzi=fenzi+total((int)(*(c+i)));
    }
    fenmu=i*8;

    return fenzi;
}


int mu(char* c)
{   int total(int k);
   int fenzi=0,fenmu=0;

    int i;
    for(i=0;*(c+i)!='\0';i++)
    {
        fenzi=fenzi+total((int)(*(c+i)));
    }
    fenmu=i*8;

    return fenmu;
}


int total(int k)
{   int n,w=0;
    while(k)
    {
        n=k%2;
        k=k>>1;
        if(n==1)
        {
            w++;
        }
    }
    return w;
}
