#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void btoR(int N,char s[100],int R)
{
   int i;int j;int N1;int temp;
   char t[100];
   N1=abs(N);
   for(i=0;N1>0;i++)
   {
       temp=N1%R;
       if(temp<10)
        t[i]=temp+'0';
       else
        t[i]=temp+'A'-10;
       N1=N1/R;
   }
   t[i]='\0';
   j=0;
   if(N<0) {s[j]='-';j++;}
   for(;i>=0;i--,j++)
    s[j]=t[i-1];
}
int main()
{
    char s[1000];
    int N,T,R;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
     { scanf("%d %d",&N,&R);
       btoR(N,s,R);
       printf("%s\n",s);
     }
     return 0;
}

