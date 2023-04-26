#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void minus(char*a,char*b)
{int k=strlen(a)-1,i,j,o;
for(i=strlen(b)-1;i>=0;i--,k--)
{if(a[k]>=b[i]) {a[k]=a[k]-b[i]+'0';}
else {
    for(j=1;a[k-j]=='0';j++) {a[k-j]='9';}
a[k-j]--;
a[k]=a[k]-b[i]+10+'0';}
}
for(o=0;a[o]=='0'&&o!=strlen(a)-1;o++);
for(;o<strlen(a);o++)
printf("%c",a[o]);}
int main()
{char a[500],b[500];
while(scanf("%s%s",a,b)!=EOF)
{int flag=0;
if(strlen(a)<strlen(b)){flag=1;}
if(strlen(a)==strlen(b)&&strcmp(a,b)<0){flag=1;}
if(flag) {printf("-");minus(b,a);}
else minus(a,b);
printf("\n");
}

}

