#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char s[10005];

int main()
{
    scanf("%s",s);
    char c;
    long long sum1=0,sum2=0,flg=1,hav=1,res=0;
    //hav代表等号的左右
    //sum1代表数字之和
    //sum2代表系数之和
    //flg代表符号
    //res临时储存系数或数字
    for(int i=0;s[i];i++)
    {
        if(s[i]=='-')
            flg=-1*hav;
        else if(s[i]=='+')
            flg=hav;
        else if(s[i]=='=')
        {
            hav=-1;
            flg=hav;
        }
        else if(s[i]>='0'&&s[i]<='9') //遇见数字的情况
        {
            res=res*10+s[i]-'0';
            if(s[i+1]>='a'&&s[i+1]<='z')
            {
                c=s[i+1];
                sum2+=res*flg;
                res=0;
                flg=hav;
                i++;
            }
            else if(s[i+1]<'0'||s[i+1]>'9') //后面是符号或是末尾
            {
                sum1+=res*flg;
                res=0;
                flg=hav;
            }
            //不然就是数字的情况，下一轮再加
        }
        else //系数为+1或-1的未知数
        {
            c=s[i];
            sum2+=flg;
            res=0;
            flg=hav;
        }
    }
    if(sum1!=0)
        printf("%c=%.3f\n",c,-1.0*sum1/sum2);
    else
        printf("%c=0.000\n",c);
    return 0;
}
//算法是想得到的
//但是实践较难
