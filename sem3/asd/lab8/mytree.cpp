#include "mytree.h"

#include <QLineEdit>

MyTreeNode::MyTreeNode(int value, MyTreeNode *parent) : value_(value), parent_(parent), left_(nullptr), right_(nullptr) {}

MyTreeNode::~MyTreeNode() {
    if (left_)  {
        delete left_;
    }

    if (right_) {
        delete right_;
    }

    value_ = 0;
}

int MyTreeNode::getValue() const {
    return value_;
}

MyTreeNode *MyTreeNode::getLeftSon() const {
    return left_;
}

MyTreeNode *MyTreeNode::getRightSon() const {
    return right_;
}

MyTreeNode *MyTreeNode::getParent() const {
    return parent_;
}

void MyTreeNode::toSubtree(int value) {
    if (value < value_) {
        toLeftSubTree(value);
    } else if (value > value_) {
        toRightSubTree(value);
    }
}

void MyTreeNode::toRightSubTree(int value) {
    if (right_ == nullptr) {
        right_ = new MyTreeNode(value, this);
    } else {
        right_->toSubtree(value);
    }
}

void MyTreeNode::toLeftSubTree(int value) {
    if (left_ == nullptr) {
        left_ = new MyTreeNode(value, this);
    } else {
        left_->toSubtree(value);
    }
}

void MyTreeNode::postorderTraversal(QLineEdit* lineEdit) {
    if (left_ != nullptr) {
        left_->postorderTraversal(lineEdit);
    }

    if (right_ != nullptr) {
        right_->postorderTraversal(lineEdit);
    }

    lineEdit->setText(lineEdit->text() + ' ' + QString::number(value_));
}

MyTreeNode* MyTreeNode::getNode(int value) {
    if (value_ == value) {
        return this;
    }

    if (left_ == nullptr && right_ == nullptr) {
        return nullptr;
    }

    MyTreeNode* result = nullptr;
    if (right_ != nullptr) {
        result = right_->getNode(value);
    }

    if (result == nullptr && left_ != nullptr) {
        result = left_->getNode(value);
    }

    return result;
}

MyTreeNode* MyTreeNode::thirdSmallest() {
    if (left_ == nullptr) {
        if (right_ == nullptr) {
            return nullptr;
        }

        if (right_->getLeftSon() == nullptr) {
            return right_->getRightSon();
        }

        return right_;
    }

    if (left_->getLeftSon() == nullptr) {
        if (left_->getLeftSon() == nullptr || left_->getRightSon() == nullptr) {
            return right_;
        }

        if (left_->getRightSon() == nullptr) {
            return nullptr;
        }

        if (value_ > left_->getRightSon()->getValue()) {
            return this;
        } else {
            return left_->getRightSon();
        }
    }

    MyTreeNode* current = left_->getLeftSon();

    while (current->getLeftSon() != nullptr) {
        current = current->getLeftSon();
    }

    return current->getParent()->getParent();
}
