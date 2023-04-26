#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_different(char* a, int len)
{
//    int m[128];
//    for(int i = 0 ; i < 128 ; i++)
//        m[i] = -1;
//    int num = 0;
//    for( int j = 0 ; j < len ; j++)
//    {
//        if( m[a[j]] == -1 )
//        {
//            num++;
//            m[a[j]] = 1;
//        }
//    }
//    return num;
    int q[21] = {0};//用于查重
    int num = 0;
    for(int i = 0; i < len; i++)
    {
        int flag = 0;
        for(int j = 0; j < len; j++)
        {
            if (a[i] == q[j] )
                flag = 1;
        }
        if (flag == 0)
            num++;
        q[i] = a[i];
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
            num[n] = get_different(word[i],strlen(word[i]));
        }
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(num[j] < num[j+1])
                {
                    char temp[30];
                    memset(temp,0,sizeof(temp));
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

        printf("case #%d\n",p);
        for(int j = 0 ; j< n ; j++)
            printf("%s\n",word[j]);
    }
}
