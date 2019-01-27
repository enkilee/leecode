class Solution {
public:
    int reverse(int x) {
        int xnum[15]={0};
        int i=0,num=0;;
        while(1){
            xnum[i]=x%10;
            num=num*10+xnum[i];
            x=x/10;
            if(x==0){
                break;
            }
            i++;
        }
        if(num%10!=xnum[i]){
            num=0;
        }
        return num;
    }
};