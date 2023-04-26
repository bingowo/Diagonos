#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char s1[81],s2[81],s[81];
        int pos1_left,pos1_right,pos2_left,pos2_right;
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        int len1 = strlen(s1),len2 = strlen(s2);
        char*pt1_left,*pt1_right,*pt2_left,*pt2_right;
        pt1_right = pt1_left = strstr(s,s1);
        if(pt1_right == NULL)
        {
            printf("case #%d:\n0\n",i);
            continue;
        }
        pos1_left = pt1_left - s;
        pt2_right = pt2_left = strstr(s,s2);
        if(pt2_right == NULL)
        {
            printf("case #%d:\n0\n",i);
            continue;
        }
        pos2_left = pt2_left - s;
        while(pt1_right != NULL)
        {
            pt1_right += len1;
            pos1_right = (strstr(pt1_right,s1) == NULL)?pt1_right - s:strstr(pt1_right,s1) - s;
            pt1_right = strstr(pt1_right,s1);
        }
        //pos1_right -= len1;
        while(pt2_right != NULL)
        {
            pt2_right += len2;
            pos2_right = (strstr(pt2_right,s2) == NULL)?pt2_right - s:strstr(pt2_right,s2) - s;
            pt2_right = strstr(pt2_right,s2);
        }
        //pos2_right -= len2; 
        int distance1 = pos2_right - (pos1_left + len1);
        int distance2 = pos1_right - (pos2_left + len2);
        printf("case #%d:\n",i);
        if(distance2 > distance1)
        {
            if(distance2 == 0)
                printf("%d\n",distance2);
            else
                printf("%d\n",distance2 - len2);
        } 
        else
        {
            if(distance1 == 0)
                printf("%d\n",distance1);
            else
                printf("%d\n",distance1 - len1);
        }       
    }
}