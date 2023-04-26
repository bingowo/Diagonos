#include <stdio.h>
#include <string.h>


void myPrint(char *res)
{
    static int tim=0;
    printf("case #%d:\n", tim);
    printf("0.");
    printf("%s\n",res);
    tim++;
}
int main()
{
    int i,j,b,numbers,len,T,digit,temp,a;
    scanf("%d",&T);

    char str1[55],result[165];
    //int a[165];
    b=8;                                //除数
    for(i=0;i<T;i++)
    {
        scanf("%s",str1);
        len=strlen(str1)-1;
        numbers=0;
        for(;len!=1;len--)
        {
            digit=str1[len]-'0';
            j=0;
            do
            {
                //j=0;
                if(j<numbers)
                {
                    temp=digit*10+result[j]-'0';
                }
                else
                {
                    temp=digit*10;
                }
                result[j++]=temp/b+'0';
                digit=temp%b;
            }while(digit!=0||j<numbers);
            numbers=j;
        }
        result[numbers]='0';
        myPrint(result);
    }
    return 0;
}
