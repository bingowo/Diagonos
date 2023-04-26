#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[150];
    int size;
    int year,month,day,hour,minute;
}myfile;

int cmpNAME(const void*a,const void*b)
{
    myfile aa=(*(myfile*)a);
    myfile bb=(*(myfile*)b);
    return strcmp(aa.name,bb.name);

}
int cmpSIZE(const void*a,const void*b)
{
    myfile aa=(*(myfile*)a);
    myfile bb=(*(myfile*)b);
    if (aa.size>bb.size) return 1;
    else if(aa.size<bb.size) return -1;
    else return strcmp(aa.name,bb.name);

}

int cmpTIME(const void*a,const void*b)
{
    myfile aa=(*(myfile*)a);
    myfile bb=(*(myfile*)b);

    if (aa.year>bb.year) return 1;
    else if(aa.year<bb.year) return -1;
    else
    {
        if (aa.month>bb.month) return 1;
        else if(aa.month<bb.month) return -1;
        else
        {
            if (aa.day>bb.day) return 1;
            else if(aa.day<bb.day) return -1;
            else
            {
                if (aa.hour>bb.hour) return 1;
                else if(aa.hour<bb.hour) return -1;
                else
                {
                    if (aa.minute>bb.minute) return 1;
                    else if(aa.minute<bb.minute) return -1;
                    else return strcmp(aa.name,bb.name);
                }
            }
        }
    }

}

int main()
{
    int n,i;

    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        printf("\n");
        myfile f[110];
        int len,j,be,en,k;
        char c;
        char stime[20];
        char mingling[10],s[5];
        for(i=0;i<n;i++)
        {
            f[i].year=0;
            f[i].month=0;
            f[i].day=0;
            scanf("%s%d%c%d%d%s",stime,&f[i].hour,&c,&f[i].minute,&f[i].size,f[i].name);
            //printf("year0=%d\n",f[i].year);
            //printf("s=%s\nhour=%d\n%c\nmin=%d\nsize=%d\nname=%s\n",stime,f[i].hour,c,f[i].minute,f[i].size,f[i].name);
            len=strlen(stime);
            for(j=0;j<len;j++)
            {
                if(stime[j]=='-')
                {
                    en=j;
                    //printf("en=%d\n",en);
                    for(k=0;k<en;k++)
                    {
                        f[i].year*=10;
                        f[i].year+=stime[k]-'0';
                    }
                    break;
                }
            }
            //printf("year=%d\n",f[i].year);
            be=en;
            for(j=be+1;j<len;j++)
            {
                if(stime[j]=='-')
                {
                    en=j;
                    for(k=be+1;k<en;k++)
                    {
                        f[i].month*=10;
                        f[i].month+=stime[k]-'0';
                    }
                    break;
                }
            }
            be=en;
            for(j=be+1;j<len;j++)
            {
                f[i].day*=10;
                f[i].day+=stime[j]-'0';
            }

             //printf("test test %d-%02d-%02d %02d:%02d%16d %s\n",f[i].year,f[i].month,f[i].day,f[i].hour,f[i].minute,f[i].size,f[i].name);
        }
        scanf("%s",s);
        scanf("%s",mingling);
        //printf("s=%s\n",s);
        //printf("mingling=%s\n",mingling);
        if(strcmp(mingling,"/NAME")==0) qsort(f,n,sizeof(myfile),cmpNAME);
        else if(strcmp(mingling,"/SIZE")==0) qsort(f,n,sizeof(myfile),cmpSIZE);
        else if(strcmp(mingling,"/TIME")==0) qsort(f,n,sizeof(myfile),cmpTIME);
    //i=0;
    //printf("test test:\n%d-%02d-%02d %02d:%02d%16d %s\n",f[i].year,f[i].month,f[i].day,f[i].hour,f[i].minute,f[i].size,f[i].name);
        for(i=0;i<n;i++)
        {
            printf("%d-%02d-%02d %02d:%02d %16d %s\n\n",f[i].year,f[i].month,f[i].day,f[i].hour,f[i].minute,f[i].size,f[i].name);
        }
        //printf("%d-%02d-%02d %02d:%02d %16d %s\n",f[i].year,f[i].month,f[i].day,f[i].hour,f[i].minute,f[i].size,f[i].name);

    }
    return 0;
}
