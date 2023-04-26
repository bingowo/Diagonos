#include<stdio.h>
#include<string.h>
int main()
{int T,i=1,j=0,k,a,n,t,c,d,l=0,h;
 char s[10000000],b[100000000]={0},g[10000000]={0};
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {scanf("%d %d",&a,&n);
  s[0]=a;g[0]=0;
  for(t=0;t<n-1;t++)
  {for(j=0;j<c;j++,l++,i++)
    {s[j]=a*s[j]%10;
     g[l+1]=a*s[j]/10;
     b[i]=s[j]+g[l];
    }
   }
   c=strlen(b);
   for(j=0;j<c/2;j++)
   {h=b[j];b[j]=b[c-j];b[c-j]=h;}
   printf("case #%d:\n",k);
   for(j=0;j<c;j++)
   printf("%c",b[j]);
 }
 return 0;
}
