#include <stdio.h>
#include <stdlib.h>
#define L 4

int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i < T;i++)
    {
        int light[L] = {0};
        //0表示R，1表示B，2表示Y，3表示G

        int cnt = 0;
        char ch;
        int flag[L] = {0};
        while((ch = getchar()) != '\n')
        {
            switch(ch)
            {
                case 'R':
                    flag[0] = 1;
                    cnt++;
                    break;
                case 'B':
                    flag[1] = 1;
                    cnt++;
                    break;
                case 'Y':
                    flag[2] = 1;
                    cnt++;
                    break;
                case 'G':
                    flag[3] = 1;
                    cnt++;
                    break;
                default:
                    cnt++;
            }
            if(cnt == L)
            {
                for(int j = 0;j < L;j++)
                {
                    if(flag[j] == 0)
                    {
                        light[j]++;
                    }
                    else
                        flag[j] = 0;
                }
                cnt = 0;
            }
            else 
                continue;
        }
        printf("case #%d:\n",i);
        for(int j = 0;j < L;j++)
        {
            printf("%d%c",light[j],(j == L - 1)?'\n':' ');
        }
    }
}
