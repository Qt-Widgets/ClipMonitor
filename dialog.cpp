#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    clipboard = qApp->clipboard();

    connect(&timer, SIGNAL(timeout()), this, SLOT(monitorClip()));
    timer.start(500);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::monitorClip()
{
    QString clipText = clipboard->text();

    //qDebug() << clipText;

    if(currentClip != clipText)
    {
        ui->clips->appendPlainText(clipText);
        currentClip = clipText;
    }
}
