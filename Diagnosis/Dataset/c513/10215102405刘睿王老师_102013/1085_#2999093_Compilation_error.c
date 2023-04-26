 #include<stdio.h>
 #include<string.h>
 void sum(char a[],char b[],char c[]);//c=a+b
 void swap(char a[]);
 int main()
 {
     char a[],b[],c[];
     freopen("5.in","r",stdin);
     while(scanf("%s%s",a,b)!=EOF)//while(cin>>a>>b)
     {
         sum(a,b,c);
         printf("%s\n",c);
     }
     return ;
 }
 void sum(char a[],char b[],char c[])//c=a+b
 {
     int i,lenA,lenB,min,max;
     int carry=,t;
     lenA=strlen(a);
     lenB=strlen(b);
     swap(a);
     swap(b);
     if(lenA>lenB)
     {
         max=lenA;
         min=lenB;
     }
     else
     {
         max=lenB;
         min=lenA;
     }
     for(i=;i<min;i++)
     {
         t=(a[i]-'')+(b[i]-'')+carry;
         c[i]=t%+'';
         carry=t/;
     }
     if(lenA>lenB)
     {
         for(i=min;i<max;i++)
         {
             t=(a[i]-'')+carry;
             c[i]=t%+'';
             carry=t/;
         }
     }
     else
     {
         for(i=min;i<max;i++)
         {
             t=(b[i]-'')+carry;
             c[i]=t%+'';
             carry=t/;
         }
     }
     if(carry!=)
     {
         c[i]=carry+'';
         i++;
     }
     c[i]='\0';
     swap(c);
 }
 void swap(char a[])
 {
     int i,len=strlen(a),t=len/;
     char ch;
     for(i=;i<t;i++)
     {
         ch=a[i];
         a[i]=a[len--i];
         a[len--i]=ch;
     }
 }