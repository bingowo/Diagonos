#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct NNode* Number;
struct NNode{
    double n;
    int offset;
};

Number solve(char s[])
{
    Number ret = (Number)malloc(sizeof(struct NNode));
    Number v1,v2;
    ret->n = 0,ret->offset = 0;
    
    if(*s==0){
        ;
    }
    else if(isdigit(s[0])){
        char *p1 = s,*p2 = s;
        char temp[15];
        while (*p2&&isdigit(*p2)) {
            p2++;
        }
        if(*p2=='.'){p2++;}
        while (*p2&&isdigit(*p2)) {
            p2++;
        }
        memmove(temp, p1, p2-p1);
        temp[p2-p1] = '\0';
        ret->n = atof(temp);
        ret->offset= strlen(temp)+1;
    }
    else{
        v1 = solve(s+2);
        v2 = solve(s+v1->offset+2);
        
        if(s[0]=='+') ret->n=v1->n+v2->n;
        if(s[0]=='-') ret->n=v1->n-v2->n;
        if(s[0]=='*') ret->n=v1->n*v2->n;
        if(s[0]=='/') ret->n=v1->n/v2->n;
        
    }
    return ret;
}

int main(void) {
    int t;
    scanf("%d",&t);
    char c=getchar();
    for (int i=0; i<t; i++) {
        char s[110];
        gets(s);
        
        Number x = solve(s);
        printf("case #%d:\n",i);
        printf("%.6lf\n",x->n);
    }
    return 0;
}
