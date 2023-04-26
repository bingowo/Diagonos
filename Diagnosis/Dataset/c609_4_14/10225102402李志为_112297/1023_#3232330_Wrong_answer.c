#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char Xu[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
typedef struct
{
    char s[28];
    int k,m,y;//y是年 k是日 m是月

}N;
int cmp(const void*a,const void*b)
{
    if(((N*)a)->y!=((N*)b)->y) return ((N*)a)->y-((N*)b)->y;
    if(((N*)a)->m!=((N*)b)->m) return ((N*)a)->m-((N*)b)->m;
    if(((N*)a)->k!=((N*)b)->k) return ((N*)a)->k-((N*)b)->k;
}
int main()
{
    N p[10001];
    int n=0,t=0,l=0,d=0,h=0;//d是判据
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        for(int j=0;j<t;j++){
            h=0;
            gets(p[j].s);
            l=strlen(p[j].s);
            if(isdigit(p[j].s[1])){
               p[j].s[2]=0;
               p[j].k=atoi(p[j].s);
               for(int a=0;a<19;a++){
                for(int b=0;b<10;b++){
                    if(Xu[a][b]==0){
                        d=1;
                        break;
                    }
                    if(p[j].s[3+b]!=Xu[a][b]) break;
                }
                if(d==1){
                    p[j].m=a;
                    break;
                }
               }
               while(p[j].s[h++]!=' ');
               p[j].y=atoi(p[j].s+h);
            }
            else{
               p[j].s[1]=0;
               p[j].k=atoi(p[j].s);
               for(int a=0;a<19;a++){
                for(int b=0;b<10;b++){
                    if(Xu[a][b]==0){
                        d=1;
                        break;
                    }
                    if(p[j].s[2+b]!=Xu[a][b]) break;
                }
                if(d==1){
                    p[j].m=a;
                    break;
                }
               }
               while(p[j].s[h++]!=' ');
               p[j].y=atoi(p[j].s+h);
            }
        }
        qsort(p,t,sizeof(p[0]),cmp);
        for(int j=0;j<t;j++)
            printf("%s\n",p[j].s);
    }
    return 0;
}