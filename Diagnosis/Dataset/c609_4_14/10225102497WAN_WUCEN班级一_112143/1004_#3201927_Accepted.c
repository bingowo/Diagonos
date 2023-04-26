#include<stdio.h>
#include<ctype.h>

int atod(char a)
{int b;
if(isalpha(a)){a=toupper(a);b=a-55;}
else b=a-48;
return b;
}

main()
{char out[32];
char in[32];
char table[]="0123456789ABCDEF";
int A,B,l,n=0;
int i=0;
scanf("%d%s%d",&A,in,&B);
for(l=0;in[l]!='\0';l++)
n=n*A+atod(in[l]);
do {out[i++]=table[n%B];}
while (n=n/B);
for(i--;i>-1;i--)
printf("%c",out[i]);
}


