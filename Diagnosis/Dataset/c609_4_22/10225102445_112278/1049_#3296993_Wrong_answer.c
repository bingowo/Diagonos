#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct F
{char a[600];
char b[600];

}stu[600];
void p(int A[],int B[],int C[])
{int i,k,V[600];
for(i=0;i<=599;i++){C[i]=0;V[i]=0;}
for(k=599;k>=1;k--)
    {if(A[k]-B[k]<0){C[k]=(10+A[k]-B[k]);V[k-1]+=1;}
    else C[k]=A[k]-B[k];
    }
for(k=599;k>=1;k--)
    {if(C[k]-V[k]<0){ C[k]=(10+C[k]-V[k]) ;V[k-1]+=1;        }
    else C[k]=C[k]-V[k];
    }

}
void copy(char a[],int B[])
{int K[600],i,u;
for(i=599;i>=0;i--){K[i]=0;}
    for( i=0;i<=strlen(a)-1;i++)
{K[i]=a[i]-'0';

}
int j=599;
for(u=i-1;u>=0;u--)
{
    B[j]=K[u];j--;

}



}
int main()
{int A[600],B[600],i=0,n,C[600];
while(scanf("%s %s",stu[i].a,stu[i].b)!=-1){i++;}
for(n=0;n<=i-1;n++)
{for(int p=599;p>=0;p--){A[p]=0;B[p]=0;}
    copy(stu[n].a,A);
    copy(stu[n].b,B);
p(A,B,C);
int u=0;
while(C[u]==0){u++;}
for(int k=u;k<=599;k++){printf("%d",C[k]);}
printf("\n");
}

return 0;
}





