#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int T = 0,N = 0,R = 0;
    int i = 0,k = 0;
    char temp;


    scanf("%d",&T);

    char** s = (char**) malloc(T * sizeof(char**));
    for (i = 0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        s[i] = (char*)malloc(1000);
        int j = 0,i1 = 0,k1 = 0;
        int n = N,r = 0;
        while(n != 0)
        {
            r = n%R;
            n = n/R;
            if(r>=0&&r<=9)
            {
                s[i][j++] = r + '0';
            }
            else if (r>=10&&r<=36)
            {
                s[i][j++] = r + 'A' - 10;
            }
        }

        for(i1=0,k1=j-1;i1<k1;i1++,k1--)
        {
            temp = s[i][i1];
            s[i][i1] = s[i][k1];
            s[i][k1] = temp;
        }

    }
    for(int i = 0;i<T;i++)
    {
        printf("%s\n",s[i]);
    }

    for(int i = 0;i<T;i++)
    {
        free(s[i]);
    }
    free(s);


    return 0;
}
