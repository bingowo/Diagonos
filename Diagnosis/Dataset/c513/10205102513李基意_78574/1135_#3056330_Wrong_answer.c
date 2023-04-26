int main(){
    long long int res[501];
    res[1]=1;res[2]=2,res[3]=3,res[4]=6;
    for(int i=5;i<501;i++ ){
        res[i]=res[i-1]-res[i-2]-res[i-4];
    }
    int n;
    scanf("%d",&n);
    printf("%lld",res[n]);
    return 0;
}