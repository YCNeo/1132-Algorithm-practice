AVLTreeDeletion(Tree T, Element X) {
    if ( T == NULL ) 
        output "Not found";
    else if ( X < T->data )
        AVLTreeDeletion ( T->left, X );
    else if ( X > T->data )
        AVLTreeDeletion ( T->right, X );
    else if ( T->left && T->right ) {
        // Find the minimum m in the right subtree;
        // Replace the current node's value with m;
        // Delete the node m from the right subtree;
        if ( T is imbalanced )
            AVLTreeRotation(T, currentNode);
    } else {
        // Adjust T's parent a pointer to bypass currentNode
        // Delete the T
        if ( T is imbalanced )
            AVLTreeRotation(T, currentNode);
    }
}

AVLTreeRotation(Tree T, Node currentNode) {
    // Rebalance the tree
    // a = the nearest imbalance ancestor of currentNode
    case currentNode of {
        a->left->left: LL(a);
        a->left->right: LR(a);
        a->right->left: RL(a);
        a->right->right: RR(a);
    }
}
