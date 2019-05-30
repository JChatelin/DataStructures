#ifndef STACK_H
#define STACK_H

#include "counter.h"
#include <stdexcept>


using namespace std;

namespace collections
{
    template <typename T, int N>
    class Stack: public Counter
    {
        public:
            Stack():Counter() {
                bottom = 0;
                top = 0;
                stack_array = new T[N];
            }

            ~Stack()
            {
                delete[] stack_array;
            }

            bool is_empty()
            {
                return top == 0;
            }

            void push(T data)
            {
                stack_array[top] = data;
                top += 1;
                if (counter < N) {
                    counter += 1;
                }
            }

            T pop()
            {
                if (this->is_empty())
                {
                    throw out_of_range("Pop from an empty stack.");
                } else
                {
                    counter -= 1;
                    top -= 1;
                    return stack_array[top];
                }
            }

        private:
            unsigned int bottom;
            unsigned int top;
            T* stack_array;
    };
}

#endif // STACK_H
