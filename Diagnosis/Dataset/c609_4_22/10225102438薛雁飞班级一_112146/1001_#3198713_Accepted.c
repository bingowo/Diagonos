int main()
{
   int N,R,r,t,i;
   char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   scanf("%d",&t);
   for(i=t;i!=0;i--){
    scanf("%d %d",&N,&R);
    int k=0,a[33],sign=1;
    if(N<0){sign=-1;N=-N;}
    do{
        r=N%R;
        a[k++]=table[r];
        N=N/R;
    }
    while(N);
    if(sign<0)printf("-");
    for(k=k-1;k!=-1;k--)
    {
       printf("%c",a[k]);
    }
    printf("\n");
   }
   return 0;
}
