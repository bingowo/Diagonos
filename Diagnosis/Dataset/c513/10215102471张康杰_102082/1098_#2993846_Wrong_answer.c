#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 256
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int j,k,len,pos,pos1,flag1 = 0;
        int light[L] = {0},flag[L];
        memset(flag,0,sizeof(int) * L);
        char input[101];
        scanf("%s",input);
        len = strlen(input);
        for(j = 0;j < len;j++)
        {
            int cnt = 0,cnt1 = 0;
            for(k = 0;k < 4;k++)
            {
                if(input[k + j] == '!')
                    cnt1++;
                cnt++;
            }
            if(cnt == 4 && cnt1 == 1)
            {
                flag1 = 1;
                pos = j;
                break;
            }
        }
        if(flag1)
        {
            for(j = pos;j < pos + 4;j++)
            {
                switch(input[j])
                {
                    case 'R':
                        flag['R'] = 1;
                        break;
                    case 'B':
                        flag['B'] = 1;
                        break;
                    case 'Y':
                        flag['Y'] = 1;
                        break;
                    case 'G':
                        flag['G'] = 1;
                        break;
                    default:
                        pos1 = j;
                }
            }
            /*
            for(j = 0;j < L;j++)
            {
                if(flag[j] == 0)
                {
                    input[pos1] = j;
                    light[j]++;
                }
            }
            */
            if(flag['R'] == 0)
            {
                input[pos1] = 'R';
                light['R']++;
            }
            else if(flag['B'] == 0)
            {
                input[pos1] = 'B';
                light['B']++;
            }
            else if(flag['Y'] == 0)
            {
                input[pos1] = 'Y';
                light['Y']++;
            }
            else
            {
                input[pos1] = 'G';
                light['G']++;
            }
            for(j = pos + 1;j < len - 3;j++)
            {
                memset(flag,0,sizeof(int) * L);
                for(k = 0;k < 4;k++)
                {
                    switch(input[j + k])
                    {
                        case 'R':
                            flag['R'] = 1;
                            break;
                        case 'B':
                            flag['B'] = 1;
                            break;
                        case 'Y':
                            flag['Y'] = 1;
                            break;
                        case 'G':
                            flag['G'] = 1;
                            break;
                    }
                }
                if(flag['R'] == 0)
                {
                    input[pos1] = 'R';
                    light['R']++;
                }
                else if(flag['B'] == 0)
                {
                    input[pos1] = 'B';
                    light['B']++;
                }
                else if(flag['Y'] == 0)
                {
                    input[pos1] = 'Y';
                    light['Y']++;
                }
            }
            for(j = pos + 2;j > 2;j--)
            {
                memset(flag,0,sizeof(int) * L);
                for(k = 0;k < 4;k++)
                {
                    switch(input[j - k])
                    {
                        case 'R':
                            flag['R'] = 1;
                            break;
                        case 'B':
                            flag['B'] = 1;
                            break;
                        case 'Y':
                            flag['Y'] = 1;
                            break;
                        case 'G':
                            flag['G'] = 1;
                            break;
                    }
                }
                if(flag['R'] == 0)
                {
                    input[pos1] = 'R';
                    light['R']++;
                }
                else if(flag['B'] == 0)
                {
                    input[pos1] = 'B';
                    light['B']++;
                }
                else if(flag['Y'] == 0)
                {
                    input[pos1] = 'Y';
                    light['Y']++;
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",light['R'],light['B'],light['Y'],light['G']);
    }
    return 0;
}