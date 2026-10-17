class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int lw = 0,mx = 0,rw = 0 ,n = cardPoints.size();
        if(k>n)return 0 ;
        if(k==n){
            return accumulate(cardPoints.begin(),cardPoints.end(), 0);
        }
        for(int  i = 0;i<k;i++){//left window whole sum
            lw += cardPoints[i];
        }
        mx  = lw;
        int r = n-1;
        for(int i =k-1;i>=0;i-- ){//shrinking and increasing windw size 
           lw -= cardPoints[i];
           rw += cardPoints[r--];
           mx = max(mx,lw+rw);
        }
        return mx;
    }
};