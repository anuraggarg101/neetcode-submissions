class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(A.size() > B.size())  return findMedianSortedArrays(B, A);

        int n = A.size();
        int m = B.size();

        int l = 0;
        int h = n;
        while(l <= h) {
            int i = (l+h)/2;
            int j = (m+n+1)/2 - i;

            int Aleft = (i == 0 ? INT_MIN : A[i-1]);
            int Aright = (i == n ? INT_MAX : A[i]);
            
            int Bleft = (j == 0 ? INT_MIN : B[j-1]);
            int Bright = (j == m ? INT_MAX : B[j]);

            if((Aleft <= Bright) and (Aright >= Bleft)) {
                // correct partition
                if ((m+n) % 2 == 0) {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0f;
                } else {
                    return max(Aleft, Bleft);
                }
            } else if (Aleft > Bright) {
                h = i-1;
            } else {
                l = i+1;
            }
        }
        return 0;
    }
};
