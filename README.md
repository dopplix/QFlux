# Make New Project

![newapp](https://user-images.githubusercontent.com/31100072/88888672-bb17db00-d279-11ea-8906-fc43e07637fe.PNG)
![project](https://user-images.githubusercontent.com/31100072/88888683-be12cb80-d279-11ea-922e-ecfc72d0000b.PNG)
![MainWidget](https://user-images.githubusercontent.com/31100072/88888690-c1a65280-d279-11ea-9c5f-0e3814a49370.PNG)

# Install

- Clone QFlux Module in Qt Project Folder

```
cd <to-qt-project-folder>
git clone https://github.com/dopplix/QFlux.git qflux
```

- Add to Project

![openfile](https://user-images.githubusercontent.com/31100072/88888794-f0242d80-d279-11ea-8fe5-d401079ee237.png)
![addfile](https://user-images.githubusercontent.com/31100072/88889065-72aced00-d27a-11ea-9bb2-f78f85c6097d.PNG)

# Setting

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

# Usuage

