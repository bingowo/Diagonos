#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    return strlen(*(char**)b)-strlen(*(char**)a);
}

main()
{
    int n; scanf("%d",&n);
    char* dic[128][500] = {}; int rec[128] = {};
    while (n--)
    {
        char buf[15];
        scanf("%s",buf);
        char *p = (char*)malloc(strlen(buf)+1);
        strcpy(p,buf);
        dic[p[0]][rec[p[0]]++] = p;
    }
    for (int i=0;i<128;i++) qsort(dic[i],rec[i],sizeof(dic[i][0]),cmp);
    char *s = (char*)malloc(5001); scanf("%s",s);
    int sign = 0;
    while (s[0])
    {
        int al = s[0];
        int index = 0;
        int find = 0;
        for (int i=0;i<rec[al];i++)
        {
            if (strstr(s,dic[al][i])==s) 
            {
                if (sign==0) {printf("%s",dic[al][i]); sign++;}
                else printf(" %s",dic[al][i]); 
                s += strlen(dic[al][i]); 
                find = 1; 
                break;}
        }
        if (find==0) 
        {
            if (sign==0) printf("%c",*s);
            else printf(" %c",*s); 
            s += 1;
        }
    }
    printf("\n");
    return 0;
}