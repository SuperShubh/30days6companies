// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1;
        int high=piles[piles.size()-1];
        while(low<high){
          int mid=(low+high)/2;
            int hour=0;
            for(int  x: piles) hour+=(x+mid-1)/mid;
            if(hour<=h) high=mid;
            else low=mid+1;
        }
        return high;
    }
};