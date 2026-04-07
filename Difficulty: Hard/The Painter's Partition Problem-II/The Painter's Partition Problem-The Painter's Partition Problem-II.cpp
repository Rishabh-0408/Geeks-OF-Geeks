class Solution {
  public:
    bool isValid(vector<int> &arr, int n, int k, int MaxBoards){    
        int Painters  = 1, Boards = 0;
        for(int i = 0; i < n; i++){
            //agr arr[i] ki valye maxpage (mid) se jayad hai
            if(arr[i] > MaxBoards) return false;
            //agar pages allowed yani mid se pages kam ho to
            if(Boards + arr[i] <= MaxBoards){
                Boards += arr[i];
            }else{
                //mid se jayada ho to student++
                Painters++;
                Boards = arr[i];
            }
        }
        if(Painters > k){
            return false;
        }else{
            return true;
        }
    }
    
    int minTime(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        //If number of student are more than number of books
        if(k > n) {
            return -1;
        }
        int Ans = -1;
        
        //Getting Range of Answers
        // ... inside findPages
        // St should be the max element, not 0
        //Because Reasoning: Socho, jo bhi hamara final answer hoga (minimum possible maximum pages), woh kam se kam sabse moti waali book ke pages ke barabar toh hoga hi, usse kam to ho hi nahi sakta. Right? Agar ek book 50 page ki hai, to aap Maxpages = 40 ka solution nikaal hi nahi sakte.
        //The Fix: Instead of starting St from 0, you should start it from the largest element in the array. This makes your search space smaller and your logic more robust.
        int St = 0;
        // for(int x : arr) {
        //   St = max(St, x);
        // }
        // or even better:
        // int St = *max_element(arr.begin(), arr.end());
        int End = 0;
        for (int i = 0; i< n; i++){
            End += arr[i];
        }
        //Getting Range of Answer Completed
        
        while(St <= End){
            int Mid = St + (End - St) / 2;
            //If Answer id valid check for more possible minimum answers 
            if(isValid(arr, n, k, Mid)){
                Ans = Mid;
                End = Mid - 1;
            }
            else{
                St = Mid + 1;
            }
        }
        return Ans;
    }
};
