#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
void p(int a[],int b[],int N,int c[],int P)
{int i,R[600];
for(i=0;i<=599;i++){R[i]=0;}
for(i=599;i>=1;i--)
{if(b[i]+a[i]>=10){R[i-1]=(b[i]+a[i])/10;c[i]=(b[i]+a[i])%10;}
else c[i]=b[i]+a[i];

}
for(i=599;i>=1;i--)
{if(c[i]+R[i]>=10){R[i-1]+=(c[i]+R[i])/10;c[i]=(c[i]+R[i])%10;}
else c[i]=c[i]+R[i];}

for(i=0;i<=599;i++){R[i]=0;}
if(c[600-P+N]>=5)
    {R[599-P+N]=1;c[600-P+N]=0;
for(i=600-P+N;i>=1;i--)
{if(c[i]+R[i]>=10){R[i-1]+=(c[i]+R[i])/10;c[i]=(c[i]+R[i])%10;}
else c[i]=c[i]+R[i];}

}
else ;



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
{
   if(n!=strlen(A))
   {int j=599-v;
     for(int i=strlen(A)-1;i>=n+1;i--)
            {a[j]=A[i]-'0';j--;}
      for(int i=n-1;i>=0;i--)
         {a[j]=A[i]-'0';j--;}
    }

    else
        {int j=599-v+1;
     for(int i=strlen(A)-1;i>=n+1;i--)
            {a[j]=A[i]-'0';j--;}
      for(int i=n-1;i>=0;i--)
         {a[j]=A[i]-'0';j--;}}

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
p(a,b,N,c,P);

if(P>=N){while(c[v]==0){v++;}
for(i=v;i<=599-P;i++){printf("%d",c[i]);}
if(v>599-P)printf("0");
printf(".");
for(i=600-P;i<=599-P+N;i++){printf("%d",c[i]);}}
else
{while(c[v]==0){v++;}
for(i=v;i<=599-P;i++){printf("%d",c[i]);}
if(v>599-P)printf("0");
printf(".");
for(i=600-P;i<=599;i++){printf("%d",c[i]);}
for(i=0;i<N-P;i++){printf("0");}
}



}
