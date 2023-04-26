#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int longest = 1,longest_cur = 1;
        int j = 0;
        char binary[33];
        unsigned int input;
        scanf("%u",&input);
        while(input != 0)
        {
            binary[j] = (input>>j)&1;
            j++;
        }
        binary[j] = '\0';
        char*pt1,*pt2;
        pt1 = binary;
        pt2 = pt1+1;
        while(*pt2)
        {
            if(*pt1 != *pt2)
                longest_cur++;
            else
            {
                if(longest_cur >= longest)
                {
                    longest = longest_cur;
                    longest_cur = 0;
                }
                else
                    longest_cur = 0;
            }
            pt1++;
            pt2++;
        }
        printf("case #%d:\n%d\n",i,longest);

    }
    return 0;
}
