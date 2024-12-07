#ifndef MYTREE_H
#define MYTREE_H

#include <QLineEdit>


class MyTreeNode {
public:
    MyTreeNode(int value, MyTreeNode* parent);
    ~MyTreeNode();

    int getValue() const;
    MyTreeNode* getLeftSon() const;
    MyTreeNode* getRightSon() const;
    MyTreeNode* getParent() const;

    void toSubtree(int value);
    void toRightSubTree(int value);
    void toLeftSubTree(int value);
    void postorderTraversal(QLineEdit* lineEdit);
    MyTreeNode* getNode(int value);
    MyTreeNode* thirdSmallest();

private:
    int value_;
    MyTreeNode* parent_;
    MyTreeNode* left_;
    MyTreeNode* right_;
};

#endif
