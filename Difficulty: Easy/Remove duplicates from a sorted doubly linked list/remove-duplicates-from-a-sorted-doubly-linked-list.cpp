/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        Node* current = head;
        while(current != nullptr && current -> next != nullptr){
            Node* front = current -> next;
             if(current -> data == front -> data){
                current -> next = front -> next;
                
               if(front->next != nullptr){
                    front->next->prev = current;
                }
               delete front;
            }
            else{
                current = current -> next;
            }
        }
        return head;
    }
};