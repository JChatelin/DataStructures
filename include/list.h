#ifndef LIST_H
#define LIST_H

#include "datastruct.h"
#include "baselist.h"

namespace collections
{
    template <typename T>
    class List : public BaseList<T>, public DataStructBasicsFunc<T>
    {
        public:
            List():BaseList<T>() {}

            bool is_empty() override
            {
                return this->begin == nullptr;
            }

            void push_front(T data) override
            {
                ListNode<T>* new_node = new ListNode<T>(data);
                if (this->is_empty())
                {
                    new_node->set_index(this->counter);
                    this->begin = new_node;
                    this->end = this->begin;
                } else
                {
                    new_node->set_index(this->begin->get_index());
                    new_node->set_successor(this->begin);
                    this->begin->set_predecessor(new_node);
                    this->increment_index(this->begin);
                    this->begin = new_node;
                }
                this->counter++;
            }

            void push_back(T data) override
            {
                ListNode<T>* new_node = new ListNode<T>(data);
                new_node->set_index(this->counter);
                if (this->is_empty())
                {
                    this->begin = new_node;
                    this->end = this->begin;
                } else
                {
                    this->end->set_successor(new_node);
                    new_node->set_predecessor(this->end);
                    this->end = new_node;
                }
                this->counter++;
            }

            ListNode<T>* pop_front()
            {
                // return a pointer to the first element of the list
                if(this->is_empty())
                {
                    return nullptr;
                } else
                {
                    ListNode<T>* current_node = this->begin;
                    this->begin = current_node->get_successor();
                    if (this->begin == nullptr)
                    {
                        this->end = nullptr;
                    } else
                    {
                        this->begin->set_predecessor(nullptr);
                    }
                    this->decrement_index(this->begin);
                    current_node->set_successor(nullptr);
                    this->counter--;
                    return current_node;
                }
            }

            ListNode<T>* pop_back()
            {
                // return a pointer to the last element of the list
                if(this->is_empty())
                {
                    return nullptr;
                } else
                {
                    ListNode<T>* current_node = this->end;
                    this->end = current_node->get_predecessor();
                    if (this->end == nullptr)
                    {
                        this->begin = nullptr;
                    } else
                    {
                        this->end->set_successor(nullptr);
                    }
                    current_node->set_predecessor(nullptr);
                    this->counter--;
                    return current_node;
                }
            }

            void insert(T data, int index) override
            {
                ListNode<T>* new_node = new ListNode<T>(data);
                if (this->is_empty())
                {
                    new_node->set_index(this->counter);
                    this->begin = new_node;
                    this->end = this->begin;
                } else
                {
                    // make sure the data is added anyway
                    if(index <= this->begin->get_index())
                    {
                        new_node->set_index(this->begin->get_index());
                        new_node->set_successor(this->begin);
                        this->begin->set_predecessor(new_node);
                        this->increment_index(this->begin);
                        this->begin = new_node;

                    } else if (index >= this->end->get_index())
                    {
                        new_node->set_index(this->counter);
                        this->end->set_successor(new_node);
                        new_node->set_predecessor(this->end);
                        this->end = new_node;
                    } else
                    {
                        ListNode<T>* current_node = this->begin;
                        ListNode<T>* predecessor = nullptr;
                        while (current_node->get_index() < index)
                        {
                            predecessor = current_node;
                            current_node = current_node->get_successor();
                        }
                        new_node->set_index(current_node->get_index());
                        predecessor->set_successor(new_node);
                        new_node->set_predecessor(predecessor);
                        new_node->set_successor(current_node);
                        current_node->set_predecessor(new_node);
                        this->increment_index(current_node);
                    }
                }
                this->counter++;
            }

            void del(int index) override
            {
                ListNode<T>* current_node = this->begin;
                while (current_node != nullptr && current_node->get_index() < index)
                {
                    current_node = current_node->get_successor();
                }
                if (current_node != nullptr)
                {
                    ListNode<T>* successor = current_node->get_successor();
                    ListNode<T>* predecessor = current_node->get_predecessor();
                    if (predecessor != nullptr)
                    {
                        predecessor->set_successor(successor);
                    }
                    if (successor != nullptr)
                    {
                        successor->set_predecessor(predecessor);
                    }
                    this->decrement_index(current_node->get_successor());
                    current_node->set_successor(nullptr);
                    delete current_node;
                    current_node = nullptr;
                    this->counter--;
                }
            }

            void clear() override
            {
                ListNode<T>* current_node = nullptr;
                while (!this->is_empty())
                {
                    current_node = this->begin;
                    this->begin = this->begin->get_successor();
                    if (this->begin != nullptr)
                    {
                        this->begin->set_predecessor(nullptr);
                    }else
                    {
                        this->end = nullptr;
                    }
                    current_node->set_successor(nullptr);
                    delete current_node;
                    current_node = nullptr;
                    this->counter--;
                }
            }

    };
}

#endif // LIST_H
