#include<stdio.h>
void  p(int a,int n,int m,int A[])
{int i=0,s,v[n+1][2],k=0,p=0;
for(i=0;i<=n;i++){A[i]=0;}
A[1]=A[2]=a;
v[1][0]=1;v[1][1]=0;
v[2][0]=0;v[2][1]=1;
for(i=3;i<=n-1;i++)
{v[i][0]=v[i-1][1];
v[i][1]=v[i-1][0]+v[i-1][1];
k+=v[i-2][1];
p+=v[i-2][0];

}

s=(m-a-p*a)/k;
for(i=3;i<=n-1;i++)
{A[i]=A[i-1]+v[i-2][0]*a+v[i-2][1]*s;

}

}
int main()
{int a,n,m,x;
scanf("%d%d%d%d",&a,&n,&m,&x);
int A[n+1];
p(a,n,m,A);
printf("%d",A[x]);
}
