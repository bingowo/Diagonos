#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int T = 0,N = 0,R = 0;
    int i = 0,k = 0;
    char temp;

    char** s[100];
    scanf("%d",&T);
    for (i = 0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        char* res = (char*)malloc(1000);
        int j = 0,i1 = 0,k1 = 0;
        int n = N,r = 0;
        while(n != 0)
        {
            r = n%R;
            n = n/R;
            if(r>=0&&r<=9)
            {
                res[j++] = r + '0';
            }
            else if (r>=10&&r<=36)
            {
                res[j++] = r + 'A' - 10;
            }
        }

        for(i1=0,k1=j-1;i1<k1;i1++,k1--)
        {
            temp = res[i1];
            res[i1] = res[k1];
            res[k1] = temp;
        }
        printf("%s\n",res);
        free(res);


    }




    return 0;
}
