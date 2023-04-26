#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{  char * x,*y;
   x= (char*) a;
   y= (char*) b;
    
    return strcmp(x,y);
}
int main()
{char s[1000],c[500][100],d[500][100]; int n,i,j,m,k,t,p,a,b,flag,q,r;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s);
 j=strlen(s);
 m=0;t=0;
 for(k=0;k<j;k++)
 { if(s[k]!=' '&&s[k]!=','&&s[k]!='.'&&s[k]!='!'&&s[k]!='?')
    {c[m][t]=s[k]; t++;}
    else if (s[k]==' '||s[k]==','||s[k]=='.'||(s[k]=='!'&&s[k+1]!=' ')||s[k]=='?')
    {c[m][t]=0;m++;t=0;}
 }
 c[m][t]=0;q=0;
 printf("case #%d:\n",i);
 qsort(c,m,sizeof(c[0]),cmp);
  for(p=0;p<m+1;p++)
 { flag=1;
 for(a=p;a<m;a++)
 { if (strlen(c[a])==strlen(c[p]))
 { for(b=0;b<strlen(c[p]);b++)
   {if (c[a][b]!=c[p][b]) flag=0;}
 }
 }
 if (flag==1)
 {
   for(b=0;b<strlen(c[p]);b++)
   {d[q][b]=c[p][b];
   }
   d[q][b]=0;
 q++;
 }
 }
  for (p=0;p<m+1;p++)
 printf("%s ",d[p]);
 printf("\n");
memset(d,0,sizeof(d));
}
 return 0;   
    
}