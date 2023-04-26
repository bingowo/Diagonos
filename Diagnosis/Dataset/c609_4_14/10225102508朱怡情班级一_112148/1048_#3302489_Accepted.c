#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        if(n==0)printf("0\n");
        else{
            int f1[26]={0};//存当前数值
            int f2[26]={1};//存前一数值
            for(int j=1;j<=n;j++){
                int carry=0;
                for(int l=0;l<26;l++){
                    int t=f1[l]+f2[l]+carry;
                    f2[l]=f1[l];
                    f1[l]=t%10;
                    carry=t/10;
                }
            }
            int k;
            for(k=25;k>=0;k--)if(f1[k])break;
            for(k=k;k>=0;k--)printf("%d",f1[k]);
            printf("\n");
        }
    }
    return 0;
}
