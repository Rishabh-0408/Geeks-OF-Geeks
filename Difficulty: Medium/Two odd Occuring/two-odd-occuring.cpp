class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int temp = 0;
        for(int i=0; i<arr.size(); i++){
            temp ^= arr[i] ;
        }
        
        int rsb = temp & (-temp);
        int n1 = 0;
        int n2 = 0;
        for(int num : arr){
            if((num & rsb) != 0){
                n1 ^= num; 
            }
            else{
                n2 ^= num;
            }
        }
        if(n1 > n2){
            return {n1,n2};
        }
        else return {n2,n1};
    }
};