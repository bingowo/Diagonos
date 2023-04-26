#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[31];
    int num;//比较的一个凭据
} str;

int cmp(const void *a,const void *b)
{
    str pa=*(str*)a;
    str pb=*(str*)b;
    if(pa.num==pb.num)
    return strcmp(pa.s,pb.s);
    else 
    return pa.num>pb.num?1:-1;
}

int main()
{
    str arr[100];
    int i=0,n=0;//n统计输入多少个，便于输出
    while(~scanf("%s",arr[i++].s))//读到EOF也会进入arr[i++].s因为，while结束输出i发现 i比输入个数大2
    n++;

    for(int i=0; i<n; i++)//双重循环，先在arr[i]找s,然后arr[i].s[j]找具体的字符，判断是否为数字
    {
        char number[9];//储存数字
        for(int j=0; j<9; j++ )//一定要初始化为0！！！！
        {
            number[j]=0;
        }
        int k=0;
        for(int j=0; arr[i].s[j]; j++)
        {
           if(arr[i].s[j]<58&&arr[i].s[j]>47)//一定要范围严谨，只能是数字的范围，因为除了字母还有其他的符号，可能比数字的ASC码小 
           number[k++]=arr[i].s[j];
        }
        if(k!=0)
        arr[i].num=atoi(number);
        else 
        arr[i].num=-1;//不能赋0，与数字0区别，注意读题干的要求
    }

    qsort(arr,n,sizeof(str),cmp);
    for(int i=0; i<n; i++)
    {
        printf("%s%c",arr[i].s,i==n-1?'\n':' ');
    }
    return 0;

}