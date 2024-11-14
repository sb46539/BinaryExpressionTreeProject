#ifndef BINARY_EXPRESSION_TREE_H
#define BINARY_EXPRESSION_TREE_H

#include "binaryTree.h"
#include <string>

class binaryExpressionTree : public binaryTreeType<std::string> {
public:
    void buildTree(const std::string& postfix);
    double evaluateExpressionTree();

private:
    double evaluate(nodeType<std::string>* p) const;

    bool search(const std::string&) const override { return false; }
    void insert(const std::string&) override {}
    void deleteNode(const std::string&) override {}
};

#endif
