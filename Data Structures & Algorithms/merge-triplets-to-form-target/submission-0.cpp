class Solution {
private:
    // using QType = vector<int>;
    // struct myComp {
    //     bool operator()(vector<int> &a, vector<int> &b) {
    //         for(int i=0;i<a.size(); i++) {
    //             if(a[i] != b[i]) {
    //                 return a[i] < b[i];
    //             }
    //         }
    //         return true;
    //     }
    // };
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int a = target[0];
        int b = target[1];
        int c = target[2];

        bool is_a_found = false;
        bool is_b_found = false;
        bool is_c_found = false;
        
        for(auto &triplet:triplets) {
            if((triplet[0] > a) or (triplet[1] > b) or (triplet[2] > c)) {
                continue;
            }
            is_a_found |= (triplet[0] == a);
            is_b_found |= (triplet[1] == b);
            is_c_found |= (triplet[2] == c);
        }

        return is_a_found and is_b_found and is_c_found;

    }
};
