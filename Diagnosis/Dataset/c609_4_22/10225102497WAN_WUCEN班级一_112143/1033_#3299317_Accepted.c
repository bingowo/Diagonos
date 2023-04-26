#include <stdio.h>
#include <string.h>

short pickb(char c,short i)
{
    short b=0;
    b=c&(char)(1<<i);
    if(b)
        b=1;
    return b;
}

int main()
{
    short T=0;
    char base64table[64];
    scanf("%hd",&T);
    getchar();
    for(char i=0;i<26;i++)
        base64table[i]=i+65;
    for(char i=26;i<52;i++)
        base64table[i]=i+71;
    for(char i=52;i<62;i++)
        base64table[i]=i-4;
    base64table[62]=43;
    base64table[63]=47;
    for(int i=0;i<T;i++)
    {
        char in[102]={0};
        short bcode[850]={0},len=0,b64len=0;
        char out[136]={0};
        fgets(in,102,stdin);
        len=strlen(in)-1;
        b64len=(8*len%6)?(8*len+(6-8*len%6))/6:8*len/6;
        for(int j=0;j<len;j++)
            for(int k=0;k<8;k++)
                bcode[8*j+k]=pickb(in[j],7-k);
        for(int j=0;j<b64len;j++)
        {
            short base=1,sum=0,test=0;
            for(int k=5;k>-1;k--)
            {
                sum+=base*bcode[6*j+k];
                base*=2;
            }
            out[j]=base64table[sum];
        }
        short add=b64len;
        while(b64len%4)
        {
            out[add++]='=';
            b64len++;
        }
        printf("case #%hd:\n",i);
        printf("%s\n",out);
    }
    return 0;
}
