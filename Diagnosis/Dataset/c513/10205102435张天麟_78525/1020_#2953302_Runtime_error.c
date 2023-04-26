#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char s[100];
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int size;
    char name[64];
}wenjian;
int cmpN(const void *a,const void *b)
{
    return strcmp(((wenjian*)a)->name,((wenjian*)b)->name);
}
int cmpS(const void *a,const void *b)
{
    return ((wenjian*)a)->size-((wenjian*)b)->size+strcmp(((wenjian*)a)->name,((wenjian*)b)->name);
}
int cmpT(const void *a,const void *b)
{
    return ((wenjian*)b)->year*634400+((wenjian*)b)->month*48800+((wenjian*)b)->day*1525+((wenjian*)b)->hour*61+((wenjian*)b)->minute-((wenjian*)a)->year*634400-((wenjian*)a)->month*48800-((wenjian*)a)->day*1525-((wenjian*)a)->hour*61-((wenjian*)a)->minute+strcmp(((wenjian*)a)->name,((wenjian*)b)->name);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    while(n!=0)
    {
        wenjian wj[n];
        for(i=0;i<n;i++)
        {
            gets(wj[i].s);
            int len=strlen(wj[i].s);
            char s[len+1];
            strcpy(s,wj[i].s);
            char c;
            int j,k=0,year=0,month=0,day=0,hour=0,minute=0,size;
            for(j=0;j<len;j++)
            {
                if(k==0)
                {
                    c=s[j];
                    if(c!='-')
                    {
                        year*=10;
                        year+=c-'0';
                    }
                    else
                    {
                        k++;
                        wj[i].year=year;
                    }
                }
                else if(k==1)
                {
                    c=s[j];
                    if(c!='-')
                    {
                        month*=10;
                        month+=c-'0';
                    }
                    else
                    {
                        k++;
                        wj[i].month=month;
                    }
                }
                else if(k==2)
                {
                    c=s[j];
                    if(c!=' ')
                    {
                        day*=10;
                        day+=c-'0';
                    }
                    else
                    {
                        k++;
                        wj[i].day=day;
                    }
                }
                else if(k==3)
                {
                    c=s[j];
                    if(c!=':')
                    {
                        hour*=10;
                        hour+=c-'0';
                    }
                    else
                    {
                        k++;
                        wj[i].hour=hour;
                    }
                }
                else if(k==4)
                {
                    c=s[j];
                    if(c!=' ')
                    {
                        minute*=10;
                        minute+=c-'0';
                    }
                    else
                    {
                        k++;
                        wj[i].minute=minute;
                    }
                }
                else if(k==5)
                {
                    c=s[j];
                    if(c!=' ')
                    {
                        k++;
                        size=c-'0';
                    }
                }
                else if(k==6)
                {
                    c=s[j];
                    if(c!=' ')
                    {
                        size*=10;
                        size+=c-'0';
                    }
                    else
                    {
                        wj[i].size=size;
                        k++;
                    }
                }
                else
                {
                    char *p;
                    p=&s[j];
                    strcpy(wj[i].name,p);
                }
            }
            char list[6];
            scanf("%s",list);
            scanf("%s",list);
            c=list[1];
            if(c=='N')
            {
                qsort(wj,n,sizeof(wj[0]),cmpN);
            }
            else if(c=='S')
            {
                qsort(wj,n,sizeof(wj[0]),cmpS);
            }
            else
            {
                qsort(wj,n,sizeof(wj[0]),cmpT);
            }
            for(i=0;i<n;i++)
            {
                printf("%s\n",wj[i].s);
            }
        }
        scanf("%d",&n);
    }
    return 0;
}
