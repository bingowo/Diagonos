#include<stdio.h>

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
