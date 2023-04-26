//digsys\1004.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
int isfloat(char *cp)
{
    while(*cp){
        if(*cp=='.')
            return TRUE;
        ++cp;
    }
    return FALSE;
}
void readANDprint(unsigned char *c,int times)// !unsigned!
{
    int tem;
    while(times--){
        printf("%02x ",*c++);
    }putchar('\n');
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    double f;
    char input[50];
    while(scanf("%s",input)!=EOF){
        if(isfloat(input)){
            f=atof(input);
            readANDprint(&f,sizeof(double));
        }else{
            n=atoi(input);
            readANDprint(&n,sizeof(int));
        }
    }
}
