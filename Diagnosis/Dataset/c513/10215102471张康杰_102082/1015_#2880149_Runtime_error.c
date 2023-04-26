#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input1[50],input2[50];
        memset(input1, '\0', 50*sizeof(char));
        memset(input2, '\0', 50*sizeof(char));
        scanf("%s %s",input1,input2);
        char plus[50];
        char*pt1 = input1,*pt2 = input2;
        int table[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        if(strlen(input1) >= strlen(input2))
        {
            pt1 = pt1 + strlen(input1) - strlen(input2);
            while(*pt2)
            {
                *pt1 += (*pt2 - '0');
                pt2 += 2;
                pt1 += 2;
            }
            strcpy(plus, input1);
        }
        else
        {
            pt2 = pt2 + strlen(input2) - strlen(input1);
            while(*pt1)
            {
                *pt2 += (*pt1 - '0');
                pt1 += 2;
                pt2 += 2;
            }
            strcpy(plus, input2);
        }
        int j,flag = 0,length = strlen(plus);
        for(j=length - 1;j>1;j=j-2)
        {
            if(plus[j] - '0' >= table[flag])
            {
                plus[j] = plus[j] - table[flag];
                plus[j - 2]++;
                flag++;
            }
            else
                continue;

        }
        if(plus[0] >= table[flag])
        {
            plus[0]--;
            printf("case #%d:1%s\n",i,plus);
        }
        else
            printf("case #%d:%s\n",i,plus);



    }
    return 0;
}
