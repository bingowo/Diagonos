#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s1[85];
        char s2[85];
        char s[85];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        int len1=strlen(s1),len2=strlen(s2),len=strlen(s);
        int mark1,mark2;
        int j,r;
        for(j=0,r=0;r<len1;j++)//查找正确mark1的位置
        {
            if(j>len-1)
                break;
            if(s1[r] != s[j])
            {
                r=0;//归零
            }
            else
            {
                r++;
            }
        }
        mark1 = j;
        
        int k,l;
        for(k=len-1,l=len2-1;l>0;k--)
        {
            if(k<0)
                break;
            if(s2[l] != s[k])
            {
                l=len2-1;
            }
            else
            {
                l--;
            }
        }
        mark2 = k;
        int dist;
        dist = mark2-mark1;
        printf("%d,%d\n",mark1,mark2);
    }
    return 0;
}

