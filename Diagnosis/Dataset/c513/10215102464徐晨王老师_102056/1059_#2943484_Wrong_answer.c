#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b){
    return *(int*)a>*(int*)b;
}
void highlocation(char* p,int rent,int lens){
    qsort(p,lens,sizeof(p[0]),cmp);
    int i;
    for(i=1;i<lens;i++){
        if(p[i]==p[0]){p[i]=p[0]+1;
        //printf("%d",p[i]);
        }
        else break;
    }
    p[0]=p[0]+1;
    i=i+1;
    //printf("%d",p[0]);
    //printf("%d%d",rent,i);
    //if(rent==0){printf("%d\n",p[0]-1);return;}
    if(rent==i){printf("%d\n",p[0]);return;}
    if(rent<i){
        printf("%d+",p[0]);
        if((i-rent)%2==0){printf("%d/5",5-(i-rent)/2);return;}
        else {printf("%d/10",10-i+rent);return;}
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