#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_different(char* a, int len)
{
    int m[128];
    for(int i = 0 ; i < 128 ; i++)
        m[i] = -1;
    int num = 0;
    for( int j = 0 ; j < len ; j++)
    {
        if( m[a[j]] == -1 )
        {
            num++;
            m[a[j]] = 1;
        }
    }
    return num;
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int p = 0 ; p < T ; p++)
    {
        int n;
        scanf("%d",&n);
        char word[n][30];
        int num[n];

        for( int i = 0; i < n ; i++)
        {
            scanf("%s",word[i]);
            getchar();
            num[i] = get_different(word[i],strlen(word[i]));
        }
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(num[j] < num[j+1])
                {
                    char temp[30];
                    strcpy(temp, word[j]);
                    strcpy(word[j], word[j+1]);
                    strcpy(word[j+1], temp);
                    int tmp;
                    tmp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = tmp;
                }
            }
        }

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(num[j] == num[j+1])
                {
                    int max = strlen(word[j]) > strlen(word[j+1]) ? strlen(word[j]) : strlen(word[j+1]);
                    for(int k = 0; k < max; k++)
                    {
                        if(word[j][k] > word[j+1][k])
                        {
                            char temp[30];
                            strcpy(temp, word[j]);
                            strcpy(word[j], word[j+1]);
                            strcpy(word[j+1], temp);
                            int tmp;
                            tmp = num[j];
                            num[j] = num[j+1];
                            num[j+1] = tmp;
                        }
                    }
                }
            }
        }
        printf("case #%d:\n",p);
        for(int j = 0 ; j< n ; j++)
            printf("%s\n",word[j]);
    }
}
