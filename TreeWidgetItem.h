#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H

#include <QTreewidgetItem >

class TreeWidgetItem : public QTreeWidgetItem
{
public:
    TreeWidgetItem(): QTreeWidgetItem(){};
    TreeWidgetItem(QTreeWidget *tree) : QTreeWidgetItem(tree)  {}
    TreeWidgetItem(QTreeWidget * parent, const QStringList & strings)
                   : QTreeWidgetItem (parent,strings)  {}
    bool operator< (const QTreeWidgetItem &other) const
    {

        int sortCol = treeWidget()->sortColumn();// the index of pressed column
        if(text(sortCol)=="+" || text(sortCol)=="-" || text(sortCol)=="X" || text(sortCol)=="/")
            return text(sortCol) < other.text(sortCol);
        int myNumber = text(sortCol).toInt();
        int otherNumber = other.text(sortCol).toInt();
        return myNumber < otherNumber;
    }
};

#endif // TREEWIDGETITEM_H
