#include <string.h>
int change(int m,int n)
{
    if(m%n==0){return n;}
    else return change(n,m%n);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char s[130];
    for(int i=0;i<n;i++){
        gets(s);
        int max=0;
        char *p=s;
        int m=strlen(s)*8;
        do{
            char n=*p;
            for(int j=0;j<8;j++){
                if((n&((char)1<<j))==((char)1<<j))max++;
            }

        }while(*p++);
        int min=change(m,max);
        max/=min;
        m/=min;
        printf("%d/%d\n",max,m);
    }
    return 0;
}
