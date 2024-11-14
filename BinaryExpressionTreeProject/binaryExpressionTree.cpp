#include "BinaryExpressionTree.h"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

void binaryExpressionTree::buildTree(const std::string& postfix) {
    destroyTree();
    std::stack<nodeType<std::string>*> nodeStack;
    std::istringstream tokens(postfix);
    std::string token;

    while (tokens >> token) {
        nodeType<std::string>* newNode = new nodeType<std::string>;
        newNode->lLink = nullptr;
        newNode->rLink = nullptr;

        if (isdigit(token[0])) {
            newNode->info = token;
            nodeStack.push(newNode);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            newNode->info = token;

            if (nodeStack.empty()) {
                throw std::invalid_argument("Error – Stack is empty");
            }
            newNode->rLink = nodeStack.top();
            nodeStack.pop();

            if (nodeStack.empty()) {
                throw std::invalid_argument("Error – Stack is empty");
            }
            newNode->lLink = nodeStack.top();
            nodeStack.pop();

            nodeStack.push(newNode);
        }
        else {
            throw std::invalid_argument("Error – unsupported token");
        }
    }

    if (!nodeStack.empty()) {
        root = nodeStack.top();
        nodeStack.pop();
        if (!nodeStack.empty()) {
            throw std::invalid_argument("Error");
        }
    }
    else {
        root = nullptr;
        throw std::invalid_argument("Error – Stack is empty");
    }
}

double binaryExpressionTree::evaluateExpressionTree() {
    if (root == nullptr) throw std::runtime_error("Empty tree");
    return evaluate(root);
}

double binaryExpressionTree::evaluate(nodeType<std::string>* p) const {
    if (isdigit(p->info[0])) {
        return std::stod(p->info);
    }
    else {
        double left = evaluate(p->lLink);
        double right = evaluate(p->rLink);
        if (p->info == "+") return left + right;
        else if (p->info == "-") return left - right;
        else if (p->info == "*") return left * right;
        else if (p->info == "/") return left / right;
        else throw std::invalid_argument("Unsupported operator");
    }
}
