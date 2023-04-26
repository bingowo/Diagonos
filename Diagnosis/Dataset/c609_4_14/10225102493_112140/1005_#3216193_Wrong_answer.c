#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int k=0;
    scanf("%d",&T);
    char s[100];
    int i;
    for (i=0;i<T;i++){
        scanf("%s",s);
        int j=0;
        while(s[j]!='\0'){
            int d;
            if(s[j]=='-') d=-1;
            else d=s[j]-'0';
            k=k*3+d;
            j++;
        }
        printf("case #%d:\n",i);
        printf("%d\n",k);
    }
    return 0;
}
