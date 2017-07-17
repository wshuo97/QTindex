#include "cretree.h"

cretree::cretree(const QString &string,QWidget *parent):QWidget(parent)
{
    model = new QFileSystemModel(this);
    model->setRootPath(string);

    treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(string));

    QPushButton *mkdirButton = new QPushButton(tr("Make Directory..."),this);
    QPushButton *rmButton = new QPushButton(tr("Remove"),this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mkdirButton);
    buttonLayout->addWidget(rmButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(treeView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setWindowTitle("File System Model");

    connect(mkdirButton,SIGNAL(clicked()),this,SLOT(mkdir()));
    connect(rmButton,SIGNAL(clicked()),this,SLOT(rm()));

}

void cretree::mkdir()
{
    QModelIndex index = treeView->currentIndex();
    if(!index.isValid()) return ;
    QString dirName = QInputDialog::getText(this,tr("Create Directory"),tr("Directory name"));
    if(!dirName.isEmpty())
    {
        if(!model->mkdir(index,dirName).isValid())
        {
            QMessageBox::information(this,tr("Create Directory"),tr("Directory name"));
        }
    }
}

void cretree::rm()
{
    QModelIndex index = treeView->currentIndex();
    if(!index.isValid()) return ;
    bool ok;
    if(model->fileInfo(index).isDir()) ok=model->rmdir(index);
    else ok=model->remove(index);
    if(!ok)
    {
        QMessageBox::information(this,tr("Remove"),tr("Failed to remove %1").arg(model->fileName(index)));
    }
}
