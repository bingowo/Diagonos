#include <stdio.h>
#include <stdlib.h>

int main()
{int r;
long long int m,n,q1=0,q2=0;
int d,j;
char a[1000];
int b[1000];
getchar();
getchar();
scanf("%s",a);
int i=0,k=0;
for(;i<strlen(a);i++)
{unsigned int l=0x8;
if(a[i]>='A') d=a[i]-'A'+10;
else d=a[i]-'0';
while(l)
{if(l&d) b[k]=1;
else b[k]=0;
k++;
l=l>>1;}}
for(j=0;j<k;j++)
{r=b[j];
m=-q1-q2+r;
n=q1-q2;
q1=m;
q2=n;}
if(q2==0) printf("%lld",q1);
else{ if(q1) printf("%lld",q1);
if(q2>0&&q1!=0) printf("+");
if(q2==1) printf("i");
else{if(q2==-1) printf("-i");
else printf("%lldi",q2);}}
return 0;
}
