#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a,int b)
{ return a?gcd(b%a,a):b;
    
}
int cmp(const void*a,const void*b)
{ int x,y;
return *(int *)a-*(int *)b;
}
int main()
{ int n,m,i,j,s,c,l1,l2,k; int a[10000];
scanf("%d %d",&n,&s);
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
qsort(a,n,sizeof(a[0]),cmp);
i=0;j=0;c=0;
while ((s!=0)&&(i<n-1))
{  k=(a[i+1]-a[i]);j=a[i]
for(k=1;k<=(a[i+1]-a[i]);k++)
    {if (s>=(i+1)) {s-=(i+1); j++;}
   else  {c=gcd(s,(i+1)); l1=s/c; l2=(i+1)/c; break;}}
   i++;
}

if ((i==n-1)&&(s!=0)) {
    while(s!=0)
    { if(s>=n) {s-=n; j++;}
     else {c=gcd(s,n); l1=s/c; l2=n/c;break;}
    }
}
if (c==0) printf("%d",j);
else printf("%d+%d/%d",j,l1,l2);
}