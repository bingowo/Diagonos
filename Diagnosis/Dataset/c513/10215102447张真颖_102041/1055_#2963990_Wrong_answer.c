#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000001]={0};
int main()
{
    int arr[127]={0};
    scanf("%s",s);
    int mlen=0,tlen=0,l=-1,r=-1;
    for(int i=0;i<strlen(s);i++)
    {
        if(arr[s[i]]==0)//当没有出现时，统计长度，标记出现
        {

            tlen++;
            arr[s[i]]=1;
        }
        else if(arr[s[i]])//当出现重复时，比较长度，更新左右下标
        {
            if(tlen>mlen)
            {
                l=l+1;//左下标向后移动一位
                r=l+tlen-1;//右下标等于左下标加长度
                arr[s[i]]=0;
                mlen=tlen;
            }
            tlen-=1;//减去开头的字符，剩下字符串的长度
        }
        if(i==strlen(s)-1&&tlen>mlen)//讨论到结尾时结束的长度是否比之前大
        {
            l=l+1;
            r=l+tlen;
        }
    }
    for(int i=l;i<=r;i++)
        printf("%c",s[i]);
    return 0;
}