#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*a,const void*b)
{int x,y;
x=*((int*)a);
y=*((int*)b);
return x-y;
}
int cmp2(const void*a,const void*b)
{int x,y;
x=*((int*)a);
y=*((int*)b);
return y-x;
}
int main()
{char f; int a[1000],i=0,j,m,c[1000],k,s;
scanf("%c",&f);
while(scanf("%d",&a[i])!=EOF) i++;
for (j=0;j<i;j++)
{for(m=j;m<i;m++)
{ if (a[m]==a[j]) a[m]=10000;}
}
k=0;
 for(j=0;j<i;j++)
 { if(a[j]!=10000) {c[k]=a[j]; k++;}
 }
 if(f=='A')
 qsort(a,i,sizeof(a),cmp2);
 else if (f=='D')
 qsort(a,i,sizeof(a),cmp1);
 for(s=0;s<k-1;s++)
 printf("%d ",c[s]);
 printf("%d",c[s]);
}
    
