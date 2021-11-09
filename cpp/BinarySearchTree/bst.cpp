/* System */
#include <iostream>

/* Local */
#include "bst.h"

void binarySearchTree::addToTree(int element) 
{
    elementNotNullCheck(element);
    //添加首节点
    if (this->m_root == nullptr) {
        this->m_root = std::make_shared<Node>(element, nullptr);
        this->m_size++;
        return;
    }

    std::shared_ptr<Node> node = this->m_root;
    std::shared_ptr<Node> parent = node;
    int cmp;
    while (node != nullptr) {
        //遍历比较插入值和目标值
        cmp = compareOfTwo(element, node->element);
        //设置目标值为parent
        parent = node;

        if (cmp > 0) {
            //插入值大于目标值，继续遍历右子树
            node = node->right;
        } else if (cmp < 0) {
            //插入值小于目标值，继续遍历左子树
            node = node->left;
        } else {
            // 插入值和目标值相等，直接返回
            return;
        }
    }
    //到此node == nullptr,证明已经找到要插入的为止

    //创建一个node，调用Node()方法
    std::shared_ptr<Node> newNode = std::make_shared<Node>(element, parent);
    //cmp保存了新节点值和parent的比较结果，直接可以用
    if (cmp > 0) {
        //新节点值大于parent的值，插入到右侧
        parent->right = newNode;
    } else {
        //新节点值小于parent的值，插入到左侧
        parent->left = newNode;
    }
    //增加计数值
    this->m_size++;
}

void binarySearchTree::elementNotNullCheck(int element) {
    if (element == 0) {
        throw std::invalid_argument("Invalid value.");
    }
}

int binarySearchTree::compareOfTwo(const int& e1, const int& e2)
{
    if (e1 < e2) {
        return -1;
    } else if (e1 > e2) {
        return 1;
    }
    return 0;
}

std::shared_ptr<Node> binarySearchTree::listPreOrderTreeComplex(std::shared_ptr<Node> node)
{
    if (node != nullptr) {
        std::cout << node->element << " ";
        //先遍历左子树
        std::shared_ptr<Node> ret = this->listPreOrderTreeComplex(node->left);
        // 如果返回nullptr,证明左子树已经遍历完成
        if (ret == nullptr) {
            //左子树遍历完，再遍历右子树
            ret = this->listPreOrderTreeComplex(node->right);
        }
        return ret;
    }

    return nullptr;
}

std::shared_ptr<Node> binarySearchTree::listInOrderTreeComplex(std::shared_ptr<Node>& node)
{
    if (node != nullptr) {
        //先遍历左子树
        std::shared_ptr<Node> ret = this->listInOrderTreeComplex(node->left);
        //打印当前node
        std::cout << node->element << " ";
        // 如果返回nullptr,则证明node的left节点为nullptr
        if (ret == nullptr) {
            return node; //直接返回当前node
        }

        //如果当前node和返回的node的parent相同，那么遍历右子树
        if (node.get() == ret->parent.get()) {
            //遍历右子树
            ret = this->listInOrderTreeComplex(node->right);
        }
        return node;
    }

    return nullptr;
}

void binarySearchTree::listPreOrderTree(std::shared_ptr<Node> node)
{
    if (node != nullptr) {
        std::cout << node->element << " ";
        //先遍历左子树
        this->listPreOrderTree(node->left);
       
        //左子树遍历完，再遍历右子树
        this->listPreOrderTree(node->right);
    }
}

void binarySearchTree::listInOrderTree(std::shared_ptr<Node>& node)
{
    if (node != nullptr) {
        //先遍历左子树
        this->listInOrderTree(node->left);
        //打印当前node
        std::cout << node->element << " ";
        //遍历右子树
        this->listInOrderTree(node->right);
    }
}

void binarySearchTree::listPostOrderTree(std::shared_ptr<Node>& node)
{
    if (node != nullptr) {
        //先遍历左子树
        this->listPostOrderTree(node->left);
        //再遍历右子树
        this->listPostOrderTree(node->right);

        std::cout << node->element << " ";
    }
}

void binarySearchTree::listingTree() {
    this->listPreOrderTree(m_root);
    std::cout << std::endl;
    this->listInOrderTree(m_root);
    std::cout << std::endl;
    this->listPostOrderTree(m_root);
};
