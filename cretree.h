#ifndef CRETREE_H
#define CRETREE_H

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QModelIndex>
#include <QPushButton>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QMessageBox>

class cretree : public QWidget
{
    Q_OBJECT
public:
    cretree(const QString &string,QWidget *parent = 0);
    QFileSystemModel *model;
    QTreeView *treeView;

signals:

public slots:
    void mkdir();
    void rm();

};

#endif // CRETREE_H
