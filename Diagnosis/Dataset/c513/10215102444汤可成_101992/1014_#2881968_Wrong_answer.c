#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int flag = 0;
int len = 0;

void ADD(char* arr, char* c, int len)
{
    int i = 0;
    int n = 0;
    for(i = len-1; i>=0; i--)
    {
        if(arr[i] == '.') continue;
        if(arr[i] + c[i] + n <3)
        {
            arr[i] = arr[i] +c[i] +n;
            n=0;
        }
        else if(arr[i] + c[i] + n <=5)
        {
            arr[i] = arr[i] + c[i] + n -3;
            n = 1;
        }
        else
        {
            arr[i] = 0;
            n = 2;
        }
    }
    if(n != 0)
    {
        flag = 1;
        len++;
        for(i = len -1; i >=0; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[0] = n;
    }
}

void MIN(char* arr, int len)
{
    int i = 0;
    if(flag == 1) i++;
    for(; i<len + flag; i++)
    {
        if(arr[i] != '.')
        {
            if (arr[i] - 1 == -1)
            {
                arr[i] = 2;
            }
            else arr[i] = arr[i] - 1;
        }
    }
}


int main()
{
    long long int A = 0;
    long long int B = 0;
    long long int n = 0;
    char arr[10000] = {0};
    char arr2[10000] = {0};
    int num = 0;
    int i = 0;
    scanf("%I64d %I64d", &A, &B);
    if(A%B == 0)
    {
        n = A / B;
        while(n)
        {
            num++;
            n = n/3;
        }
        len += num;
        n = A / B;
        int i = 0;
        for(i = num-1; i>=0; i--)
        {
            arr[i] = n % 3;
            n = n/3;
        }
    }
    else
    {
        if (A>B)
        {
            n = A / B;
            while(n)
            {
                num++;
                n = n/3;
            }
            len += num;
            n = A / B;
            int i = 0;
            for(i = num-1; i>=0; i--)
            {
                arr[i] = n % 3;
                n = n/3;
            }
        }
        else
        {
            arr[num++] = 0;
            len = 2;
        }
        arr[num] = '.';
        n = A % B;
        while(n)
        {
            arr[++num] = n*3/B;
            n = n*3 - (n*3/B) *B;
            len++;
        }
        len++;
    }
    for (i = 0; i<len; i++)
    {
        if (arr[i] != '.') arr2[i] = 1;
        else arr2[i] = '.';
    }
    ADD(arr, arr2, len);
    MIN(arr, len);
    i = 0;
    if(arr[i]==0 && arr[i+1] ==0) i++;
    int fflag = 0;
    for(; i<len+flag; i++)
    {
        int fff = 0;
        int j = 0;
        if(arr[i] == '.')
        {
            printf("%c", arr[i]);
            fflag = 2;
        }
        else if(arr[i] == 0 && fflag ==2)
        {
            for(j = i+1; j<len; j++)
            {
                if(arr[j] != 0)
                {
                    fff = 3;
                    break;
                }
            }
            if(fff == 3) printf("%d", arr[i]);
            else break;
        }
        else
        {
            printf("%d", arr[i]);
        }
    }


    return 0;
}
