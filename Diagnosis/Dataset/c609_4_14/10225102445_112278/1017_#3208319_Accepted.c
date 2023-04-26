#include <stdio.h>
#include<stdlib.h>
int Amp(const void*a,const void*b)
{return *(int*)a-*(int*)b;}
int Bmp(const void*c,const void*d)
{return *(int*)d-*(int*)c;}

int main()
{char c;
int A[1000],i=0,B[1000],t=0;
scanf("%c",&c);
while(scanf("%d",&A[i])!=EOF){i++;}
B[0]=A[0];
for(int u=1;u<=i-1;u++)
{  for(int j=0;j<=t;j++)
    {if(A[u]!=B[j]&&j==t){B[j+1]=A[u];t++;}
     if(A[u]==B[j]) break;
    }
}
if(c=='A') {qsort(B,t+1,4,Amp);}
else  {qsort(B,t+1,4,Bmp);}
for(int y=0;y<=t;y++)
{printf("%d ", B[y]);}
return 0;
}
