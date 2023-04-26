#include <stdio.h>
#include <string.h>


int main()
{
    int T,a;
    scanf("%d",&T);
    char s[100];
    for(int i=0;i<T;i++){
        int b=0;
        scanf("%s",s);
        a=strlen(s);
        for(int i=0;i<a;i++){
            if(s[i]=='-'){
                b=b*3-1;
            }else if(s[i]=='0'){
                b=b*3+0;}
            else{
                b=b*3+1;
            }
        }
        printf("case #%d:\n%d\n",i,b);
    }
    return 0;
}
