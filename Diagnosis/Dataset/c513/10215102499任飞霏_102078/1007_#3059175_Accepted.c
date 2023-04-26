#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int n;
        scanf("%d",&n);
        int m = n;
        int k=0,cmp=1;
        for(k=0;k<32;k++){
            if(cmp >= n)break;
            cmp *= 2;
        }
        int max = 1,len=1;
        int flag = n & 1;

        for(int i=0;i<k-1;i++){
            n = n >> 1;
            int temp = n & 1;
            if(temp != flag){
                len++;
                flag = temp;
            }
            else
                len = 1;
            if(len>max)max = len;

        }
        if(k==32 && m%2 == 0)max-=1;
        printf("%d\n",max);
    }
    return 0;
}
