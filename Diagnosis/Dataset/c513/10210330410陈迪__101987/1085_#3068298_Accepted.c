#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20000
int compare(char *s1, char *s2);
int main()
{
    char str1[MAX], str2[MAX], temp[MAX];
    while(scanf("%s",temp)!=EOF)
    {
        strcpy(str1,temp);
        scanf("%s",temp);
        strcpy(str2,temp);
        int a[MAX], b[MAX], len;
        int i;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[0]=strlen(str1);
        for(i=1;i<=a[0];i++) a[i]=str1[a[0]-i]-'0';
        b[0]=strlen(str2);
        for(i=1;i<=b[0];i++) b[i]=str2[b[0]-i]-'0';
        if(compare(str1,str2)==0)
        {
            for(i=1;i<=a[0];i++)
            {
                a[i]-=b[i];
                if(a[i]<0) a[i+1]--,a[i]+=10;
            }
            a[0]++;
            while(a[a[0]]==0 && a[0]>1) a[0]--;
            for(i=a[0];i>=1;i--) printf("%d",a[i]);
            printf("\n");
        }
        else
        {
            printf("-");
            for(i=1;i<=b[0];i++)
            {
                b[i]-=a[i];
                if(b[i]<0) b[i+1]--,b[i]+=10;
            }
            b[0]++;
            while(b[b[0]]==0 && b[0]>1) b[0]--;
            for(i=b[0];i>=1;i--) printf("%d",b[i]);
            printf("\n");
        }
    }
}
int compare(char *s1, char *s2)
{
    if(strlen(s1)>strlen(s2)) return 0;
    if(strlen(s1)<strlen(s2)) return 1;
    for(int i=0;i<strlen(s1);i++)
    {
        if(s1[i]>s2[i]) return 0;
        if(s1[i]<s2[i]) return 1;
    }
    return 0;
}
