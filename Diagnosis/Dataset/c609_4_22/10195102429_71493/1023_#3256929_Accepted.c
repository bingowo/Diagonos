#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data{
    int d;
    char m[10];
    int y;
    int nm;

};
char* month[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax", "zac", "ceh", "mac", "kankin","muan", "pax","koyab","cumhu","uayet"};


int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.y!=d1.y){
        return d1.y-d2.y;
    }
    else{
        if(d2.nm!=d1.nm){
            return d1.nm-d2.nm;
        }
        else{
            return d1.d-d2.d;
        }
    }

}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++){
        struct data p[10000];
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            p[i].nm=0;
            scanf("%d",&p[i].d);
            getchar();
            scanf("%s",p[i].m);
            scanf("%d",&p[i].y);
            for(int j=0;j<19;j++){
                    if(strcmp(p[i].m,month[j])==0){
                        p[i].nm=j;
                    }

            }

        }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("case #%d:\n",cas);
    for(int k=0;k<n;k++){
        printf("%d",p[k].d);
        printf(".");
        printf(" %s",p[k].m);
        printf(" %d\n",p[k].y);
    }
    }

    return 0;
}
