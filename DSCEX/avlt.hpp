#include <memory>
#include <cstddef>
#include <algorithm>
#include <initializer_list>


template <typename T>
class avltnode
{
public:
    T val;
    int height;
    ::std::shared_ptr<avltnode> left;
    ::std::shared_ptr<avltnode> right;

    avltnode(T val, ::std::shared_ptr<avltnode> left = nullptr, ::std::shared_ptr<avltnode> = nullptr):
        val(val), height(1), left(left), right(right) {}

    int bf()
    {
        return (left ? left->height : 0) - (right ? right->height : 0);
    }
};


template <typename T>
class avlt
{
public:
    using value_type = T;
    using size_type = int;
    using reference = T&;
    using const_reference = const T&;
    using pointer = ::std::shared_ptr<T>;
    using const_pointer = ::std::shared_ptr<const T>;


private:
    using node_type = avltnode<T>;
    using node_pointer = ::std::shared_ptr<node_type>;
    using const_node_pointer = ::std::shared_ptr<const node_type>;
    using node_reference = node_type&;
    using const_node_reference = const node_type&;

    node_pointer p_root = nullptr;
    size_type p_size = 0;

    node_pointer p_search(const T& val)
    {
        auto res = p_root;
        while (res)
        {
            if (res->val == val) return res;
            else res = (res->val < val) ? res->right : res->left;
        }
        return res;
    }

    node_pointer p_insert(node_pointer& root, const T& val)
    {
        if (root == nullptr) root = ::std::make_shared<node_type>(val);
        else if (val < root->val)
        {
            root->left = p_insert(root->left, val);
            if (root->bf() == 2) root = (val < root->left->val) ? left_left(root) : left_right(root);
        }
        else if (val > root->val)
        {
            root->right = p_insert(root->right, val);
            if (root->bf() == -2) root = (val > root->right->val) ? right_right(root) : right_left(root);
        }
        else return root;

        root->height = std::max(p_height(root->left), p_height(root->right)) + 1;

        return root;
    }

    size_type p_height(node_pointer np)
    {
        return np ? np->height : 0;
    }

    node_pointer left_left(node_pointer k2)
    {
        auto k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;

        k2->height = ::std::max(p_height(k2->left), p_height(k2->right)) + 1;
        k1->height = ::std::max(p_height(k1->left), k2->height) + 1;

        return k1;
    }

    node_pointer right_right(node_pointer k1)
    {
        auto k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;

        k1->height = ::std::max(p_height(k1->left), p_height(k1->right)) + 1;
        k2->height = ::std::max(p_height(k2->right), k1->height) + 1;

        return k2;
    }

    node_pointer left_right(node_pointer k3)
    {
        k3->left = right_right(k3->left);
        return left_left(k3);
    }

    node_pointer right_left(node_pointer k1)
    {
        k1->right = left_left(k1->right);
        return right_right(k1);
    }


public:
    avlt() {}
    avlt(::std::initializer_list<T> l)
    {
        for (auto &v : l) insert(v);
    }

    ~avlt() {}


    bool empty()
    {
        return p_root;
    }

    size_type size()
    {
        return p_size;
    }


    void clear()
    {
        p_root = nullptr;
    }

    bool search(const T& val)
    {
        return p_search(val);
    }

    void insert(const T& val)
    {
        p_insert(p_root, val);
    }

    void remove(const T& val)
    {
        // ...
    }
};
