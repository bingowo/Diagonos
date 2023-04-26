#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int for_a;
    int for_x;
}NUM;

typedef struct{
    NUM up[1];
    NUM sum[1];
}STA;

int main()
{
    int orisum, stations, finsum, que;
    scanf("%d%d%d%d",&orisum,&stations,&finsum,&que);

    if(que <= 2){
        printf("%d",orisum);
        return 0;
    }

    STA s[21];
    s[1].up->for_a = 1, s[1].up->for_x = 0;   s[1].sum->for_a = 1, s[1].sum->for_x = 0;
    s[2].up->for_a = 0, s[2].up->for_x = 1;   s[2].sum->for_a = 1, s[2].sum->for_x = 0;

    for(int i = 3; i <= stations; i++){
        s[i].up->for_a = s[i-1].up->for_a + s[i-2].up->for_a,      s[i].up->for_x = s[i-1].up->for_x + s[i-2].up->for_x;
        s[i].sum->for_a = s[i-1].sum->for_a + s[i-2].up->for_a,    s[i].sum->for_x = s[i-1].sum->for_x + s[i-2].up->for_x;
    }

    int x = 0;
    x = (finsum - s[stations-1].sum->for_a * orisum) / s[stations-1].sum->for_x;

    int ans = 0;
    ans = s[que].sum->for_a * orisum + s[que].sum->for_x * x;
    printf("%d",ans);

    return 0;
}
