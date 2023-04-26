#include<stdio.h>
#include<string.h>
int main()
{int T,i=0,j=0,k,a,n,t,c,d,l=0,h,e,p;
 char s[10000],b[10000]={0},g[10000]={0};
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {scanf("%d %d",&a,&n);
  s[0]=a;g[0]=0;
  for(t=0;t<n-1;t++)
  { c=strlen(s);
    for(j=0;j<c;j++,l++,i++)
    {s[j]=a*s[j]%10;
     g[l+1]=a*s[j]/10;
     b[i]=s[j]+g[l];
     }
     e=strlen(b);
     s[c]='\0';
     strcpy(s,b);
     b[e]='\0';
   }
   p=strlen(s);
   for(j=0;j<p/2;j++)
   {h=s[j];s[j]=s[p-j];s[p-j]=h;}
   printf("case #%d:\n",k);
   for(j=0;j<p;j++)
   printf("%c",s[j]);
 }
 return 0;
}
