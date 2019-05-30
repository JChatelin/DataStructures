#ifndef LISTNODE_H
#define LISTNODE_H

namespace collections
{
    namespace nodes
    {
        template <typename T>
        class ListNode
        {
            public:
                ListNode()
                {
                    successor = nullptr;
                    predecessor = nullptr;
                }

                ListNode(T data):ListNode()
                {
                    this->data = data;
                }

                T get_data()
                {
                    return data;
                }

                void set_data(T data)
                {
                    this->data = data;
                }

                int get_index()
                {
                    return index;
                }

                void set_index(int index)
                {
                    this->index = index;
                }

                ListNode<T>* get_predecessor()
                {
                    return predecessor;
                }

                void set_predecessor(ListNode<T>* predecessor)
                {
                    this->predecessor = predecessor;
                }

                ListNode<T>* get_successor()
                {
                    return successor;
                }

                void set_successor(ListNode<T>* successor)
                {
                    this->successor = successor;
                }


            private:
                ListNode<T>* successor;
                ListNode<T>* predecessor;
                T data;
                int index;
        };
    }
}

#endif // LISTNODE_H
