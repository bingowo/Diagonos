#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int trans(char c)
{
    if(c == '-')
        return -1;
    else if(c == '0')
        return 0;
    else
        return 1;
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        char *s = (char*) malloc(100000*sizeof(char));
        scanf("%s",s);
        unsigned len = strlen(s);
        int num = 0;
        for(int j = 0;j < len;j++)
        {
            int k = len-j-1;
            num += pow(3,k)*trans(s[j]);
        }
        printf("%d\n",num);
        free(s);
    }
    return 0;
}