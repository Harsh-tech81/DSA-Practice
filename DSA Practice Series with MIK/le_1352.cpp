class ProductOfNumbers {
public:
    vector<int> pref;
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            pref.clear();
        } else if (pref.empty())
            pref.push_back(num);
        else {
            pref.push_back(pref.back() * num);
        }
    }

    int getProduct(int k) {
        int n = pref.size();
        if (k == n)
            return pref.back();
        else if (k > n)
            return 0;
        return pref.back() / pref[n - 1 - k];
    }
};