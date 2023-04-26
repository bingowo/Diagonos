#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int a;
    int b;
}vec;
int cmp(const void *p1,const void *p2){
    vec * a= (vec *)p1;
    vec * b= (vec *)p2;
    if(a->a>b->a){
        return 1;
    }
    else{
        return -1;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        vec m[100]={0};
        int t[101]={0};
        for(int i=0;i<n;i++){
            scanf("%d%d",&m[i].a,&m[i].b);
        }
        qsort(m,n,sizeof(vec),cmp);
        int sign=0;

        for(int p=1;p<n;p++){
            if(m[p].a==m[p-1].a&&m[p].b!=m[p-1].b){
                sign=1;
                break;
            }else if(m[p].a==m[p-1].a){
                continue;
            }
            else{
                if(t[m[p].a]==0){
                    t[m[p].a]++;
                }else{
                    sign=1;
                    break;
                }
            }
        }
        if(sign){
            printf("Poor dxw!\n");
            continue;
        }
        for(int q=0;q<n;q++){
            if(t[m[q].b]!=0){
                sign=1;
                break;
            }
        }
        if(sign){
            printf("Poor dxw!\n");
        }else{
            printf("Lucky dxw!\n");
        }
    }
    return 0;
}
