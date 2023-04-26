#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int isstring(char *a)
{ if(strlen(a)==1&&a[0]=='a') return -1;
 else if (strlen(a)==2&&a[0]=='a'&&a[1]=='n') return -1;
 else if (strlen(a)==3&&a[0]=='a'&&a[1]=='n'&&a[2]=='d') return -1;
 else if (strlen(a)==3&&a[0]=='t'&&a[1]=='h'&&a[2]=='e') return -1;
 else if (strlen(a)==3&&a[0]=='f'&&a[1]=='o'&&a[2]=='r') return -1; 
 else if (strlen(a)==2&&a[0]=='o'&&a[1]=='f') return -1;
 else return 1;
}
int main()
{int T,i,j,k,sum,d; char s[110][110];
scanf("%d",&T);
for(i=0;i<T;i++)
{j=0; while(scanf("%s",s[j])!='\n') j++;
sum=0;
for(k=0;k<j;k++)
{
if(isstring(s[k])==1) sum++;
}
printf("case #%d:\n",i);
for(d=0;d<j;d++)
{ printf("%s ",s[d]);
}
printf("%d\n",sum);
}
    
}