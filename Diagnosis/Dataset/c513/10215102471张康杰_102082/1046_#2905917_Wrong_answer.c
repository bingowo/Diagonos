#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i,count = 0;
    scanf("%d",&T);
    char*exclusion[6] = {"the","a","an","for","of","and"};
    for(i = 0;i < T;i++)
    {
        char word[101];
        while(scanf("%s",word))
        {   
            int flag = 1;
            for(int j = 0;j < 6;j++)
            {
                if(strcmp(word,exclusion[j]) == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                count++;
            if(getchar() == '\n')
                break;
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
}