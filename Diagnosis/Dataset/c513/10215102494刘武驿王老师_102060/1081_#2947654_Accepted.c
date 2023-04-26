#include<stdio.h>
#include<string.h>
void multi(int *a,int b,int* res,int lena,int lenres)
{
    int next=0,tmp,i;
    for(i=0;i<lena;i++)
    {
        tmp=a[lena-i-1]*b;
        tmp+=next;
        res[lenres-i-1]=tmp%10;
        next=tmp/10;
    }
}
int main()
{
    int nums[200],res[200],len=200;
    int pros;
    scanf("%d",&pros);
    for(int x=0;x<pros;x++)
    {
    int a,n;
    scanf("%d %d",&a,&n);
    for(int i=0;i<200;i++)
    {
        nums[i]=0;
        res[i]=0;
    }
    nums[199]=1;
    for(int i=0;i<n;i++)
    {
        multi(nums,a,res,len,len);
        for(int j=0;j<200;j++) nums[j]=res[j];
        for(int j=0;j<200;j++) res[j]=0;
    }
    int test=0;
    printf("case #%d:\n",x);
    for(int j=0;j<200;j++)
    {
        if(nums[j]!=0) test=1;
        if(test==1) printf("%d",nums[j]);
    }
    printf("\n");
    }
}
