#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QTreeView>
#include <QTimer>

class TreeView: public QTreeView
{
  Q_OBJECT
public:
  TreeView(QWidget *parent = 0);

protected:
  virtual void mouseDoubleClickEvent(QMouseEvent * event);


};
#endif // TREEVIEW_H
