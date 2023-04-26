#include <stdio.h>

int method(int,int);int max,sta,cnt,tar;
int main(){
    int loop;
    scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {
        scanf("%d %d %d %d",&max,&sta,&cnt,&tar);
        printf("%d\n",method(0,sta));
    }
    
}

int method(int i,int position){
    if(i == cnt) return position == tar;
    if(position == 1) return method(i+1,2);
    else if(position == max) return method(i+1,max-1);
    else return method(i+1,position+1) + method(i+1,position-1);
}