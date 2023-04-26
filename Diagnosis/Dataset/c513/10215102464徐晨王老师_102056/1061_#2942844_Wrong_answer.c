#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
char s[16];
long long int sum;
};
int cmp(const void* a,const void* b){
struct data x=*(struct data*)a;
struct data y=*(struct data*)b;
if(x.sum==y.sum)return x.sum>y.sum;
else return strcmp(x.s,y.s);

}

int main(){
    int N;
    scanf("%d",&N);
    struct data p[N];
    for(int n=0;n<N;n++){
        char* ss;
        scanf("%s",p[n].s);
        int lens=strlen(p[n].s);
        int s1[128];
        for(int i=0;i<128;i++){
            s1[i]=-1;
        }
        ss=p[n].s;
        s1[*ss]=1;
        int ant=0;
        while(*++ss){
            if(s1[*ss]==-1){
                s1[*ss]=ant;
                if(ant==0)ant=ant+2;
                else ant=ant+1;

            }
        }
        if(ant<2)ant=2;
        p[n].sum=0;
        char* sss=p[n].s;
        while(*sss){
            p[n].sum=p[n].sum*ant+s1[*sss++];
        }
    }
    qsort(p,N,sizeof(p[0]),cmp);
    for(int n=0;n<N;n++){
    printf("%s\n",p[n].s);
    }

    return 0;
}
