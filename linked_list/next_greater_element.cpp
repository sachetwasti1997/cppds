class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> lst;
        while(head){
            lst.push_back(head->val);
            head = head -> next;
        }
        stack<int> stk;
        vector<int> res(lst.size(), 0);
        int i = lst.size() - 1;
        stk.push(lst[i]);
        i--;
        while(i >= 0){
            while(!stk.empty() && lst[i] >= stk.top()) stk.pop(); 
            if(!stk.empty()) res[i] = stk.top();
            else res[i] = 0;
            stk.push(lst[i]);
            i--;
        }
        return res;
    }
};