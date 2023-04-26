#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
void p(int a,int n,int A[])
{int i,y,u,B[300],c;
for(i=0;i<=299;i++){A[i]=0;B[i]=0;}
A[299]=a;
  if(a!=0){for(int m=0;m<=n-2;m++)
    { i=299;y=0;
    while(A[y]==0){y++;}
    for(u=0;u<=299;u++){B[u]=0;}
        for(i=299;i>=y;i--)
       { if((A[i]*a)>=10){B[i-1]=(A[i]*a)/10;c=(A[i]*a)%10;A[i]=c;}
                else {A[i]*=a;}
      }

 for(int k=299;k>=0;k--)
        {if((A[k]+B[k])<10)A[k]+=B[k];
      else{B[k-1]=B[k-1]+((A[k]+B[k])/10);A[k]=(A[k]+B[k])%10;}
       }

    }}
else{A[299]=1;}



}
int main()
{int T,a,n,i,k;
int A[300];
scanf("%d\n",&T);
for(i=0;i<=T-1;i++)
{scanf("%d %d",&a,&n);

p(a,n,A);
printf("case #%d:\n",i);
k=0;
while(A[k]==0){k++;}
for(int m=k;m<=299;m++){printf("%d",A[m]);}
printf("\n");

}



return 0;
}
