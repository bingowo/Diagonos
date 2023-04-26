#include <stdio.h>
#include <stdlib.h>
void solvei(int n){
    unsigned char*p=(unsigned char*)&n;
    int c=sizeof(int);
    while(c--)printf("%02x ",*p++);
    printf("\n");

}
void solved(double n){
    unsigned char*p=(unsigned char*)&n;
    int c=sizeof(double);
    while(c--)printf("%02x ",*p++);
printf("\n");
}
int main()
{
char s[100];
while(scanf("%s",s)!=EOF)
{
    int i=0;
    int flag=0;
    while(s[i]!='\0')
    {
        if(s[i]=='.'){flag=1;break;}
        i++;
    }
    if(flag==1)solved(atof(s));
    else solvei(atoi(s));
}
    return 0;
}
