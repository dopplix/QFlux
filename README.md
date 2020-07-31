# Make New Project

![newapp](https://user-images.githubusercontent.com/31100072/88888672-bb17db00-d279-11ea-8906-fc43e07637fe.PNG)
![project](https://user-images.githubusercontent.com/31100072/88888683-be12cb80-d279-11ea-922e-ecfc72d0000b.PNG)
![MainWidget](https://user-images.githubusercontent.com/31100072/88888690-c1a65280-d279-11ea-9c5f-0e3814a49370.PNG)

# Install

- Clone QFlux Module in Qt Project Folder

```
cd <qt-project-folder>
git clone https://github.com/dopplix/QFlux.git qflux
cd qflux
git clone https://github.com/dopplix/QJsonObjectMutex.git store
```

- Add to Project

![openfile](https://user-images.githubusercontent.com/31100072/88888794-f0242d80-d279-11ea-8fe5-d401079ee237.png)
![addfile1](https://user-images.githubusercontent.com/31100072/88910285-389e1400-d297-11ea-808a-1b5caae927dc.PNG)
![addfile2](https://user-images.githubusercontent.com/31100072/88910355-55d2e280-d297-11ea-92c1-a579354ea9f4.PNG)

# Setting

## ActionTypes

- add ActionTypes Header File

![addHeader](https://user-images.githubusercontent.com/31100072/88890280-5ca02c00-d27c-11ea-95db-64788fdf69c9.PNG)
![addActionTypes](https://user-images.githubusercontent.com/31100072/88890403-8c4f3400-d27c-11ea-9816-0f08708f0157.PNG)

- Define ActionTypes

```cpp
#ifndef ACTIONTYPES_H
#define ACTIONTYPES_H

#include <QString>

namespace ActionTypes {
    const QString DEFAULT_ACTION = "DEFAULT_ACTION";
}

#endif // ACTIONTYPES_H
```

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
#include "actionTypes.h"

//class MainWidget : public QWidget{
class MainWidget : public ConnectedWidget{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void onStoreChanged(QJsonObject diffObj) override;
    
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

- Add New Class

![addnew](https://user-images.githubusercontent.com/31100072/88888887-19dd5480-d27a-11ea-9ef9-3daf72e0ce98.png)
![addclass](https://user-images.githubusercontent.com/31100072/88888949-3e393100-d27a-11ea-82c5-472af7269249.PNG)
![dispatcher](https://user-images.githubusercontent.com/31100072/88888897-206bcc00-d27a-11ea-8ab0-96d2fb2cc23f.PNG)

1. Include Dispatcher Core

2. Add Default "dispatch" Slot

#### dispatcher.h
```cpp
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>
#include "qflux/dispatchercore.h"

class Dispatcher : public DispatcherCore{
    Q_OBJECT
    
public:
    Dispatcher();

public slots:
    void dispatch(QString actionType, QJsonObject payload) override;

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

# Connect to Dispatcher

- Global Dispatcher

#### main.cpp
```cpp
#include <QApplication>
#include "mainwidget.h"
#include "dispatcher.h"

Dispatcher* dispatcher;

int main(int argc, char *argv[]){    
    QApplication a(argc, argv);
    dispatcher = new Dispatcher;
    MainWidget w;
    dispatcher->connectWidget(&w);
    w.show();
    return a.exec();
}
```

- Every ConnectedWidget Must Connect to dispatcher

#### under includes
```cpp
...
#include "dispatcher.h"

extern Dispatcher* dispatcher;
```

#### use
```cpp
SomeWidget* sw = new SomeWidget; // Parent is ConnectedWidget
dispatcher->connectWidget(sw);
```

# Usuage

## Action : Widget -> Store

- Create Action

#### mainwidget.cpp
```cpp
QJsonObject payload;
payload.insert("TEST_KEY","TEST_VALUE");
emit(action(ActionTypes::DEFAULT_ACTION,payload));
```    

- Dispatch

#### dispatcher.cpp
```cpp
void Dispatcher::dispatch(QString actionType, QJsonObject payload){
    if(actionType==ActionTypes::DEFAULT_ACTION){
        //Do Something
        store.setObject(payload);
    }else{
        
    }
}
```

## Listen : Store -> Widget

#### mainwidget.cpp
```cpp
void MainWidget::onStoreChanged(QJsonObject diffObj){
    QString key = diffObj.keys().at(0);
    QJsonValue value = diffObj.value(key);
    if(key=="TEST_KEY"){
        //Update Some Views
    }else{
        
    }
}
```

## Use Store : Get State In Widget

#### mainwidget.cpp
```cpp
QJsonObject state = getState();
```

# Example

- qflux-starter

https://github.com/dopplix/qflux-starter
