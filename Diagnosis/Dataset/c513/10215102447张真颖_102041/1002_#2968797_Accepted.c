#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    int arr[127]={0};
    for(int i=0;i<T;i++)
    {
        char s[61]={0};
        scanf("%s",s);
        int sign=0;
        for(int i=0;i<127;i++)
             arr[i]=-1;//标记每个元素的数值,一定要放在循环里初始化
        for(int i=0;i<strlen(s);i++)//遍历字符串，更新arr
        {
            if(i==0)//如果是第一个，必为1
            {
                arr[s[i]]=1;
                sign=1;//改变一下进制
            }
            else if(sign==1&&arr[s[i]]==-1)//如果第二个非重复的，必为0
            {
                arr[s[i]]=0;
                sign+=1;
            }
            else if(sign>1&&arr[s[i]]==-1)//剩下的值就和上一个进制的值是一样的了
            {
                arr[s[i]]=sign;
                sign+=1;
            }
        }
        if(sign==1&&s[0]=='1') sign=2;//特殊情况，如果是1和0组成的字符串，两者都有，那么上面循环会包含，如果全是1，那么算出来的进制是1，需要改成2
        long long r=0;
        for(int i=0;i<strlen(s);i++)
            r=r*sign+arr[s[i]];
        printf("case #%d:\n%lld\n",i,r);
    }
    return 0;
}