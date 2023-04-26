#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double a[26];//存放26个字母所本别代表的频率


//输出字符所代表的频率
double count1(char b)
{
    if(b >= 'A' && b <= 'Z')
    {
        return a[b - 'A'];
    }
    else
    {
        return a[b - 'a'];
    }
}

//将大写字符变为小写字母
int change(char x)
{
    if(x >= 'a')
    {
        return x;
    }
    else
    {
        return x + 32;
    }
}

//比较
int cmp(const void* a, const void* b)
{
    char A = *(char*)a;
    char B = *(char*)b;
    //比较字母所带表的频率
    if(count1(A) != count1(B))
    {
        return count1(A) < count1(B) ? 1:-1;
    }
    else
    {
        //查看是否为同一字母
        if(((A - 32) == B)||((A + 32)==B)||A == B)
        {
            if(A == B)
                return 1;
            else
                return A < B;
        }
        else
        {
            //将不同的字母都转换为大写并比较
            return change(A) > change(B);
        }
    }
}

int main()
{
    int T;
    char s[101];
    int lens;
    scanf("%d",&T);
    for(int i = 0;i < T; i++)
    {
        for(int j = 0;j < 26; j++)
        {
            scanf("%lf",&a[j]);//将频率记录到数组中
        }
        scanf("%s",s);
        lens = strlen(s);
       qsort(s,lens,sizeof(s[0]),cmp);
       printf("case #%d:\n%s",i,s);
       printf("\n");
    }
    return 0;
}
