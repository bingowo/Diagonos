#include<stdio.h>

int get_length(char str[])
{
    char *p = str;
    int count = 0;
    while (*p++ != '\0') count++ ;
    return count;
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int j = 0 ; j < T ; j++)
    {
        char s[101];
        int count = 0;
        for(int i = 0 ; (s[i] = getchar())!= '\n' ;i++)
        {
            if(s[i] == ' ') count = count + 1;
        }
        printf("case #%d:\n",j);
        printf("%d\n",count+1);
    }
        return 0;
}
