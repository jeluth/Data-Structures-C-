#ifndef MAIN_WESSELS_BAG_H
#define MAIN_WESSELS_BAG_H
#include <cstdlib>

namespace main_wessels_5
{
    class bag
    {
        public:
            //typedefs and member constants
            typedef int value_type;
            typedef std::size_t size_type;
            static const size_type CAPACITY = 30000;
            //constructors
            bag();
            //member functions
            void insert(const value_type& entry);
            bool erase_one(const value_type& target);
            size_type erase(const value_type& target);
            void operator +=(const bag& addend);
            //constant member functions
            size_type size() const;
            size_type count(const value_type& target) const;
        private:
            value_type data[CAPACITY];
            size_type used;
    };

    bag operator +(const bag& b1, const bag& b2);
}

#endif // BAG_H
