#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void find_prev(vector<int> heights, int n, vector<int> &prev)
{
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        prev[i] = st.top();
        st.push(i);
    }
}
void find_next(vector<int> heights, int n, vector<int> &next)
{
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        next[i] = st.top();
        st.push(i);
    }
}
int largestRectangleArea(vector<int> heights)
{
    int n = heights.size();

    vector<int> prev(n);
    find_prev(heights, n, prev);

    vector<int> next(n);
    find_next(heights, n, next);

    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int length = heights[i];

        if (next[i] == -1)
            next[i] = n;

        int breadth = next[i] - prev[i] - 1;
        int newarea = length * breadth;

        area = max(area, newarea);
    }
    return area;
}

void maximalRectangle(vector<vector<int>> &matrix2)
{

    int area = largestRectangleArea(matrix2[0]);

    for (int i = 1; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            if (matrix2[i][j] != 0)
            {
                matrix2[i][j] += matrix2[i-1][j];
            }
            else
                matrix2[i][j] = 0;
        }
        area = max(largestRectangleArea(matrix2[i]), area);
    }
    cout << area;
}
int main()
{
    vector<vector<char>> matrix(4, vector<char>(5));
    matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, 
    {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    vector<vector<int>> matrix2(4, vector<int>(5));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix2[i][j] = (matrix[i][j] - '0');
        }
    }

    maximalRectangle(matrix2);

    return 0;
}