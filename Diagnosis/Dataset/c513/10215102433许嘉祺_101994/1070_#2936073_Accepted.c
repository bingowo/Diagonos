#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()

{   int d;
    scanf("%d",&d);
int a[21],num00[21],num01[21],num10[21],num11[21];
memset(a,0,sizeof(a));
num00[2]=1;
num11[2]=1;
num10[2]=1;
num01[2]=1;
a[1]=2;
a[2]=4;

    for(int i=3;i<=20;i++){
        num00[i]=num00[i-1]+num10[i-1];
        num11[i]=num01[i-1]+num11[i-1];
        num10[i]=num11[i-1]+num01[i-1];
        num01[i]=num00[i-1];
        a[i]=num00[i]+num01[i]+num10[i]+num11[i];
    }
    while (d!=-1){

        printf("%d\n",a[d]);
        scanf("%d",&d);
    }
    return 0;
}