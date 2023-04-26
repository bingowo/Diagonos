#include<string.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        char a[55],b[155];
        scanf("%s",a);
        int len,number=0,j;
        int  digit,temp;
        len=strlen(a)-1;

        for(;len!=1;len--)
        {
           digit=a[len]-'0';
           j=0;
           do
           {
                if(j<number)temp=digit*10+b[j]-'0';
           else temp=digit*10;
           b[j++]=temp/8+'0';
           digit=temp%8;

           }while(digit!=0||j<number);
           number=j;
        }
        b[number]='\0';
        printf("case #%d:\n",i);
        printf("0.%s\n",b);
    }
    return 0;
}
