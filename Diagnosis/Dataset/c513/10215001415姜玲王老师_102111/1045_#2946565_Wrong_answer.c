#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {char a;int number;} pair;
int cmp(const void*a,const void*b)
{return (int*)a-(int*)b;
}
int aset(char* a,pair*s)
{int k=0,j;
for(int i=0;i<strlen(a);i++)
{s[k].a=a[i];
j=1;
for(;a[i]=a[i+1]&&i<strlen;i++)
{j++;}
s[k].number=j;
k++;}
return k;}
int  judge(pair*c,pair*b,int k)
{for(int i=0;i<k;i++)
{if(c[i].a!=b[i].a) {return 1;}}
return 0;
}
int main()
{int n,rcent,temp;
scanf("%d",&n);
pair s[100000][100];
char a[100];
scanf("%s",a);
rcent=aset(a,s[0]);
for(int i=1;i<n;i++)
{char a[100];
scanf("%s",a);
temp=aset(a,s[i]);
if(temp!=rcent){printf("-1");return 0;}
}
for(int i=0;i<n-1;i++)
{if(judge(s[i],s[i+1],rcent)) {printf("-1"); return 0;}}
int sum=0;
for(int i=0;i<rcent;i++)
{
for(int j=0;j<n;j++){int a[100000];a[j]=s[j][i].number;}
qsort(a,n,sizeof(a[0]),cmp);
for(int k=0;k<n-k-1;k++) sum+=a[n-k-1]-a[k];
}
printf("%d",sum);
}
