#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    char s[200];
    for(int i =0 ;i<T;i++)
    {
        scanf("%s",&s);
        int point = 0;
        long long int anw = 0;
        while(s[point])
        {
         anw*=3;
        switch(s[point])
        {
        case '1':
            anw+=1;
            break;
        case '-':
            anw -= 1;
            break;
        case '0':
            break;
        }
        point ++;
        }
        printf("case #%d:\n%lld\n",i,anw);

    }
    return 0;

}
