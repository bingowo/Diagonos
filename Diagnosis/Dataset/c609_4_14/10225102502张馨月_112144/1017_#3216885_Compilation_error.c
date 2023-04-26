/*
#include<stdio.h>
#include<stdlib.h>
int cmp1 (const void*a,const void*b)
{
    //if(*(int*)a!=*(int*)b)
        return *(int*)a-*(int*)b;
    //else
}

int cmp2 (const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    char seq;
    scanf("%c\n",&seq);
    int line[101];
    int i=0;
    scanf("%d",&line[0]);
    i++;
    while(line[i-1]!=-1)
    {
        scanf("%d",&line[i]);
        i++;
    }

    if (seq=='A')//升序
        qsort(line,i,sizeof(line[0]),cmp1);
    if(seq=='D')//降序
        qsort(line,i,sizeof(line[0]),cmp2);

    int j;
    for(j=0;j<i-1;j++)
        printf("%d ",line[j]);

    printf("%d",line[++j]);

    return 0;
}
*/

#include<stdio.h>
int main()
{
        int i, s[1000], length = 0, data;
    scanf("%d", &data);
    while(data > 0)
    {
        s[length++] = data;
        scanf("%d", &data);
 }
int j;
    for(j=0;j<length-1;j++)
        printf("%d ",s[j]);

    printf("%d",s[++j]);

    return 0;
}