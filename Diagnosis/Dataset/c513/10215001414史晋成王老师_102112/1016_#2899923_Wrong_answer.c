#include<stdio.h>
#include<stdlib.h>
int main()
{int N,R,j,i=0; char a[10000]={0};
scanf("%d %d",&N,&R);
if(R<=-10)
{ 
    while(N)
    { if((N%R>=0)&&(N%R<10))
     a[i]='0'+N%R;
     else if((N%R>=0)&&(N%R>=10))
     a[i]='A'+N%R-10;
     else if((N%R<0)&&(N-(N/R+1)*R<10))
     a[i]='0'+N-(N/R+1)*R;
     else if((N%R<0)&&(N-(N/R+1)*R>=10))
     a[i]='A'+N-(N/R+1)*R-10;
     if(N%R>=0)
      N=N/R;
     else
     N=N/R+1;
      i++;
    }
    
}
if (R>=-10)
{while(N)
    { if(N%R>=0)
     a[i]=N%R+'0';
     else 
     a[i]=N-(N/R+1)*R+'0';
     if(N%R>=0)
      N=N/R;
     else
     N=N/R+1;
      i++;
    }
    
}
if(N==0) printf("0");
else {
for(j=i-1;j>=0;j--)
    {printf("%c",a[j]);}}
}