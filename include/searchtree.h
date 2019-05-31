#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include "datastruct.h"
#include "basetree.h"
#include <iostream>

using namespace std;

namespace collections
{
    template <typename T>
    class SearchTree: public BaseTree<T>, public DataStructBasicsFunc<T>
    {
        public:

            SearchTree():BaseTree<T>() {}

            bool is_empty() override
            {
                return this->root == nullptr;
            }

            TreeNode<T>* minimum() override
            {
                TreeNode<T>* node = minimum(this->root);
                return node;
            }

            TreeNode<T>* maximum() override
            {
                TreeNode<T>* node = maximum(this->root);
                return node;
            }



            void insert(T data, int key) override
            {
                TreeNode<T>* new_node = new TreeNode<T>(data);
                new_node->set_key(key);
                if (this->is_empty())
                {
                    this->root = new_node;
                } else
                {
                    TreeNode<T>* current_node = this->root;
                    TreeNode<T>* father = nullptr;
                    while (current_node != nullptr)
                    {
                        father = current_node;
                        if (current_node->get_key() < key)
                        {
                            current_node = current_node->get_right_son();
                        } else
                        {
                            current_node = current_node->get_left_son();
                        }
                    }
                    if (father != nullptr)
                    {
                        if (father->get_key() < key)
                        {
                            father->set_right_son(new_node);
                        } else
                        {
                            father->set_left_son(new_node);
                        }
                        new_node->set_father(father);
                    }
                }
                this->counter++;
            }

            TreeNode<T>* search(int key) override
            {
                TreeNode<T>* current_node = find_node(this->root, key);
                return current_node;
            }

            void del(int key) override
            {
                TreeNode<T>* current_node = find_node(this->root, key);
                if (current_node != nullptr)
                {
                    if (current_node->get_left_son() == nullptr)
                    {
                        this->transplant(current_node, current_node->get_right_son());
                    } else if (current_node->get_right_son() == nullptr)
                    {
                        this->transplant(current_node, current_node->get_left_son());
                    } else
                    {
                        // Need to fixed the code here to make sure the functions runs properly
                        TreeNode<T>* mini = minimum(current_node->get_right_son());
                        if (mini->get_father() != current_node)
                        {
                            TreeNode<T>* mini_left_son = mini->get_left_son();
                            this->transplant(mini, mini->get_right_son());
                            mini->set_right_son(current_node->get_right_son());
                            if (mini_left_son != nullptr)
                            {
                                mini_left_son->set_father(mini);
                            }
                        }
                        this->transplant(current_node, mini);
                        mini->set_left_son(current_node->get_left_son());
                        if (mini->get_left_son() != nullptr) {
                            mini->get_left_son()->set_father(current_node);
                        }
                    }
                    delete current_node;
                    current_node = nullptr;
                    this->counter--;
                }
            }

            void clear() override
            {
                this->priv_clear(this->root);
                this->root = nullptr;
                this->counter = 0;
            }


        private:

            TreeNode<T>* find_node(TreeNode<T>* node, int key)
            {
                TreeNode<T>* current_node = node;
                while (current_node != nullptr && current_node->get_key() != key)
                {
                    if (current_node->get_key() < key)
                    {
                        current_node = current_node->get_right_son();
                    } else
                    {
                        current_node = current_node->get_left_son();
                    }
                }
                return current_node;
            }

            TreeNode<T>* minimum(TreeNode<T>* current_node)
            {
                TreeNode<T>* father = nullptr;
                while (current_node != nullptr)
                {
                    father = current_node;
                    current_node = current_node->get_left_son();
                }
                return father;
            }

            TreeNode<T>* maximum(TreeNode<T>* current_node)
            {
                TreeNode<T>* father = nullptr;
                while (current_node != nullptr)
                {
                    father = current_node;
                    current_node = current_node->get_right_son();
                }
                return father;
            }


    };
}

#endif // SEARCHTREE_H
