#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int map[110];
int n,p,m,t;

int step[2] = {-1,1};

void travel(int d)
{
    static int depth = 0;
    if(depth==m){
        map[d]++;
        return;
    }
    else{
        for (int i=0; i<2; i++) {
            depth++;
            if (d+step[i]>0&&d+step[i]<n+1) {
                travel(d+step[i]);
            }
            depth--;
        }
    }
    
}


int main(void) {
    int k;
    scanf("%d",&k);
    for (int i=0; i<k; i++) {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        memset(map, 0, sizeof(map));
        travel(p);
        printf("%d\n",map[t]);
    }
}