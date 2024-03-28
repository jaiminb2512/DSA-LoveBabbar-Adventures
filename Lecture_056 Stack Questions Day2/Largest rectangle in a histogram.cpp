#include <vector>
#include <stack>

using namespace std;

int largestRectangle(vector<int> &heights) {
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    // Process any remaining elements in the stack
    while (!st.empty()) {
        int height = heights[st.top()];
        st.pop();
        int width = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}
