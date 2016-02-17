#ifndef MULTISET_H
#define MULTISET_H

namespace wessels_main_lab6
{
    class multiset
    {
        public:
            multiset();
            value_type;
            size_type;
            size_type count(const value_type& target) const;
            size_type erase(const value_type& target);
            size_type size() const;
            iterator insert(const value_type& entry);
        protected:
        private:
    };
}
#endif // MULTISET_H
