/**
**********************************************************************************************************************************************************************************************************************************
* @file:	list.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	03/08/2022 21:46:05
* @brief:	class List
**********************************************************************************************************************************************************************************************************************************
**/

#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class List
{
public:
    List();

    bool isEmpty() const;
    int size() const;
    virtual void *first() const;
    virtual void *last() const;
    virtual void *at(int pos) const;
    virtual bool insert(void *info);

    virtual int indexOf(void *value, int size = 0) const;

    virtual void *removeAt(int pos, bool free_object = false);
    virtual void *remove(void *value, bool free_object = false);
    void clean();

private:
    struct TNode
    {
        void *info_;
        TNode *next_;
        TNode *before_;
    };
    TNode *node_;
    int size_;
};

#endif // !__LIST_H__
