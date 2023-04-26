#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void arange1(int* arr,int num)
{
    for(int j=0;j<20;j++)
    for (int i=0;i<num;i++)
    {
        if (arr[i] > arr[i+1])
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

void arange2(int* arr,int num)
{
    for(int j=0;j<20;j++)
    for (int i=0;i<num;i++)
    {
        if (arr[i] < arr[i+1])
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main()
{
    char T;
    cin >> T;
    int a[101];
    int i,j;
    cin >> a[0];
    for(i=1;getchar()!='\n';i++)
        cin >> a[i];//存储完成
        
    int x=i-1;
    if(T == 'A')
        arange1(a,x);
    else arange2(a,x);
    
    int b[101];
    int m = 0;
     for(int i=0;i<x+1;++i)
    {
        int j=0;
        for(;j<m;++j)
        {
            if(a[i]==b[j])//拿a[i]与b中的元素比较
                break;//如果找到相同的就跳出循环
        }
        if(j==m)//则没有找到相同的
            b[m++]=a[i];//把a中不同的存到b中
    }

    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
        
    return 0;
}