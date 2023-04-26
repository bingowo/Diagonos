#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int M; scanf("%d ",&M);
        char s[2002] = {}; gets(s);
        printf("case #%d:\n",i);
        for (int j=0;s[j];)
        {
            int cnt = j+M;
            int wordnum = 0;
            if (!isspace(s[j+M]))
            {
                for (int k=j+M;!isspace(s[k]);k--) cnt--;
            }
            if (cnt>=strlen(s))
            {
                char *p = s+j;
                printf("%s\n",p);
                break;
            }
            char* buffer[100]; int index = 0;
            char word[21] = {}; int p =0;
            for (int k=j;k<=cnt;k++)
            {
                if (!isspace(s[k])) {word[p++] = s[k]; wordnum++;}
                else if (word[0]!=0&&isspace(s[k]))
                {
                    char *ptr = (char*)malloc(strlen(word)+1);
                    strcpy(ptr,word);
                    buffer[index++] = ptr;
                    memset(word,0,sizeof(word)); 
                    p = 0;
                }
            }
            if (word[0]!=0)
            {
                char *ptr = (char*)malloc(strlen(word)+1);
                strcpy(ptr,word);
                buffer[index++] = ptr;
                memset(word,0,sizeof(word)); 
                p = 0;
            }
            int sep = (M-wordnum)/(index-1);
            int gap = (M-wordnum)%(index-1);
            char ans[2001] = {};
            for (int k=0;k<(index-1-gap);k++) {strcat(ans,buffer[k]); for (int q=0;q<sep;q++) strcat(ans," ");}
            for (int k=index-1-gap;k!=index-1;k++) {strcat(ans,buffer[k]); for (int q=0;q<sep+1;q++) strcat(ans," ");}
            strcat(ans,buffer[index-1]);
            printf("%s\n",ans);
            j += cnt-j+1;
        }
    }
    system("pause");
    return 0;
}