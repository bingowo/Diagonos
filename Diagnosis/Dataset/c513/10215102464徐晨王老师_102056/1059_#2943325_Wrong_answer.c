#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b){
    return *(int*)a>*(int*)b;
}
void highlocation(char* p,int rent,int lens){
    qsort(p,lens,sizeof(p[0]),cmp);
    int i;
    for(i=0;i<lens;i++){
        if(p[i]==p[0]){p[i]=p[i]+1;}
        else break;
    }
    p[0]=p[0]+1;
    if(rent==i)printf("%d\n",p[i]);
    if(rent<i){
        printf("%d+",p[0]);
        if((i-rent)%2==0)printf("%d/5",5-(i-rent)/2);
        else printf("%d/10",10-i+rent);
    }
    else return highlocation(p,rent-i,lens);
}
int main(){
int n,s;
scanf("%d%d",&n,&s);
int list[n];
for(int i=0;i<n;i++){
    scanf("%d",&list[i]);
}
highlocation(list,s,n);
return 0;
}
