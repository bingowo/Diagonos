#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int n;
int d00[21],d01[21],d1[21];


d00[2] = d01[2] = 1;
d1[2] = 2;

for(n=3;n<=20;n++){
d00[n] = d00[n-1]+d01[n-1];
d01[n] = d1[n-1];
d1[n] = d00[n-1]+d1[n-1];
}
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        else printf("%d\n",d00[n]+d01[n]+d1[n]);
    }
    return 0;
}