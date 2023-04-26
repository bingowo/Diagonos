#include<stdio.h>
#include<string.h>
#define L 500

void input(int a[2*L+2])//输入与存储
{int i=0,j,k;
 char s[L+1];
 scanf("%s",s);
 while(s[i]!='.')i++;
 for(j=i-1,k=i-1;j>=0;j--,k--)
 a[j]=s[k]-'0';
 for(j=i+1;j<strlen(s);j++,k++)
 a[j]=s[k]-'0';
}

void add(int a[2*L+2],int b[2*L+2],int N)//计算
{int t;
 for(t=2*L;t>L+N;t--)
 {a[t]+=b[t];
  a[t-1]+=a[t]/10;
  a[t]%=10;
 }
 if(a[t+1]>=5) a[t]++;
 for(t=L+N;t>=0;t--)//有没有=
 {a[t]+=b[t];
  a[t-1]+=a[t]/10;
  a[t]%=10;
 }
}

void output(int a[2*L+2],int N)
{int t=0,i,j;
 while(t<=L&&a[t]==0) t++;
 if(t>L) printf("0");
 else
    {while(t<=L)
     printf("%d",a[t++]);}
 printf(".");
 while(t<=L+N)
 printf("%d",a[t++]);
}

int main()
{int a[2*L+2]={0},b[2*L+2]={0},N;
 input(a);
 input(b);
 scanf("%d",&N);
 add(a,b,N);
 output(a,N);
 return 0;
}
