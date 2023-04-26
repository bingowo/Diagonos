#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int strcompare(char*s,char*t)
{
    int len1 = strlen(s),len2 = strlen(t);
    int len_min;
    if(len1 != len2)
        return 0;
    else
    {
        for(int i = 0;i < len1;i++)
        {
            if(toupper(s[i]) != toupper(t[i]);
                return 0;
        }
    }
    return 1;
}
int main()
{
    int T,i,count = 0;
    scanf("%d",&T);
    char*exclusion[6] = {"the","a","an","for","of","and"};
    //大小写的问题，大写的英文单词和小写的一样，如何处理
    for(i = 0;i < T;i++)
    {
        char word[101];
        while(scanf("%s",word))
        {   
            int flag = 1;
            for(int j = 0;j < 6;j++)
            {
                if(strcompare(word,exclusion[j]) == 0)
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