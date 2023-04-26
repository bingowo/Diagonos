#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void p(int a[],int b[],int N,int c[])
{int i,h,R[600];
for(i=0;i<=599;i++){R[i]=0;}
for(i=599;i>=1;i--)
{if(b[i]+a[i]>=10){R[i-1]=(b[i]+a[i])/10;c[i]=(b[i]+a[i])%10;}
else c[i]=b[i]+a[i];

}
for(i=599;i>=1;i--)
{if(c[i]+R[i]>=10){R[i]+=(c[i]+R[i])/10;c[i]=(c[i]+R[i])%10;}
else c[i]=c[i]+R[i];}


}
int point(char A[])
{
    for(int i=0;i<=strlen(A)-1;i++)
    {
        if(A[i]=='.'){return i;break;}

    }
    return strlen(A);
}
void copy(int a[],char A[],int n,int v)
{ int j=599-v;
    for(int i=strlen(A)-1;i>=n+1;i--)
 {a[j]=A[i]-'0';
         j--;
  }
  for(int i=n-1;i>=0;i--)
  {
  a[j]=A[i]-'0';
   j--;
  }

}
int main()
{ char A[600],B[600];
int i,a[600],b[600],N,P1,P2,k,c[600],v=0,P;
scanf("%s %s %d",A,B,&N);
P1=strlen(A)-point(A)-1;
P2=strlen(B)-point(B)-1;
for(i=0;i<=599;i++){b[i]=0;a[i]=0;c[i]=0;}
if(P1>=P2)
{P=P1;k=P1-P2;copy(a,A,point(A),0);copy(b,B,point(B),k);}
else {P=P2;k=P2-P1;copy(b,B,point(B),0);copy(a,A,point(A),k);}
/*for(i=0;i<=599;i++){printf("%d",a[i]);}
printf("\n");
for(i=0;i<=599;i++){printf("%d",b[i]);}*/
p(a,b,N,c);
while(c[v]==0){v++;}
for(i=v;i<=599-P;i++){printf("%d",c[i]);}
printf(",");
for(i=600-P;i<=599;i++){printf("%d",c[i]);}
}
