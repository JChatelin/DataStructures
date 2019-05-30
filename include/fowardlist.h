#ifndef FOWARDLIST_H
#define FOWARDLIST_H

#include "datastruct.h"
#include "baselist.h"

namespace collections
{
    template <typename T>
    class FowardList: public BaseList<T>, public DataStructBasicsFunc<T>
    {
        public:
            FowardList():BaseList<T>() {}

            FowardList(FowardList<T>& obj)
            {
                this->begin = obj.begin;
                this->end = obj.end;
            }

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
                    this->end = new_node;
                }
                this->counter++;
            }

            ListNode<T>* pop()
            {
            // Return a pointer to the first node of the list
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
                    }
                    this->decrement_index(this->begin);
                    current_node->set_successor(nullptr);
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
                    if(index <= this->begin->get_index())
                    {
                        new_node->set_index(this->begin->get_index());
                        new_node->set_successor(this->begin);
                        this->increment_index(this->begin);
                        this->begin = new_node;

                    } else if (index >= this->end->get_index())
                    {
                        new_node->set_index(this->counter);
                        this->end->set_successor(new_node);
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
                        new_node->set_successor(current_node);
                        this->increment_index(current_node);
                    }
                }
                this->counter++;
            }

            void del(int index) override
            {
                ListNode<T>* current_node = this->begin;
                ListNode<T>* predecessor = nullptr;
                while (current_node != nullptr && current_node->get_index() < index)
                {
                    predecessor = current_node;
                    current_node = current_node->get_successor();
                }
                if (current_node != nullptr)
                {
                    if (predecessor != nullptr)
                    {
                        predecessor->set_successor(current_node->get_successor());
                    }
                    this->decrement_index(current_node->get_successor());
                    current_node->set_successor(nullptr);
                    delete current_node;
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
                    current_node->set_successor(nullptr);
                    delete current_node;
                    this->counter--;
                }
            }

    };
}

#endif // FOWARDLIST_H
