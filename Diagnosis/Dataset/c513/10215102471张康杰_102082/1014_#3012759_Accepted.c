#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int A,B,i;
    scanf("%d %d",&A,&B);
    int pos = 30,temp_B = B;
    int tri[60] = {0},pos1 = pos,pos2 = pos;
    int left = A / B,right = A % B;
    for(i = pos - 1;left != 0;i--)
    {
        tri[i] = left % 3;
        left /= 3;
    }
    pos1 = i + 1;
    for(i = pos;right != 0;i++)
    {
        temp_B /= 3;
        tri[i] = right / temp_B;
        right = right - temp_B * tri[i];
    }
    pos2 = i - 1;
    int carry = 0;
    for(i = pos2;i >= pos1;i--)
    {
        tri[i] = tri[i] + carry + 1;
        carry = tri[i] / 3;
        tri[i] %= 3;
    }
    if(carry)
    {
        tri[i] = tri[i] + carry + 1;
        pos1--;
    }
    for(i = pos1;i <= pos2;i++)
    {
        tri[i] -= 1;
        if(tri[i] == -1)
            tri[i] = 2;
    }
    /* if(A / B == 0 && A % B != 0)
    {
        printf("0.");
        for(i = pos1;i <= pos2;i++)
            printf("%d",tri[i]);
    }
    else if(A / B != 0 && A % B == 0)
    {
        for(i = pos1;i <= pos2;i++)
            printf("%d",tri[i]);
    }
    else if(A / B != 0 && A % B != 0)
    {
        for(i = pos1;i <= pos2;i++)
        {
            if(i == pos)
                putchar('.');
            printf("%d",tri[i]);
        }
    }
    else
    {
        putchar('0');
    } */
    if(A == 0)
        putchar('0');
    else if(pos1 < 30 && pos2 >= 30)
    {
        for(i = pos1;i <= pos2;i++)
        {
            if(i == pos)
                putchar('.');
            printf("%d",tri[i]);
        }
    }
    else if(pos1 >= 30)
    {
        printf("0.");
        for(i = pos1;i <= pos2;i++)
            printf("%d",tri[i]);
    }
    else if(pos2 <= 30)
    {
        for(i = pos1;i <= pos2;i++)
            printf("%d",tri[i]);
    }
    putchar('\n');
    return 0;
}