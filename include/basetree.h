#ifndef BASETREE_H
#define BASETREE_H

#include "treenode.h"
#include "counter.h"

namespace collections
{
    template <typename T>
    class BaseTree : public Counter
    {
        public:
            BaseTree(): Counter(), root(nullptr) {}
            virtual TreeNode<T>* minimum() = 0;
            virtual TreeNode<T>* maximum() = 0;
            virtual TreeNode<T>* search(int key) = 0;

        protected:
            TreeNode<T>* root;

            void priv_clear(TreeNode<T>* current_node)
            {
            // this function delete all the node from currentNode
                if (current_node != nullptr)
                {
                    priv_clear(current_node->get_left_son());
                    priv_clear(current_node->get_right_son());
                    current_node->set_left_son(nullptr);
                    current_node->set_right_son(nullptr);
                    delete current_node;
                }
            }

            void transplant(TreeNode<T>* current_node, TreeNode<T>* son)
            {
                // This attach son parameter with the current_node parameter's father
                TreeNode<T>* father = current_node->get_father();
                if (father == nullptr)
                {
                    root = son;
                } else if (father->get_left_son() == current_node)
                {
                    father->set_left_son(son);
                } else {
                    father->set_right_son(son);
                }
                if (son != nullptr)
                {
                    son->set_father(father);
                }
            }
    };
}

#endif // BASETREE_H
