#include <stdio.h>

int method(int,int);int max,sta,cnt,tar;
int main(){
    scanf("%d %d %d %d",&max,&sta,&cnt,&tar);
    printf("%d",method(0,sta));
}

int method(int i,int position){
    if(i == cnt) return position == tar;
    if(position == 0) return method(i+1,1);
    else if(position == max) return method(i+1,max-1);
    else return method(i+1,position+1) + method(i+1,position-1);
}