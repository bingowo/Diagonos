#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
typedef struct {char a;int number;} pair;
int cmp(const void*a,const void*b)
{return (int*)a-(int*)b;
}
int aset(char* c,pair*s)
{int k=0,j;
for(int i=0;i<strlen(c);i++)
{s[k].a=c[i];
j=1;
for(;c[i]==c[i+1]&&i<strlen(c);i++)
{j++;}
s[k].number=j;
k++;}
return k;}
int judge(pair*c,pair*b,int k)
{for(int i=0;i<k;i++)
{if(c[i].a!=b[i].a) {return 1;}}
return 0;
}
int main()
{int n,rcent,temp;
int sum=0;
scanf("%d",&n);
pair s[100000][100];

char c[100];
scanf("%s",c);
rcent=aset(c,s[0]);
for(int i=1;i<n;i++)
{char c[100];
scanf("%s",c);
temp=aset(c,s[i]);
if(temp!=rcent){printf("-1");return 0;}
}
for(int i=0;i<n-1;i++)
{if(judge(s[i],s[i+1],rcent)) {printf("-1"); return 0;}}

for(int i=0;i<rcent;i++)
{int w[100000]={0};
for(int j=0;j<n;j++){w[j]=s[j][i].number;}
qsort(w,n,sizeof(w[0]),cmp);
for(int k=0;k<n;k++) {sum+=abs(w[k]-w[n/2]);}
}
printf("%d",sum);}
