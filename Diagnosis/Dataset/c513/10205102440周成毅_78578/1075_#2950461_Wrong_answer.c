#include <stdio.h>

int main() {
    int M,N;
    int matrix[200][200];
    scanf("%d %d",&M,&N);
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&matrix[i][j]);
    int sum=matrix[0][0],pos_x=0,pos_y=0,len=0;
    char path[401];
    while(pos_x != M-1 || pos_y!=N-1){
        if (pos_x==M-1){
            path[len++]='D';
            sum+=matrix[pos_x][pos_y+1];
            pos_y++;
        } else if(pos_y==N-1){
            path[len++]='R';
            sum+=matrix[pos_x+1][pos_y];
            pos_x++;
        } else{
            path[len++]=matrix[pos_x+1][pos_y]>matrix[pos_x][pos_y+1]?'D':'R';
            matrix[pos_x+1][pos_y]>matrix[pos_x][pos_y+1]?pos_y++:pos_x++;
            sum+=matrix[pos_x][pos_y];
        }
    }
    printf("%d\n",sum);
    for(int i=len-1;i>=0;i--)
        printf("%c",path[i]);
    printf("\n");
    return 0;
}
