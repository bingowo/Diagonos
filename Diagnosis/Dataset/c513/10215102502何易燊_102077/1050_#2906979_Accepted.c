#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[],char t[])
{
    for (int i=strlen(s)-1,k=0;i>=0;i--) t[k++] = s[i];
}

main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s[81] = {},t[81] = {};
        char s_[81] = {}, t_[81] = {};
        char s1[81] = {}, s2[81] = {};
        char s1_[81] = {}, s2_[81] = {};
        scanf("%s %s",s1,s2);
        reverse(s1,s1_); reverse(s2,s2_);
        scanf("%s",s);
        reverse(s,t);
        strcpy(s_,s); strcpy(t_,t);
        int num;
        if (strstr(s,s1)==NULL||strstr(t,s2_)==NULL) num = 0;
        else if (strcmp(s,s1)==0&&strcmp(s,s2)==0) num = 0;
        else
        {
            int p = strstr(s,s1)-s;
            int q = strstr(t,s2_)-t;
            num = strlen(s)-q-p-strlen(s1)-strlen(s2);
            int p_ = strstr(s_,s2)-s_;
            int q_ = strstr(t_,s1_)-t_;
            int num_ = strlen(s_)-q_-p_-strlen(s1)-strlen(s2);
            if (num_>num) num = num_;
        }
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}