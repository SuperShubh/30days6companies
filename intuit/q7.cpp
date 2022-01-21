// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

 int shipWithinDays(vector<int>& weights, int D) {

        int left = 0, right = 0;
        for (int w: weights){
            left = max(left, w);
            right+=w;
            }
        while (left < right) {
            int mid = (left + right) / 2, ans = 1, cur = 0;
            for (int i = 0; i < weights.size() && ans <= D; cur += weights[i++]){
                if (cur + weights[i] > mid)
                    cur = 0, ans++;
            }
            if (ans > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
