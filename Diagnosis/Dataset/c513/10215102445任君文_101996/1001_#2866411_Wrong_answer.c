#include <string.h>
#include <stdio.h>
#define N 8
unsigned h2i(char s[])
{
int res,m,i,q;
char c;
m=strlen(s);
res=0;
i=0;
while(i<m)
{
c=s[i];
q=0;
if((c>='1')&&(c<='9')){q=(int)c;}
if((c=='a')||(c=='A')){q=10;}
if((c=='b')||(c=='B')){q=11;}
if((c=='c')||(c=='C')){q=12;}
if((c=='d')||(c=='D')){q=13;}
if((c=='e')||(c=='E')){q=14;}
if((c=='f')||(c=='F')){q=15;}
i=i+1;
res=res*16+q;
}
return(res);
}

int main()
{
    char s[N+1];
    scanf("%s",s);
    printf("%u\n",h2i(s));
    return 0;
}