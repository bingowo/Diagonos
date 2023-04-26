#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int t;int number;
}Data;

int main()
{
    int n,m = 0;
    Data N[11];//n为问题数，N[]为所输入的数，M用于存储不重复字符串长度;
    scanf("%d\n",&n);//输入问题数
    for(int i=0;i<n;i++)
    {
        scanf("%d",&N[i].t);//输入被检索的数；
    }
    for(int j=0;j<n;j++)
    {
        m = N[j].t;
        int temp = 1, ans = 0;
        while(m)
        {
            if(m%2==1)
            {
                m = m>>1;
                if(m%2==0&&m>0) temp++;
                else{
                    if(temp>ans)    ans=temp;
                    temp = 1;
                }
            }
            else{
                m = m>>1;
                if(m%2>0)temp++;
                else{
                    if(temp>ans)ans=temp;
                    temp = 1;
                }
            }
            N[j].number = ans;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",N[i].number);
    }
    return 0;
}