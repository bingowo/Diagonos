#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void insert(char*a,char b,int c)
{char d[102];
strcpy(d,a);
a[c]=b;
for(int i=c+1;i<strlen(d)+1;i++)
{a[i]=d[i-1];}

}
void cancel(char*a)
{char b[102];
int i;
strcpy(b,a);
memset(a,0,102);
int k=0;
if(b[0]!=b[1])
{a[0]=b[0];k++;}
for( i=1;i<strlen(b)-1;i++)
{if(b[i]!=b[i-1]&&b[i]!=b[i+1]) a[k++]=b[i];}
if(b[i]!=b[i-1]) a[k]=b[i];

}
int judge(char*a)
{if(strstr(a,"AA")) return 1;
if(strstr(a,"BB")) return 1;
if(strstr(a,"CC")) return 1;
return 0;
}
int main()
{int n,min,temp;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    printf("case #%d:\n",i);
    char a[102],p[102];
scanf("%s\n",a);
strcpy(p,a);
insert(a,'A',0);
while(judge(a)) {cancel(a);}
min=strlen(a);
strcpy(a,p);
insert(a,'B',0);
while(judge(a)) cancel(a);
temp=strlen(a);
if(temp<min) min=temp;
strcpy(a,p);
insert(a,'C',0);
while(judge(a)) cancel(a);
temp=strlen(a);
if(temp<min) min=temp;
strcpy(a,p);
for(int k=1;k<strlen(a)+1;k++)
{insert(a,'A',k);
while(judge(a)) cancel(a);
temp=strlen(a);
if(temp<min) min=temp;
strcpy(a,p);
insert(a,'B',k);
while(judge(a)) cancel(a);
temp=strlen(a);
if(temp<min) min=temp;
strcpy(a,p);
insert(a,'C',k);
while(judge(a)) cancel(a);
temp=strlen(a);
if(temp<min) min=temp;
strcpy(a,p);
}
printf("%d\n",strlen(p)-min+1);
}
}
