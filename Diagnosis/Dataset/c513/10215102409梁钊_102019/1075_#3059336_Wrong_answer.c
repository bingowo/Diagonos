#include<stdio.h>
#include<string.h>

int main()
{
    int m,n;
    scanf("%d%d",&m, &n);
    int A[m][n];
    for(int i=0; i!=m; i++)
        for(int j=0; j!=n; j++)
            scanf("%d",&A[i][j]);
    int row = 0; 
    int cal = 0;
    int add_all = 0;
    char move[m+n-2] ;
    add_all += A[0][0];
    for(int i=0; i!=m+n-2; i++){
        if(row == m-1){
            cal++;
            add_all += A[row][cal];
            move[i] = 'R';
        }
        else if(cal == n-1){
            row++;
            add_all += A[row][cal];
            move[i] = 'D';            
        }
        else if(A[row+1][cal] > A[row][cal+1]){
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