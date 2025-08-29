class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int size = temperatures.size();
      vector<int> result(size);

        for(int i = 0; i < size; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            result[st.top()] = 0;
            st.pop();
        }

        return result;
    }
};