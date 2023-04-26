#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char date[11];
    char clock[6];
    int  digit;
    char name[64];
}DATA;

int cmpname(const void*a , const void*b)
{
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    return strcmp(x->name , y->name);
}

int cmpsize(const void*a , const void*b)
{      //大小升序 ，文件名升序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    if(x->digit != y->digit)
        return(x->digit - y->digit);
    else
        return strcmp(x->name , y->name);
}

int cmptime(const void*a , const void*b)
{      //时间升序 ，文件名升序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    if(strcmp(x->date , y->date) != 0)
        return strcmp(x->date , y->date);
    else
    {
        if(strcmp(x->clock , y->clock) != 0)
            return strcmp(x->clock , y->clock);
        else 
            return strcmp(x->name , y->name);
    }
}




int main()
{
    int n;         //每个问题中信息的行数
    
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        int index;
        int i;
        char order[20];
        DATA FILE[n];
        for(index = 0;index < n;index++)   //输入文件信息
        {
            scanf("%s",FILE[index].date);
            scanf("%s",FILE[index].clock);
            scanf("%d",&FILE[index].digit);
            scanf("%s",FILE[index].name);
        }
        
        gets(order);
        if(strcmp(order,"LIST /NAME") == 0)
        {
            qsort(FILE , n , sizeof(DATA) , cmpname);
            for(i=0 ; i<n ; i++)
            {
                printf("%s ",FILE[i].date);
                printf("%s ",FILE[i].clock);
                printf("%16d ",FILE[i].digit);
                printf("%s\n",FILE[i].name);
            }
            print("\n");
        }
        if(strcmp(order,"LIST /SIZE") == 0)
        {
            qsort(FILE , n , sizeof(DATA) , cmpsize);
            for(i=0 ; i<n ; i++)
            {
                printf("%s ",FILE[i].date);
                printf("%s ",FILE[i].clock);
                printf("%16d ",FILE[i].digit);
                printf("%s\n",FILE[i].name);
            }
            print("\n");
        }
        if(strcmp(order,"LIST /TIME") == 0)
        {
            qsort(FILE , n , sizeof(DATA) , cmptime);
            for(i=0 ; i<n ; i++)
            {
                printf("%s ",FILE[i].date);
                printf("%s ",FILE[i].clock);
                printf("%16d ",FILE[i].digit);
                printf("%s\n",FILE[i].name);
            }
            print("\n");
        }
            
    }
    return 0;
}







