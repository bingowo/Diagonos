#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int z = 1; z <= t; z++)
    {
        char a[500];
        scanf("%s",a);
        printf("case #%d:\n",z);
        int each[500] = {0};
        char c[500] = {0};
        c[0] = a[0];
        each[0]++;
        int m = 0;
        for(int i = 1; i < (int)strlen(a); i++)
        {
            if(a[i] == c[m])
            {
                while(i < (int)strlen(a) && a[i] == c[m])
                {
                    if(each[m] == 255)
                    {
                        m++;
                        c[m] = a[i];
                    }
                    each[m]++;
                    i++;
                }
                i--;
            }
            else
            {
                m++;
                c[m] = a[i];
                each[m]++;
            }
        }
        m++;
        for(int i = 0; i < m; i++)
        {
            printf("%d%c",each[i],c[i]);
        }
        printf("\n");
    }
    return 0;
}
