#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    int aa=*(int*)a,bb=*(int*)b;
    return aa-bb;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int pw[7]={0};
        int a[127]={0};
        char s[31]={0};
        scanf("%s",s);
        for(int j=0;j<strlen(s);j++)
            a[s[j]]+=1;
        int cnt=0;
        for(int j='E';j<='W';)
        {
            switch(j)
            {
                case 'E':
                {
                    while(a[j])
                    {
                        if(a['Z']&&a['R']&&a['O']) pw[cnt++]=0,a['Z']-=1,a['R']-=1,a['O']-=1,a['E']-=1;
                        else if(a['N']&&a['O']) pw[cnt++]=1,a['N']-=1,a['E']-=1,a['O']-=1;
                        else if(a[j]>=2&&a['T']&&a['R']&&a['H']) pw[cnt++]=3,a['E']-=2,a['T']-=1,a['H']-=1,a['R']-=1;
                        else if(a['F']&&a['I']&&a['V']) pw[cnt++]=5,a['F']-=1,a['I']-=1,a['V']-=1,a['E']-=1;
                        else if(a[j]>=2&&a['S']&&a['V']&&a['N']) pw[cnt++]=7,a['S']-=1,a['V']-=1,a['N']-=1,a['E']-=2;
                        else if(a['I']&&a['G']&&a['H']&&a['T']) pw[cnt++]=8,a['I']-=1,a['G']-=1,a['H']-=1,a['T']-=1,a['E']-=1;
                        else if(a['N']>=2&&a['I']) pw[cnt++]=9,a['N']-=2,a['I']-=1,a['E']-=1;
                    }
                    j++;
                    break;
                }
                case 'F':
                {
                    while(a[j])
                    {
                        if(a['O']&&a['U']&&a['R']) pw[cnt++]=4,a['O']-=1,a['U']-=1,a['R']-=1,a['F']-=1;
                    }
                    j++;
                    break;
                }
                case 'I':
                {
                    while(a[j])
                    {
                        if(a['S']&&a['X']) pw[cnt++]=6,a['I']-=1,a['S']-=1,a['X']-=1;
                    }
                    j++;
                    break;
                }
                case 'O':
                {
                    while(a[j])
                    {
                        if(a['T']&&a['W']) pw[cnt++]=2,a['O']-=1,a['T']-=1,a['W']-=1;
                    }
                    j++;
                    break;
                }
                default:j++;
            }
        }
        qsort(pw,cnt,sizeof(pw[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<cnt;j++)
            printf("%d",pw[j]);
        printf("\n");
    }
    return 0;
}