#include <stdio.h>
#include <string.h>

char* strbstr(char*str1, char* str2)
{
    char* ret=NULL;
    while(strstr(str1,str2)!=NULL)
    {
        ret=strstr(str1,str2);
        str1+=strlen(str2);
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        char s1[100], s2[100], s[100];
        scanf("%s %s %s",s1, s2, s);
        char* p1=strstr(s,s1), *p2=strbstr(s,s2);
        char* p3=strstr(s,s2), *p4=strbstr(s,s1);
        int len1=0,len2=0;
        if(p1 == p2)
        {len1=0;}
        else if(p1==NULL || p2==NULL)
        {len1=0;}
        else 
        {len1=p2-p1-strlen(s1);}

        
        if(p3 == p4)
        {len2=0;}
        else if(p3==NULL || p4==NULL)
        {len2=0;}
        else 
        
        {len2=p4-p3-strlen(s2);}
        int max=(len1>len2)?len1:len2;
        printf("case #%d:\n",j);
        printf("%d\n",max);
    }
    return 0;
}