
#include <stdlib.h>
#include<stdio.h>
int my_strcmp(char *str1,char*str2)
{
int i=0,j=0;
while((*str1++!='\0')&&(*str2++!='\0'))
{
if((*str1>='0'&&*str1<='9')||(*str2>='0'&&*str2<='9'))
if(*str2<'0'||*str2>'9')
return -1;
else
if(*str1<'0'||*str1>'9')
return 1;
else
if(*str1==*str2);
else
{
if(*str1>*str2)
return -1;
else
return 1;
}
i+=(int)*str1;
j+=(int)*str2;
}
if(i==j)return 0;
return i>j?-1:1;
}
int main()
{
char str[30][30]={"\0"},c,node[30];
int my_return,i=0,j=0,k;
while((c=getche())!='\r')
{
if(c==' ')
{i++;j=0;}
else {str[i][j]=c;j++;}
}i++;
for(j=0;j<i;j++)
for(k=0;k<i-j;k++)
if((my_return=my_strcmp(str[k],str[k+1]))==-1)
{
strcpy(node,str[k+1]);
strcpy(str[k+1],str[k]);
strcpy(str[k],node);
}
for(j=0;j<i;j++)
printf("\n%s",str[j]);
getch();
}