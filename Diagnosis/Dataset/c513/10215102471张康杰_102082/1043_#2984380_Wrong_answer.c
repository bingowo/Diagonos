#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这里感觉可以用递归来写
int delete(char*s)
{
    int count = 0,pair = 0,flag = 0;
    char*pt1,*pt2;
    pt1 = s;
    pt2 = pt1 + 1; 
    int count_cur = 1;
    while(*pt2)
    {
        if(*pt1 == *pt2)
        {
            count_cur++;
            *pt2 = '\0';
            pt2++;
            pair = 1;
            flag = 1;
            continue;
        }
        else
        {
            if(pair)
            {
                *pt1 = '\0';
                count += count_cur;
                count_cur = 1;
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
    if(pair)
    {
        *pt1 = '\0';
        count += count_cur;
        strcat(s,pt2);
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
        char input[101],temp[101];
        scanf("%s",input);
        int count,j,longest = 0,current = 0;
        count = delete(input);
        int len = strlen(input),pos = 0;
        char*pt1,*pt2;
        pt1 = input;
        pt2 = strcpy(temp,input);
        if(len == 0)
        {
            printf("case #%d:\n%d\n",i,count+1);
            continue;
        }
        for(pt1;*pt1;pt1++,pos++)
        {
            pt2 = temp + pos;
            *pt2 = '\0';
            current = count + delete(strcat(temp,pt2+1)) + 2;
            if(current > longest)
            {
                longest = current;
            }
            current = 0;
            strcpy(temp,input);
        }
        printf("case #%d:\n%d\n",i,longest);
    }

}