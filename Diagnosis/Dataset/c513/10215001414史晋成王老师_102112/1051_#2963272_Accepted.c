#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int n,i,j,t,k,p,q,r; char s[110],a[8000],b[110]={0};
char s1[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
s1[65]=0;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s);
 j=0;k=0;
 while(s[j])
 { t=s[j];
 for(k=(j+1)*8-1;k>=8*j;k--)
 { a[k]=t%2;
   t=t/2;
 }
  j++;
 }
k=k+9;
while(k%6!=0) {a[k]=0;k++;}
q=k/6;
for(p=0;p<q;p++)
{ b[p]=0;
    for(r=p*6;r<=p*6+5;r++)
  {b[p]*=2;b[p]+=a[r];}
}
printf("case #%d:\n",i);
for(p=0;p<q;p++)
printf("%c",s1[b[p]]);
while(q%4!=0)
{printf("=");q++;}
printf("\n");
}
}