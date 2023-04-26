#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(char *p1,int length,char p2)
{
    for(int i = 0;i<length;i++)
    {
        if(*(p1+i) == p2)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    char s[200];
    char all[62];
    for(int i =0 ;i<T;i++)
    {
        int flag = 0;//特判1111的情况
        int a[123];//记录字符存储的值
        int R =0;
        char *p = s;
        scanf("%s",&s);
        int length = 0;
        while((*p)!=0)//取得R值
            {
                if(cmp(all,length,*p))
                {
                    all[length] = *p;
                    length ++;
                    R+=1;
                }
                p++;
            }
        if (R==1)
        {
            flag = 1;
            R =2;
        }
        for(int j = 0;j < strlen(all);j++)
        {
            if(flag)
            {
                a[all[j]] = 1;
                break;
            }
            else if(j == 0)a[all[j]] = 1;
            else if(j==1) a[all[j]] = 0;
            else a[all[j]] = j;
        }
        long long int res = 0;
        for(int j = 0;j< strlen(s);j++)
        {
            res *=R;
            res += a[s[j]];
        }
        printf("case #%d:\n%lld\n",i,res);
    }
    return 0;

}
