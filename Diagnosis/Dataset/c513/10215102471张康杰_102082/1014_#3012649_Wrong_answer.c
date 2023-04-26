#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int A,B,i;
    scanf("%d %d",&A,&B);
    int tri[60] = {0},cnt = 0,pos;
    int left = A / B,right = A % B;
    for(i = 0;right != 0;i++)
    {
        tri[i] = right % 3;
        right /= 3;
    }
    pos = i - 1;
    for(i;left != 0;i++)
    {
        tri[i] = left % 3;
        left /= 3;
    }
    cnt = i;
    int carry = 0;
    for(i = 0;i < cnt;i++)
    {
        tri[i] = tri[i] + carry + 1;
        carry = tri[i] / 3;
        tri[i] %= 3;
    }
    if(carry)
    {
        tri[i] += carry;
        cnt++;
    }
    for(i = 0;i < cnt;i++)
    {
        tri[i] -= 1;
        if(tri[i] == -1)
            tri[i] = 2;
    }
    int flag = 1;
    for(i = cnt - 1;i >= 0;i--)
    {
        if(i == pos + 1)
        {
            printf("%d",tri[pos + 1]);
            putchar('.');
            flag = 0;
        }
        else if(flag && tri[i] == 0)
            continue;
        else
        {
            printf("%d",tri[i]);
        }
    }
    putchar('\n');
    return 0;
}