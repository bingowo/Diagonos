#include<stdio.h>
#include<string.h>
int x;
void f(int n,int r,char s[])
{
    while(n/r!=0){
        
        if(n%r>9){
            s[x++]=n%r-10+'A';
        }
        else{
            s[x++]=n%r+'0';
        }n/=r;
    }
    if(n%r>9){
            s[x]=n%r-10+'A';
            s[++x]='\0';
        }
        else{
            s[x]=n%r+'0';
            s[++x]='\0';
        }

}
int main()
{
    int t,n,r,i;
    char s[32];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        if (n<0){
            printf("-");
            n=-n;
        }else if(n==0)printf("0");

        x=0;
        f(n,r,s);
        for(i=strlen(s)-1;i>=0;i--){
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}