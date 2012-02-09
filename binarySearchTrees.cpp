#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

namespace interview_qs 
{
static int comparator(const void* a, const void* b)
{
    return (*(int*)a- *(int*)b);
}

static int max(int a, int b)
{
    return a > b ? a : b;
}

class bst
{
public:
    struct node 
    {
        node* left;
        node* right;
        int data;
        
        node() : left(NULL), right(NULL), data(-1)
        { ; }

        node(int datain) : left(NULL), right(NULL), data(datain)
        { ; }
    };
    node* _root;

    node* bst_from_array_helper(int* array, int start, int end)
    {
        if (start > end) return NULL;

        int mid = start + (end-start)/2;
        node* newn = new node(array[mid]);
        newn->left = bst_from_array_helper(array,start,mid-1);
        newn->right = bst_from_array_helper(array,mid+1,end);
        return newn;
    }
    
    bst() : _root(NULL) 
    { ; }

    bst(int* array, int size)
    {
        bst_from_array(array,size);
    }

    void bst_from_array(int* array, int size)
    {
        qsort(array, size, sizeof(int), comparator);
        _root = bst_from_array_helper(array, 0, size-1);
    }

    void inorder()
    {
        printf("In order traversal:\n");
        inorder_helper(_root);
    }

    void inorder_helper(node* n)
    {
        if (!n) return;
        
        inorder_helper(n->left);
        printf("%d\n", n->data);
        inorder_helper(n->right);
    }
    
    int maxdepth()
    {
        return maxdepth_helper(_root, 0);
    }

    int maxdepth_helper(node* n, int depth_so_far)
    {
        if (!n) return depth_so_far;
        
        return max(maxdepth_helper(n->left, depth_so_far+1),
                   maxdepth_helper(n->right, depth_so_far+1));
    }

    node* least_common_ancestor(node* a, node* b)
    {
        return least_common_ancestor_helper(_root, a, b);
    }

    node* least_common_ancestor_helper(node* curr, node* a, node* b)
    {
        if (a->data < curr->data && b->data > curr->data)  // opposite sides
            return curr;
   
        if (curr == a || curr == b)
            return curr;
        else if (a->data < curr->data)                        // same side
            return least_common_ancestor_helper(curr->left, a, b);
        else
            return least_common_ancestor_helper(curr->right, a, b);
    }
};
}

using namespace interview_qs;

int main(void)
{
    int array[] = {125, 160, 3012, 5, 12, 8, 96, 168, 55, 908, 
        415, 33, 44, 125, 29, 101, 3442, 292, 10002};
    printf("Number of elements %lu\n", sizeof(array)/sizeof(int));
    bst* b = new bst(array, sizeof(array)/sizeof(int));
    b->inorder();
    printf("max depth: %d\n", b->maxdepth());    

    bst::node* nodea = b->_root->left->left;
    bst::node* nodeb = b->_root->left->left->right;
    printf("a %d b %d\n", nodea->data, nodeb->data);

    printf("least common ancestor of %d and %d is %d\n", nodea->data, 
            nodeb->data, (b->least_common_ancestor(nodea, nodeb))->data);
}


