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
    if (strchr(s,'.')==1)solved(atof(s));
    else solvei(atoi(s));
}
    return 0;
}
