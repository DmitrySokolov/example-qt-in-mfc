#ifndef QMYDIALOG_API_H
#define QMYDIALOG_API_H


#if defined(CREATE_MY_API)
    #define MY_API  __declspec(dllexport)
#else
    #define MY_API  __declspec(dllimport)
#endif



using Callback_t = void(*)(char** data, size_t data_size);


MY_API  int showMyDialog(Callback_t fn);


#endif // QMYDIALOG_API_H
