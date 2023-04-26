#include <stdio.h>
#include <stdlib.h>

int count(int floors, int current, int minute, int end){
    if(minute == 0 && current == end)
        return 1;
    if(minute == 0 && current != end)
        return 0;

    if(current == 1)
        return count(floors,current+1,minute-1,end);
    if(current == floors)
        return count(floors,current-1,minute-1,end);

    return count(floors,current-1,minute-1,end) + count(floors,current+1,minute-1,end);
}


int main(){
    int N;
    scanf("%d",&N);
    for(int R = 0; R < N; R++){

        int n,m,p,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);

        printf("%d\n",count(n,p,m,t));
    }
}