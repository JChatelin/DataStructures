#ifndef COUNTER_H
#define COUNTER_H

namespace collections
{
    class Counter
    {
        public:
            Counter()
            {
                counter = 0;
            }

            inline unsigned int count()
            {
                return counter;
            }

        protected:
            unsigned int counter;
    };
}

#endif // COUNTER_H
