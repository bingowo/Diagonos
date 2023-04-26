#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000001]={0};
int main()
{
    int arr[127]={0};
    for(int i=0;i<127;i++) arr[i]=-1;
    scanf("%s",s);
    int mlen=0,tlen=0,rl=0,rr=0,tl=0,tr=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(arr[s[i]]==-1)//当没有出现时，统计长度，标记出现
        {
            tlen++;
            arr[s[i]]=i;
            tr++;
        }
        else if(arr[s[i]]!=-1)//当出现重复时，比较长度，更新左右下标
        {
            int x=tl;
            if(tlen>mlen)
            {
                rl=tl;
                rr=tr;
                mlen=tlen;
            }
            tl=arr[s[i]]+1;//左下标向后移动到重复的位
            for(int j=x;j<arr[s[i]];j++)
                arr[s[j]]=-1;
            tlen=tlen-(tl-x)+1;//现在的长度减去（重复下标-开头下标）
            tr=i;
            arr[s[i]]=i;
        }
        if(i==strlen(s)-1&&tlen>mlen)//讨论到结尾时结束的长度是否比之前大
        {
            rr=i;
        }
    }
    for(int i=rl;i<=rr;i++)
        printf("%c",s[i]);
    return 0;
}