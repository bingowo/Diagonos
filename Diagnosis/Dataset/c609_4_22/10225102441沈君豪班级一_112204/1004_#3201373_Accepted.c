#include <stdio.h>
#include <string.h>
#include <ctype.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void f(int m,int n)
{
    char z;
    if(m/n>0){
        f(m/n,n);
    }
    z=table[m%n];
    printf("%c",z);
 }

int main()
{
    int a,b,x,y;
    scanf("%d",&a);
    char s[100];
    scanf("%s",s);
    b=strlen(s);
    x=0;
    for(int i=0;i<b;i++){
        if(isdigit(s[i])){
            x = x*a + s[i]-48;
        }else if(s[i]<97){
            x = x*a + s[i]-65+10;}
        else{
            x = x*a + s[i]-97+10;
        }

    }
    scanf("%d",&y);
    f(x,y);
    return 0;

}
