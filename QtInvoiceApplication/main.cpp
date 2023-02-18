#include "QtInvoiceApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtInvoiceApplication w;
    w.show();
    return a.exec();
}
