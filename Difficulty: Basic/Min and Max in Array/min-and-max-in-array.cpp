class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0; i<arr.size(); i++){
            mini = min(mini,arr[i]);
            maxi = max(maxi,arr[i]);
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};