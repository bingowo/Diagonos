#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cmp(const void*p,const void* q)
{
    int* a=(int*)p;
    int* b=(int*)q;
    return(*a-*b);
}
int main()
{
    int T;
    scanf("%d",&T);
    char s[30];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        int a[100]={0};
        int ans[20]={0};int k=0;
        for(int i=0;i<strlen(s);i++)
        {
            a[s[i]]++;
        }
        int t=a['Z'];
        for(int i=0;i<t;i++)
        {
            a['Z']--;a['E']--;a['R']--;a['O']--;
            ans[k++]=0;
        }
        t=a['W'];
        for(int i=0;i<t;i++)
        {
            a['T']--;a['W']--;a['O']--;
            ans[k++]=2;
        }
        t=a['X'];
        for(int i=0;i<t;i++)
        {
            a['S']--;a['I']--;a['X']--;
            ans[k++]=6;
        }
        t=a['G'];
        for(int i=0;i<t;i++)
        {
            a['E']--;a['I']--;a['G']--;a['H']--;a['T']--;
            ans[k++]=8;
        }
        t=a['S'];
        for(int i=0;i<t;i++)
        {
            a['S']--;a['E']--;a['V']--;a['E']--;a['N']--;
            ans[k++]=7;
        }
        t=a['V'];
        for(int i=0;i<t;i++)
        {
            a['F']--;a['I']--;a['V']--;a['E']--;
            ans[k++]=5;
        }
        t=a['F'];
        for(int i=0;i<t;i++)
        {
            a['F']--;a['O']--;a['U']--;a['R']--;
            ans[k++]=4;
        }
        t=a['R'];
        for(int i=0;i<t;i++)
        {
            a['T']--;a['H']--;a['R']--;a['E']--;a['E']--;
            ans[k++]=3;
        }
        t=a['I'];
        for(int i=0;i<t;i++)
        {
            a['N']--;a['I']--;a['N']--;a['E']--;
            ans[k++]=9;
        }
        t=a['O'];
        for(int i=0;i<t;i++)
        {
            a['O']--;a['N']--;a['E']--;
            ans[k++]=1;
        }
        qsort(ans,k,sizeof(ans[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<k;i++) printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
