#include "connectedwidget.h"

QJsonObject ConnectedWidget::getState(){
    QJsonObject* statePtr = new QJsonObject;
    emit(requestState(statePtr));
    return *statePtr;
}
