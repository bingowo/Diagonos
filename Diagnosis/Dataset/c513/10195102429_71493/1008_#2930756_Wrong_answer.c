#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a,b;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
            scanf("%d%d",&a,&b);
            int num=a^b;
            int count = 0;
	        while(num != 0){
	            if((num & 1) != 0)
                    ++count;
		       num = num >> 1;
	}
        printf("%d",count);
    }

    return 0;
}
