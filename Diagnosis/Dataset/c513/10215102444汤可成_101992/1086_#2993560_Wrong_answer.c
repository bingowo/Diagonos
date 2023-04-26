#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void SUB(char*s1, char* s2, int N)
{
    int len = strlen(s1)>strlen(s2)?strlen(s1):strlen(s2);
    for(int i = len-1; i>=0; i--)
    {
        if(s1[i] <= 0) s1[i] += '0';
        if(s2[i] <= 0) s2[i] += '0';
        if(s1[i] == '.') continue;
        if(s1[i] >= s2[i]) s1[i] = s1[i] - s2[i] + '0';
        else
        {
            if(s1[i-1]!='.')
            {
                s1[i-1]--;
                s1[i] = s1[i] - s2[i] + 10 + '0';
            }
            else
            {
                s1[i-2]--;
                s1[i] = s1[i] - s2[i] + 10 + '0';
            }
        }
    }
    s1[len] = 0;
    //四舍五入
    int p = 0;
    while(s1[p]!='.') p++;
    if(s1[p+N+1]>='5')
    {
        s1[p+N]++;
        for(int i = p+N; i>=0; i--)
        {
            if(s1[i] == '.') continue;
            if(s1[i]>'9')
            {
                s1[i] = s1[i]-10;
                if(s1[i-1]!='.')s1[i-1]++;
                else s1[i-2]++;
            }
        }
    }
    //输出
    int i = 0;
    while(s1[i] == '0') i++;
    if(s1[i] == '.')
    {
        printf("0.");
        i++;
        for(int j = 0; j<N; j++)
        {
            printf("%c", s1[i]);
            i++;
        }
    }
    else
    {
        int j = 0;
        for(j = 0; j<1050; j++)
        {
            if(s1[j] == '.') break;
        }
        for(; i <= j+N; i++)
        {
            if(s1[i] == 0) s1[i] = '0';
            printf("%c", s1[i]);
        }
    }
}

int main()
{

    //获取
    char s1[1050], s2[1050];
    int N;
    for(int i = 0; i<1050; i++)
    {
        s1[i] = '0';
        s2[i] = '0';
    }
    scanf("%s %s %d", s1, s2, &N);
    int p1, p2;
    for(p1 = 0; p1<1050; p1++)
    {
        if(s1[p1] == '.') break;
    }
    for(p2 = 0; p2<1050; p2++)
    {
        if(s2[p2] == '.') break;
    }
    if(p1 == 1050)
    {
        p1 = strlen(s1);
        s1[strlen(s1)+1] = '\0';
        s1[strlen(s1)] = '.';
    }
    if(p2 == 1050)
    {
        p2 = strlen(s2);
        s2[strlen(s2)+1] = '\0';
        s2[strlen(s2)] = '.';
    }

    //对齐
    if(p1<p2)
    {
        int d = p2-p1;
        for(int i = strlen(s1); i>=0; i--)
        {
            s1[i+d] = s1[i];
            s1[i] = '0';
        }
    }
    else if(p2<p1)
    {
        int d = p1-p2;
        for(int i = strlen(s2); i>=0; i--)
        {
            s2[i+d] = s2[i];
            s2[i] = '0';
        }
    }

    //减法
    if(strcmp(s1, s2)>=0)
    {
        SUB(s1, s2, N);
    }
    else
    {
        printf("-");
        SUB(s2, s1, N);
    }
    return 0;
}
