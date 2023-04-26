#include<stdio.h>
#include<stdlib.h>
void F(long long int A[],long long int B[],long long int len)
{long long int i,t,c,y,r;
 for(i=0;i<=len-1;i++)
    {t=0;y=63;long long int K[64]={0};
  if(A[i]>0){c=A[i];while(c!=0){if(c%2==1){t++;}c/=2;}
   B[i]=t;}
   else if (A[i]==0){B[i]=0;}
   else
    {c=-A[i];
    while(c!=0){K[y]=c%2;c/=2;y--;}
    K[0]=1;t=1;
for(r=1;r<=63;r++)
{if(K[r]==0){K[r]=1;t++;}
else K[r]=0;}

if(K[63]==0){t=t+1;}
else
{for(r=62;r>=1;r--)
  {if(K[r]==0){break;} }
    t=t-62+r;
}

B[i]=t;
   }

}

}
int main()
{long long int T,i,a,b,A[10000],B[10000],k,p;
scanf("%lld\n",&T);
for(i=0;i<=T-1;i++)
{scanf("%lld\n",&a);
for(b=0;b<=a-1;b++){scanf("%lld",&A[b]);}
F(A,B,a);
for(p=0;p<=a-1;p++)
{for(long long int j=0;j<=a-2;j++)
  {if(B[j]<B[j+1]){k=A[j];A[j]=A[j+1];A[j+1]=k;k=B[j];B[j]=B[j+1];B[j+1]=k;}
    else if(B[j]==B[j+1]&&A[j]>A[j+1]){k=A[j];A[j]=A[j+1];A[j+1]=k;}
  }

}

printf("case #%lld:\n",i);
for(k=0;k<=a-1;k++){printf("%lld ",A[k]);}
printf("\n");
}

return 0;
}
