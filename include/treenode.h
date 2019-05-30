#ifndef TREENODE_H
#define TREENODE_H

namespace collections
{
    namespace nodes
    {
        template <typename T>
        class TreeNode
        {
            public:
                TreeNode()
                {
                    father = nullptr;
                    left_son = nullptr;
                    right_son = nullptr;
                }

                TreeNode(T data): TreeNode()
                {
                    this->data = data;
                }

                TreeNode(T data, int key):TreeNode(data)
                {
                    this->key = key;
                }

                T get_data()
                {
                    return data;
                }

                void set_data(T data)
                {
                    this->data = data;
                }

                int get_key()
                {
                    return key;
                }

                void set_key(int key)
                {
                    this->key = key;
                }

                TreeNode<T>* get_father()
                {
                    return father;
                }

                void set_father(TreeNode<T>* father)
                {
                    this->father = father;
                }

                TreeNode<T>* get_right_son()
                {
                    return right_son;
                }

                void set_right_son(TreeNode<T>* right_son)
                {
                    this->right_son = right_son;
                }

                TreeNode<T>* get_left_son()
                {
                    return left_son;
                }

                void set_left_son(TreeNode<T>* left_son)
                {
                    this->left_son = left_son;
                }

            private:
                TreeNode<T>* father;
                TreeNode<T>* left_son;
                TreeNode<T>* right_son;
                T data;
                int key;
        };
    }
}

#endif // TREENODE_H
