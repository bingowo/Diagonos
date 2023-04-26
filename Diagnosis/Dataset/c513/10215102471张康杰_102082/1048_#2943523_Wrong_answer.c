#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct 
{
    int coe;
    int exp;
}NUM;
int cmp(const void*a,const void*b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
    NUM num1[100];
    NUM num2[100];
    char s[101],t[101];
    while(scanf("%s %s",s,t) != EOF)
    {
        char*pt1,*pt2;
        pt1 = s;
        pt2 = t;
        int i = 0,j = 0;
        int flag2 = 0,flag3 = 0;
        //三个flag分别记录
        for(pt1;*pt1;pt1++)
        {
            if(isdigit(*pt1))
            {   
                flag3 = 1;
                if(flag2)
                {
                    num1[i].coe = -(*pt1 - '0');
                    flag2 = 0;
                }
                else
                {
                    num1[i].coe = *pt1 - '0';
                    //if(*(pt1+1) != 'x')
                        //num[i].exp = 0;
                }
            }
            else if(*pt1 == 'x')
            {
                if(flag3)
                    flag3 = 0;
                else
                    num1[i].coe = 1;
                if(*(pt1++))
                {
                    if(*pt1 == '^')
                    {
                        pt1++;
                        if(isdigit(*pt1))
                            num1[i].exp = *pt1 - '0';

                    }
                    else
                    {
                        num1[i].exp = 1;
                        if(*pt1 == '+')
                            i++;
                        else if(*pt1 == '-')
                        {
                            flag2 = 1;
                            i++;
                        }
                    }
                }
                else
                {
                    num1[i].exp = 1;
                }
                    
            }
            else if(*pt1 == '-')
            {
                flag2 = 1;
                i++;
            }
            else if(*pt1 == '+')
                i++;
        }
        if(flag3)
        {
            num1[i].exp = 0;
        }
        flag2 = 0,flag3 = 0;
        for(pt2;*pt2;pt2++)
        {
            if(isdigit(*pt2))
            {   
                flag3 = 1;
                if(flag2)
                {
                    num2[j].coe = -(*pt2 - '0');
                    flag2 = 0;
                }
                else
                {
                    num2[j].coe = *pt2 - '0';
                    //if(*(pt2+1) != 'x')
                        //num[i].exp = 0;
                }
            }
        
            else if(*pt2 == 'x')
            {
                if(flag3)
                    flag3 = 0;
                else
                    num2[j].coe = 1;
                if(*(pt2++))
                {
                    if(*pt2 == '^')
                    {
                        pt2++;
                        if(isdigit(*pt2))
                            num2[j].exp = *pt2 - '0';

                    }
                    else
                    {
                        num2[j].exp = 1;
                        if(*pt2 == '+')
                        j++;
                        else if(*pt2 == '-')
                        {
                            flag2 = 1;
                            j++;
                        }
                    }
                }
                else
                {
                    num2[j].exp = 1;
                }
                    
            }
            else if(*pt2 == '-')
            {
                flag2 = 1;
                j++;
            }
            else if(*pt2 == '+')
                j++;
        }
        if(flag3)
        {
            num2[j].exp = 0;
        }
        int mutiple[100];
        memset(mutiple,0,sizeof(int)*100);
        //结构体怎么初始化为0？？？？？？？
        //int coefficent[100],count = 0;
        int count = 0;
        //i执行到这变成0了？？？？
        for(int k = 0;k <= i;k++)
        {
            for(int h = 0;h <= j;h++)
            {
                mutiple[num1[k].exp + num2[h].exp] += num1[k].coe*num2[h].coe;
                count++;
                //coefficent[count++] = num1[k].exp + num2[h].exp;
            }
        }
        for(int k = 99;k >= 0;k--)
        {
            if(mutiple[k] == 0)
                continue;
            printf("%d%c",mutiple[k],' ');
        }
        putchar('\n');
    }
    return 0;
}

