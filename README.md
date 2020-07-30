# Install

- Clone QFlux Module in Qt Project Folder

```
cd <to-qt-project-folder>
git clone https://github.com/dopplix/QFlux.git qflux
```

# Usage

## Modify Plain Widget to ConnectedWidget

1. Include ConnectedWidget

2. Change Parent Widget Name
    QWidget to ConnectedWidget

3. Add Default "onStoreChanged" Slot

#### mainwidget.h
```cpp
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "qflux/connectedwidget.h"

//class MainWidget : public QWidget{
class MainWidget : public ConnectedWidget{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void onStoreChanged(QJsonObject diffObj);
    
};
#endif // MAINWIDGET_H
```

#### mainwidget.cpp
```cpp
#include "mainwidget.h"

//MainWidget::MainWidget(QWidget *parent) : QWidget(parent){
MainWidget::MainWidget(QWidget *parent) : ConnectedWidget(parent){
    
}
MainWidget::~MainWidget(){
    
}
void MainWidget::onStoreChanged(QJsonObject diffObj){
    
}
```

## Make Dispatcher

1. Include Dispatcher Core

2. Add Default "dispatch" Slot

#### dispatcher.h
```cpp
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>
#include "qflux/dispatchercore.h"

class Dispatcher : public DispatcherCore{

public:
    Dispatcher();

public slots:
    void dispatch(QString actionType, QJsonObject payload);

};

#endif // DISPATCHER_H
```

#### dispatcher.cpp
```cpp
#include "dispatcher.cpp"

Dispatcher::Dispatcher(){
    
}
void Dispatcher::dispatch(QString actionType, QJsonObject payload){
    
}
```

