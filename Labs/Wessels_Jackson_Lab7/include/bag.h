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
            static const size_type DEFAULT_CAPACITY = 100;
            //constructors
            bag(size_type initial_capacity = DEFAULT_CAPACITY);
            bag(const bag& source);
            ~bag();
            //member functions
            void reserve(size_type new_capacity);
            void insert(const value_type& entry);
            bool erase_one(const value_type& target);
            size_type erase(const value_type& target);
            void operator +=(const bag& addend);
            void operator =(const bag& source);
            //constant member functions
            size_type size() const;
            size_type count(const value_type& target) const;
            size_type getCapacity() const {return capacity;}
        private:
            value_type *data;
            size_type used;
            size_type capacity;
    };

    bag operator +(const bag& b1, const bag& b2);
}

#endif // BAG_H
