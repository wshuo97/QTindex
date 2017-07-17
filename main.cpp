#include "where.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    where f;
    f.show();

    return a.exec();
}
