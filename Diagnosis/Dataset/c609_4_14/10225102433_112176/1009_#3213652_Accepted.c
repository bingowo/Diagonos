#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(int a,int b)
{
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    while(max%min)
    {
        int res = max%min;
        max = min;
        min = res;
    }
    return min;
}

int main()
{
    int n;scanf("%d",&n);
    char c = getchar();
    while(n--)
    {
        char s[200] = {0};
        fgets(s,200,stdin);
        int fz = 0;
        int fm = (strlen(s)-1)*8;
        for(int i = 0;i < strlen(s)-1;i++)
        {
            unsigned char c = s[i];
            int cnt = 0;
            while(c)
            {
                if(c&1)
                    cnt++;
                c = c>>1;
            }
            fz += cnt;
        }
        int key = find(fz,fm);
        fz /= key;
        fm /= key;
        printf("%d/%d\n",fz,fm);
    }
    return 0;
}