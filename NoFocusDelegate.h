#ifndef NOFOCUSDELEGATE_H
#define NOFOCUSDELEGATE_H
#include<QObject>
#include<QPainter>
#include<QStyledItemDelegate>

class No_Focus_Delegate : public QStyledItemDelegate

{

public:

    No_Focus_Delegate(QObject *pParent = 0);

    ~No_Focus_Delegate();

 public:

    void paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const;

};
#endif // NO_FOCUS_DELEGATE_H
