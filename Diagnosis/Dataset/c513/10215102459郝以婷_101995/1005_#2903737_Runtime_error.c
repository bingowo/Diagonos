#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,j,len,result,left,k;
    char eight[51],ten[150]={0};
    scanf("%d ",T);
    ten[0]='0';
    ten[1]='.';
    for(i=2;i<150;i++)
        ten[i]='0';
    for(i=0;i<T;i++)
    {
        scanf("%s",eight);
        len=strlen(eight);
        left=0;
        for(j=len-1;j>=2;j--)
        {
            k=2;
            if(left==0)
            {
                left=((eight[j]-48)*10+ten[k]-48)%8;
                result=((eight[j]-48)*10+ten[k]-48)/8;
                ten[k]=result+48;
                k++;
            }
            while(left!=0)
            {
                result=(left*10+ten[k]-48)/8;
                left=(left*10+ten[k]-48)%8;
                ten[k]=result+48;
                k++;
            }
            if(k>(len-2)*3+2)
                break;
        }
        printf("case #%d\n",i);
        for(j=0;j<k;j++)
            printf("%c",ten[j]);
        printf("\n");
    }
    return 0;
}
