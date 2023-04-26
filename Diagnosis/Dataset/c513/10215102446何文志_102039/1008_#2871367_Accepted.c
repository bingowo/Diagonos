#include <stdio.h>
#include <stdlib.h>


char* itobinaryString(int N)
{
    char* s = (char*)malloc(100);
    memset(s,0,100);
    int n = N,r = 0,i = 0;

    while(n != 0)
    {
        r = n%2;
        n = n/2;
        s[i++] = r + '0';

    }
    while(strlen(s)<32)
    {
        s[i++] = '0';
    }
    reverseString(s);

    return s;
}

void reverseString(char* s)
{
    int len = strlen(s);
    int i = 0,j = len;
    char temp = 0;
    for(i = 0,j = len-1;i<j;i++,j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    int inputList[100][2];

    for(int i = 0;i<T;i++)
    {
        int x = 0,y = 0;
        scanf("%d%d",&x,&y);
        inputList[i][0] = x;
        inputList[i][1] = y;
    }

    for(int i = 0;i<T;i++)
    {
        char* sx = itobinaryString(inputList[i][0]);
        char* sy = itobinaryString(inputList[i][1]);
        int res = 0, j = 0;
        while((sx[j]!=0)&&(sy[j]!=0))
        {
            if(sx[j] != sy[j])
            {
                res++;
            }
            j++;
        }
        printf("%d\n",res);
        free(sx);free(sy);
    }


    return 0;
}
