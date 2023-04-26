#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int erase(char*s)
{
    int len,i,len1 = strlen(s);
    int flag = 0,delete = 1;
    while(delete != 0)
    {
        int cnt = 0;
        len = strlen(s);
        for(i = 0;i < len;i++)
        {
            if(s[i] == s[i + 1])
            {
                delete = 1;
                break;
            }
        }
        if(i == len)
            break;
        for(i = 0;i < len;i++)
        {
            if(s[i] == s[i + 1])
            {
                flag = 1;
                continue;
            }
            else
            {
                if(flag)
                {
                    flag = 0;
                    continue;
                }
                else
                {
                    *(s + cnt) = s[i];
                    cnt++;
                }
            }
        }
        *(s + cnt) = '\0';
    }
    return len1 - len;
}

void insert(char*s,char ch,int pos)
{
    char pt[102] = {'\0'},*pt1,temp;
    temp = s[pos];
    s[pos] = '\0';
    pt1 = s + pos + 1;
    memcpy(pt,pt1,strlen(pt1));
    sprintf(s,"%s%c%c%s",s,ch,temp,pt);
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int delete_max = 0,delete_cur = 0,len;
        char s[101],temp[102];
        scanf("%s",s);
        len = strlen(s);
        for(int j = 0;j < len;j++)
        {
            memcpy(temp,s,len);
            insert(temp,'A',j);
            delete_cur = erase(temp);
            if(delete_cur > delete_max)
                delete_max = delete_cur;
            memset(temp,'\0',102);
            memcpy(temp,s,len);
            insert(temp,'B',j);
            delete_cur = erase(temp);
            if(delete_cur > delete_max)
                delete_max = delete_cur;
            memset(temp,'\0',102);
            memcpy(temp,s,len);
            insert(temp,'C',j);
            delete_cur = erase(temp);
            if(delete_cur > delete_max)
                delete_max = delete_cur;
            memset(temp,'\0',102);
        }
        sprintf(temp,"%s%c",s,'A');
        delete_cur = erase(temp);
        if(delete_cur > delete_max)
                delete_max = delete_cur;
        memset(temp,'\0',102);
        sprintf(temp,"%s%c",s,'B');
        delete_cur = erase(temp);
        if(delete_cur > delete_max)
                delete_max = delete_cur;
        memset(temp,'\0',102);
        sprintf(temp,"%s%c",s,'C');
        delete_cur = erase(temp);
        if(delete_cur > delete_max)
                delete_max = delete_cur;
        memset(temp,'\0',102);
        printf("case #%d:\n%d\n",i,delete_max);
    }
    return 0;
}