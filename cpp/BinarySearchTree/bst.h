#include <memory>

class Node {
public:
    int element;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> parent;
public:
    Node(int element, std::shared_ptr<Node> parent) {
        this->element = element;
        this->parent = parent;
    };
};

class binarySearchTree {
private:
    int m_size = 0;
    std::shared_ptr<Node> m_root;
public:
    binarySearchTree() : m_size(0), m_root(nullptr) {};
    ~binarySearchTree() = default;

    int sizeOfTree() { return m_size ; }

    bool isEmptyTree() { return m_size == 0; }

    void clearTree() {};

    void addToTree(int element);

    void removeFromTree();

    std::shared_ptr<Node> listPreOrderTreeComplex(std::shared_ptr<Node> node);
    std::shared_ptr<Node> listInOrderTreeComplex(std::shared_ptr<Node>& node);
    void listPreOrderTree(std::shared_ptr<Node> node);
    void listInOrderTree(std::shared_ptr<Node>& node);
    void listPostOrderTree(std::shared_ptr<Node>& node);
    void listingTree();

    bool containsInTree() const { return false; }

    int compareOfTwo(const int& e1, const int& e2);

    void elementNotNullCheck(int element);
};
