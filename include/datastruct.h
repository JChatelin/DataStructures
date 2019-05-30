#ifndef DATASTRUCT_H
#define DATASTRUCT_H

namespace collections
{
    template <typename T>
    class DataStructBasicsFunc
    {
        public:
            virtual bool is_empty() = 0; // check if the data structure is empty or not
            virtual void insert(T data, int keyOrIndex) = 0; // Add the data at the specified index or with the specified key
            virtual void clear() = 0; // delete all the data in the data structure
            virtual void del(int keyOrIndex) = 0; // delete the data at the specified index or with the specified key
    };
}

#endif // DATASTRUCT_H
