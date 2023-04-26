#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int GCD(int x,int y)
{
    if(x%y == 0)
        return y;
    else
        return GCD(y,x%y);
}
int main()
{
    char input[31];
    int table[3] = {0,1,-1};
    scanf("%s",input);
    char*pt1,*pt2;
    int power1=0,power2=0,left=0,right=0;
    pt1 = input;
    while(*pt1 != '.')
    {
        pt1++;
    }
    pt2 = pt1;
    pt1--;
    while(*pt1)
    {
        left += table[*pt1-'0']*pow(3,power1);
        power1++;
        pt1--;
    }
    while(*pt2)
    {
        right = right*3 + table[*pt2 - '0'];
        pt2++;
        power2++;
    }
    printf("%d %d %d",left,right/GCD(right,pow(3,power2)),pow(3,power2)/GCD(right,pow(3,power2)));
    return 0;
}