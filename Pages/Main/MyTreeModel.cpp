//
// Created by DELL on 2023/12/2.
//

#include "MyTreeModel.h"
#include <vector>
#include <functional>
#include <string>
#include <filesystem>


MyTreeModel::MyTreeModel(QObject *parent)
        : QAbstractItemModel(parent), rootItem(new MyTreeItem)
{
}

QModelIndex MyTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
        return QModelIndex();
    MyTreeItem *parentItem = getItem(parent);
    auto childPtr = parentItem->subItems.at(row);
    if (childPtr){
        return createIndex(row, column, childPtr.get());
    }else{
        return QModelIndex();
    }
}

QModelIndex MyTreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid()){
        return QModelIndex();
    }
    MyTreeItem *childItem = getItem(index);
    auto parentPtr = childItem->parentItem;
    if(!parentPtr || parentPtr == rootItem){
        return QModelIndex();
    }
    return createIndex(parentPtr.get()->row, 0, parentPtr.get());
}

int MyTreeModel::rowCount(const QModelIndex &parent) const
{
    MyTreeItem *parentItem = getItem(parent);
    return parentItem->subItems.size();
}

int MyTreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant MyTreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    MyTreeItem *item = getItem(index);
    if(role == Qt::DisplayRole){
        //TreeView继承自TableView，所以可以通过不同的column来取单元格数据
        role = Qt::UserRole + index.column();
    }
    switch (role) {
        case NameRole: return item->name;
        case DetailRole: return item->detail;
        default: break;
    }
    return QVariant();
}

QHash<int, QByteArray> MyTreeModel::roleNames() const
{
    QHash<int, QByteArray> names = QAbstractItemModel::roleNames();
    names.insert(QHash<int, QByteArray>{
             {NameRole, "name"}
            ,{DetailRole, "detail"}
    });
    return names;
}

void MyTreeModel::resetItems()
{
    beginResetModel();
    QSharedPointer<MyTreeItem> lv1{new MyTreeItem};
    lv1->parentItem = rootItem;
    rootItem->subItems.append(lv1);
    lv1->row = 0;
    lv1->name = QString("MarkdownEditor");
    int cnt=0;
    for(auto i: std::filesystem::directory_iterator("D:\\MarkdownEditor")){
        QSharedPointer<MyTreeItem> lv2{new MyTreeItem};
        lv2->parentItem = lv1;
        lv1->subItems.append(lv2);
        lv2->row = cnt++;
        lv2->name = QString::fromStdString(i.path().filename().string());
    }
    qDebug()<<__FUNCTION__<<rowCount()<<columnCount();
}

MyTreeItem *MyTreeModel::getItem(const QModelIndex &idx) const
{
    if(idx.isValid()){
        MyTreeItem *item = static_cast<MyTreeItem*>(idx.internalPointer());
        if(item){
            return item;
        }
    }
    return rootItem.get();
}

