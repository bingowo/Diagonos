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
    for(int j=0;s[j]!=0;j++)
    {
        a[s[j]]++;
    }

   /* two:w
    four:u  five:F
    six:x  seven:S
    eight:g three:H

    one:O
    nine:I*/
 while(a['Z'])
    {
        a['Z']--;
        a['E']--;
        a['R']--;
        a['O']--;
        ans[cnt++]=0;
    }
    while(a['W'])
    {
        a['T']--;
        a['W']--;
        a['O']--;
        ans[cnt++]=2;
    }
    while(a['U'])
    {
        a['F']--;
        a['O']--;
        a['U']--;
        a['R']--;
        ans[cnt++]=4;

    }
     while(a['X'])
    {
        a['S']--;
        a['I']--;
        a['X']--;
        ans[cnt++]=6;
    }
     while(a['G'])
    {

        a['E']--;
        a['I']--;
        a['G']--;
        a['H']--;
        a['T']--;
        ans[cnt++]=8;
    }
    while(a['F'])
    {

        a['F']--;
        a['I']--;
        a['V']--;
        a['E']--;
        ans[cnt++]=5;
    }

    while(a['S'])
    {

        a['S']--;
        a['E']--;
        a['V']--;
        a['E']--;
        a['N']--;
        ans[cnt++]=7;
    }
    while(a['T'])
    {

        a['T']--;
        a['H']--;
        a['R']--;
        a['E']--;
        a['E']--;
        ans[cnt++]=3;
    }
    while(a['O'])
    {

        a['O']--;
        a['N']--;
        a['E']--;

        ans[cnt++]=1;
    }
    while(a['I'])
    {

        a['N']--;
        a['I']--;
        a['N']--;
        a['E']--;
        ans[cnt++]=9;
    }
    qsort(ans,cnt,sizeof(ans[0]),cmp);////
    printf("case #%d:\n",i);
    for(int j=0;j<cnt;j++)
        printf("%d",ans[j]);
    printf("\n");
}
return 0;
}


