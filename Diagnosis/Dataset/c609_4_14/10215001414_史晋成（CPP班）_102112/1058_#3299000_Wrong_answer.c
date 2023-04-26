#include<stdio.h>
#include<stdlib.h>
int main()
{int N,R,j,i=0,f; char a[10000]={0};
scanf("%d",&N);
f=N;
    
if (R>=-10)
{while(N)
    { if(N%-2>=0)
     a[i]=N%-2+'0';
     else 
     a[i]=N-(N/-2+1)*-2+'0';
     if(N%-2>=0)
      N=N/-2;
     else
     N=N/-2+1;
      i++;
    }
    
}
if(f==0) printf("0");
else {
for(j=i-1;j>=0;j--)
    {printf("%c",a[j]);}}
}