#include <stdio.h>
#include <stdlib.h>

long long table[16][2] = {
    {0,0},{1,0},{-1,1},{0,1},
    {0,-2},{1,-2},{-1,-1},{0,-1},
    {2,2},{3,2},{1,3},{2,3},
    {2,0},{3,0},{1,1},{2,1}
    };

int main()
{
    getchar();getchar();
    int str[1000];
    for(int i = 0;i < 1000;i++){
        str[i] = 0;
    }
    //int num = 4;
    char c;
    long long ansx = 0,ansy = 0;
    while((c = getchar()) != '\n'){
        int a;
        if(c >= '0' && c <= '9')a = c - '0';
        else if(c >= 'A' && c <= 'Z')a = c - 'A' + 10;
        /*printf("a = %d\n",a);
        printf("tablex = %lld",table[a][1]);
        printf("tabley = %lld",table[a][0]);*/
        ansx = ansx * (-4) + table[a][0];
        ansy = ansy * (-4) + table[a][1];
        //printf("ansx = %lld,ansy = %lld\n",ansx,ansy);
    }
    /*if(ansy < 0)printf("%lld%lldi",ansx,ansy);
    else if(ansy == 0)printf("%lld",ansx);
    else if(ansy == 1)printf("%lld+i",ansx);
    else if(ansy > 1)printf("%lld+%lldi",ansx,ansy);
    */
    if(ansx != 0){
        printf("%lld",ansx);
        if(ansy < 0)printf("%lldi",ansy);
        else if(ansy == 1)printf("+i");
        else if(ansy > 1)printf("+%lldi",ansy);
    }
    else if(ansx == 0){
        if(ansy < 0)printf("%lldi",ansy);
        else if(ansy == 1)printf("i");
        else if(ansy > 1)printf("%lldi",ansy);
    }

    return 0;
}
