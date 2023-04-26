#include <stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int n, m, k, i, j, min, a, b, c, ul = 0, ur = 0, dl = 0, dr = 0, num = 0, sb = 0, xb = 0, zb = 0, yb = 0;
    scanf("%d%d%d", &n, &m, &k);
    min = n > m? m:n;
    int d[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	scanf("%d", &d[i][j]);
    	}
    }
    if(m != 1 && n != 1){
    	for(i=0;i<n;i++){
        	for(j=0;j<m;j++){//选原点 
        		for(c = 1; c < min; c++){//选边长 
        		
        			for(a=0;a<n;a++){
        				for(b=0;b<m;b++){
        					if(fabs(a+b-i-j) <= c){
        						if(a==i&&b>j)yb += d[a][b];
        						else if(a==i&&b<j)zb += d[a][b];
        						else if(a>i&&b==j)xb += d[a][b];
        						else if(a<i&&b==j)sb += d[a][b];
        						else if(a<i&&b<j)ul += d[a][b];
        						else if(a<i&&b>j)ur += d[a][b];
        						else if(a>i&&b>j)dl += d[a][b];
        						else if(a>i&&b<j)dr += d[a][b];
							}
    					}
    				}//printf("%d\n", d[i][j]+xb+yb+dr);
    				if(i == 0 && j == 0){
    					if(d[i][j]+xb+yb+dr>=k)num += 1;
					}
    				else if(i == 0 && j == m-1){
    					if(d[i][j]+xb+zb+dl>=k)num += 1;
					}
    				else if(i == n-1 && j == 0){
    					if(d[i][j]+sb+yb+ur>=k)num += 1;
					}
    				else if(i == n-1 && j == m-1){
    					if(d[i][j]+sb+zb+ul<k)num += 1;
					}
    				else if(i == 0 && j != 0 && j != m-1){
    					if(d[i][j]+xb+yb+dr>=k)num += 1;
						if(d[i][j]+xb+zb+dl>=k)num += 1;
					}
    				else if(i == n-1 && j != 0 && j != m-1){
    					if(d[i][j]+sb+yb+ur>=k)num += 1;
						if(d[i][j]+sb+zb+ul>=k)num += 1;
					}
    				else if(j == 0 && i != 0 && i != n-1){
    					if(d[i][j]+xb+yb+dr>=k)num += 1;
						if(d[i][j]+sb+yb+ur>=k)num += 1;
					}
    				else if(j == m-1 && i != 0 && i != n-1){
    					if(d[i][j]+xb+zb+dl>=k)num += 1;
						if(d[i][j]+sb+zb+ul>=k)num += 1;
					}
					else{
						if(d[i][j]+xb+zb+dl>=k)num += 1;
						if(d[i][j]+sb+zb+ul>=k)num += 1;
						if(d[i][j]+xb+yb+dr>=k)num += 1;
						if(d[i][j]+sb+yb+ur>=k)num += 1;
					}
    				ul = 0, ur = 0, dl = 0, dr = 0, sb = 0, xb = 0, zb = 0, yb = 0;
				}
        	
    		}
    	}
	}
	else{
		for(i=0;i<n;i++){
        	for(j=0;j<m;j++){
        		if(d[i][j] >= k)num++;
    		}
    	}
	}
    	printf("%d", num);
    	return 0;
}

		
	