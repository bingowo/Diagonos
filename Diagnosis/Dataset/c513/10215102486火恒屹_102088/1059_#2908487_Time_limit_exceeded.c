#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int main()
{
    int width,ame;
    scanf("%d %d",&width,&ame);
    int height[1001]={0};
    for(int i=0;i<width;i++)
        scanf("%d",&height[i]);
    qsort(height,width,sizeof(int),cmp);
    int numerator=0;
    int denominator=0;
    while(ame)
    {
        int i=0;
        while(height[i]==height[i+1]) i++;
        if(ame>=i+1)
        {
            ame=ame-i-1;
            for(int j=0;j<=i;j++)
                height[j]=height[j]+1;
        }
        else
        {
            numerator=ame;
            denominator=i+1;
        }
    }
    for(int j=1;j<=numerator;j++)
    {
        if((numerator%j==0)&&(denominator%j==0))
            {numerator=numerator/j;
             denominator=denominator/j;}
    }
    if(numerator==0)
        printf("%d",height[0]);
    else
        printf("%d+%d/%d",height[0],numerator,denominator);
    return 0;
}
