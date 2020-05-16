class KthLargest {
public:
    typedef pair<int, int> PII;
    set<PII> s;
    int k, t;
    KthLargest(int k, vector<int>& nums) {
        this->k = k, t = 0;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
        return ;
    }
    int add(int val) {
        if (s.size() < k) {
            s.insert(PII(val, t++));
        } else if(val > s.begin()->first) {
            s.erase(s.begin());
            s.insert(PII(val, t++));
        }
        return s.begin()->first;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
