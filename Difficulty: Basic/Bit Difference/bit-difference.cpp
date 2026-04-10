class Solution {
  public:
    int countBitsFlip(int a, int b) {
        // code here
        int count = 0;
        int ans = a ^ b;
        for(int i = 0; i<31; i++){
            if(ans & (1 << i)){
                count++;
            }
        }
        return count;
    }
};