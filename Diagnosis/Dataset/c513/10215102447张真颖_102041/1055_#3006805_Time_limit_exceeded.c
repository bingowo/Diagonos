#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[128];
    for(int i=0;i<128;i++) arr[i]=-1;
    int start=0;//标记最长无重复子串的起始位置
    int maxlen=0;//标记长度
    int t=0;//标记比较的开始

    char s[1000001]={0};
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(arr[s[i]]>=t)
        {
            t=arr[s[i]]+1;
            arr[s[i]]=i;
        }
        else
        {
            arr[s[i]]=i;
            if(maxlen<i-t+1)
            {
                maxlen=i-t+1;
                start=t;
            }
        }
    }
    for(int i=start;i<start+maxlen;i++)
        printf("%c",s[i]);

}