//时间复杂度表示：<预处理, 单次查询>
//数组无法放在内存中，所以需要预处理分块，设分块的大小为 T, 复杂度表示为
// 	<O(nlog(n/T)), O(log(n/T) + T)>
//即分块后用 Binary Search Tree 索引，节点里存子树里包含数的数目，这个
//	索引可以放在内存中，每次查询只需要访一次外存。
//预处理需要 log(n/T) 趟，用 partition 操作，第一趟先分为两半
//然后之后每一趟都把上一趟的一块分为两半，直到树高为 log(n/T), T 大小只是平均值。
//partition 后二叉树节点左子节点存左半节点，右子存右半节点
//每一块用快排中的 partition 操作选取元素，需要 avg O(T) 时间


class KFinder{
public:
	//return 0 for successfully call, -1 for errors
	//r for saved result, undefined value when return -1
	int findKthInHugeArray(int k, int& r) {
		block_descriptor bd = findKthBlock(root, k);
		vector<int> num;
		num.reserve(size_block);

		if (read_block(bd, num) == 0) {

			int n = num.size();

			function<int(int, int, int)> findInBlock = [&](int k, int start, int end){

				int pivot = random() % (end - start) + start;
				swap(num[start], num[pivot]);
				pivot_v = num[start];
				int i = start;
				int j = end - 1;

				while (i < j) {
				    while (i < j && num[j] >= pivot_v) j--;
				    
				    num[i] = num[j];
				    
				    while (i < j && num[i] <= pivot_v) i++;
				    num[j] = num[i];
				}
				num[i] = pivot_v;
				pivot = i;

				if (pivot == k) return num[pivot];
				else if (pivot < k)
					return findInBlock(k - pivot, pivot + 1, end);
				else
					return findInBlock(k, start, pivot);
			}
			
			r = findInBlock(k, 0, n);
			return 0;
		}

		return -1;
	}
private:

	TreeNode {
		TreeNode *left;
		TreeNode *right;
		block_descriptor bd;
		int count;
	}
	TreeNode *root;
	int size_block;
	int read_block(block_descriptor bd, vector<int> &num) {
		//..if bad block_descriptor return -1
		//return 0 for read successfully from disk or databases
		//return -1 for errors
	}

	block_descriptor findKthBlock(TreeNode *root, int k) {
		assert(root != NULL);
		if (root->left == NULL && root->right == NULL) return root->bd;

		assert(root->left);
		if (k <= root->left->count) return findKthBlock(root->left, k);

		assert(root->right);
		return findKthBlock(root->right, k - root->left->count);
	}

};




