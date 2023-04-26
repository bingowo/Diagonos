#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for (int p = 0; p < t; p++)
    {
        char a[111111];
        scanf("%s",a);
        int sum = 0;
        for (int i = 0; a[i] != '\0'; i++)
        {
            if (a[i] == '1')
            {
                sum = sum * 3 + 1;
            }
            if (a[i] == '0')
            {
                sum = sum * 3 + 0;
            }
            if (a[i] == '-')
            {
                sum = sum * 3 - 1;
            }
        }
        printf("case #%d:\n%d",p,sum);
    }
}