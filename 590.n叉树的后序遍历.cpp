/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        Node* rt = root;
        st.push(rt);
        while (st.size()) {
            rt = st.top(); st.pop();
            res.push_back(rt->val);
            for (int i = 0; i < rt->children.size(); i++) st.push(rt->children[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

