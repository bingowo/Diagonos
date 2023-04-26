#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    int i;
    scanf("%d",&T);
    getchar();
    
    //输入字符串
    //
    for (i=0;i<T;i++)
    {
        int j;
        char s[21];
        int cnt_a[26]={0};//统计各个字母出现次数
        int cnt_d[10]={0};//统计各个数字出现次数
        char *p=NULL;
        scanf("%s",s);
        p=s;

        while (*p)
        {
            cnt_a[*p-'A']++;
            p++;
        }

        //解密——找到每个单词中的独一无二的字符
        j=strlen(s);
        while (j>0)
        {
            if (cnt_a['W'-'A'])
            {
                cnt_d[2]++;
                cnt_a['T'-'A']--; cnt_a['W'-'A']--; cnt_a['O'-'A']--;
                j-=3;
            }
            else if (cnt_a['U'-'A'])
            {
                cnt_d[4]++;
                cnt_a['F'-'A']--; cnt_a['O'-'A']--; cnt_a['U'-'A']--; cnt_a['R'-'A']--;
                j-=4;
            }
            else if(cnt_a['X'-'A'])
            {
                cnt_d[6]++;
                cnt_a['S'-'A']--; cnt_a['I'-'A']--; cnt_a['X'-'A']--;
                j-=3;
            }
            else if (cnt_a['G'-'A'])
            {
                cnt_d[8]++;
                cnt_a['E'-'A']--; cnt_a['I'-'A']--; cnt_a['G'-'A']--; cnt_a['H'-'A']--; cnt_a['T'-'A']--;
                j-=5;
            }
            else if (cnt_a['Z'-'A'])
            {
                cnt_d[0]++;
                cnt_a['Z'-'A']--; cnt_a['E'-'A']--; cnt_a['R'-'A']--; cnt_a['O'-'A']--;
                j-=4;
            }
            else 
            {
                if (cnt_a['O'-'A'])
                {
                    cnt_d[1]++;
                    cnt_a['O'-'A']--; cnt_a['N'-'A']--; cnt_a['E'-'A']--;
                    j-=3;
                }
                else if(cnt_a['R'-'A'])
                {
                    cnt_d[3]++;
                    cnt_a['T'-'A']--; cnt_a['H'-'A']--; cnt_a['R'-'A']--; cnt_a['E'-'A']-=2;
                    j-=5;
                }
                else if(cnt_a['F'-'A'])
                {
                    cnt_d[5]++;
                    cnt_a['F'-'A']--; cnt_a['I'-'A']--; cnt_a['V'-'A']--; cnt_a['E'-'A']--;
                    j-=4;
                }
                else if (cnt_a['S'-'A'])
                {
                    cnt_d[7]++;
                    cnt_a['S'-'A']--; cnt_a['E'-'A']-=2; cnt_a['V'-'A']--; cnt_a['N'-'A']--;
                    j-=5;
                }
                else if (cnt_a['I'-'A'])
                {
                    cnt_d[9]++;
                    cnt_a['N'-'A']-=2; cnt_a['I'-'A']--; cnt_a['E'-'A']--;
                    j-=4;
                }
            }
            
        }

        //输出部分
        printf("case #%d:\n",i);

        for (j=0;j<=9;j++)
        {
            if (cnt_d[j])
            {
                while (cnt_d[j])
                {
                    printf("%d",j);
                    cnt_d[j]--;
                }
            }
        }

        putchar('\n');
    }
    return 0;
}