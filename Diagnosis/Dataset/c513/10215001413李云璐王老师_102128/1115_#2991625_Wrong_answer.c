#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[100];
        scanf("%s",s);
        int len=strlen(s);
        int flag=0;
        for(int l=0;l<len-1;l++)
        {
            int wei;
            char min='9';
            wei=len-1;
            for(int k=len-1;k>l;k--)
            {
                if(s[k]>s[l]) {flag=1;min=(min>s[k])?s[k]:min;wei=(min>=s[k])?k:wei;}
            }
            if(flag==1) {char z=s[l];s[l]=s[wei];s[wei]=z;break;}
        }
        printf("case #%d:\n",i);
        if(flag==0)
        {
            printf("%c0",s[len-1]);
            for(int j=len-2;j>=0;j--)
                printf("%c",s[j]);
            printf("\n");
        }
        if(flag==1) {printf("%s\n",s);}





    }
    return 0;
}
