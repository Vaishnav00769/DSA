/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,Node*> um;
        Node* temp = head;
        while(temp)
        {
            um[temp] = new Node(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(temp)
        {
            Node* ntemp = um[temp];
            ntemp -> next = um[temp -> next];
            ntemp -> random = um[temp -> random];
            temp = temp -> next;
        }
        return um[head];
    }
};