/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == nullptr) {
                s += "# ";
                continue;
            }

            s += to_string(temp->val) + " ";

            q.push(temp->left);
            q.push(temp->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        stringstream ss(data);
        string token;

        ss >> token;
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (ss >> token) {
                if (token != "#") {
                    curr->left = new TreeNode(stoi(token));
                    q.push(curr->left);
                }
            }
            if (ss >> token) {
                if (token != "#") {
                    curr->right = new TreeNode(stoi(token));
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));