
#include <algorithm>
#include <cassert>
#include "bag.h"
using namespace std;
namespace main_wessels_5
{

bag::bag(size_type initial_capacity)
{
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
}

bag::bag(const bag& source)
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    copy(source.data, source.data + used, data);
}

bag::size_type bag::size () const
{
    return used;
}

bag::~bag()
{
    delete [] data;
}

void bag::reserve(size_type new_capacity)
{
    value_type *larger_array;

    if(new_capacity == capacity)
        return;

    if(new_capacity < used)
        new_capacity = used;

    larger_array = new value_type[new_capacity];
    copy(data, data + used, larger_array);
    delete [] data;
    data = larger_array;
    capacity = new_capacity;
}

bag::size_type bag::count(const value_type& target) const
{
    size_type answer;
    size_type i;
    answer = 0;
    for (i = 0 ; i < used; ++i)
        if (target == data[i])
        ++answer;
    return answer;
}

 void bag::insert(const value_type& entry)
 {
     if(used == capacity)
        reserve(used + (capacity * .1));
     data[used] = entry;
     ++used;
 }

 void bag::operator +=(const bag& addend)
 {
     if (used + addend.used > capacity)
        reserve(used + addend.used);

     copy(addend.data, addend.data + addend.used, data + used);
     used += addend.used;
 }

 bool bag::erase_one(const value_type& target)
 {
     size_type index;

     index = 0;
     while ((index < used) && (data[index] != target))
        ++index;

     if (index == used)
        return false;

     --used;
     data[index] = data[used];
     return true;
 }

 void bag::operator =(const bag& source)
 {
     value_type *new_data;

     //check for self-assignment
     if(this == &source)
        return;

     if(capacity != source.capacity)
     {
         new_data = new value_type[source.capacity];
         delete [] data;
         data = new_data;
         capacity = source.capacity;
     }

     used = source.used;
     copy(source.data, source.data + used, data);
 }

 bag operator +(const bag& b1, const bag& b2)
 {
     bag answer(b1.size() + b2.size());

     answer += b1;
     answer += b2;

     return answer;
 }


}
