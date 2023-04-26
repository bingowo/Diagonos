#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
# define L 500
int main()
{ char s1[1000]={0},s2[1000]={0},s3[1000];
int i,j,a[1001]={0},b[1001]={0},n,x,y,s,k,p;
scanf("%s%s%d",s1,s2,&n);
i=0;
while(s1[i]!='.'&&s1[i]) i++;
for(k=L,s=i-1;s>=0;s--,k--)
a[k]=s1[s]-'0';
for(k=L+1,s=i+1;s<strlen(s1);s++,k++)
a[k]=s1[s]-'0';
i=0;
while(s2[i]!='.'&&s2[i]) i++;
for(k=L,s=i-1;s>=0;s--,k--)
b[k]=s2[s]-'0';
for(k=L+1,s=i+1;s<strlen(s2);s++,k++)
b[k]=s2[s]-'0';

for(i=2*L;i>L+n;i--)
{ a[i]=a[i]+b[i];
  a[i-1]+=a[i]/10;
    a[i]%=10;
}
if(a[i+1]>=5) a[i]++;
for(i=L+n;i>0;i--)
{ a[i]=a[i]+b[i];
  a[i-1]+=a[i]/10;
    a[i]%=10;
}
p=0;
while(a[p]==0&&p<=L) p++;
if(p>L) printf("0");
else{
for(i=p;i<=L;i++)
printf("%d",a[i]);}
printf(".");
for(i=L+1;i<=L+n;i++)
printf("%d",a[i]);
}