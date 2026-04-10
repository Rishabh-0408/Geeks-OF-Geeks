class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        for(int i = 0; i < k; i++){
            n = n / 2;
        }
        if(n % 2 == 1) return true;
        else false;
    }
};