#include <cstdlib>
#include <cassert>
#include "bag.h"
#include "node1.h"
using namespace std;
using namespace main_savitch_5;
namespace main_wessels_5
{

bag::bag()
{
    head_ptr = NULL;
    many_nodes = 0;
}

bag::bag(const bag& source)
{
    node *tail_ptr;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;
}

bag::~bag()
{
    list_clear(head_ptr);
    many_nodes = 0;
}

bag::size_type bag::size () const
{
    return many_nodes;
}

bag::size_type bag::count(const value_type& target) const
{
    size_type answer;
    const node *cursor;

    answer = 0;
    cursor = list_search(head_ptr, target);
    while(cursor != NULL)
    {
        ++answer;
        cursor = cursor->link();
        cursor = list_search(cursor, target);
    }
    return answer;
}

bag::value_type bag::grab() const
{
    size_type i;
    const node *cursor;

    assert(size() > 0);
    i = (rand() % size()) + 1;
    cursor = list_locate(head_ptr, i);
    return cursor->data();
}

 void bag::insert(const value_type& entry)
 {
     list_head_insert(head_ptr, entry);
     ++many_nodes;
 }

bag::size_type bag::erase(const value_type& target)
 {
     size_type answer =0;
     node *target_ptr;

     target_ptr = list_search(head_ptr, target);
     while(target_ptr != NULL)
     {
         target_ptr->set_data(head_ptr->data());
         target_ptr = target_ptr->link();
         target_ptr = list_search(target_ptr, target);
         list_head_remove(head_ptr);
         --many_nodes;
         ++answer;
     }
     return answer;
 }

 void bag::operator +=(const bag& addend)
 {
     node *copy_head_ptr;
     node *copy_tail_ptr;

     if(addend.many_nodes > 0)
     {
         list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
         copy_tail_ptr->set_link(head_ptr);
         head_ptr = copy_head_ptr;
         many_nodes += addend.many_nodes;
     }
 }

 void bag::operator -=(const bag & subtrahend)
 {
     node *copy_head_ptr;
     node *copy_tail_ptr;

     if(subtrahend.many_nodes > 0)
     {
         list_copy(subtrahend.head_ptr, copy_head_ptr, copy_tail_ptr);
         for(int i = 1; i <= list_length(copy_head_ptr); i++)
         {
             value_type val = list_locate(copy_head_ptr, i)->data();
             erase_one(val);
         }
     }
 }

 bool bag::erase_one(const value_type& target)
 {
     node *target_ptr;
     target_ptr = list_search(head_ptr, target);
     if(target_ptr == NULL)
        return false;
     target_ptr->set_data(head_ptr->data());
     list_head_remove(head_ptr);
     --many_nodes;
     return true;
 }

 void bag::operator =(const bag& source)
 {
    node *tail_ptr;

    if(this == &source)
        return;

    list_clear(head_ptr);
    many_nodes = 0;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;
 }

 bag operator +(const bag& b1, const bag& b2)
 {
     bag answer;

     answer += b1;
     answer += b2;
     return answer;
 }

 bag operator -(const bag &b1, const bag &b2)
 {
     bag answer;
     answer += b1;

     answer -= b2;
     return answer;
 }


}
