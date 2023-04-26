#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    while(n != -1)
    {
        int num = (int)pow(2,n);
        int cnt = 0;
        for(int i = 0; i<num; i++)
        {
            int p = i;
            int j = n-1;
            char* s = (char*)malloc(n);
            for(int j = 0;j<n; j++)
            {
                s[j] = '0';
            }
            while(p)
            {
                if(p&1) s[j] = '1';
                j--;
                p = p>>1;
            }
            if(strstr(s,"101") == NULL) cnt++;
            free(s);
        }
        printf("%d\n", cnt);
        scanf("%d", &n);
    }
    return 0;
}
