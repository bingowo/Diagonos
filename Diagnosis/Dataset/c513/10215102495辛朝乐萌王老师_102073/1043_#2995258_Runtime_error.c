#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

void insert(char *s,char c,int index)
{
    int len = strlen(s);
    memmove(s+index+1, s+index, len-index+1);
    *(s+index)=c;
}

int del(char *s)
{
    int ret = 0;
    int issame=0,iscomplete=1,lens;
    char *pa=s;
    char *pb=pa+1;
    char *pend=NULL,*pstart=NULL;
    while (1) {
        lens=strlen(s);
        pend=s+lens;
        pstart=s;
        if (*pb==*pa) {
            issame=1;
        }
        else{
            issame=0;
        }
        if (issame) {
            pb++;
        }
        else{
            if (pb-pa>1) {
                ret+=(pb-pa);
                memmove(pa, pb, pend-pb+1);
                iscomplete=0;
                if(*pstart=='\0'){
                    break;
                }
                else if(*pa=='\0'){
                    pa-=-1;
                    pb=pa+1;
                    continue;
                }
                else{
                    pb=pa+1;
                    continue;
                }
            }
            if (*pb=='\0') {
                if (!iscomplete) {
                    pa=s;
                    pb=pa+1;
                    iscomplete=1;
                }
                else{
                    break;
                }
            }
            else{
                pb+=1;
                pa+=1;
            }
        }
    }
    return ret;
}


int main(void){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        char s[102],temp[102];
        scanf("%s",s);
        strcpy(temp, s);
        int max=0,len=strlen(s),num;
        for (int j=0; j<=len; j++) {
            for (int k=0; k<3; k++) {
                strcpy(temp, s);
                insert(temp, 'A'+k, j);
                num=del(temp);
                if (num>max) {
                    max=num;
                }
            }
        }
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}
