#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void sum(char*a)
{int i;
char b[11],c[11];
strcpy(b,a);
strcpy(c,a);
memset(a,0,sizeof(a[0])*11);
for(i=0;i<strlen(b);i++)
{a[i]+=(b[i]-'0'+c[strlen(c)-1-i]-'0')%10+'0';
a[i+1]+=(b[i]-'0'+c[strlen(c)-1-i]-'0')/10;
}
if(a[i]!=0) a[i]+='0';}
int ispalindrome(char*a)
{int i;
for(i=0;a[i]==a[strlen(a)-1-i]&&i<strlen(a);i++);
if(i==strlen(a)) return 1;
return 0;}
int palindrome(char*a,int t)
{sum(a);
t++;
if(ispalindrome(a)) return t;
return palindrome(a,t);

}
int main()
{char a[11];
scanf("%s",a);
printf("%d ",palindrome(a,0));
printf("%s",a);


}
