#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long s2d(char s[])
{
    int arr[127]={0};
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
    if(sign==1) sign=2;//特殊情况，如果是1和0组成的字符串，两者都有，那么上面循环会包含，如果全是1，那么算出来的进制是1，需要改成2
    long long r=0;
    for(int i=0;i<strlen(s);i++)
        r=r*sign+arr[s[i]];
    return r;
}


int cmp(const void*pa,const void*pb)
{
    char* a=*(char(*)[16])pa,*b=*(char(*)[16])pb;
    if(s2d(a)>s2d(b)) return 1;
    else if(s2d(a)<s2d(b)) return -1;
    else return strcmp(a,b);
}

int main()
{
    int N=0;
    scanf("%d",&N);
    char s[10000][16]={0};
    for(int i=0;i<N;i++)
        scanf("%s",s[i]);
    qsort(s,N,sizeof(s[0]),cmp);
    for(int i=0;i<N;i++)
        printf("%s\n",s[i]);
    return 0;
}