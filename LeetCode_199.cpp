vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		res.push_back(q.front()->val);
		while (size--)
		{
			TreeNode* temp = q.front();
			q.pop();
			if (temp->right) q.push(temp->right);
			if (temp->left) q.push(temp->left);
		}
	}
	return res;
}
