#include <memory>
#include <cstddef>
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
        val(val), height(0), left(left), right(right) {}

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
    using node_pointer = ::std::shared_ptr<avltnode>;
    using const_node_pointer = ::std::shared_ptr<const avltnode>;
    using node_reference = avltnode&;
    using const_node_reference = const avltnode&;

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

    size_type p_height()
    {
        return p_root ? p_root->height : 0;
    }

    void left_rotation(node_pointer np)
    {

    }

    void right_rotation(node_pointer np)
    {

    }

    void left_right(node_pointer np)
    {

    }

    void right_left(node_pointer np)
    {

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
        if (!p_root)
        {
            p_root = ::std::make_shared<avltnode>(val);
            return;
        }

        // ...
    }

    void remove(const T& val)
    {

    }
};
