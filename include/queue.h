#ifndef QUEUE_H
#define QUEUE_H

#include "counter.h"
#include <stdexcept>

using namespace std;

namespace collections
{
    template <typename T, int N>
    class Queue: public Counter
    {
        public:
            Queue():Counter() {
                bottom = 0;
                top = 0;
                queue_array = new T[N];
            }

            ~Queue()
            {
                delete[] queue_array;
            }

            bool is_empty()
            {
                return bottom == top;
            }

            void push(T data)
            {
                queue_array[top] = data;
                // this if statement loop the queue
                if (top == N)
                {
                    top = 0;
                } else
                {
                    top += 1;
                }
                if (counter < N)
                {
                    counter += 1;
                }
            }

            T pop()
            {
                if (this->is_empty())
                {
                    throw out_of_range("Pop from an empty queue.");
                } else {
                    T data = queue_array[bottom];
                    // this if statement loop the queue
                    if (bottom == N)
                    {
                        bottom = 0;
                    } else
                    {
                        bottom +=  1;
                    }
                    counter -= 1;
                    return data;
                }
            }

        private:
            unsigned int bottom;
            unsigned int top;
            T* queue_array;
    };
}

#endif // QUEUE_H
