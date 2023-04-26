#include<stdio.h>
#include<string.h>

int main()
{
    int m,n;
    scanf("%d %d",&m, &n);
    int A[m][n];
    for(int i=0; i!=m; i++)
        for(int j=0; j!=n; j++)
            scanf("%d",&A[i][j]);
    int row, cal, add_all = 0, 0, 0;
    char move[m+n-2] ;
    add_all += A[0][0];
    for(int i=0; i!=m+n-3; i++){
        if(A[row+1][cal] > A[row][cal+1]){
            cal++;
            add_all += A[row][cal];
            move[i] = 'R';
        }
        else{
            row++;
            add_all += A[row][cal];
            move[i] = 'D';
        }
    }
    add_all += A[m][n];
    printf("%d\n%s",add_all, move);

    
    
    
}