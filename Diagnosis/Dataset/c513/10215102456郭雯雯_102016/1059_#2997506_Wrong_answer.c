#include<stdlib.h>
#include<stdio.h>

struct high{
    int it,zi,mu;
};

int cmp(const void* a,const void* b){
    int c=*(int *)a,d=*(int *)b,t=c-d;
    return t;
}

int main(){
    int n,s;
    scanf("%d %d",&n,&s);
    int h[n];
    for(int i=0;i<n;i++)scanf("%d",&h[i]);
    qsort(h,n,sizeof(int),cmp);
    struct high hi;
    hi.it=h[0];hi.zi=0;hi.mu=1;
    int w=0,i=0,v;
    while(s>0){
        if(h[i]<h[i+1]){
            w=i+1;
            v=w*(h[i+1]-h[i]);
            if(s>=v){s-=v;hi.it=h[i+1];}
            else{
                hi.zi=s;
                s=0;
                hi.it=h[i+1];
                hi.mu=w;
                
            }
            i++;
        }
        if(h[i]==h[i+1]){
            while(h[i]==h[i+1])i++;
            w=i+1;
            v=w*(h[i+1]-h[i]);
            if(s>=v){s-=v;hi.it=h[i+1];}
            else{
                hi.zi=s;
                s=0;
                hi.it=h[i+1];
                hi.mu=w;
                
            }
            i++;
        }
        
    }
    if(hi.zi!=0)printf("%d+%d/%d",hi.it,hi.zi,hi.mu);
    else printf("%d",hi.it);
}