//sort\1020.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define LOCAL
#define TRUE 1
#define FALSE 0
struct onefile
{
    int year,month,day,hour,minute;
    long long size;
    char name[70];
};
typedef struct onefile Afile;
Afile flist[105];

int cmpname(Afile*x,Afile*y)
{
    return strcmp(x->name,y->name);
}
int cmptime(Afile*x,Afile*y)
{
    if(x->year==y->year){
        if(x->month==y->month){
            if(x->day==y->day){
                if(x->hour==y->hour){
                    if(x->minute==y->minute){
                        return cmpname(x,y);
                    }else{
                        return x->minute>y->minute?1:-1;
                    }
                }else{
                    return x->hour>y->hour?1:-1;
                }
            }else{
                return x->day>y->day?1:-1;
            }
        }else{
            return x->month>y->month?1:-1;
        }
    }else{
        return x->year>y->year?1:-1;
    }
}

int cmpsize(Afile*x,Afile*y)
{
    if(x->size==y->size)
        return cmpname(x,y);
    else
        return x->size>y->size?1:-1;
}
char field[7];

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    while(scanf("%d",&n)&&n!=0){
        for(int in=0;in<n;++in){
            scanf("%d-%d-%d",&flist[in].year,&flist[in].month,&flist[in].day);
            scanf("%d:%d",&flist[in].hour,&flist[in].minute);
            scanf("%lld",&flist[in].size);
            scanf("%s",&flist[in].name);
        }
        scanf("%s",field);
        scanf("%s",field);
        switch(field[1]){
    case'N':
        qsort(flist,n,sizeof(flist[0]),cmpname);
        break;
    case'S':
        qsort(flist,n,sizeof(flist[0]),cmpsize);
        break;
    case'T':
        qsort(flist,n,sizeof(flist[0]),cmptime);
        break;
        }
        for(int in=0;in<n;++in){
            printf("%04d-%02d-%02d ",flist[in].year,flist[in].month,flist[in].day);
            printf("%02d:%02d ",flist[in].hour,flist[in].minute);
            printf("%16lld ",flist[in].size);
            printf("%s",flist[in].name);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
