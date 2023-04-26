#include <stdio.h>

int main()
{
    int T = 0;
    scanf("%d", &T);
    getchar();
    char s[20] = {0};
    int i = 0;
    for (i = 0; i < T; i++)
    {
        int num = 0;
        int sum = 0;
        while((s[num] = getchar() )!= '\n')
        {
            num++;
        }

        s[num] = 0;
        int i = 0;
        for(i = 0; i < num; i++)
        {
            if(s[i] == '1')
            {
                sum = sum*3 + 1;
            }
            else if(s[i] == '0')
            {
                sum = sum*3 + 0;
            }
            else
            {
                sum = sum*3 -1;
            }
        }
        printf("case #%d:\n", i);
        printf("%d\n", sum);
    }
    return 0;
}
