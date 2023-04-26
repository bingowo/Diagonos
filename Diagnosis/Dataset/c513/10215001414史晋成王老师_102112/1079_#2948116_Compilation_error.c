#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cmp(const void*a,const void*b)
{ return *((int*)a)-*((int*)b);
}
int main()
{ int i,j,n,m,s,a[10000],b[1000000],o,t,l,u,k,p,q,f,x,ans=0;
scanf("%d",&t);
for(i=0;i<t;i++)
{  scanf("%d %d",&n,&m);
   for(j=0;j<n;j++)
    scanf("%d",&a[j]);
    p=1;f=0;
    while(p<=n)
    { for(q=0;q<=n-p;q++)
    { for(o=0;o<p;o++)
      b[f]+=a[q+o];
      f++;
    }
    p++;
    }
      printf("case #%d:\n",i);
    qsort(b,f,sizeof(int),cmp);
    for(k=0;k<m;k++)
    { scanf("%d %d",&l,&u);
      for(x=l-1;x<=u-1;x++)
        ans+=b[x];
        printf("%d\n",x); 
    }
    for(s=0;s<f;s++)

}
    
}