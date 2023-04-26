#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[101];memset(s,0,101*sizeof(char));
    while(scanf("%s",s)!=EOF)
    {
        char* p[101];memset(p,0,101*sizeof(char*));
        char wordList[101][21];memset(wordList,0,101*21*sizeof(char));
        int i = 0;
        while(scanf("%s",wordList[i])!=0)
        {
            p[i] = wordList[i];
            i++;
        }
        printf("%s\n",s);
        for(int j = 0;j<i;j++)
        {
            printf("%s ",*p[j]);
        }
    }
    return 0;
}
