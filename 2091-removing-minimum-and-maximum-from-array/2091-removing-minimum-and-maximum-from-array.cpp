class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int a = min(minIndex, maxIndex);
        int b = max(minIndex, maxIndex);

        int fromLeft = b + 1;
        int fromRight = n - a;

        int oneFromEachSide = (a + 1) + (n - b);

        return min({fromLeft, fromRight, oneFromEachSide});
    }
};