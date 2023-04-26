#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a = 0;
    scanf("%c", &a);
    int arr[1001] = {0};
    int num = 0;
    char ch = 0;
    do
    {
        scanf("%d",&num);
        arr[num]++;
    }
    while((ch = getchar())!='\n');
    if(a == 'A')
    {
        int i = 0;
        for(i = 1; i<1001; i++)
        {
            if(arr[i] != 0) printf("%d ", i);
        }
    }
    else
    {
        int i = 0;
        for(i = 1000; i>0; i--)
        {
            if(arr[i] != 0) printf("%d ", i);
        }
    }
    return 0;
}
