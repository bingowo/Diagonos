#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 12

double pol(){
    char in[LEN];
    scanf("%s",in);
    if(getchar() == '\n') return strtod(in,NULL);
    if(!strcmp(in,"+")) return pol()+pol();
    if(!strcmp(in,"-")) return (pol())-pol();
    if(!strcmp(in,"*")) return pol()*pol();
    if(!strcmp(in,"/")) return (pol())/pol();
    else return strtod(in,NULL);
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        double out;

        out = pol();

        printf("case #%d:\n",i);
        printf("%.6lf\n",out);
    }
    return 0;
}