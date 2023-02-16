
// 迭代器
#include <stdio.h>
#include <stdlib.h>

typedef void *(*CreateIteratorCB)(Collection *collection);
typedef bool (*HasNextCB)(Collection *collection, void *collectionIter);
typedef void *(*GetNextCB)(Collection *collection, void *collectionIter);


typedef enum {
    COLLECTION_LIST,
    COLLECTION_AVL,
} CollectionType;

typedef struct Collection {
    void *data; // 指向集合数据结构
    CreateIteratorCB createIter; // 创建自己特有的迭代控制块
    HasNextCB hasNext; // 此集合的hasNext回调
    GetNextCB getNext; // 此集合的getnext回调
    // 其他集合的处理函数
} Collection;

typedef struct {
    Collection *collection; // 要遍历的集合数据
    void *collectionIter; // 数据集合自己的迭代控制块
} Iterator;


// 创建特定类型的集合
Collection *CreateCollection(CollectionType type) 
{
    // 根据集合类型申请并初始化Collection的数据结构，初始化collection结构体时，会根据起类型挂载对应的CreateITerator等处理函数
}

// 针对输入的集合创建其迭代器
Iterator *CreateIterator(Collection *collection)
{
    Iterator *iter = malloc(sizeof(Iterator));
    if (iter == NULL) {
        return NULL;
    }
    iter->collection = collection;
    iter->collectionIter = collection->createIter(collection);
    return iter;
}

bool HashNext(Iterator *iter)
{
    return iter->collection->hasNext(iter->collection, iter->collectionIter);
}

void *GetNext(Iterator *iter)
{
    return iter->collection->getNext(iter->collection, iter->collectionIter);
}
