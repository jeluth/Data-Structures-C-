//Jackson Wessels HW3 CS 3304
#include "cassert"
#include "sequence.h"
namespace main_wessels
{

sequence::sequence()
{
    used = 0;
    active_index = false;
}

void sequence::start()
{
    if(used > 0)
    {
        current_index = 0;
        active_index = true;
    }

}

void sequence::advance()
{
    assert(active_index);
    if(current_index >= used - 1)
        active_index = false;
    else
        current_index++;

}

void sequence::insert(const value_type& entry)
{
    assert(size() < CAPACITY);
    if(active_index)
    {
        for(int i = used; i > current_index; --i)
            data[i] = data[i - 1];

        data[current_index] = entry;
    }
    else
        {
            data[0] = entry;
            current_index = 0;
            active_index = true;
        }
        used++;
}

void sequence::attach(const value_type& entry)
{
    assert(size() < CAPACITY);
    if(active_index)
    {
        for(int i = used; i > current_index + 1; --i)
            data[i] = data[i - 1];

        ++current_index;
        data[current_index] = entry;
    }
    else if(used > 0)
        {
            data[used - 1] = entry;
            current_index = used - 1;

        }
    else
    {
        data[0] = entry;
        current_index = 0;
        active_index = true;
    }
        used++;
}

void sequence::remove_current()
{
    assert(active_index);
    for(int i = current_index + 1; i < used; ++i)
    {
        data[i-1] = data[i];
    }
    used--;
    if(used == 0)
        active_index = false;
}

sequence::size_type sequence::size() const
{
    return used;
}

bool sequence::is_item() const
{
    if(active_index)
        return true;
    else
        return false;
}

sequence::value_type sequence::current() const
{
    assert(active_index);
    return data[current_index];
}

}
