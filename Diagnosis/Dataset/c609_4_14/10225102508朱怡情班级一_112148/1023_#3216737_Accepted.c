#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct
{
    int d;
    int m;
    int y;
}maya;

int cmp(const void* a,const void *b)
{
    maya x=*(maya*)a;
    maya y=*(maya*)b;
    if(x.y!=y.y)return x.y-y.y;
    else if(x.m!=y.m)return x.m-y.m;
    else return x.d-y.d;
}

int main()
{
    char key[][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        maya a[10009];
        for(int j=0;j<n;j++){
            char s[100];
            scanf("%d",&a[j].d);
            getchar();
            scanf("%s",s);
            for(int k=0;key[k]!=0;k++){
                if(strcmp(key[k],s)==0){
                    a[j].m=k;
                    break;
                }
            }
            scanf("%d",&a[j].y);
        }
        qsort(a,n,sizeof(maya),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++){
            printf("%d. %s %d\n",a[j].d,key[a[j].m],a[j].y);
        }
    }
    return 0;
}
