#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int I=0;I<T;I++) {
        char a[30];
        scanf("%s",a);
        int len=strlen(a);
        int plus=0;
        for(int i=0;i<len;i++) {
            if(a[i]=='1')
                plus=plus*3+1;
            else if(a[i]=='-')
                plus=plus*3-1;
            else
                plus=plus*3;
        }
        printf("case #%d:\n",I);
        printf("%d\n",plus);
    }
    return 0;
}
