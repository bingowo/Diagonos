#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        int M; scanf("%d ",&M);
        char s[2002] = {}; gets(s);
        for (int j=0;s[j];j+=M)
        {
            if (j+M>=strlen(s))
            {
                char *p = s+j;
                printf("%s\n",p);
                break;
            }
            for (;isspace(s[j]);) j++;
            char *ptr;
            char* word[50] = {}; int index = 0;
            char buf[50] = {}; int p=0;
            for (int k=j;k<j+M;k++)
            {
                if (!isspace(s[k])) buf[p++] = s[k];
                else
                {
                    ptr = (char*)malloc(strlen(buf)+1);
                    strcpy(ptr,buf);
                    word[index++] = ptr;
                    p = 0;
                    memset(buf,0,sizeof(buf));
                }
            }
            int wordnum = 0;
            for (int j = 0;j<index;j++) wordnum += strlen(word[j]);
            if (isspace(s[j+M])) 
            {
                wordnum += strlen(buf);
                ptr = (char*)malloc(strlen(buf)+1);
                strcpy(ptr,buf);
                word[index++] = ptr; p = 0;
                memset(buf,0,sizeof(buf));
            }
            else j -= strlen(buf);
            char ans[2001] = {};
            if (index==1) {strcat(ans,word[0]); for (int j=0;j<M-strlen(word[0]);j++) strcat(ans," ");}
            else
            {
                int sep = (M-wordnum)/(index-1);
                int gap = (M-wordnum)%(index-1);
                for (int k=0;k<(index-1-gap);k++) {strcat(ans,word[k]); for (int q=0;q<sep;q++) strcat(ans," ");}
                for (int k=index-1-gap;k!=index-1;k++) {strcat(ans,word[k]); for (int q=0;q<sep+1;q++) strcat(ans," ");}
                strcat(ans,word[index-1]);
            }
            printf("%s\n",ans);
        }
    }
    return 0;
}