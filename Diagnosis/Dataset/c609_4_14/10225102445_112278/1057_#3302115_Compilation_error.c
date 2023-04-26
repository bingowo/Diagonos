#include<stdio.h>
void p(int A[],int k)
{int B[1000],i,f,C[1000],d,D[1000];//c½øÎ»£»
for(i=0;i<=999;i++){A[i]=0;B[i]=0;C[i]=0;}D[i]=0;}
A[999]=1;
for(f=2;f<=k;f++)
{B[999]=f%10;
B[998]=(f/10)%10;
B[997]=(f/100)%10;
B[996]=(f/1000)%10;
for(d=999;d>=996;d--)
{
for(i=999;i>=1;i--)
{if(B[d]*A[i]>=10){C[i-1]=(B[d]*A[i])/10;A[i]=(B[d]*A[i])%10;}
  else A[i]*=B[d];
}
for(i=999;i>=1;i--)
{if(C[i]+A[i]>=10){C[i-1]=(C[i]+A[i])/10;A[i]=(C[i]+A[i])%10;}
  else A[i]+=C[i];
}

for(i=999;i>=0;i--){B[i]=0;C[i]=0;}


}


}

}

int t(int A[])
{int i,v=0,k;
while(A[v]==0){v++;}
for(i=999;i>=v;i--)
    {if(A[i]!=0){k=i;break;}}
return 999-k;
}
int main()
{int n,A[1000],o,k;
scanf("%d",&n);
for(int v=0;v<n;v++)
{scanf("%d",&k);
    p(A,k);
 o=t(A);
 printf("case #%d:\n",v);
printf("%d\n",o);

}

}
