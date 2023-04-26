#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void* q1,const void* q2)
{
    int* p1=(int *)q1;
    int* p2=(int *)q2;
    return (*p1-*p2);
}
int cmp2(const void* q1,const void* q2)
{
    int* p1=(int *)q1;
    int* p2=(int *)q2;
    return (*p2-*p1);
}
int main()
{
    char c;
    scanf("%c",&c);
    int s[101]={0};
    int m;
    
    int i=0;
    do
    {
        scanf("%d", &s[i]);
        i++;
    } while (getchar() != '\n');
    if(c=='A')
        qsort(s,i,sizeof(int),cmp1);
    else 
        qsort(s,i,sizeof(int),cmp2);
    for(int j=0;j<i;j++)
    {
        while(s[j]==s[j+1]) 
        {
            for(int k=j;k<i;k++)
                s[k]=s[k+1];
            i--;
        }
    }
    for(int m=0;m<i;m++)
    {
        printf("%d ",s[m]);
    }
    printf("\n");
    return 0;
}