#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   //the unsorted ListArray of cds
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int numItems = cds->size();
   cout << numItems << endl;
   cout << endl;

   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
   delete iter;

   BinaryTreeIterator<CD>* bst_iter = bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
    //  cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (not minimum height)
   //display whether the binary search tree is balanced (should not be balanced)


	cout<<"BST height:  "<<bst->getHeight()<<endl;
	cout<<"BST is balanced:  "<<bst->isBalanced()<<endl;




   //create a minimum height binary search tree
   BinarySearchTree<CD>* min_bst = bst->minimize();
   bst_iter = min_bst->iterator();

   //make sure that an inorder traversal gives sorted order
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
    //  cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

	cout<<"BST min height:  "<<min_bst->getHeight()<<endl;
	cout<<"BST is balanced:  "<<min_bst->isBalanced()<<endl;




	cout<<"hi 0"<<endl;
   //create a complete binary search tree
   BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
   delete bst;
	cout<<"hi 1"<<endl;
   //make sure that an inorder traversal gives sorted order
   bst_iter = complete_bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
    //  cd->displayCD();
   }
   delete bst_iter;
	cout<<"hi 2"<<endl;
   //DO THIS
   //display the height of the complete binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

	cout<<"Complete BST height:  "<<complete_bst->getHeight()<<endl;
	cout<<"Complete BST is balanced:  "<<complete_bst->isBalanced()<<endl;

	cout<<"hi 3"<<endl;




   delete complete_bst;

   deleteCDs(cds);
   delete cds;
   return 0;
}
