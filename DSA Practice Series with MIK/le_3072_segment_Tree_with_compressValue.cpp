
class SegmentTree {
public:
    int m;
    vector<int> segTree;
    SegmentTree(int size) {
        m = size;
        segTree.assign(4 * m, 0); // initialization with value 0
    }
    void updateSegTree(int i, int l, int r, int cv) {
        if (l == r) {
            segTree[i]++; // update freq
            return;
        }
        int mid = l + (r - l) / 2;
        if (cv <= mid) {
            updateSegTree(2 * i + 1, l, mid, cv);
        } else {
            updateSegTree(2 * i + 2, mid + 1, r, cv);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    int segTreeQueryRange(int st, int end, int i, int l, int r) {
        if (r < st || l > end)   // out of range
            return 0;            // no overlap
        if (l >= st && r <= end) // completely inside the range
            return segTree[i];   // return freq
        int mid = l + (r - l) / 2;
        int leftSum = segTreeQueryRange(st, end, 2 * i + 1, l, mid);
        int rightSum = segTreeQueryRange(st, end, 2 * i + 2, mid + 1, r);
        return leftSum + rightSum;
    }
    void update(int cv) {
        // 0 -->index of root
        // 0-->start range
        // m-1-->end range
        // cv-->compressed value
        updateSegTree(0, 0, m - 1, cv);
    }

    int query(int st, int end) {
        return segTreeQueryRange(st, end, 0, 0, m - 1);
    }
};

class Solution {
public:
    // use segment tree but to calculate the freq of the element we generally
    // take the freq array of max no. of nums[i] value so it is 10^9 so by
    // taking the that much size of the array for segment trees it gives MLE so
    // try generic method to solve this which is applying for more such Q
    // Fenwick tree or binary indexed tree (BIT) by using this concept also this
    // Q can be solved we used the concept of compress the values to easily
    // store in the vector we compress all the ele values so that it becomes
    // small we can use small array we have to always range queries(in the
    // particular range we have to check no. of el greater than a target) so use
    // segment tree since the seg tree size becomes very large so we use the
    // concept of compressed segment tree VVVI
    // void buildSegmentTree(int i, int l, int r, string& s) {
    //     if (l == r) {
    //         segTree[i] = return;
    //     }
    //     int mid = l + (r - l) / 2;
    //     buildSegmentTree(2 * i + 1, l, mid, s);
    //     buildSegmentTree(2 * i + 2, mid + 1, r, s);
    //     segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    // }

    vector<int> resultArray(vector<int>& nums) {
        // T.C. is O(Nlog(N)) // log(N) for segment trees
        int n = nums.size();
        vector<int> copy = nums;
        sort(copy.begin(), copy.end()); // sorted the copy array
        vector<int> arr1, arr2;
        unordered_map<int, int> mp; // to store copy[i]--compressed value(cv)
        int cv = 0;
        for (int el : copy) { // compressed value given to copy[i]
            if (!mp.count(el)) {
                mp[el] = cv++;
            }
        }
        int m = mp.size();       // cv values are {0,1,2,3,...m-1}
        SegmentTree segTree1(m); // for arr1
        SegmentTree segTree2(m); // for arr2

        // 1st ops
        arr1.push_back(nums[0]);
        segTree1.update(mp[nums[0]]);
        // 2nd ops
        arr2.push_back(nums[1]);
        segTree2.update(mp[nums[1]]);

        for (int i = 2; i < n; i++) {
            int cv = mp[nums[i]];
            int cnt1 =
                segTree1.query(cv + 1, m - 1); // no. of el > nums[i] in arr1
            int cnt2 =
                segTree2.query(cv + 1, m - 1); // no. of el > nums[i] in arr2
            bool addToArr1 = false;
            if (cnt1 > cnt2) {
                addToArr1 = true;
            } else if (cnt1 < cnt2) {
                addToArr1 = false;
            } else {
                addToArr1 = (arr1.size() <= arr2.size());
            }

            if (addToArr1) {
                arr1.push_back(nums[i]);
                segTree1.update(cv);
            } else {
                arr2.push_back(nums[i]);
                segTree2.update(cv);
            }
        }

        arr1.insert(
            end(arr1), begin(arr2),
            end(arr2)); // end of the array1,append all the ele of the arr2
        return arr1;
    }
};