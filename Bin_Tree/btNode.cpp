#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode* &bst_root, int insInt)
{
   if (bst_root == 0)
   {
      bst_root = new btNode;
      bst_root->data = insInt;
      bst_root->left = bst_root->right = 0;
      return;
   }

   btNode * cursor = bst_root;
   for(;;)
   {
      if (cursor->data == insInt)
         return;
      if (insInt < cursor->data)
      {
         if(cursor->left == 0)
         {
            cursor->left = new btNode;
            cursor->left->data = insInt;
            cursor->left->left = cursor->left->right = 0;
            return;
         }
         else
            cursor = cursor->left;
      }
      else
         if(cursor->right == 0)
         {
            cursor->right = new btNode;
            cursor->right->data = insInt;
            cursor->right->left = cursor->right->right = 0;
            return;
         }
         else
            cursor = cursor->right;
   }
}

bool bst_remove(btNode * &bst_root, int remInt)
{
   if (bst_root == 0)
      return false;
   if (remInt < bst_root->data)
      return bst_remove(bst_root->left, remInt);
   if (remInt > bst_root->data)
      return bst_remove(bst_root->right, remInt);

   if (bst_root->left == 0 && bst_root->right == 0)
   {
      btNode * old_bst_root = bst_root;
      bst_root = 0;
      delete old_bst_root;
      return true;
   }
   if (bst_root->left == 0 || bst_root->right == 0)
   {
      btNode * old_bst_root = bst_root;
      if ( bst_root->left != 0)
         bst_root = bst_root->left;
      else
         bst_root = bst_root->right;
      delete old_bst_root;
      return true;
   }
   else
   {
      bst_remove_max(bst_root->left, bst_root->data);
      return true;
   }
}

void bst_remove_max(btNode * &bst_root, int& nodeData)
{
   if (bst_root->right == 0)
   {
      nodeData = bst_root->data;
      btNode * old_bst_root = bst_root;
      bst_root = bst_root->left;
      delete old_bst_root;
      return;
   }
   else
      bst_remove_max(bst_root->right, nodeData);
}

