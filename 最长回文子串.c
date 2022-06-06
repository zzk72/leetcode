char * longestPalindrome(char * s){
int p1=0,p2=0,i,j,flag,len=strlen(s);
int max=1,mp1=0,mp2=0;
char a[260];
if(len==0||len==1)return s;
for(p1=0;p1<len;p1++){
    for(p2=p1+1;p2<len;p2++){
        flag=1;
       for(i=p1,j=p2;i<j;){
           if(s[i]==s[j]){
               i++;j--;
           }else break;
        }
        if(i>=j){
            if(p2+1-p1>max){
               max=p2+1-p1;mp1=p1;mp2=p2;
            }
        }
    }
}
if(s[mp2])s[mp2+1]='\0';
return s+mp1;
}
