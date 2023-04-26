#include <stdio.h>
#include <string.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    char s0[100],s1[100];
    for (int z = 0; z < t; z++)
    {
        unsigned int num = 0;
        scanf("%s", s0);
        int len = strlen(s0);
        for (int i = 0; i < len; i++)
        {
            if (s0[i] == '-') s1[i] = -1;
            else if (s0[i] == '0')s1[i] = 0;
            else s1[i] = 1;
        }
        printf("case #%d:\n", z);
        for (int i = 0; i < len; i++)
        {
            unsigned int x = s1[i] * pow(3, len - i - 1);
            num += x ;
        }
        printf("%d\n", num);
    }
    return 0;
}
