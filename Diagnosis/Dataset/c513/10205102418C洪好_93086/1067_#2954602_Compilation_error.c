#include<stdio.h>
long long IT(int num)
{
    long long *arr = new long long[num + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i <= num; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[num];
}

int main()
{
    int t;
    //cin >> t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int num;
        //cin >> num;
        scanf("%d",&num);
        //cout << "case #" << i << ":"<<endl;
        printf("case #%d:\n",i);
        //cout <<IT(num) <<endl;
        printf("%d\n",IT(num));
    }

    return 0;
}