#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int n;
    scanf("%d ",&n);
    for (int i=0;i<n;i++)
    {
        char *s = (char*)malloc(101);
        gets(s);
        strcat(s," ");
        int cnt = 0;
        char word[101];
        while (sscanf(s,"%s",word)!=EOF)
        {
            for (int j=0;word[j];j++) if (word[j]>='A'&&word[j]<='Z') word[j] += 'a'-'A';
            if (strcmp(word,"the")!=0&&strcmp(word,"a")!=0&&strcmp(word,"an")!=0&&strcmp(word,"of")!=0
                &&strcmp(word,"for")!=0&&strcmp(word,"and")!=0) cnt++;
            s = strchr(s,' ')+1;
        }
        printf("case #%d:\n%d\n",i,cnt);
    }
    return 0;
}