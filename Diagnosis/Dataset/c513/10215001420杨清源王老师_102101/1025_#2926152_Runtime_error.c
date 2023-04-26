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

void swap_num(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void swap_str(char *a, char *b)
{
    char temp[30];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
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
            num[n] = get_different(word[i],strlen(word[i]));
        }
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(num[j] > num[j+1])
                {
                    swap_num(num[j],num[j+1]);
                    swap_str(word[j],word[j+1]);
                }
            }
        }

        printf("case #%d\n",p);
        for(int j = 0 ; j< n ; j++)
            printf("%s\n",word[j]);
        }
}
