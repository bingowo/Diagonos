#include <stdio.h>
#include <stdlib.h>

int main()
{int norm['1'+1];
norm['0'-1]=2;
norm['0']=0;
norm['1']=1;
long long a,b,c,d,m,temp;
int i,j,k,l,n,y,z;
int s[1000]={0},p[1000]={0};
scanf("%lld%lld",&a,&b);
if(a==0) {printf("0");return 0;}
c=a%b;
d=a%b;
temp=a/b;
for(j=0;temp;j++){s[j]=temp%3;temp/=3;}
if(c){for(i=-2;b;i++)b/=3;
for(k=i;d;k--){p[k]=d%3;d/=3;}
for(l=i;l>0;l--)
    {p[l]++;
if(p[l]>=3)
    {p[l]-=3;p[l-1]++;}
    p[l]--;}
p[l]++;
if(p[l]>=3){p[l]-=3;s[0]++;}
p[l]--;}
for(n=0;n<j;n++){s[n]++;if(s[n]>=3){s[n]-=3;s[n+1]++;}s[n]--;}
for(y=j;s[y]==0&&y!=0;y--);
for(;y>=0;y--) printf("%d",norm[s[y]+'0']);
if(c){printf(".");
for(z=0;z<=i;z++)printf("%d",norm[p[z]+'0']);}}
