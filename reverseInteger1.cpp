class Solution {
public:
    int reverse(int x) {
        int result=0;
        int num;
        while(x!=0){
            num=x%10;
            if(result<INT_MIN/10.0||result>INT_MAX/10.0)
                return 0;
            result=result*10+num;
            x/=10;
            
        }
        return result;
    }
};