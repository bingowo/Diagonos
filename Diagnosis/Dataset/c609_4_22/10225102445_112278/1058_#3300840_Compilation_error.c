#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
void p(int a[],int b[],int k)
{int c[1000],i,v=0;
for(i=0;i<=999;i++){c[i]=0;}
if(k==1)
{while(v==0)
{  for(i=0;i<=998;i++)
{if(a[i]/(-2)==0){c[i+1]=a[i];a[i]=0;}
else {a[i]=-(a[i]/(-2));c[i+1]=a[i]%(-2)}
}

for(i=0;i<=998;i++)
 {

 }


for(i=999;i>=0;i--)
{if(a[i]!=0){v=0;break;}}
if(i=-1&&a[0]==0){v=1;}
}
}
else


}
int main()
{char A[1000];
scanf("%s",A);
int a[1000],i,j=999,b[1000],k;
for(i=0;i<=999;i++){a[i]=0;b[i]=0;}
if(A[0]=='-')
{for(i=strlen(A)-1;i>=1;i--){a[j]=A[i]-'0';j--;}
k=-1;
p(a,b,k);
    }
else
{for(i=strlen(A)-1;i>=0;i--){a[j]=A[i]-'0';j--;}
k=1;
p(a,b,k);

}
j=0;
while(b[j]==0){j++;}
for(i=j;i<=999;i++){printf("%d",b[i]);}


}
