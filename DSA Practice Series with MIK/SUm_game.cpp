class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftKnownSum = 0;
        int rightKnownSum = 0;
        int leftQMark = 0;
        int rightQMark = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQMark++;
            else
                leftKnownSum += (num[i] - '0');
        }
        for (int i = n/2; i < n; i++) {
            if (num[i] == '?')
                rightQMark++;
            else
                rightKnownSum += (num[i] - '0');
        }
        int totalQMark = leftQMark + rightQMark;
        if (totalQMark % 2) // alice will always win if the Q mark is Odd
            return 1;
        return 2 * leftKnownSum + 9 * leftQMark !=
               2 * rightKnownSum + 9 * rightQMark;
    }
};