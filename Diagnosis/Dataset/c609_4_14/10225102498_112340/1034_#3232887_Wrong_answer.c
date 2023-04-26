#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* s = (char*)malloc(100000*sizeof(char));
    char* num = (char*)malloc(100000*sizeof(char));
    memset(s,0,100000*sizeof(char));
    memset(num,0,100000*sizeof(char));
    int i, j;
    scanf("%s", s);
    int len = strlen(s);
    int cnt = 0;
    for(i=0; i<=len; i++)
    {
        if(i == len)
        {
            if(cnt == 0)
            {
                printf("-1");
                break;
            }
        }
        int sum = 0, k = 0;
        if(s[i]=='0'&&s[i+1]=='x')
        {
            for(j=i+2; ;j++)
            {
                if((s[j]>='a'&&s[j]<='f')||(s[j]>='0'&&s[j]<='9'))
                {
                    num[k] = s[j];
                    k++;
                }
                else
                    break;
            }
        }
        if(k != 0)
        {
            int t = 1;
            for(j=k-1; j>=-1; j--)
            {
                if(j == -1)
                {
                    printf("%d ", sum);
                    cnt++;
                    break;
                }
                if(num[j]>='0'&&num[j]<='9')
                    sum += (num[j] - '0')*t;
                if(num[j]>='a'&&num[j]<='f')
                    sum += (num[j] - 'a' + 10)*t;
                t *= 16;
            }
        }
    }

    return 0;
}
