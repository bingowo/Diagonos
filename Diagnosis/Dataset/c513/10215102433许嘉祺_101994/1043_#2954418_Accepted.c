#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int erase(char*s)
{
    char s1[105],s2[105];
    int find=1;
    strcpy(s2,s);
    int len1=strlen(s2),len=0;;

    while (find==1)
    {
        find=0;
        len=0;
        for (int i=0; i<strlen(s2); i++)
        {
            if (i==0)
            {
                if (s2[i]==s2[i+1]) find=1;
                else s1[len++]=s2[i];
            }
            else if(i==strlen(s2)-1)
            {
                if (s2[i]==s2[i-1]) find=1;
                else s1[len++]=s2[i];
            }
            else if(s2[i]==s2[i-1]||s2[i]==s2[i+1]) find=1;
            else s1[len++]=s2[i];
        }
        s1[len]=0;
        strcpy(s2,s1);
    }

    return len1-strlen(s2);

}


int main()
{
    int t;
    scanf("%d",&t);
    char s[105];
    for (int i=0; i<t; i++)
    {
        scanf("%s",s);
        int find=1;
        int count=strlen(s);
        while (find==1)
            find=erase(s);
        count=count-strlen(s);

        int nummax=0;
        int num=0;
        for (int j=0; j<strlen(s)+1; j++)
        {
            char t[105];
            for (int k=0; k<j &&j!=0; k++) t[k]=s[k];
            for (int k=j; k<strlen(s)+1; k++) t[k+1]=s[k];
            for (int k=0; k<3; k++)
            {
                t[j]='A'+k;
                num=erase(t);
                if (num>nummax)nummax=num;
            }
        }
        printf("case #%d:\n",i);

        printf("%d\n",nummax);

    }

    return 0;
}
