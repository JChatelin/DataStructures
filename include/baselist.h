#ifndef BASELIST_H
#define BASELIST_H

#include "listnode.h"
#include "counter.h"

namespace collections
{
    using namespace collections::nodes;

    template <typename T>
    class BaseList : public Counter
    {
        protected:
            ListNode<T>* begin;
            ListNode<T>* end;

            void increment_index(ListNode<T>* current_node)
            {
                // increment all the index form current_node parameter
                while(current_node != nullptr)
                {
                    current_node->set_index(current_node->get_index() + 1);
                    current_node = current_node->get_successor();
                }
            }

            void decrement_index(ListNode<T>* current_node)
            {
                // decrement all the index form current_node parameter
                while(current_node != nullptr)
                {
                    current_node->set_index(current_node->get_index() - 1);
                    current_node = current_node->get_successor();
                }
            }

        public:
            BaseList():Counter()
            {
                this->begin = nullptr;
                this->end = nullptr;
            }

            virtual void push_front(T data) = 0; // Add data at the beginning of the list
            virtual void push_back(T data) = 0; // Add data at the end of the list
    };
}

#endif // BASELIST_H
