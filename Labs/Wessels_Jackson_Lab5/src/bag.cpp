
#include <algorithm>
#include <cassert>
#include "bag.h"
using namespace std;
namespace main_wessels_5
{

bag::bag()
{
    used = 0;

}

bag::size_type bag::size () const
{
    return used;
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
     assert(size() < CAPACITY);
     data[used] = entry;
     ++used;
 }

 void bag::operator +=(const bag& addend)
 {
     assert(size() + addend.size() <= CAPACITY);

     copy(addend.data, addend.data + used, data + used);
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

 bag operator +(const bag& b1, const bag& b2)
 {
     bag answer;
     assert(b1.size() + b2.size() <= bag::CAPACITY);

     answer += b1;
     answer += b2;

     return answer;
 }
}
