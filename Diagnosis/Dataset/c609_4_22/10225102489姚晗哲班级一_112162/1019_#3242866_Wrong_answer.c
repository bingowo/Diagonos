#include <stdio.h>
#include <stdlib.h>
/*输入所有整数arr1
依次除以10，每次将得到的为零的放到一个数列num1，num2
再讲每个数列进行qsort运算
*/
int compare(const *a,const *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int arr[1000000];
    int end[1000000];
    int i=0;
    do
    {
        scanf("%d",&arr[i++]);
    }while(getchar()!='\n');//共有i个数；
    int en=0;
    for(int m=10;en!=i;)
    {
        for(int n=0;n<i;n++)
        {
            int p=0;
            int arr2[1000000];
            if((arr[n]/m)==0)
            {
                arr2[p]=arr[n];
                p++;//arr2共p个数据；
            }
            m*=10;
            qsort(arr2,p,sizeof(int ),compare);//升序排列
            for(p--;p<=0;p--)
            {
                end[en]=arr2[p];
                en++;
            }
        }

    }
    for(int k=0;k!=i;k++)
        printf("%d ",end[k]);
    return 0;
}
