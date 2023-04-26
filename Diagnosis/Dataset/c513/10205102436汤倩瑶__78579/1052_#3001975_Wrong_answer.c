#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    return *((int *)a)-*((int *)b);

}
int main()
{int T;
scanf("%d",&T);
char s[25];

for(int i=0;i<T;i++)
{
    scanf("%s",s);
    int a[128]={0};
    int ans[20]={0};
    int cnt=0;
    for(int j=0;s[j];j++)
    {
        a[s[j]]++;
    }
   /* two:w
    four:u  five:F
    six:x  seven:S
    eight:g three:H

    one:O
    nine:I*/

    while(a['W']>0)
    {
        a['T']--;
        a['W']--;
        a['O']--;
        ans[cnt++]=2;
    }
    while(a['U']>0)
    {
        a['F']--;
        a['O']--;
        a['U']--;
        a['R']--;
        ans[cnt++]=4;
    }
     while(a['X']>0)
    {
        a['S']--;
        a['I']--;
        a['X']--;
        ans[cnt++]=6;
    }
     while(a['G']>0)
    {

        a['E']--;
        a['I']--;
        a['G']--;
        a['H']--;
        a['T']--;
        ans[cnt++]=8;
    }
    while(a['F']>0)
    {

        a['F']--;
        a['I']--;
        a['V']--;
        a['E']--;
        ans[cnt++]=5;
    }
    while(a['S']>0)
    {

        a['S']--;
        a['E']--;
        a['V']--;
        a['E']--;
        a['N']--;
        ans[cnt++]=7;
    }
    while(a['T']>0)
    {

        a['T']--;
        a['H']--;
        a['R']--;
        a['E']--;
        a['E']--;
        ans[cnt++]=3;
    }
    while(a['O']>0)
    {

        a['O']--;
        a['N']--;
        a['E']--;

        ans[cnt++]=1;
    }
    while(a['I']>0)
    {

        a['N']--;
        a['I']--;
        a['N']--;
        a['E']--;
        ans[cnt++]=9;
    }
    qsort(ans,cnt,sizeof(ans),cmp);
    printf("case #%d:\n",i);
    for(int j=0;j<cnt;j++)
        printf("%d",ans[j]);
    printf("\n");
}
return 0;
}


