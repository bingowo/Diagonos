#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *a,const void *b)
{
    int a1=*(int *)a;
    int b1=*(int *)b;
    return (a1>b1)?1:-1;
}
int cmp2(const void *a,const void *b)
{
    int a1=*(int *)a;
    int b1=*(int *)b;
    return (a1<b1)?1:-1;
}
int main()
{
    char a,c;
    scanf("%c",&a);
    getchar();
    int nums[101];
    int i=0,j=0;
    char num[1001];
    do
    {
        int j;
        nums[i]=0;
        scanf("%s",num);
        for(j=0;j<strlen(num);j++)
        {
            nums[i]=nums[i]*10+num[j]-'0';
        }
       //printf("(%d )",nums[i]);
        i++;
    }while(c=getchar()==' ');
    if(a=='A')qsort(nums,i,sizeof(nums[0]),cmp1);
    else if(a=='D')qsort(nums,i,sizeof(nums[0]),cmp2);
    printf("%d",nums[j]);
    j++;
    for(;j<i-1;j++)
    {
        if(nums[j]!=nums[j-1])printf(" %d",nums[j]);
    }
    if(nums[i-1]!=nums[j-1])printf(" %d",nums[i-1]);

    return 0;

}