#include<stdio.h>
#include<string.h>
int F(char g[],int BASE,char b[],int H,int S)
{int k=0,m=1,AB[100];
for(int h=H;h>=0;h--)
{for(int j=0;j<=S;j++)
  {if(g[h]==b[j]){AB[h]=j;break;}}
}
for(int h=H;h>=0;h--)
{if(AB[h]==0){k+=m;}
else if(AB[h]==1){k+=0;}
else{k+=m*AB[h];}
m*=BASE;
}

return k;

}
int main()
{int a,i,u,k,r,t,s,base;
char A[100],B[100];
scanf("%d\n",&a);
for(i=0;i<a;i++)
{u=0;
while((A[u]=getchar())!='\n'){u++;}
A[u]='\0';
B[0]=A[0];
s=0;
for(r=1;r<=u-1;r++)
{for(t=0;t<=s;t++)
    {if(B[t]!=A[r]&&t==s){s++;B[s]=A[r];}
     if(B[t]==A[r]) break;
    }
}
base=s+1;

k=F(A,base,B,u-1,s);
printf("case #%d:\n%d\n",i,k);
}

return 0;
}
