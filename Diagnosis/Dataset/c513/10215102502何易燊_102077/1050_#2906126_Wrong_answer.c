#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s[81],t[81];
        char s1[81] = {}, s2[81] = {}, s2_[82] = {};
        scanf("%s %s",s1,s2_);
        for (int j=strlen(s2_)-1,k=0;j>=0;j--) s2[k++] = s2_[j];
        scanf("%s",s);
        for (int j=strlen(s)-1,k=0;j>=0;j--) t[k++] = s[j];
        int num;
        if (strstr(s,s1)==NULL||strstr(t,s2)==NULL) num = -1;
        else
        {
            int p = strstr(s,s1)-s;
            int q = strstr(t,s2)-t;
            num = strlen(s)-q-p-strlen(s1)-strlen(s2);
        }
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}