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
        int mark1,mark11,mark2,mark22;
        int j,r;
        int dist,d1,d2;
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
        int J,R;
        for(J=len-1,R=len1-1;R>-1;J--)//查找正确mark11的位置
        {
            if(J<0)
                break;
            if(s1[R] != s[J])
            {
                R=len1-1;
            }
            else
            {
                R--;
            }
        }
        mark11 = J;
        
        if(j == len && r != len1) //没找到
        {
            mark1 = 100;
        }
        
        int k,l;
        for(k=len-1,l=len2-1;l>-1;k--)
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
        
        int K,L;
        for(K=0,L=0;L<len2;K++)//查找正确mark22的位置
        {
            if(K>len-1)
                break;
            if(s2[L] != s[K])
            {
                L=0;//归零
            }
            else
            {
                L++;
            }
        }
        mark22 = K;
        
        if(k == -1 && l != -1)//没找到
        {
            mark2 = -100;
        }
        
        d1=abs(mark1-mark2)+1;
        d2=abs(mark11-mark22)+1;
        if(d1>d2 && d1<len)
            dist = d1;
        else if(d2>d1 && d2<len)
            dist = d2;
        else if(d1<d2 && d2>len)
            dist = d1;
        else if(d1>d2 && d1>len)
            dist = d2;
        
        if(mark1 == 100 || mark2 == -100 || (strcmp(s1,s2) == 0 && strcmp(s,s1) == 0))
            printf("0\n");
        else if(dist > 0)
            printf("%d\n",dist);
        printf("%d  %d\n",mark1,mark2);
        printf("%d  %d\n",mark11,mark22);
    }
    return 0;
}

