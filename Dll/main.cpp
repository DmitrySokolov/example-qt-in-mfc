#define CREATE_MY_API

#include <QApplication>
#include "mydialog.h"


MY_API  int showMyDialog(Callback_t fn)
{
    int argc = 0;
    QApplication app(argc, nullptr);
    QMyDialog dlg(fn);
    dlg.show();
    return app.exec();
}
