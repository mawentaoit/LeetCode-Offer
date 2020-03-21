class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        int j = 0;
        for(int i = 0; i < pushed.size(); i++) {
            st.push_back(pushed[i]);
            while(!st.empty() && st.back() == popped[j]){
                st.pop_back();
                j++;
            }
        }
        return st.empty();
    }
};