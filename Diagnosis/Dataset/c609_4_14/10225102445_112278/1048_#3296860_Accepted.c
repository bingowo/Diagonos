#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
void p(int a,int A[])
{int i,u,B[300],C[300],D[300];
for(i=0;i<=299;i++){A[i]=0;B[i]=0;C[i]=0;D[i]=0;}
C[299]=0;
D[299]=1;
if(a==0){A[299]=0;}
else if(a==1){A[299]=1;}
else {for(i=0;i<=a-2;i++)
    {
  for(u=0;u<=299;u++){A[u]=0;B[u]=0;}
    for(int k=299;k>=1;k--)
        {if((C[k]+D[k])>=10){B[k-1]=(C[k]+D[k])/10;A[k]=(C[k]+D[k])%10;}
        else A[k]=(C[k]+D[k]);
        }
    for(int k=299;k>=1;k--)
    {if((A[k]+B[k])>=10){B[k-1]+=(A[k]+B[k])/10;A[k]=(A[k]+B[k])%10;}
    else A[k]+=B[k];
    }
for(int k=0;k<=299;k++){C[k]=D[k];D[k]=A[k];}

    }

}

}
int main()
{int T,a,i,k;
int A[300];
scanf("%d\n",&T);
for(i=0;i<=T-1;i++)
{scanf("%d",&a);
p(a,A);
printf("case #%d:\n",i);
if(a!=0){k=0;
while(A[k]==0){k++;}
for(int m=k;m<=299;m++){printf("%d",A[m]);}}
else printf("0");
printf("\n");

}



return 0;
}





