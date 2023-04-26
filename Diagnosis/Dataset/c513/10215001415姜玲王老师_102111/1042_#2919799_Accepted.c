 #include <stdio.h>
#include <stdlib.h>
#include<string.h>
char d[100];
void print(char*a,int len,int l,int r)
{if(l==r) return;
for(;l!=r;l++)
{d[len]=a[l];
d[len+1]=0;
printf("%s\n",d);
print(a,len+1,l+1,r);

}}


int main()
{int n;
char a[17];
scanf("%d",&n);
for(int i=0;i<n;i++)
{int b[130]={0},count=0;
char c[53]={0};
printf("case #%d:\n",i);
scanf("%s",a);
for(int k=0;k<strlen(a);k++)
{b[a[k]]++;}
for(int k=0;k<26;k++)
{if(b[k+'A']) c[count++]='A'+k;}
for(int k=0;k<26;k++)
{if(b[k+'a']) c[count++]='a'+k;}
print(c,0,0,strlen(c));
}
return 0;}


