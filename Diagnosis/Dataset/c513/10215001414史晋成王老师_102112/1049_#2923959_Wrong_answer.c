#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{char s[1000],c[500][100]; int n,i,j,m,k,t,p;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s);
 j=strlen(s);
 m=0;t=0;
 for(k=0;k<j;k++)
 { if(s[k]!=' '&&s[k]!=','&&s[k]!='.'&&s[k]=='!')
    {c[m][t]=s[k]; t++;}
    else if (s[k]==' '||s[k]==','||s[k]=='.'||s[k]=='!')
    {c[m][t]=0;m++;t=0;}
 }
 for (p=0;p<m;p++)
 printf("%s ",c[p]);
 printf("\n");
}
 return 0;   
    
}