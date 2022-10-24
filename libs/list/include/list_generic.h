/**
**********************************************************************************************************************************************************************************************************************************
* @file:	list_generic.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	03/08/2022 21:45:55
* @brief:	class List_generic
**********************************************************************************************************************************************************************************************************************************
**/

#ifndef __LISTGENERIC_H__
#define __LISTGENERIC_H__

#include "list.h"
#include <stdio.h>

template <class T>
class ListGeneric
{
public:
    ListGeneric()
    {
        list_ = List();
    }

    ~ListGeneric()
    {
        if (list_.size() > 0)
            clean();
    }

    ListGeneric<T> &operator=(const ListGeneric<T> &other)
    {
        list_.clean();
        list_ = List();

        for (int i = 0; i < other.size(); i++)
        {
            if (other.at(i) != nullptr)
                insert(new T(*other.at(i)));
        }

        return *this;
    }

    bool isEmpty() const
    {
        return list_.isEmpty();
    }

    int size() const
    {
        return list_.size();
    }

    T *first() const
    {
        if (!isEmpty())
            return (T *)list_.first();
        else
            return nullptr;
    }

    T *last() const
    {
        if (!isEmpty())
            return (T *)list_.last();
        else
            return nullptr;
    }

    T *at(int pos) const
    {
        if (!isEmpty())
            return (T *)list_.at(pos);
        else
            return nullptr;
    }

    bool insert(const T *value)
    {
        return list_.insert((void *)value);
    }

    int indexOf(T *value) const
    {
        return list_.indexOf((void *)value);
    }

    T *removeAt(int pos)
    {
        if (!isEmpty())
            return (T *)list_.removeAt(pos);
        else
            return nullptr;
    }

    T *remove(T *value)
    {
        if (!isEmpty())
            return (T *)list_.remove(value);
        else
            return nullptr;
    }

    void clean(bool delete_all = true)
    {
        if (delete_all)
        {
            T *value;
            while (!isEmpty())
            {
                value = (T *)(list_.removeAt(0));
                delete value;
            }
        }
        else
            list_.clean();
    }

private:
    List list_;
};

#endif // !__LISTGENERIC_H__
