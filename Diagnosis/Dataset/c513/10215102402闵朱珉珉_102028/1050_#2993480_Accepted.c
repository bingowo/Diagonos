#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf ("%d",&T);
    getchar();
    for (int q=0;q<T;q++)
    {
        char s1[81]="",s2[81]="",s[81]="",temp1[81]="",temp2[81]="";
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);//in
        int len=strlen(s),len1=strlen(s1),len2=strlen(s2);
        int num=0;
        char *p=s;
        for (int i=0;i<len;i++)
        {
            strncpy(temp1,p+i,len1);
            if (strcmp(s1,temp1)==0)
            {
                int t1=0,t2=0;
                for (int j=i+len1;j<len-len2+1;j++)
                {
                    strncpy(temp2,p+j,len2);
                    t2++;
                    if (strcmp(s2,temp2)==0)
                    {
                        t2--;
                        if(t2>t1) t1=t2;
                        t2++;
                    }
                }
                if (t1>num) num=t1;
            }
        }
        for (int i=0;i<len;i++)
        {
            strncpy(temp2,p+i,len2);
            if (strcmp(s2,temp2)==0)
            {
                int t1=0,t2=0;
                for (int j=i+len2;j<len-len1+1;j++)
                {
                    strncpy(temp1,p+j,len1);
                    t2++;
                    if (strcmp(s1,temp1)==0)
                    {
                        t2--;
                        if(t2>t1) t1=t2;
                        t2++;
                    }
                }
                if (t1>num) num=t1;
            }
        }
        printf("case #%d:\n",q);
        printf("%d\n",num);
    }
    return 0;
}
