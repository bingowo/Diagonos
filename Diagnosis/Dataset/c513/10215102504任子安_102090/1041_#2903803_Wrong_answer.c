#include <stdio.h>
#include <string.h>

int main()
{
    char a[51];
    int i=1, j=0, k=0;
    scanf("%s",a);
    for(;a[j]!='\0';j++)
    {
        if(a[j]==a[j+1]||a[j+1]=='\0')
        {
            if(k<i)
            {
                k=i;
                i=1;
            }
            else
            {
                i++;
            }
            printf("%d\n",k);
        }
    }
    return 0;
}