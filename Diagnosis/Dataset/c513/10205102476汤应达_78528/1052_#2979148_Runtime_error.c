#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int l1[100],l2[100];

int find(char c,char*s)
{
    for(int i=0;i<(int)strlen(s);i++)
        if(s[i]==c) return i;
    return -1;
}

int cmp(const void*a,const void*b)
{return *(int*)a>*(int*)b?1:-1;}

int main()
{
    l1['W']=2,l1['U']=4,l1['X']=6,l1['G']=8,l1['Z']=0;
    l2['F']=5,l2['S']=7,l2['O']=1,l2['T']=3;
    int T;scanf("%d",&T);getchar();
    for(int p=0;p<T;p++)
    {
        int ans[10],cnt=0;
        char line[20];gets(line);
        int l=strlen(line);
        for(int i=0;i<(int)strlen(line);i++)
        {
            switch (line[i])
            {
            case 'W':
                {char tmp[4]="TWO";ans[cnt++]=2;l-=3;
                for(int t=0;t<3;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'U':
                {char tmp[5]="FOUR";ans[cnt++]=4;l-=4;
                for(int t=0;t<4;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'X':
                {char tmp[4]="SIX";ans[cnt++]=6;l-=3;
                for(int t=0;t<3;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'G':
                {char tmp[6]="EIGHT";ans[cnt++]=8;l-=5;
                for(int t=0;t<5;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'Z':
                {char tmp[5]="ZERO";ans[cnt++]=0;l-=4;
                for(int t=0;t<4;t++)
                    line[find(tmp[t],line)]=-1;
                break;}         
            default:
                break;
            }
        }
        for(int i=0;i<(int)strlen(line);i++)
        {
            switch (line[i])
            {
            case 'F':
                {char tmp[5]="FIVE";ans[cnt++]=5;l-=4;
                for(int t=0;t<4;t++)
                    line[find(tmp[t],line)]=-1;
                break;}     
            case 'S':
                {char tmp[6]="SEVEN";ans[cnt++]=7;l-=5;
                for(int t=0;t<5;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'O':
                {char tmp[4]="ONE";ans[cnt++]=1;l-=3;
                for(int t=0;t<3;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'T':
                {char tmp[6]="THREE";ans[cnt++]=3;l-=5;
                for(int t=0;t<5;t++)
                    line[find(tmp[t],line)]=-1;
                break;}            
            default:
                break;
            }
        }
        for(int i=0;i<l/4;i++) ans[cnt++]=9;
        qsort(ans,cnt,sizeof(int),cmp);
        printf("case #%d:\n",p);
        for(int i=0;i<cnt;i++) printf("%d",ans[i]);
        printf("\n");
    }

    return 0;
}