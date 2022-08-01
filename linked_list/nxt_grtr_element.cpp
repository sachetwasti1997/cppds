class Solution {
private:
    ListNode* reverse(ListNode *h, int &cnt){
        if(!h -> next)return h;
        ListNode *prev{nullptr}, *curr{h}, *nxt{h->next};
        while(curr){
            cnt++;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        return curr;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse(head);
        int cnt = 0;
        stk.push(head.val);
        head = head->next;
        vector<int> res(cnt, 0);
        while(head){
            while(!stk.empty() && head->val >= stk.top()) stk.pop(); 
            if(!stk.empty()) res[i] = stk.top();
            stk.push(head->val);
            head = head->next;
        }
        return res;
    }
};