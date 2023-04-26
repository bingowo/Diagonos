#include <stdio.h>
long long int L[10000];
int List[10000][30];
int main()
{
    int num=0,wide=10000,high=30;
    long long int res=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
        scanf("%lld",&L[i]);
    long long int min = L[0];
    int minIndex = 0;
    for(int i=1;i<num;i++){
        if(L[i]<min){
        	min=L[i];
			minIndex=i;	
		}
    }
    for(int i=0;i<num;i++)
        res = res^L[i]; 
    if(res!=0) printf("-1");
    else {
        for(int i=0;i<wide;i++)
            for(int j=0;j<high;j++)
                List[i][j]=0;
        for(int i=0;i<num;i++)
        {
            if(i!=minIndex) {
                int index = high-1,temp=0,count=0;
                while(L[i]!=0){
                    List[i][index--] = L[i]%10;
                    L[i] = L[i]/10;
                }
                for(int j=high-1; j>=0; j--){
                    temp = List[num][j]+List[i][j]+count; 
                    count = temp/10;
                    List[num][j]= temp%10;
                }
            }
        }
        int zero=0; for(zero=0;List[num][zero]==0;zero++);
        for(int i=zero;i<high;i++)
        {
            printf("%d",List[num][i]);
        }
    }
    return 0;
}