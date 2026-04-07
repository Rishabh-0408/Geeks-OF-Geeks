// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    Node* getTail(Node* head){
        Node* temp = head;
        while(temp ->next != nullptr){
            temp = temp -> next;
        }
        return temp;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        Node* right = getTail(head);
        Node* left = head;
        while(left -> data < right -> data){
            if(left -> data + right -> data == target){
                ans.push_back({left->data,right->data});
                left = left -> next;
                right = right -> prev;
            }
            else if(left -> data + right -> data < target){
                left = left -> next;
            }
            else{
                right = right -> prev;
            }
        }
        return ans;
    }
};