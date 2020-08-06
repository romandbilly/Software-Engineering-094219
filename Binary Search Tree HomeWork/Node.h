
#ifndef HW4_NODE_H
#define HW4_NODE_H
#include <ostream>
using std::ostream;
using std::cout;
using std::endl;
/*
 * a template class that represent the nodes of tree
 * each node contain parent , left child , right child ,key and item
 */
template <typename T, typename G>
class Node
{
private:
    Node * _parent;
    Node* _left;
    Node * _right;
    const T _key;
    G _item;

public:
    /*
     * a constructor
     */
    Node(const T& key, const G& item, Node* parent=NULL): _key(key),_item(item),_parent
            (parent),_left(NULL),_right(NULL){}
    /*
     * the method return the item
     */
    inline const G& getItem() const{ return _item;}
    /*
     * the method return the key
     */
    inline const T& getKey() const{ return _key;}
    /*
     * the method return the left child
     */
    inline Node* getLeftChild () const{ return _left;}
    /*
     * the method return the right child
     */
    inline Node* getRightChild () const{ return _right;}
    /*
     * the method take care to the connections between the nodes in case of new inserted
     * node
     */
    void assignChild(Node *child)
    {
        if (child->_key < _key)
            _left = child;
        else
            _right = child;
    }
    /*
     * the method nullifies the child of parent and make the parent null.
     */
    void unAssignChild()
    {
        if(this ==_parent->_left)
            _parent->_left = NULL;
        else
            _parent->_right = NULL;
        _parent = NULL;
    }
    /*
     * the operator print the node according to the requested form
     */
    friend ostream &operator<<( ostream &output, const Node &current )
    {
        output << "key: " << current._key << "\t data:" << current._item<< endl;
        return output;
    }
    /*
     * the method is help func for inOrderTraversal func.
     * the method print the tree nodes.
     */
    void visit()
    {
        if (_left != NULL)
            _left->visit();
        cout << *this;
        if (_right != NULL)
            _right->visit();
    }

    /*
     * a destructor
     */
    ~Node(){};
};


#endif //HW4_NODE_H
