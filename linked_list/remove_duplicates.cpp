ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    int cnt = 0;
    ListNode * hd = head;
    while(hd){
        cnt++;
        hd = hd -> next;
    }
    unordered_map<int, int>mp(cnt);
    hd = head;
    while(hd){
        if(!mp.count(hd->val))mp[hd->val] = 0;
        mp[hd->val]++;
        hd = hd -> next;
    }
    ListNode *n_hd{nullptr}, *tmp{head}, *tl{nullptr};
    while(tmp){
        if(mp[tmp->val] < 2){
            if(!n_hd){
                n_hd = tmp;
                tl = n_hd;
            }
            else {
                tl->next = tmp;
                tl = tl -> next;
            }
        }
        tmp = tmp -> next;
    }
    if(tl)tl -> next = nullptr;
    return n_hd;
}