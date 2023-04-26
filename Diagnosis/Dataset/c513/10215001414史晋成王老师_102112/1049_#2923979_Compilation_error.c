#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{char s[1000],c[500][100],d[500][100]; int n,i,j,m,k,t,p,a,b,flag;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s);
 j=strlen(s);
 m=0;t=0;
 for(k=0;k<j;k++)
 { if(s[k]!=' '&&s[k]!=','&&s[k]!='.'&&s[k]!='!'&&s[k]!='?')
    {c[m][t]=s[k]; t++;}
    else if (s[k]==' '||s[k]==','||s[k]=='.'||s[k]=='!'||s[k]=='?')
    {c[m][t]=0;m++;t=0;}
 }
 c[m][t]=0;
 for(p=0;p<m+1;p++)
 { flag=1;
   for(a=p+1;a<m+1;a++)
 { if (strlen(c[a])==strlen(c[p]))
 { for(b=0;b<strlen(c[a]);b++)
   {if (c[a][b]!=c[p][b]) flag=0;}
 }
 }
 if (falg==1) d[p]=c[p];
 }
 
 printf("case #%d:\n",i);
  for (p=0;p<m+1;p++)
 printf("%s ",d[p]);
 printf("\n");

}
 return 0;   
    
}