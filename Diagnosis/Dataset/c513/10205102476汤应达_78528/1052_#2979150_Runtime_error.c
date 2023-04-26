#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    int T;scanf("%d",&T);getchar();
    for(int p=0;p<T;p++)
    {
        int ans[10],cnt=0;
        char line[20],tmp[6];gets(line);
        int l=strlen(line);
        for(int i=0;i<(int)strlen(line);i++)
        {
            switch (line[i])
            {
            case 'W':
                {strcpy(tmp,"TWO");ans[cnt++]=2;l-=3;
                for(int t=0;t<3;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'U':
                {strcpy(tmp,"FOUR");ans[cnt++]=4;l-=4;
                for(int t=0;t<4;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'X':
                {strcpy(tmp,"SIX");ans[cnt++]=6;l-=3;
                for(int t=0;t<3;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'G':
                {strcpy(tmp,"EIGHT");ans[cnt++]=8;l-=5;
                for(int t=0;t<5;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'Z':
                {strcpy(tmp,"ZERO");ans[cnt++]=0;l-=4;
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
                {strcpy(tmp,"FIVE");ans[cnt++]=5;l-=4;
                for(int t=0;t<4;t++)
                    line[find(tmp[t],line)]=-1;
                break;}     
            case 'S':
                {strcpy(tmp,"SEVEN");ans[cnt++]=7;l-=5;
                for(int t=0;t<5;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'O':
                {strcpy(tmp,"ONE");ans[cnt++]=1;l-=3;
                for(int t=0;t<3;t++)
                    line[find(tmp[t],line)]=-1;
                break;}
            case 'T':
                {strcpy(tmp,"THREE");ans[cnt++]=3;l-=5;
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