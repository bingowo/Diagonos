#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char* str;
    int num;
}STR;
int compar(const void *p1,const void *p2);
void myPrint(STR *a,int n);
int main()
{
    int T,n,i,j;
    STR *a;
    char* temp;
    temp=(char*)malloc(21*sizeof(char));
    //memset(temp,0,21*sizeof(char));
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        a=(STR*)malloc(n*sizeof(STR));          //给a申请了空间后还要给a里面的str申请空间
        for(i=0;i<n;i++)
        {
            memset(temp,0,21*sizeof(char));
            a[i].str=(char*)malloc(21*sizeof(char));
            scanf("%s",a[i].str);
            a[i].num=0;

            for(j=0;j<strlen(a[i].str);j++)
            {
                if(strchr(temp,a[i].str[j])==NULL)
                {
                    a[i].num++;
                    temp[strlen(temp)]=a[i].str[j];
                }
            }
        }
        qsort(a,n,sizeof(STR),compar);        //二维数组不是char**，而是行指针
        myPrint(a,n);
        for(i=0;i<n;i++)
        {
            free(a[i].str);
        }
        free(a);
    }
    free(temp);
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    STR *a=(STR*)p1,*b=(STR*)p2;
    if(a->num>b->num)
        flag=-1;
    else if(a->num<b->num)
        flag=1;
    else
    {
        if(strcmp(a->str,b->str)>0)
            flag=1;
        else
            flag=-1;
    }
    return flag;
}
void myPrint(STR *a,int n)
{
    static int tim=0;
    int i;
    printf("case #%d:\n",tim);
    for(i=0;i<n;i++)
    {
        puts(a[i].str);
    }
}
