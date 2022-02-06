#include"resources.h"

class Solution
{
public:
    char* Serialize(TreeNode* root) {
        string pre, mid;
        if (!root)return nullptr;
        pre_travel(root, pre);
        mid_travel(root, mid);
        char* res = new char[pre.size() * 2 + 2];
        memcpy(res, pre.c_str(), sizeof(char) * pre.size());
        res[pre.size()] = ',';
        memcpy(res + pre.size() + 1, mid.c_str(), sizeof(char) * mid.size());
        res[pre.size() + 1 + mid.size()] = '\0';
        return res;
    }
    TreeNode* Deserialize(char* str) {
        if (!str)return nullptr;
        int i = 0;
        vector<int> pre, mid;
        for (; str[i] != ','; ++i)pre.push_back(str[i] + '0');
        for (++i; str[i] != '\0'; ++i)mid.push_back(str[i] + '0');
        return reConstructBinaryTree(pre, mid);
    }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0)return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        rebuild(pre, vin, root);
        return root;
    }
    void rebuild(vector<int>pre, vector<int> vin, TreeNode* root)
    {
        if (pre.size() == 0)return;
        int pos = get_pos(vin, pre[0]);
        vector<int> vin_left(vin.begin(), vin.begin() + pos),
            vin_right(vin.begin() + pos + 1, vin.end());
        vector<int> pre_left(pre.begin() + 1, pre.begin() + vin_left.size() + 1),
            pre_right(pre.begin() + 1 + vin_left.size(), pre.end());
        TreeNode* left = pre_left.size() != 0 ? new TreeNode(pre_left[0]) : nullptr;
        TreeNode* right = pre_right.size() != 0 ? new TreeNode(pre_right[0]) : nullptr;
        root->left = left;
        root->right = right;
        rebuild(pre_left, vin_left, left);
        rebuild(pre_right, vin_right, right);
    }

    int get_pos(const vector<int>& target, int num)
    {
        int size = target.size();
        for (int i = 0; i < size; ++i)
            if (num == target[i])
                return i;
        return 0;
    }

    void mid_travel(TreeNode* root, string& s)
    {
        if (root->left)mid_travel(root->left, s);
        s += root->val - '0';
        if (root->right)mid_travel(root->right, s);
    }

    void pre_travel(TreeNode* root, string& s)
    {
        s += root->val - '0';
        if (root->left)pre_travel(root->left, s);
        if (root->right)pre_travel(root->right, s);
    }
};


int main(void)
{
    Solution s;

    return 0;
}