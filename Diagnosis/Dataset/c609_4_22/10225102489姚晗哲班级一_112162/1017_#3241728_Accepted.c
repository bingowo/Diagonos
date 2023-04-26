#include <stdio.h>
int main()
{
    char type;
    scanf("%c\n",&type);//输入字母指令
    int arr[1000];
    int i=0;
    do
    {
        scanf("%d",&arr[i]);
        i++;
    }while((getchar())!='\n');//输入数组
        for(int n=1;n<i;n++)
        {
            if(arr[n]<arr[n-1])
            {
                int temp=arr[n];int j=n-1;
                for(;j>=0&&arr[j]>temp;j--)
                    arr[j+1]=arr[j];//把大于那个数的挪到后面
                arr[j+1]=temp;//插入
            }
        }
        int m=0;
        int arr2[1000];
        arr2[m]=arr[0];//新数组，跳过重复项
        m++;
        for(int l=1;l<=(i-1);l++)
        {
            if(arr[l]!=arr[l-1])
            {
                arr2[m]=arr[l];
                m++;
            }

        }//新数组建成
        if(type=='A')
        {
            for(int p=0;p<m;p++)
                printf("%d ",arr2[p]);
        }
        else
        {
            for(int u=0,k=m-1;u<k;u++,k--)
        {
            int ji=arr2[u];
            arr2[u]=arr2[k];
            arr2[k]=ji;
        }
        if(type=='D')
        {
            for(int p=0;p<m;p++)
                printf("%d ",arr2[p]);
        }
        }
    return 0;
}
