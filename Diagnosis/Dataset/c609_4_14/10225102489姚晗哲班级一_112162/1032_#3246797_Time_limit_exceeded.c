#include <stdio.h>
#include <stdlib.h>
/*字符数组char
用max和n来判断
*/
int main()
{
    int max=1,n;
    char arr[50];
    int i=0;
    do
    {
        scanf("%c",&arr[i]);
        i++;
    }while(getchar()!='\n');//输入数组
    for(int go=1;go<i;go++)
    {
        n=0;
        while(arr[go]!=arr[go-1])
        {
            n++;
            go++;
        }
        n++;//首次数据可以
        if(n>max)
            max=n;
    }
    printf("%d",max);
    return 0;
}