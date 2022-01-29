#include"resources.h"

class Solution
{
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		
		if (sequence.size() == 0)return false;
		else return verify(sequence);
	}
	int get_pos(vector<int> sequence, int num)
	{
		int len = sequence.size();
		for (int i = 0; i < len; ++i)
		{
			if (sequence[i] >= num)return i;
		}
		return len;
	}

	bool verify(vector<int> sequence)
	{
		//判断一个序列是否为二叉搜索树的后序遍历序列,需要用到后序遍历序列的知识结构
		//由于后序遍历为左右根,所以序列最后一个一定为根节点,而根节点的左子树比根小,右子树比根大
		//所以序列除最后一个数之外的其他部分可以划分为两个连续部分,第一段全比根小,第二段全比根大；
		//再对这分出来的两段进行递归,直到只有一个元素为根.
		int len = sequence.size();
		if (len == 1 || len == 0)return true;
		int root = sequence.back();
		int pos = get_pos(sequence, root);
		for (int i = pos; i < len; ++i)if (sequence[i] < root)return false;
		vector<int> left(sequence.begin(), sequence.begin() + pos),
			right(sequence.begin() + pos, sequence.end() - 1);
		return verify(left) && verify(right);
	}
};


int main(void)
{
	Solution s;

	return 0;
}