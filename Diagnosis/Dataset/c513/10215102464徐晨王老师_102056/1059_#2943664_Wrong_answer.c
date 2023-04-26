#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simplify(int x,int y){
    if(x%y==0)return y;
   else return simplify(y,x%y);
}

int cmp(const void* a,const void* b){
    return *(int*)a>*(int*)b;
}
void highlocation(int* p,int rent,int lens){
    qsort(p,lens,sizeof(p[0]),cmp);
    int i;
    for(i=1;i<lens;i++){
        if(p[i]==p[0]){p[i]=p[0]+1;
        }
        else break;
    }
    p[0]=p[0]+1;
    if(rent==i){printf("%d\n",p[0]);return;}
    if(rent<i){
        printf("%d+",p[0]-1);
        printf("%d/%d",rent/simplify(i,rent),i/simplify(i,rent));
        return;
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
