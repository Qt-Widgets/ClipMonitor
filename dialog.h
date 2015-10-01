#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QClipboard>
#include <QTimer>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void monitorClip();

private:
    Ui::Dialog *ui;
    QClipboard *clipboard;
    QString currentClip;
    QTimer timer;
};

#endif // DIALOG_H
