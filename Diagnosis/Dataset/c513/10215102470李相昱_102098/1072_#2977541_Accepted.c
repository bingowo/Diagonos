#include <stdio.h>
#include <math.h>
#define ll long long

ll xx,yy;
int ans;
char c[107];

void putx(char a){
    if(xx >= 0)
        a = a == 'E' ? 'W' : 'E';
    c[++ans]=a;
}
void puty(char a){
    if(yy >= 0)
        a = a == 'N' ? 'S' : 'N' ;
    c[++ans]=a;
}
ll _abs(ll aa){
	return aa >= 0 ? aa : -aa ;
}

int main(){
    scanf("%lld%lld",&xx,&yy);
    if(xx == 0 && yy == 0){
        puts("0");
        return 0;
    }
    if((xx&1) == 0 && (yy&1) == 0){
        puts("-1");
        return 0;
    }
    if((xx&1) == 1 && (yy&1) == 1){
        puts("-1");
        return 0;
    }
    ll x=_abs(xx),y=_abs(yy);
    while(1){
	    if(x == 0 && y == 1){
	    	puty('S');
	    	break ;
		}
		if(x == 1 && y == 0){
			putx('W');
			break ;
		}
	
	    if(x&1){//x是奇数
	        y >>= 1;
	        if(y&1){//y/2是奇数
	            if(((x-1) >> 1 & 1) == 0){
	                putx('W');
	                x=x-1>>1;
	            }
	            else {
	                putx('E');
	                x=x+1>>1;
	            }
	
	        }
	        else {//y/2是偶数
	            if((x+1) >> 1 & 1){
	                putx('E');
	                x=x+1>>1;
	            }
	            else {
	                putx('W');
	                x=x-1>>1;
	            }
	        }
	    }
	
	    else {//y是奇数
	        x >>= 1;
	        if(x&1){//x/2是奇数
	            if(((y-1) >> 1 & 1) == 0){
	                puty('S');
	                y=y-1>>1;
	            }
	            else {
	                puty('N');
	                y=y+1>>1;
	            }
	        }
	        else {//x/2是偶数
	            if((y+1) >> 1 & 1){
	                puty('N');
	                y=y+1>>1;
	            }
	            else {
	                puty('S');
	                y=y-1>>1;
	            }
	        }
	    }
	}
    printf("%d\n",ans);
    for(int i = 1 ; i <= ans ; ++ i)
        printf("%c",c[i]);
    return 0;
}
/*
5 70

7
ESESSNN

1000000000000 -999999999999

41
SSSSSSSSSSSSWWWWSWSWWSWSWWSWSWSSWWWSWSSSE
*/