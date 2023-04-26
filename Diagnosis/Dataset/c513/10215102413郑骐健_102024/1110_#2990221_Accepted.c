#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[200];
    scanf("%s",s);
    int po=0;
    double xl =0;
    double num =0;
    int el = 1;
    char p;
    while(s[po]!=0)
    {
        int sym =1;
        int cnt = 0;
        if(s[po]=='-')
        {
            sym = -1;
            po++;
        }
        else if(s[po]=='+')po++;

        while(isdigit(s[po]))
        {
            cnt=cnt*10+s[po]-'0';
            po++;
        }
        if(s[po]>='a'&&s[po]<='z')
        {
            p = s[po];
            if(cnt ==0)cnt =1;
            xl +=el*sym*cnt;
            po++;
        }
        else
        {
            num -= el*sym*cnt;
        }
        if(s[po]=='=')
        {
            el=-1;
            po++;
        }
    }
    double res = num/xl;
    printf("%c=%.3lf",p,res);
    return 0;
}
