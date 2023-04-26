#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 81

void reverse(char a[])
{
    int i = 0,j = strlen(a) - 1;
    char temp;
    while(i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char s1[L],s2[L],s[L],temp[L],temp1[L],temp2[L];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        memcpy(temp,s,L);
        memcpy(temp1,s1,L);
        memcpy(temp2,s2,L);
        reverse(temp);
        reverse(temp1);
        reverse(temp2);
        int dis1,dis2;
        int len = strlen(s),len1 = strlen(s1),len2 = strlen(s2);
        dis1 = (len - (strstr(temp,temp2) - temp)) - (strstr(s,s1) - s) - len1 - len2;
        dis2 = (len - (strstr(temp,temp1) - temp)) - (strstr(s,s2) - s) - len1 - len2;
        printf("case #%d:\n%d\n",i,(dis1 > dis2)?dis1:dis2);
    }
    return 0;
}