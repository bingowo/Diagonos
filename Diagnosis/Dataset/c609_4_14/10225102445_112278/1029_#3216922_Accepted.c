#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b )
{return *(int*)a-*(int*)b;}
int main()
{int m,n,A[1000],B[1000],i,C[1000],D[1000],x=0,y=0,p,E[1000],z,u;
scanf("%d\n",&m);
for(i=0;i<m;i++)
{scanf("%d",&A[i]);}
getchar();
scanf("%d\n",&n);
for(i=0;i<n;i++)
{scanf("%d",&B[i]);}
qsort(B,n,4,cmp);

for(i=0;i<n;i++)
{for(p=0;p<m;p++)
   {if(B[i]==A[p]){D[x]=B[i];E[x]=p;x++;break;}
     if(p==m-1) {C[y]=B[i] ;y++; }
   }

}

for(i=0;i<x-1;i++)
{for(z=0;z<x-1-i;z++)
    {if(E[z]>E[z+1]){u=D[z];D[z]=D[z+1];D[z+1]=u;u=E[z];E[z]=E[z+1];E[z+1]=u;}

    }
}


for(i=0;i<x;i++)
{printf("%d ",D[i]);}


for(i=0;i<y;i++)
{printf("%d ",C[i]);}
return 0;
}