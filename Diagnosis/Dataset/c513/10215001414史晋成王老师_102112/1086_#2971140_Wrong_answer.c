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
if(strcmp(s1,s2)>=0||strlen(s1)>strlen(s2))
{
for(i=2*L;i>L+n;i--)
{ a[i]=a[i]-b[i];
if(a[i]<0)
  {a[i]+=10;a[i-1]-=1;}
}
if(a[i+1]>=5) a[i]++;
for(i=L+n;i>0;i--)
{ a[i]=a[i]-b[i];
  if(a[i]<0)
  {a[i]+=10;a[i-1]-=1;}
}
p=0;
while(a[p]==0&&p<=L) p++;
if(p>L) printf("0");
else{
for(i=p;i<=L;i++)
printf("%d",a[i]);}
printf(".");
for(i=L+1;i<=L+n;i++)
printf("%d",a[i]);}
else
{
for(i=2*L;i>L+n;i--)
{ b[i]=b[i]-a[i];
if(b[i]<0)
  {b[i]+=10;b[i-1]-=1;}
}
if(b[i+1]>=5) b[i]++;
for(i=L+n;i>0;i--)
{ b[i]=b[i]-a[i];
  if(b[i]<0)
  {b[i]+=10;b[i-1]-=1;}
}
p=0;
while(b[p]==0&&p<=L) p++;
printf("-");
if(p>L) printf("0");
else{
for(i=p;i<=L;i++)
printf("%d",b[i]);}
printf(".");
for(i=L+1;i<=L+n;i++)
printf("%d",b[i]);}

}