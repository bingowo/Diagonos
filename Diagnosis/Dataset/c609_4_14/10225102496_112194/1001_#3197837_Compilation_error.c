#include<stdlib.h>
#include<stdio.h>

void btoR(int N,char s[1000],int R)
{
   int i;int j;int quo=1;int N;
   char t[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   N=abs(n);
   for(i=0;N!=0;i++)
     N=N/b;
   if(n>=0) 
  {
    for(j=i-1;j>=0;j--)
   { s[j]=t[n%b];
     n=n/b;}
     s[i]='\0';
  }
   else
  {
   n=-n;
   for(j=i;j>=1;j--)
   { s[j]=t[n%b];
     n=n/b;}
   s[0]='-';
   s[i+1]='\0';
   }
}

}
int main()
{
    char s[1000]
    int N,T,R;
    scanf("%d",&T);
    for(int i=0;i<N;i++)
     { scanf("%d%d",&N,&R);
       printf("%s\n",btoR(N,s,R)))
}