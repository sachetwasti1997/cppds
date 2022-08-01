typedef vector<int> v_int;

class NumArray {
private:
    v_int seg_tree;
    int sz;
    v_int arr;
    
    int construct_tree(int sti, int si, int se){
        if(si == se){
            tree[sti] = arr[si];
            return arr[si];
        }
        int mid = (si+se)/2;
        tree[sti] = construct_tree(2 * si + 1, si, mid) + construct_tree(2 *si + 2, mid+1, se);
        return tree[sti];
    }

    int findSum(int qs, int qe, int si, int ei, int sti){
        if(qs > ei || si > qe)return 0;
        if(qs <= si && qe >= ei)return tree[sti];
        int mid = (si+ei)/2;
        return findSum(qs, qe, si, mid, 2 * sti + 1) + findSum(qs, qe, mid + 1, ei, 2 * sti + 2);
    }

    void update(int si, int ei, int i, int sti, int diff){
        if(i < ss || i > se)return;
        seg_tree[sti] += diff;
        if(ei > si){
            int mid = (ei+si)/2;
            update(si, mid, i, 2 * sti + 1, diff);
            update(si, mid, i, 2 * sti + 2, diff);
        }
    }
    
public:
    NumArray(v_int &nums) {
        seg_tree = v_int(4 * nums.size(), -1);
        sz = nums.size();
        arr = nums;
        construct_tree(0, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        update(0, sz - 1, index, 0, val - arr[index])
    }
    
    int sumRange(int left, int right) {
        return findSum(left, right, 0, sz - 1, 0);
    }
};