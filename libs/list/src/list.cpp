/**
**********************************************************************************************************************************************************************************************************************************
* @file:	list.cpp
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	03/08/2022 21:46:12
* @brief:	class List
**********************************************************************************************************************************************************************************************************************************
**/

#include "list.h"

List::List()
{
    node_ = nullptr;
    size_ = 0;
}

bool List::isEmpty() const
{
    return node_ == nullptr;
}

int List::size() const
{
    return size_;
}

void *List::first() const
{
    if (!isEmpty())
    {
        return node_->info_;
    }
    return nullptr;
}

void *List::last() const
{
    if (isEmpty())
    {
        return nullptr;
    }
    TNode *node = nullptr;
    for (node = node_; node->next_ != nullptr; node = node->next_)
        ;
    return node->info_;
}

void *List::at(int pos) const
{
    int i = 0;
    TNode *node = nullptr;
    if (pos < 0)
        return node;
    for (node = node_; node != nullptr && i != pos; node = node->next_)
        i++;

    if (node != nullptr)
        return node->info_;
    else
        return nullptr;
}

bool List::insert(void *info)
{
    TNode *node;

    if ((node = (TNode *)malloc(sizeof(TNode))) != nullptr)
    {
        if (!isEmpty())
        {
            for (TNode *last_node = node_; last_node != node; last_node = last_node->next_)
            {
                if (last_node->next_ == nullptr)
                {
                    last_node->next_ = node;
                    node->before_ = last_node;
                }
            }
        }
        else
        {
            node_ = node;
            node->before_ = nullptr;
        }

        node->info_ = info;
        node->next_ = nullptr;
        size_++;
        return true;
    }
    else
        return false;
}

int List::indexOf(void *value, int size) const
{
    int i = 0;
    TNode *node = nullptr;
    for (node = node_; node != nullptr && memcmp(value, node->info_, size) != 0; node = node->next_)
        i++;

    if (node != nullptr)
        return i;
    else
        return -1;
}

void *List::removeAt(int pos, bool free_object)
{
    int i = 0;
    TNode *node = nullptr;
    void *info = nullptr;
    for (node = node_; node != nullptr && i < pos; node = node->next_)
        i++;
    if (node != nullptr && !isEmpty())
    {
        size_--;
        if (node->before_ != nullptr)
        {
            node->before_->next_ = node->next_;
        }
        if (node->next_ != nullptr)
        {
            node->next_->before_ = node->before_;
        }
        if (node == node_)
        {
            node_ = node->next_;
        }
        info = node->info_;
        if (free_object)
        {
            free(node->info_);
            info = nullptr;
        }
        free(node);
    }
    return info;
}

void *List::remove(void *value, bool free_object)
{
    int index = indexOf(value);
    return removeAt(index, free_object);
}

void List::clean()
{
    void *node = nullptr;
    for (node = node_; node != nullptr; node = node_)
    {
        node_ = (node_)->next_;
        free(node);
    }
}
