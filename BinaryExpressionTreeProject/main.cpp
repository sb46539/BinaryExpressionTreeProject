#include <iostream>
#include <fstream>
#include "BinaryExpressionTree.h"

int main() {
    binaryExpressionTree exprTree;
    std::ifstream infile("RpnData.txt");
    std::ofstream outfile("Results.txt");

    std::string postfix;
    while (getline(infile, postfix)) {
        try {
            exprTree.buildTree(postfix);
            double result = exprTree.evaluateExpressionTree();
            outfile << "Expression: " << postfix << " = " << result << "\n";
            exprTree.destroyTree();
        }
        catch (const std::exception& e) {
            outfile << "Error evaluating expression: " << postfix << " - " << e.what() << "\n";
        }
    }

    infile.close();
    outfile.close();
    std::cout << "Results written to Results.txt\n";
    return 0;
}
