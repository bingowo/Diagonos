#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
    int n; scanf("%d ",&n);
    for (int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        int M; scanf("%d ",&M);
        char* s = (char*)malloc(2002); gets(s);
        strcat(s," ");
        char buf[50] = {}; int p = 0;
        char* word[50] = {}; int index = 0;
        int alphanum = 0;
        char ans[2001] = {};
        while (sscanf(s,"%s",buf)!=EOF)
        {
            s = strchr(s,' ')+1;
            while (*s==' ') s++;
            if (strlen(buf)+index+alphanum<M)
            {
                char *ptr = (char*)malloc(strlen(buf)+1);
                strcpy(ptr,buf);
                word[index++] = ptr;
                alphanum += strlen(buf);
                memset(buf,0,sizeof(buf));
            }
            else if (strlen(buf)+index+alphanum==M)
            {
                char *ptr = (char*)malloc(strlen(buf)+1);
                strcpy(ptr,buf);
                word[index++] = ptr;
                alphanum += strlen(buf);
                memset(buf,0,sizeof(buf));
                if (index==1) {strcat(ans,word[0]); for (int j=0;j<M-strlen(word[0]);j++) strcat(ans," ");}
                else
                {
                    int sep = (M-alphanum)/(index-1);
                    int gap = (M-alphanum)%(index-1);
                    for (int k=0;k<(index-1-gap);k++) {strcat(ans,word[k]); for (int q=0;q<sep;q++) strcat(ans," ");}
                    for (int k=index-1-gap;k!=index-1;k++) {strcat(ans,word[k]); for (int q=0;q<sep+1;q++) strcat(ans," ");}
                    strcat(ans,word[index-1]);
                }
                printf("%s\n",ans);
                memset(ans,0,sizeof(ans)); memset(word,0,sizeof(word));
                alphanum = 0; index = 0;
            }
            else
            {
                if (index==1) {strcat(ans,word[0]); for (int j=0;j<M-strlen(word[0]);j++) strcat(ans," ");}
                else
                {
                    int sep = (M-alphanum)/(index-1);
                    int gap = (M-alphanum)%(index-1);
                    for (int k=0;k<(index-1-gap);k++) {strcat(ans,word[k]); for (int q=0;q<sep;q++) strcat(ans," ");}
                    for (int k=index-1-gap;k!=index-1;k++) {strcat(ans,word[k]); for (int q=0;q<sep+1;q++) strcat(ans," ");}
                    strcat(ans,word[index-1]);
                }
                printf("%s\n",ans);
                memset(ans,0,sizeof(ans)); memset(word,0,sizeof(word));
                alphanum = 0; index = 0;
                char *ptr = (char*)malloc(strlen(buf)+1);
                strcpy(ptr,buf);
                word[index++] = ptr;
                alphanum += strlen(buf);
                memset(buf,0,sizeof(buf));
            }
        }
        for (int j=0;j<index;j++) printf("%s ",word[j]);
        printf("\n");
    }
    system("pause");
    return 0;
}