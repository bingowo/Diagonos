#include <stdio.h>
#include <string.h>
void itob(int n,char s[100],int b)
{
    int sign=1;
    if (n<0){
        n=-n;
        sign=-1;
    }
    int i=0,j=0;
    char a[100];
    for (i=0;n>0;n=n/b){
        if (n%b<10){
            a[i++]=n%b+'0';
        }else{
            a[i++]=n%b+'A'-10;
        }
    }
    if (sign==-1){
        a[i]='-';
    }else{
        i--;
    }
    for (i;i>=0;i--,j++){
        s[j]=a[i];
    }
    s[j++]='\0';
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,b;
        char s[100] = {0};
        scanf("%d%d",&n,&b);
        itob(n,s,b);
        printf("%s\n",s);
    }
    return 0;
}