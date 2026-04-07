class Solution {
  public:
    bool canWePlace(vector<int> &stalls,int dist, int cows){
        int countCow = 1, LastStalls = stalls[0];
        for(int i = 1; i <stalls.size(); i++){
            if(stalls[i] - LastStalls >= dist){
                countCow++;
                LastStalls = stalls[i];
                if(countCow >= cows) return true;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canWePlace(stalls, mid, k) == true){
                low = mid + 1;
            }else{
                high = mid - 1; 
            }
        }
        return high;
    }
};