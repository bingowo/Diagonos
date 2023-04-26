#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(void *a,void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    char tmp=getchar();
    for(int i=0;i<n;i++)
    {
        char s[100];
        scanf("%s",s);
        int maps[1000],ans[1000],count=0;
        memset(maps,0,1000);
        for(int j=0;j<strlen(s);j++) maps[s[j]]++;
        while(maps['Z']!=0)
        {
            ans[count++]=0;
            maps['Z']--;
            maps['E']--;
            maps['R']--;
            maps['O']--;
        }
        while(maps['X']!=0)
        {
            ans[count++]=6;
            maps['S']--;
            maps['I']--;
            maps['X']--;
        }
        while(maps['G']!=0)
        {
            ans[count++]=8;
            maps['E']--;
            maps['I']--;
            maps['G']--;
            maps['H']--;
            maps['T']--;
        }
        while(maps['S']!=0)
        {
            ans[count++]=7;
            maps['S']--;
            maps['E']--;
            maps['V']--;
            maps['E']--;
            maps['N']--;
        }
         while(maps['V']!=0)
        {
            ans[count++]=5;
            maps['F']--;
            maps['I']--;
            maps['V']--;
            maps['E']--;
        }
         while(maps['F']!=0)
        {
            ans[count++]=4;
            maps['F']--;
            maps['O']--;
            maps['U']--;
            maps['R']--;
        }
        while(maps['W']!=0)
        {
            ans[count++]=2;
            maps['T']--;
            maps['O']--;
            maps['W']--;
        }
         while(maps['H']!=0)
        {
            ans[count++]=3;
            maps['T']--;
            maps['H']--;
            maps['R']--;
            maps['E']--;
            maps['E']--;
        }
        while(maps['O']!=0)
        {
            ans[count++]=1;
            maps['O']--;
            maps['N']--;
            maps['E']--;
        }
        while(maps['I']!=0)
        {
            ans[count++]=9;
            maps['N']--;
            maps['I']--;
            maps['N']--;
            maps['E']--;
        }
        qsort(ans,count,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(int x=0;x<count;x++) printf("%d",ans[x]);
        printf("\n");
    }
}
