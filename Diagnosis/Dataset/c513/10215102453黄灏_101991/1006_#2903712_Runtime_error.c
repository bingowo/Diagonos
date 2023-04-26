#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        char th[1000];//三进制数
        int ans[1000];//十进制数
        int len=0;
        int sum;
        while(scanf("%c",th[len])!=EOF) len++;
        for(int i=0;i<len;i++){
            if(th[i]=='-') ans[i]=-1;
            if(th[i]=='1') ans[i]=1;
            else ans[i]=0;
            sum = sum+ans[i]*pow(3,len-1-i);
        }
        printf("case #%d:\n",cas);
        printf("%d",sum);

    }
    return 0;
}
