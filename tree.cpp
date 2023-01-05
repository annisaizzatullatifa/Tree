#include "tree.h"

adrNode newNode_1301213328(infotype x){
    adrNode P = new Node;
    info(P) = x;
    left(P) = NULL;
    right(P) = NULL;
    return P;
}
adrNode findNode_1301213328(adrNode root, infotype x){
    if(root != NULL){
        if(info(root) == x){
            return root;
        }else{
            if(x > info(root)){
                findNode_1301213328(right(root), x);
            }else{
                findNode_1301213328(left(root), x);
            }
        }
    }else{
        return NULL;
    }
}
void insertNode_1301213328(adrNode &root, adrNode p){
    if(root == NULL){
        root = p;
    }else{
        if(info(p) > info(root)){
            insertNode_1301213328(right(root), p);
        }else{
            insertNode_1301213328(left(root), p);
        }
    }
}

void printPreOrder_1301213328(adrNode root){
    if ( root != NULL ){
        cout << info( root ) << " ";
        printPreOrder_1301213328( left( root ) );
        printPreOrder_1301213328( right( root ) );
    }
}
void printDescendant_1301213328(adrNode root, infotype x){
    adrNode p = findNode_1301213328(root, x);
    if(p != NULL){
        if(info(p) != x){
            cout << info(p) << " ";
            printPreOrder_1301213328(left(p));
            printPreOrder_1301213328(right(p));
        }else{
            printPreOrder_1301213328(left(p));
            printPreOrder_1301213328(right(p));
        }
    }
}
int sumNode_1301213328(adrNode root){
     if(root != NULL){
        return info(root) + sumNode_1301213328(left(root)) + sumNode_1301213328(right(root));
    }
}
int countLeaves_1301213328(adrNode root){
    if (root == NULL) {
        return 0;
    }
    if (left(root) == NULL && right(root) == NULL) {
        return 1;
    }
    return countLeaves_1301213328(left(root)) + countLeaves_1301213328(right(root));
}
int heightTree_1301213328(adrNode root){
    if (root == NULL) {
        return -1;
    }
    int left_height = heightTree_1301213328(left(root));
    int right_height = heightTree_1301213328(right(root));

    if (left_height > right_height) {
        return left_height + 1;
    }else{
        return right_height + 1;
    }
}
