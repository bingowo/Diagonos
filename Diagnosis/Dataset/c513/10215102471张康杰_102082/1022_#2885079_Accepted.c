#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int StringCmp(const void*p1,const void*p2)
{
    char*pt1 = *(char**)p1,*pt2 = *(char**)p2;
    pt1 = strchr(pt1,'@'),pt2 = strchr(pt2,'@');
    pt1++;
    pt2++;
    if(strcmp(pt2,pt1) != 0)
        return strcmp(pt1,pt2);
    else
        return strcmp(*(char**)p2,*(char**)p1);
}
int main()
{
    int T;
    char**email;
    char s[1000001];
    scanf("%d",&T);
    email = (char**)malloc(T*sizeof(char*));
    for(int i = 0;i < T;i++)
    {
        int len;
        scanf("%s",s);
        len = strlen(s);
        email[i] = (char*)malloc(len + 1);
        strcpy(email[i],s);
    }
    qsort(email,T,sizeof(char*),StringCmp);
    for(int i =0;i < T;i++)
        printf("%s\n",email[i]);
    for(int i = 0;i < T;i++)
    {
        free(email[i]);
    }
    free(email);

    return 0;
}
