#ifndef CONNECTEDWIDGET_H
#define CONNECTEDWIDGET_H

#include <QWidget>
#include <QJsonObject>

class ConnectedWidget : public QWidget{
    Q_OBJECT

public:
    explicit ConnectedWidget(QWidget *parent = nullptr) : QWidget(parent){}
    QJsonObject getState();

signals:
    void action(QString actionType, QJsonObject payload);
    void requestState(QJsonObject* statePtr);

public slots:
    virtual void onStoreChanged(QJsonObject diffObj) = 0;

};

#endif // CONNECTEDWIDGET_H
