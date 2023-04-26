#include <stdio.h>

main()
{
    char s[100] = {};
    scanf("%s",s);
    if (s[0]=='i'&&s[1]==0) {printf("11");return 0;}
    if (s[0]=='0'&&s[1]==0) {printf("0");return 0;}
    if (s[0]=='-'&&s[1]=='i'&&s[2]==0) {printf("111");return 0;}
    int sign = (s[0]=='-')? -1: 1;
    int index = (sign==-1)? 1 : 0;
    long long r = 0, i = 0, num = 0;
    while (s[index])
    {
        if (s[index]>='0'&&s[index]<='9')
        {
            num = num*10+s[index]-'0'; 
            index++;
            if (!s[index]) r = num*sign;
            continue;
        }
        else if (s[index]=='i')
        {
            i = num*sign;
            num = 0;
            break;
        }
        else
        {
            r = num*sign;
            num = s[index+1]=='i'?1:0;
            sign = (s[index]=='+')?1:-1;
            index++;
            continue;
        }
        r = num*sign;
    }

    int ans[200] = {0}, m = 0;
    long long a=r, b=i, c=-1, d=1;
    int res;
    while (r||i)
    {
        res = (r&1)^(i&1);
        ans[m++] = res;
        a -= res;
        r = (a*c+b*d)/(c*c+d*d);
        i = (b*c-a*d)/(c*c+d*d);
        a = r, b = i;
    }
    while (m>0) printf("%d",ans[--m]);
    printf("\n");
    system("pause");
    return 0;
}