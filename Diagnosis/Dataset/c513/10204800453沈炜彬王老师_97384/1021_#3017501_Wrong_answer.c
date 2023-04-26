#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

int weight[26];

int
main()
{
    char A[27];
    char temp[2200];
    char ans[100][21];
    int count = 0;
    int count2 = 0;
    
    while (~scanf("%s\n",A))
    {
        count = 0;
        count2 = 0;
        for (int i=0; i<26; i++)
        {
            weight[A[i]-'A'] = i;
        }
        
        gets(temp);
        for (int i=0; i<strlen(temp); i++)
        {
            if (temp[i]==' ')
            {
                ans[count][count2] = '\0';
                count2 = 0;
                count++;
                continue;
            }
            else
            {
                ans[count][count2] = temp[i];
                count2++;
            }
        }
        ans[count][count2] = '\0';
        qsort(ans, count+1, sizeof(ans[0]), cmp);
        for (int i=0; i<count+1; i++)
        {
            printf("%s",ans[i]);
            if (i+1 != count+1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    
    return 0;
}


int
cmp(const void* a,const void* b)
{
    char* c1 = (char*)a;
    char* c2 = (char*)b;
    char ch1,ch2;
    
    for (int i=0; i< (strlen(c1)>strlen(c2)?strlen(c1):strlen(c2)) ; i++)
    {
        ch1 = c1[i]>='a'?c1[i]-32:c1[i];
        ch2 = c2[i]>='a'?c2[i]-32:c2[i];
        if (weight[ch1-'A']>weight[ch2-'A'])
        {
            return 1;
        }
        else if (weight[ch1-'A']<weight[ch2-'A'])
        {
            return -1;
        }
    }
    if (strlen(c1)>strlen(c2))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}