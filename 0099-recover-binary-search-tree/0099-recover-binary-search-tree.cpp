class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first,*mid,*last,*prev;
        first=mid=last=nullptr;
        prev=new TreeNode(INT_MIN);
        TreeNode *curr=root;
        while(curr){
            if(!curr->left){ // left was done and we are at curr node
                // curr node is less than it's inorder predecessor (not folllowing sorted conditi[[[[[[[[[[[[]()]()]()]()]()]()]()]()]()]()]()]()on)
                if(curr->val<prev->val){
                    // condition gets violated for the first time
                    if(!first){
                        first=prev;
                        mid=curr;
                    }
                    else last=curr;
                }
                prev=curr;
                curr=curr->right;
            }
            else{
                TreeNode *now=curr->left;
                while(now->right && now->right!=curr)
                    now=now->right;
                if(!now->right){
                    now->right=curr;
                    curr=curr->left;
                }
                else{
                    now->right=nullptr;
                    if(curr->val<prev->val){
                        if(!first){
                            first=prev;
                            mid=curr;
                        }
                        else last=curr;
                    }
                    prev=curr;
                    curr=curr->right;
                }
            }
        }
        if(!last) swap(first->val,mid->val); // Case-2
        else swap(first->val,last->val); // Case-1
    }
};