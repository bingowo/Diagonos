#include <stdio.h>
#include <string.h>
/*字符数组char
用max和n来判断
*/
int main()
{
    int max=1,n=1;
    char arr[50];
    int i=0;
    scanf("%s",arr);//输入数组
    i=strlen(arr);
    for(int go=1;go<i;go++)
    {
        if(arr[go]!=arr[go-1])
            n++;
        else
        {
            n=1;

        }
        if(n>max)
            max=n;
    }
    printf("%d",max);
    return 0;
}
