#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这里感觉可以用递归来写
int delete(char*s)
{
    int count = 1,pair = 0;
    char*pt1,*pt2;
    pt1 = s;
    pt2 = pt1 + 1; 
    while(*pt2)
    {
        if(*pt1 == *pt2)
        {
            count++;
            *pt2 = '\0';
            pt2++;
            pair = 1;
            continue;
        }
        else
        {
            if(pair)
            {
                *pt1 = '\0';
                strcat(s,pt2);
                pt1 = s;
                pt2 = pt1 + 1;
                pair = 0;
            }
            else
            {
                pt2++;
                pt1++;
            }
                
        }
    }
    return count;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i < T;i++)
    {
        char input[101];
        scanf("%s",input);
        int count,j,longest = 0,current = 0;
        count = delete(input);
        int len = strlen(input);
        char*pt1 = input,*pt2 = pt1;
        for(pt2;*pt2;pt2++)
        {
            *pt2 = '\0';
            current = count + delete(strcat(pt1,pt2+1));
            if(current > longest)
            {
                longest = current;
            }
            current = 0;

        }
        printf("case #%d:\n%d\n",longest);
    }

}