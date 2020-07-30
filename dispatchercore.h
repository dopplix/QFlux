#ifndef DISPATCHERCORE_H
#define DISPATCHERCORE_H

#include <QThread>
#include "qjsonobjectmutex.h"
#include "connectedwidget.h"

class DispatcherCore : public QObject{
    Q_OBJECT

public:
    explicit DispatcherCore(QObject *parent = nullptr);
    void connectWidget(ConnectedWidget* widget);
    QJsonObjectMutex* getStore(){return &store;}
    QJsonObjectMutex store;

private:
    QThread* dispatcherThread = new QThread;

signals:

public slots:
    virtual void dispatch(QString actionType, QJsonObject payload) = 0;

};

#endif // DISPATCHERCORE_H
