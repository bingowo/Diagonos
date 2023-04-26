#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* a,const void* b)
{
    int* a1=(int*)a;
    int* b1=(int*)b;
    if(*a1>*b1) return 1;
    else return -1;
}

int cmpD(const void* a,const void* b)
{
    int* a1=(int*)a;
    int* b1=(int*)b;
    if(*a1<*b1) return 1;
    else return -1;
}
int main()
{
    char c;
    scanf("%c",&c);
    int count=0;
    int number[101];
    int result[101];
    int index=0;
    char ch;
    do{
        scanf("%d",&number[count++]);
        ch=getchar();
    }while(ch!='\n');
     

    if(c=='A')
    {
        qsort(number,count,sizeof(number[0]),cmpA);
    }
    else{
        qsort(number,count,sizeof(number[0]),cmpD);
    }
    result[index++]=number[0];
    for(int i=1;i<count;i++)
    {
        if(number[i-1]!=number[i])
        {
            result[index++]=number[i];
        }
        else{continue;}

    }
    for(int i=0;i<index-1;i++)
    {
        printf("%d ",result[i]);
    }
    printf("%d\n",result[index-1]);
    return 0;


}
