#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
   bool static cmp(const pair<int, int>&a,const pair<int, int>&b)
   {
      return a.second > b.second;
   }
   vector<int> contents;
   vector<int> findMode(TreeNode* root) {
      if (root == NULL)return {};
      midBST(root);
      int size = contents.size();
      unordered_map<int, int> dict;
      for (int i = 0; i < size; ++i)
      {
         if (dict.find(contents[i]) != dict.end())dict[contents[i]] += 1;
         else dict[contents[i]] = 1;
      }
      vector<pair<int, int>> temp;
      for (auto& i : dict)temp.push_back(i);
      sort(temp.begin(), temp.end(), cmp);
      size = dict.size();
      vector<int> ans;
      int max = dict.begin()->second;
      for (auto i = dict.begin(); i!=dict.end(); ++i)
      {
         if (i->second == max)ans.push_back(i->first);
         else break;
      }
      return ans;
   }

   void midBST(TreeNode* root)//中序遍历,即先遍历左子节点,在处理当前节点,再遍历右子节点.
      //同理有前序遍历,先处理当前节点,再遍历左,最后右,先根后左再右
      //还有后序遍历,先左后右再根
      //在搜索二叉树中,即左节点<=根且右节点>=根的二叉树中,中序遍历能得到一个有序数组.
   {
      if (root == NULL)return;
      midBST(root->left);
      contents.push_back(root->val);
      midBST(root->right);
      return;
   }
};

int main(void)
{
   Solution s;
   TreeNode* t = NULL;
   s.findMode(t);
   return 0;
}