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
    }while(getchar()!='\n');
    for(int go=1;go<i;)
    {
        n=1;
        while(arr[go]!=arr[go-1])
        {
            n++;
            go++;
        }
        if(n>max)
            max=n;
            go++;
    }
    printf("%d",n);
    return 0;
}