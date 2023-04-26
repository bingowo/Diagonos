#include<stdio.h>
#include<string.h>
int main()
{
    char s[51];
    int i ,a[50],m = 0,j,flag = 1;
    scanf("%s",s);
    for(i = 0;i<strlen(s);i++)
    {
        switch(s[i])
        {
            case')':flag = flag*1000;break;
            case'(':flag = flag/1000;break;
            case'I':a[m] = flag*1;m++;break;
            case'V':a[m] = flag*5;m++;break;
            case'X':a[m] = flag*10;m++;break;
            case'L':a[m] = flag*50;m++;break;
            case'C':a[m] = flag*100;m++;break;
            case'D':a[m] = flag*500;m++;break;
            case'M':a[m] = flag*1000;m++;break;

        }
    }
    long long int res = 0;
    for(j = 0;j<m-1;j++)
    {
        if(a[j]<a[j+1]) res = res - a[j];
        else res = res + a[j];
    }
    printf("%lld",res+a[m-1]);
    return 0;
}
