#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct 
{
    int ci;;
    int xi;
}node;
int get(node a[],char *p){
    int sign=1;int ai=0;
    while(*p){
        if(*p=='-'){
            sign=-1;a[ai].xi=0;a[ai].ci=0;
            p++;
            if(*p=='x'){
                a[ai].xi=sign*1;
                a[ai].ci=1;p++;
                if(*p=='^'){
                    int num=0;p++;
                    while(*p>='0'&&*p<='9'){
                        num=num*10+*p-'0';p++;
                    }
                    a[ai].ci=num;
                }
            }
            else {
                int num=0;
                while(*p>='0'&&*p<='9'){
                    num=num*10+*p-'0';
                    p++;}
                num=num*sign;
                a[ai].xi=num;
                if(*p=='x'){
                    a[ai].ci=1;p++;
                }
                if(*p=='^'){
                    p++;int num=0;
                    while(*p>='0'&&*p<='9'){
                        num=num*10+*p-'0';
                        p++;
                    }
                    a[ai].ci=num;
                }
            }
            ai++;
        }
        else if(*p=='x'){
            a[ai].xi=1;a[ai].ci=1;
            p++;
            if(*p=='^'){
                int num=0;p++;
                while(*p>='0'&&*p<='9'){
                    num=num*10+*p-'0';
                    p++;
                }
                a[ai].ci=num;
            }
            ai++;
        }
        else if(*p>='0'&&*p<='9'){
            a[ai].xi=0;a[ai].ci=0;
            int num=0;
            while(*p>='0'&&*p<='9'){
                num=num*10+*p-'0';p++;
            }
            a[ai].xi=num;
            if(*p=='x'){
                a[ai].ci=1;
                p++;}
            if(*p=='^'){
                int num=0;
                p++;
                while(*p>='0'&&*p<='9'){
                    num=num*10+*p-'0';p++;
                }
                a[ai].ci=num;
            }
            ai++;
        }
        else if(*p=='+'){
            a[ai].ci=0;a[ai].xi=0;
            int num=0;p++;
            while(*p>='0'&&*p<='9'){
                num=num*10+*p-'0';p++;
            }
            a[ai].xi=num;
            if(*p=='x'){
                a[ai].ci=1;
                p++;}
            if(*p=='^'){
                p++;int num=0;
                while(*p>='0'&&*p<='9'){
                    num=num*10+*p-'0';p++;
                }
                a[ai].ci=num;
                }
            ai++;
        }
    }
    return ai;
}
int cmp(const void *a ,const void *b){
    node x=*(node*)a,y=*(node*)b;
    return x.ci<y.ci?1:-1;
}
int main(){
    node a[100];int ai=0;
    node b[100];int bi=0;
    char s[101];
    while(scanf("%s",s)!=EOF){
        char *p=s;
        ai=get(a,p);
        p=s;
        scanf("%s",s);
        bi=get(b,p);
        node ret[500];int ri=0;
        for(int i=0;i<ai;i++){
            for(int j=0;j<bi;j++){
                ret[ri].xi=a[i].xi*b[j].xi;
                ret[ri].ci=a[i].ci+b[j].ci;
                ri++;
            }
        }
        qsort(ret,ri,sizeof(ret[0]),cmp);
        for(int i=1;i<ri;i++){
            if(ret[i].ci==ret[i-1].ci){
                ret[i].xi+=ret[i-1].xi;
                ret[i-1].xi=0;
            }
        }
        for(int i=0;i<ri;i++){
            if(ret[i].xi!=0){
                printf("%d ",ret[i].xi);
            }
        }
        printf("\n");
    }
}