#include <stdio.h>
#include <stdlib.h>

int answer[100];
int R;  //进制
int top; //栈顶

void convert(int N, int R)
{
    int temp = N;
    top = 0;

    while(N)
    {
        temp = N % R;

        if(temp < 0)
        {
            temp -= R;
            N += R;
        }

        answer[++top] = temp;

        N /= R;
    }
}

int main()
{
    int N;

    scanf("%d %d", &N, &R);

    convert(N, R);

    int i = top;

    for(; i > 0; i--)
    {
        if(-R <= 9)
        {
            printf("%d", answer[i]);
        }

        else
        {
            if(answer[i] >= 10)
                printf("%c", answer[i] - 10 + 'A');
            else
                printf("%c", answer[i] + '0');
        }
    }

    return 0;
}
