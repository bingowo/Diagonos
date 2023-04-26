#include <stdio.h>
#include <stdlib.h>

int n;

int findH(int* h,int l){
    for(int i=l;i<n;i++){
        if(h[i]>h[l]){
            return i;
        }
    }
    return n;
}

int cmp(const void *a,const void *b){
    int pa=*(int*)a,pb=*(int*)b;
    return pa>pb?1:-1;
}


int GCD(int a,int b){
    if(a==0) return b;
    else return GCD(b%a,a);
}

int main()
{
    int s;scanf("%d%d",&n,&s);
    int hight[n];
    for(int i=0;i<n;i++){
        scanf("%d",&hight[i]);
    }
    qsort(hight,n,sizeof(int),cmp);

    double H=0;
    int rest=s,fenzi=0,fenmu=0;
    int tmp=0,wid;
    while(rest){
        tmp=wid=findH(hight,tmp);
        if(wid<=rest){
            rest-=wid;
            H++;
        }
        else if(wid>rest){
            fenzi=rest;
            fenmu=wid;
            rest=0;
        }
    }
    int gcd;
    if(fenzi*fenmu){
        gcd=GCD(fenzi,fenmu);
        fenzi/=gcd;
        fenmu/=gcd;
    }

    if(H==0){
        printf("%d/%d",fenzi,fenmu);
    }
    else{
        printf("%d",(int)H+hight[0]);
        if(fenzi*fenmu){
            printf("+%d/%d",fenzi,fenmu);
        }
    }

}
