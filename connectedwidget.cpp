#include "connectedwidget.h"
#include <QDebug>

ConnectedWidget::ConnectedWidget(QWidget* parent): QWidget(parent){

}
QJsonObject ConnectedWidget::getState(){
    QJsonObject* statePtr = new QJsonObject;
    emit(requestState(statePtr));
    return *statePtr;
}
