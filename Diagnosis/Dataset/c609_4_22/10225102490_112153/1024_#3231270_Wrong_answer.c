#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    //long long time;
    int year,mon,day,hour,minute;
    int sizef;
    char name[101];
} file;
char *m[] = {"NAME","SIZE","TIME"};
char shunxu[5];
int cmp(file* a, file* b)
{
    //printf("cmp\n");
    if (strcmp(shunxu,m[0]) == 0) {return strcmp(a->name,b->name);}
    else if (strcmp(shunxu,m[1]) == 0)
    {
        //printf("size\n");
        if (a->sizef != b->sizef)
        {
            if (a->sizef > b->sizef) return 1;
            else return -1;
        }
        else return strcmp(a->name,b->name);
    }
    else if (strcmp(shunxu,m[2]) == 0)
    {
        //printf("time\n");
        if (a->year != b->year) return a->year - b->year;
        else if (a->mon != b->mon) return a->mon - b->mon;
        else if (a->day != b->day) return a->day - b->day;
        else if (a->hour != b->hour) return a->hour - b->hour;
        else if (a->minute != b->minute) return a->minute - b->minute;
        else return strcmp(a->name,b->name);
    }
    else return 0;
}

void shuru(int n,file *a)
{
    for (int i = 0; i < n; i++)
    {
        //long long Time;
        int y,mo,d,h,mi;
        scanf("%d-%d-%d %d:%d",&y,&mo,&d,&h,&mi);
        //printf("%d %d %d %d %d\n",y,mo,d,h,mi);
        a[i].year = y; a[i].mon = mo; a[i].day = d; a[i].hour = h; a[i].minute = mi;
        //printf("%d %d %d %d %d\n",a[i].year, a[i].mon, a[i].day, a[i].hour, a[i].minute);
        //Time = y*pow(10,8) + mo*pow(10,6) + d*pow(10,4) + h*pow(10,2) + mi;
        //printf("%lld",Time);
        //a[i].time = Time;

        char c;
        while ((c=getchar()) == ' '); //printf("%c\n",c);
        a[i].sizef = c - '0';//printf("%d\n",a[i].sizef);
        while ((c=getchar()) != ' ') {a[i].sizef = a[i].sizef * 10 + c - '0'; /*printf("%d ",a[i].sizef);*/}
        //a[i].sizef = s;
        //printf("\n");
        //printf("%s\n",a[i].sizef);

        int j = 0;
        while ((c=getchar()) != '\n'){ a[i].name[j] = c;/*printf("%c",a[i].name[j]);*/ j++;}
        a[i].name[j] = '\0';
        //printf("%s\n",a[i].name);
    }
}

void Sort(file *ps,int n)
{
    //printf("sort\n");
    qsort(ps,n,sizeof(file),cmp);
}


int main()
{
    int n;
    //char c;
    while (scanf("%d",&n) && n != 0 )
    {
        //n = c - '0';
        //printf("%d\n",n);
        file *a = (file*)malloc(sizeof(file) * n);
        shuru(n,a);
        scanf("LIST /%s",shunxu);
        //printf("%s\n",shunxu);
        Sort(a,n);
        for (int i = 0; i < n; i++)
        {
            printf("%d-%02d-%02d %02d:%02d %16d %s\n",
               a[i].year,a[i].mon,a[i].day,a[i].hour,a[i].minute,a[i].sizef,a[i].name);
        }
        free(a);
    }
}
