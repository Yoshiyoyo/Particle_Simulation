/********************************************************************************
** Form generated from reading UI file 'openglwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLWINDOW_H
#define UI_OPENGLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include "openglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_openglwindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QOpenGLWidget *openGLWidget;

    void setupUi(OpenGLWindow *openglwindow)
    {
        if (openglwindow->objectName().isEmpty())
            openglwindow->setObjectName(QString::fromUtf8("openglwindow"));
        openglwindow->resize(400, 300);
        pushButton = new QPushButton(openglwindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 270, 75, 23));
        pushButton_2 = new QPushButton(openglwindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 270, 75, 23));
        openGLWidget = new QOpenGLWidget(openglwindow);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 401, 271));

        retranslateUi(openglwindow);

        QMetaObject::connectSlotsByName(openglwindow);
    } // setupUi

    void retranslateUi(OpenGLWindow *openglwindow)
    {
        openglwindow->setWindowTitle(QApplication::translate("openglwindow", "openglwindow", nullptr));
        pushButton->setText(QApplication::translate("openglwindow", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("openglwindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class openglwindow: public Ui_openglwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLWINDOW_H
