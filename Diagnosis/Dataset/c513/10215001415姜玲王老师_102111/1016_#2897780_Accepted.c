#include <stdio.h>
#include <stdlib.h>

int main()
{char k[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
int num[1000];
int a,b,temp,i;
scanf("%d%d",&a,&b);\
if(a==0){printf("0");return 0;}
for(i=0;a;i++)
    {temp=a%b;
    if(temp<0){num[i]=temp-b;a=(a-num[i])/b;}
    else{num[i]=a%b;a/=b;}}
for(i--;i>=0;i--){printf("%c",k[num[i]]);}}
