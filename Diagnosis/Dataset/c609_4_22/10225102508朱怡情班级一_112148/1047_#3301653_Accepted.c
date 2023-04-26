#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        int result[95]={1};
        int n,a;
        scanf("%d%d",&n,&a);
        for(int i=0;i<a;i++){
            int carry=0;
            for(int j=0;j<95;j++){
               int t=result[j]*n+carry;
               result[j]=t%10;
               carry=t/10;
            }
        }
        int i;
        for(i=94;i>=0;i--)
            if(result[i]!=0)break;
        for(i=i;i>=0;i--)
            printf("%d",result[i]);
        printf("\n");
    }
    return 0;
}
