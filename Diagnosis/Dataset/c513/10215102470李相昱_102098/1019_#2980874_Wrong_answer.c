
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1,const void*p2){
    int*a =(int*)p1;
    int*b =(int*)p2;
    if(*(a++)<*(b++)){
        return 1;
    }else if(*(a++)>*(b++)){
        return -1;
    }else{

    }

}
int main() {
    struct{
        int team;
        int score;
    }s[10]={{1,0},{2,0},
            {3,0},{4,0},
            {5,0},{6,0},
            {7,0},{8,0},
            {9,0},{10,0}};
    int n,m;
    while(scanf("%d%d",&n,&m)&& ((m||n)!=0)){
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c ==1){
                s[a-1].score += 3;
                s[b-1].score-- ;
            }
            else if(c==-1) {
                s[b-1].score +=3;
                s[a-1].score--;
            }
            else{
                s[a-1].score++;
                s[b-1].score++;
            }
        }
    }
    qsort(s,n,sizeof(s[0]),cmp);
    return 0;
}
