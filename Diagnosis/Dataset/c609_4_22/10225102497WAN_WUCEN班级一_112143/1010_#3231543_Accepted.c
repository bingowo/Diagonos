#include<stdlib.h>
#include<stdio.h>
main()
{char table[]="0123456789ABCDEFGHIJ";
int base,n,sign=0,i=0;
char out[16];
scanf("%d%d",&n,&base);
do {if(n%base>=0){out[i++]=table[n%base];n=n/base;}
    else {out[i++]=table[n%base-base];n=n/base+1;}}
while (n);
i--;
for(;i>=0;i--)
printf("%c",out[i]);
printf("\n");
}

