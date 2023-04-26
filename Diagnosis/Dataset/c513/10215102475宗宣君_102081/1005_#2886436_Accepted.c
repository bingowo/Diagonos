#include <stdio.h>
#include <string.h>
void trans(int q)
{
    char a[50],b[1000];
    scanf("%s",a);
    int len = strlen(a) - 1,num,m = 0,dlen = 0,res;
    for(;len!=1;len--)
    {
        num = a[len] - '0';
        int i = 0;
        do
        {
            if(i<dlen) res = num*10+b[i]-'0';
            else res = num*10;
            m = res%8;
            b[i++] = res/8 +'0';
            num = m;
        }while(m||i<dlen);
        dlen = i;
    }
    b[dlen] = '\0';
    printf("case #%d:\n0.",q);
    int j;
    for(j = 0;j<dlen;j++)
        printf("%c",b[j]);
    printf("\n");
}
int main()
{
    int a;
    scanf("%d",&a);
    int i;
    for(i = 0;i<a;i++)
        trans(i);
    return 0;
}
