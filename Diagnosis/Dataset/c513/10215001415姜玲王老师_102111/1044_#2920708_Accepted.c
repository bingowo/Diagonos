#include <stdio.h>
#include <stdlib.h>

int main()
{char c,d,f;
unsigned long long sum=0;
c=getchar();
int flag=0;
while((d=getchar())!=EOF)
{sum=0;
if(c=='0'&&d=='x')
{f=getchar();
if(f>='a'&&f<='f')
    {flag++;
sum=sum*16+f-'a'+10;
while((f=getchar())!=EOF&&((f>='0'&&f<='9')||(f>='a'&&f<='f')))
{if(f>='a'&&f<='f') {sum=sum*16+f-'a'+10;}
else{sum=sum*16+f-'0';}}
printf("%llu ",sum);
c=f;}
else{if(f>='0'&&f<='9')
{flag++;
sum=sum*16+f-'0';
while((f=getchar())!=EOF&&((f>='0'&&f<='9')||(f>='a'&&f<='f')))
{if(f>='a'&&f<='f') {sum=sum*16+f-'a'+10;}
else{sum=sum*16+f-'0';}}
printf("%llu ",sum);
c=f;}
else c=f;}}
else{c=d;}
}
if(flag==0) printf("-1");}

