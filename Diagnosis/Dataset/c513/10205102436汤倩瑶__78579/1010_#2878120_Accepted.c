#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{

    char s[510];
    scanf("%s",s);
    printf("0001");
    int l=strlen(s);
    char a[]="0000000000";
    int i=0;
    while(l!=0)
    {
        a[9-i]=l%2+'0';
        l=l/2;
        i++;
    }
    l=strlen(s);
    printf("%s",a);
    int t1=l/3;
    int t2=l%3;
    for(int j=0;j<t1;j++)
    {
char b[]="0000000000";
        int p=100*(s[j*3]-'0')+10*(s[j*3+1]-'0')+s[j*3+2]-'0';
    i=0;
    while(p!=0)
    {
        b[9-i]=p%2+'0';
        p=p/2;
        i++;
    }

printf("%s",b);
    }
if(t2==2){
    char c[]="0000000";
    int p=10*(s[l-2]-'0')+s[l-1]-'0';
    i=0;
    while(p!=0)
    {
        c[6-i]=p%2+'0';
        p=p/2;
        i++;
    }
    printf("%s",c);
}
else if(t2==1){
     char c[]="0000";
    int p=s[l-1]-'0';
    i=0;
    while(p!=0)
    {
        c[3-i]=p%2+'0';
        p=p/2;
        i++;
    }
    printf("%s",c);
}

}
