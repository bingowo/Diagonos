#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct File
{
    int year;
    int mon;
    int day;
    int hour;
    int min;
    long long size;
    char name[30];
    
}file;

int Ncmp(const file A ,const file B)
{
    return (A.name < B.name?1:-1);
};
int Scmp(const file A ,const file B)
{
    if(A.size != B.size)
    {return (A.size < B.size?1:-1);}
    else 
        return (A.name < B.name?1:-1);
    
};
int Tcmp(const file A ,const file B)
{
    if(A.year < B.year)
    {return 1;}
    else if(A.year > B.year)
    {return 0;}
    else
    {
        if(A.mon < B.mon)
        {return 1;}
        else if(A.mon > B.mon)
        {return 0;}
        else
        {
            if(A.day < B.day)
            {return 1;}
            else if(A.day > B.day)
            {return 0;}
            else
            {
                if(A.hour < B.hour)
                {return 1;}
                else if(A.hour > B.hour)
                {return 0;}
                else
                {
                    if(A.min < B.min)
                    {return 1;}
                    else if(A.min > B.min)
                    {return 0;}
                    else
                    {
                        return(A.name < B.name?1:-1);
                    }
                }
            }
        }
    }

};


void func(int total)
{
    file* F ;
    F=(file* )malloc (sizeof(file)*total);
    for(int i = 0; i < total; i++)
    {
        char c;
        scanf("%d%c",&F[i].year, &c);
        scanf("%d%c",&F[i].mon, &c);
        scanf("%d%d%c",&F[i].day, &F[i].hour,&c);
        scanf("%d%lld%s",&F[i].min, &F[i].size, &F[i].name);
    }

    char list[10];
    char opera[10];
    scanf("%s%s",&list,&opera);

    if(opera == "/NAME")
    {
        sort(F,F+total,Ncmp);
    }
    else if (opera == "/SIZE")//
    {
        sort(F,F+total,Scmp);
    }
    else if (opera == "/TIME")
    {
        sort(F,F+total,Tcmp);
    }
    
    for(int i = 0; i < total; i++)
    {
        printf("%04d-%02d-%02d %02d:%02d%17lld ",F[i].year,F[i].mon,F[i].day,F[i].hour,F[i].min,F[i].size);
        printf("%s\n",F[i].name);
    }
    printf("\n");

}

int main()
{
    int total = 1;
    
    
    while(total)
    {   
        scanf("%d",&total);
        func(total);
    }
        
    return 0;
    
    
}
