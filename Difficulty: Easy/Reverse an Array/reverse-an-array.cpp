class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int left=0;
        int right=arr.size()-1;
        for(left=0;left<right;left++)
        {
            if(arr[left]==arr[right]){
                swap(arr[left],arr[right]);
            }
           
            swap(arr[left],arr[right]);
            right--;
        }
        
    }
};