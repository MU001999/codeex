/*
Q-URL: https://www.codewars.com/kata/sum-the-tree/cpp
*/

// Return the sum of all values in the tree, including the root
int sumTheTreeValues(node* root) {
  return root != nullptr ? root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right): 0;
}