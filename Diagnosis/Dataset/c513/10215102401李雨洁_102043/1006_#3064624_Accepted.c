#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int n; scanf("%d",&n);
    int m = n;
    char s[1000];
    int num[1000];
    for(int j = 0 ; j < m ; j+=1)
    {
        int sum = 0;
        scanf("%s",s);
        int len = strlen(s);
        for(int i = 0 ; i < len ; i++)
        {
            if(s[i] == '-') num[i] = -1;
            if(s[i] == '1') num[i] = 1;
            if(s[i] == '0') num[i] = 0;
            sum = sum + num[i]*pow(3,len-1-i);
        }
        printf("case #%d:\n%d\n",j,sum);
    }
    return 0;
}
