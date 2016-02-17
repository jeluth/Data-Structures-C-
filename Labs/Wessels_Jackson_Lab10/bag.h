#ifndef MAIN_WESSELS_BAG_H
#define MAIN_WESSELS_BAG_H
#include <cstdlib>
#include "node1.h"
using namespace main_savitch_5;
namespace main_wessels_5
{
    class bag
    {
        public:
            //typedefs and member constants
            typedef std::size_t size_type;
            typedef node::value_type value_type;
            //constructors
            bag();
            bag(const bag& source);
            ~bag();
            //member functions
            void insert(const value_type& entry);
            bool erase_one(const value_type& target);
            size_type erase(const value_type& target);
            void operator +=(const bag& addend);
            void operator -=(const bag &subtrahend);
            void operator =(const bag& source);
            //constant member functions
            size_type size() const;
            size_type count(const value_type& target) const;
            value_type grab() const;
        private:
           node *head_ptr;
           size_type many_nodes;
    };

    bag operator +(const bag& b1, const bag& b2);
    bag operator -(const bag & b1, const bag & b2);
}

#endif // BAG_H
