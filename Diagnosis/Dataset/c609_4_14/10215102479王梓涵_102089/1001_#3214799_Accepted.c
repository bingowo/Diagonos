#include<stdio.h>
void itob(int n,char s[100],int b)
{
int i=0,j,d,sign;
char c;
if((sign=n)<0) n=-n; //记录符号
do
{ d = n%b;
if(d<10) s[i] = d+'0';
else s[i] = d-10+'A';
i++;
n/=b;
}while(n>0);
if(sign<0) s[i++]='-';
s[i]='\0';
for(i=0,j=strlen(s)-1;i<j;i++,j--) //反转
c=s[i],s[i]=s[j],s[j]=c;
}
int main()
{
    int chance,n,b;
    scanf("%d",&chance);
    int i;
    for(i=0;i<chance;i++){
    char s[100];
    scanf("%d%d",&n,&b);
    itob(n,s,b);
    printf("%s\n",s);}
    return 0;
}