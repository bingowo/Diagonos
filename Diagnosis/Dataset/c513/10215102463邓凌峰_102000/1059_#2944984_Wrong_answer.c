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
    int tmp=0,h0=hight[0],ss;
    while(rest){
        tmp=findH(hight,tmp);
        ss=tmp*(hight[tmp]-h0);
        if(ss<=rest){
            rest-=ss;
            H+=hight[tmp]-h0;
        }
        else if(ss>rest){
            fenzi=rest;
            fenmu=ss;
            rest=0;
        }
        h0=hight[tmp];
    }
    int gcd;
    if(fenzi*fenmu){
        gcd=GCD(fenzi,fenmu);
        fenzi/=gcd;
        fenmu/=gcd;
    }

    if(hight[0]==0){
        printf("%d/%d",fenzi,fenmu);
    }
    else{
        printf("%d",(int)H+hight[0]);
        if(fenzi*fenmu){
            printf("+%d/%d",fenzi,fenmu);
        }
    }
}
