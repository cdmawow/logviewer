#include "NoFocusDelegate.h"

No_Focus_Delegate::No_Focus_Delegate(QObject *pParent)
    :QStyledItemDelegate(pParent)
{
}
No_Focus_Delegate::~No_Focus_Delegate()
{
}
void No_Focus_Delegate::paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const

 {

    QStyleOptionViewItem itemOption(option);

    if (itemOption.state & QStyle::State_HasFocus)

    {
       itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
    }

    QStyledItemDelegate::paint(painter, itemOption, index);

 }

