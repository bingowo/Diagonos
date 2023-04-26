#include<stdio.h>
#include<malloc.h>
//将圆柱的高乘以半径降序排序，取前m个
struct cylinder{
    int r;
    int h;
}*cy;

int cmp(const void *a,const void *b){
    struct cylinder *cy1=(struct cylinder *)a;
    struct cylinder *cy2=(struct cylinder *)b;
    if(((cy1->r)*(cy1->h))!=((cy2->r)*(cy2->h)))
        return (((cy2->r)*(cy2->h))-((cy1->r)*(cy1->h)));
    else return ((cy2->r)-(cy1->r));
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    cy=(struct cylinder *)malloc(sizeof(struct cylinder)*n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&cy[i].r,&cy[i].h);
    }
    int S=cy[0].r*cy[0].r+2*cy[0].h*cy[0].r;
    int k=0;
    for(int i=1;i<n;i++){
        int temp=cy[i].r*cy[i].r+2*cy[i].h*cy[i].r;
        if(temp>S){
            S=temp;
            k=i;
        }
    }
    if(m==1){
        S=S;
    }
    for(int i=0;i<m;i++){
        if(k==i||cy[i].r>=cy[k].r){
            continue;
            m++;
        }
        S+=2*cy[i].h*cy[i].r;
    }
    printf("%d",S);
    return 0;
}
