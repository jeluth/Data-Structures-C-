//Jackson Wessels HW3 CS 3304
//FILE:sequence.h
//CLASS PROVIDED: sequence
//
//TYPEDEF AND MEMBER CONSTANTS for the sequence class:
//    typedef ____ value_type
//        sequence::value_type is the data type of the items in the sequence.
//            It may be any of the C++ built-in types(int,char,etc.) or a class with a default constructor,
//            an assignment operator, and a copy constructor
//    typedef ____ size_type
//        sequence::size_type is the data type of any variable that keeps track of how many items are in a sequence.sequence()
//
//    static const size_type CAPACITY = ______
//        sequence::CAPACITY is the maximum number of items that a sequqnce can hold.
//
//CONSTRUCTOR for the sequence class:
//    sequence()
//        Postcondition: the sequence has been initiated as an empty sequence.sequence()
//
//MODIFICATION MEMBER FUNCTIONS for the sequence class:
//    void start()
//        Postcondition: The first item in the sequence becomes the current item (but if the sequence is empty, then there is no
//            current item).
//
//    void Advance()
//        Precondition: is_item returns true.
//        Postcondition: If the current item was already the last item in the sequence, then there is no longer any current item. Otherwise,
//            the new item is the item immediately after the original current item.
//
//    void insert(const value_type& entry)
//        Precondition: size() < CAPACITY
//        Postcondition: A new copy of entry has been inserted in the sequence before the current item. If there was no current item, then the
//            new entry has been inserted at the front. In either case, the new item is now the current item in the sequence.
//
//    void attach(const value_type& entry)
//        Precondition: size() < CAPACITY
//        Postcondition: A new copy of entry has been inserted in the sequence after the current item. If there was no current item, then the new entry
//            has been attached to the end of the sequence. In either case, the new item is now the current item of the sequence.
//
//    void remove_current()
//        Precondition: is_item returns true.
//        Postcondition: The current item has been removed from the sequence, and the item after this(if there is one) is now the current item.
//
//CONSTANT MEMBER FUNCTIONS for the sequence class:
//    size_type size() const
//        Postcondition: The return value is the number of items in the sequence.
//
//    bool is_item() const
//        Postcondition: A true return value indicates that there is a valid "current" item that may be retrieved by the current member function (listed below)
//            A false return value indicates that there is no valid current item.
//
//    value_type current() const
//        Precondition: is_item() returns true.
//        Postcondition: The item returned is the current item in the sequence.
//
//VALUE SEMANTICS for the sequence class:
//        Assignments and the copy constructor may be used with the sequence objects.


#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstdlib>
using namespace std;
namespace main_wessels
{

    class sequence
    {
        public:
            //TYPEDEFS AND MEMBER CONSTANTS
            typedef double value_type;
            typedef size_t size_type;
            static const size_type CAPACITY = 30;
            //CONSTRUCTOR
            sequence();
            //MODIFICATION MEMBER FUNCTIONS
            void start();
            void advance();
            void insert(const value_type& entry);
            void attach(const value_type& entry);
            void remove_current();
            //CONSTANT MEMBER FUNCTIONS
            size_type size() const;
            bool is_item() const;
            value_type current() const;
        protected:
        private:
            value_type data[CAPACITY];
            size_type used;
            size_type current_index;
            bool active_index;
    };

}
#endif // SEQUENCE_H
