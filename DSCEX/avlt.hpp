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

    node_pointer root = nullptr;
    size_type p_size;

    node_pointer p_search(const T& val)
    {

    }
    
    size_type p_height()
    {

    }


public:
    avlt() {}
    avlt(::std::initializer_list<T> l)
    {
        // ...
    }

    ~avlt() {}

    
    bool empty()
    {

    }

    size_type size()
    {
        return p_size;
    }


    void clear()
    {

    }

    bool search(const T& val)
    {
        return p_search(val);
    }

    void insert(const T& val)
    {

    }

    void remove(const T& val)
    {

    }

}
