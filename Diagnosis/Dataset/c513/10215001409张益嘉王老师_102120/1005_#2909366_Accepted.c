#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[55];
        int a[55],len,j,k,n,digit,temp,numbers;
        char str[1000];
        memset(str,0,sizeof(char)*1000);
        double re=0.0;
        scanf("%s",s);
        len=strlen(s);
        for(j=2,k=0;j<len;j++,k++)
        {
            a[k]=s[j]-'0';
        }
        numbers = 0;
        for(k=(len-3);k>=0;k--)
        {
            digit = a[k];
            j = 0;
            do
            {
                if (j < numbers) temp = digit*10 + str[j]-'0';
                else temp = digit*10;
                str[j++] = temp/8 + '0';
                digit = temp%8;
            } while (digit!=0 || (j < numbers));
             numbers = j;

        }
        str[numbers] = '\n';
        //printf("[%d]n=%d\n",i,n);


        /*for(j=strlen(str)-1;j>=0;j--)
        {
            if(str[j]=='0') str[j]=0;
            else break;
        }*/
        printf("case #%d:\n0.%s",i,str);

    }
    return 0;
}
