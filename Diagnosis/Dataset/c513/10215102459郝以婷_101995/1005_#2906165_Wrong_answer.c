#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,j,len,result,left,k,max,numbers;
    char eight[51],ten[150];
    scanf("%d ",&T);
    ten[0]='0';
    ten[1]='.';
    for(i=0;i<T;i++)
    {
        for(j=2;j<150;j++)
            ten[j]='0';
        scanf("%s",eight);
        max=0;
        numbers=0;
        len=strlen(eight);
        left=0;
        for(j=len-1;j>=2;j--)
        {
            k=2;
            //printf("%c 66\n",eight[j]);
            if(left==0)
            {
                left=((eight[j]-48)*10+ten[k]-48)%8;
                result=((eight[j]-48)*10+ten[k]-48)/8;
                ten[k]=result+48;
                //printf("%c %d\n",ten[k],left);
                k++;
            }
            do
            {
                result=(left*10+ten[k]-48)/8;
                left=(left*10+ten[k]-48)%8;
                ten[k]=result+48;
                //printf("%c %d\n",ten[k],left);
                k++;
            }while(left!=0||k-2<numbers);
            numbers=k-2;
            //if(k>max)
                //max=k;
            //if(max>(len-2)*3+2)
                //break;
        }
        printf("case #%d:\n",i);
        for(j=0;j<max;j++)
            printf("%c",ten[j]);
        printf("\n");
    }
    return 0;
}
