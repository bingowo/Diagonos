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
        int light[L] = {0},flag[L] = {0};
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
            for(j = pos;j < pos + L;j++)
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
            for(j = 0;j < L;j++)
            {
                if(flag[j] == 0)
                {
                    input[pos1] = j;
                    light[j]++;
                }
            }
            for(j = pos + 1;j < len - 3;j++)
            {
                memset(flag,0,4*sizeof(int));
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
                for(int m = 0;m < L;j++)
                {
                    if(flag[m] == 0)
                    {
                        input[pos1] = m;
                        light[m]++;
                    }
                }
            }
            for(j = pos + 2;j > 2;j++)
            {
                memset(flag,0,4*sizeof(int));
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
                for(int m = 0;m < L;j++)
                {
                    if(flag[m] == 0)
                    {
                        input[pos1] = m;
                        light[m]++;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",light['R'],light['B'],light['Y'],light['B']);
    }
    return 0;
}