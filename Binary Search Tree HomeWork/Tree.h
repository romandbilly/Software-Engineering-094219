
#ifndef HW4_TREE_H
#define HW4_TREE_H
#include "Node.h"
#include <stdexcept>
#include <string>
using std::range_error;
using std::cerr;
using std::string;

const string TREE_CONTENT("Binary search tree content:");
/*
 * a template class that represent a tree
 * the tree contain root and size
 */

template <typename T,typename G>
class Tree
{
public:
    typedef Node<T, G> TreeNode;
private:
   TreeNode*_root;
    size_t _size;
    /*
     * this is a help method for the search method
     * the method return TreeNode pointer to the requested Node
     * if not found return Null
     */
    TreeNode* treeSearch(TreeNode *current, const T& key) const
    {
        if(current == NULL || current->getKey() == key)
        {
            return current;
        }
        if( key < current->getKey())
            return treeSearch(current->getLeftChild(),key);
        else
            return treeSearch(current->getRightChild(),key);
    }
public:
    /*
     * a constructor
     */
    Tree():_root(NULL),_size(0){}
    /*
     * the method check if the tree is empty
     */
    inline bool isEmpty() const{if (_root == NULL) return true; else return false;}
    /*
     * the method return the size of the tree
     */
    inline size_t size() const{ return _size;}
    /*
     * the method get key and return pointer to the requested node
     * if not found in the tree so return null
     */
     TreeNode* search (const T& key) const
    {
        try
        {
            TreeNode *isExist = treeSearch(_root, key);
            if(!isExist)
                throw range_error("Key was not found");
            return isExist;
        }
        catch(range_error &err){
            cerr << err.what() << endl;
        }
        return NULL;
    }
    /*
     * the method insert a new node to the tree
     */
    void insert(const T& key, const G& item)
    {
        try
        {
        if (_root == NULL)
        {
            _root = new TreeNode(key, item);
            _size++;
        }
        else
        {
                    TreeNode *y = _root;
                    TreeNode *x = NULL;
                    while (y != NULL)
                    {
                        x = y;
                        if (key < y->getKey())
                            y = y->getLeftChild();
                        else
                        {
                            if (key > y->getKey())
                                y = y->getRightChild();
                            else
                                throw range_error("Key not unique");
                        }
                    }
                    TreeNode *newBorn = new TreeNode(key, item, x);
                    x->assignChild(newBorn);
                    _size++;
                }
            }
        catch (range_error &err)
        {
            cerr << err.what()<< endl;
        }
    }
    /*
     * the method delete a leaf from the tree
     */
     void deleteLeaf(const T& key)
    {
        try
        {
            TreeNode *nominatetoDelete = this->search(key);
            if (nominatetoDelete){
            if (!nominatetoDelete->getLeftChild() && !nominatetoDelete->getRightChild())
                {
                    nominatetoDelete->unAssignChild();
                    delete nominatetoDelete;
                    _size--;
                }
                else
                    throw range_error("The node is not a leaf!");
            }
        }
        catch (range_error &err)
        {
            cerr << err.what() << endl;
        }
    }
    /*
     * the method print the tree nodes
     */
    void inOrderTraversal()const
    {
        cout << TREE_CONTENT << endl;
        _root->visit();
    }
    /*
     * this is a help method to destructor
     * the method delete the nodes of the tree
     */
    void DestroyRecursive(TreeNode* node)
    {
        if (node)
        {
            DestroyRecursive(node->getLeftChild());
            DestroyRecursive(node->getRightChild());
            delete node;
        }
    }
    /*
     * a destructor
     */
    ~Tree()
    {
        DestroyRecursive(_root);
    }
};

#endif //HW4_TREE_H