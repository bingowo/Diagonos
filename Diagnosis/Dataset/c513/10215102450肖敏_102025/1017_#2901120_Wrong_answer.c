#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char t[50];
    int s[100];
    int i,j,count = 1,sum = 0;
    memset(s,100,0);
    s['I'] = 1;s['V'] = 5;s['X'] = 10;s['L']= 50;s['C']= 100;s['D']= 500;s['M']= 1000;
    scanf("%s",t);
    int len = strlen(t);
    for(i = 0;i < len;i ++)
    {
        if(t[i] == t[i+1])
        {
            count ++;

        }
        else
        {
            sum += s[t[i]] * count;
            count = 1;
        }
        if((s[t[i+1]] - s[t[i]] > 0) && (s[t[i+1]] - s[t[i]] < (s[t[i]] * 10)) )
        {
            if(t[i] =='I' || t[i] == 'X' || t[i] =='C')
            {
                sum += s[t[i+1]] - s[t[i]];
                i ++;
            }
            else
            {
                sum += s[t[i]];
            }
        }



    }

    printf("%d",sum);
    return 0;
}
