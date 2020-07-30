#include "dispatchercore.h"

DispatcherCore::DispatcherCore(QObject *parent) : QObject(parent){
    this->moveToThread(dispatcherThread);
    dispatcherThread->start();
}
void DispatcherCore::connectWidget(ConnectedWidget *widget){
    connect(&store,&QJsonObjectMutex::somethingChanged,widget,&ConnectedWidget::onStoreChanged);
    connect(widget,&ConnectedWidget::action,this,&DispatcherCore::dispatch);
    connect(widget,&ConnectedWidget::requestState,this,[=](QJsonObject* statePtr){
        *statePtr = store.getObject();
    },Qt::BlockingQueuedConnection);
}
