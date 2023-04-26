#include<stdio.h>
#include<string.h>
int main()
{
    /*总体思路：要找到字符串所能表示的最小数，
    由数学知识可知：进制数不同字符的个数相等
    利用循环找出不同字符的个数：
    第一层循环：遍历字符串中的字符并逐个进行判断，计数值cnt应当在这一层循环之前声明并赋初值0；
    第二层循环：遍历当前字符前面的字符，如果遇到相同的则进入跳出当前循环，
    并且将先前的相同字符对应的值取出来放在当前字符对应的值地址中，
    如果第二层循环结束仍然没有在前面的字符中找到相同的字符，
    则计数值cnt+1，如果cnt==2，则将当前字符对应的值设置为0，
    否则如果cnt>2，则将当前字符对应的值设置为cnt-1
    然后利用秦九韶算法计算每一串字符串对应的最小值：
    遍历memry[j][1]；*/
    int t,i=0;
    char arr[10][60];       //存放输入字符串的数组
    char memry[60][2];//声明一个存放字符和其对应的数值的二维数组
    long long rslt[10];     //结果数组
    scanf("%d",&t);
    while(i<t)
    {
        scanf("%s",*(arr+i));
        char *q=*(arr+i);
        //查找相同字符的个数
        int cnt=0;
        int j=0;
        while(*q)
        {
            char *p=*(arr+i);
            do
            {
                if(*p!=*q)continue;
                else
                {
                    if(p==q)
                    {//如果到当前字符只有该字符本身等于它，则在顺序中是一个新的字符
                        cnt++;
                        memry[j][1]=cnt==1?1:cnt==2?0:cnt-1;
                        break;
                    }
                    else
                    {//否则将前面出现过的字符所代表的值再一次和当前字符匹配
                        memry[j][0]=*p;
                        char *p2=*(arr+i);
                        int k=p-p2;
                        memry[j][1]=memry[k][1];
                        break;
                    }
                }
            }while(q>p++);
            q++;j++;
        }
        if(cnt==1)cnt++;
        //如果遍历所有的字符，找不到第二个不同的字符，则cnt用作进制数时需要+1
        memry[j][1]=-1;//flag
        j=0;
        long long temp=memry[0][1];
        while(memry[++j][1]>=0)
        {
            temp=temp*cnt+memry[j][1];
        }
        rslt[i]=temp;   //秦九韶算法获取每个字符串所能表示的最小数值
        i++;
    }
    for(i=0;i<t;i++)printf("case #%d:\n%lld\n",i,rslt[i]);
    return 0;
}
