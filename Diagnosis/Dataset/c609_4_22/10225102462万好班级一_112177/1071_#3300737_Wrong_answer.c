#include <stdio.h>


int xm[4] = {1,0,-1,0},ym[4] = {0,1,0,-1};

int super(int stepp[]);

void method(int n,int x,int y);

int xi,yi;
int step[70];int sign = -1;
int main()
{
    super(step);
    scanf("%d %d",&xi,&yi);
    method(0,0,0);
    printf("%d",sign);
}



int super(int stepp[]){
    stepp[0] = 1;
    for (int i = 1; i < 70; ++i) {
        stepp[i] = 2*stepp[i-1];
    }
}
void method(int n,int x,int y){
    if(x == xi && y == yi) {sign = n;return;}
    else if(n == 10){sign = -1;return;}
    for (int i = 0; i < 4; ++i)
    {
        x = x + step[n-1]*xm[i];
        y = y + step[n-1]*ym[i];
        method(n+1,x,y);
    }
}