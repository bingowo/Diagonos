#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag0;

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        flag0=0;
        int time[150]={0};//记录不同字母出现的次数
        char w[10][6]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
        char s[25];
        scanf("%s",s);
        int l=strlen(s);
        int ans[10]={0};
        for(int y=0;y<10;y++) ans[y]=-1;
        for(int i=0;i<l;i++)
        {
            time[s[i]]++;
        }

        minus(time,ans,0,0,9);

        printf("case #%d:\n",z);

        for(int k=0;k<10;k++)
            if(ans[k]!=-1) printf("%d",ans[k]);


        printf("\n");
    }


    return 0;
}





void minus(int *a1,int *b,int l,int len,int des)
{
    if(flag0==1) return;
    int a[150];
    char w[10][6]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

    copy(a,a1,150);

    if(l==des) return;

    for(;l<des;l++)
    {
        if(flag0==1) break;
        b[len]=l;
        for(int z=0;z<=len;z++)
        {
            int l0=strlen(w[b[z]]);
            for(int k=0;k<l0;k++)
            {
                a[w[b[z]][k]]--;
            }
        }
        if(judge(a)==1) {flag0=1;return;}
        else copy(a,a1,150);
        minus(a,b,l+1,len+1,des);
        l--;
    }
    return ;
}

int judge(int *a)
{
    int i;
    int flag=0;
    for(i=60;i<150;i++)
    {
        if(a[i]!=0) return 0;
    }
    return 1;
}


void copy(int *a,int *a1,int l)
{
    for(int i=0;i<l;i++)
    {
        a[i]=a1[i];
    }
    return ;
}
