#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFtp>
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>

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
    void connectClicked();
    void disconnectClicked();
    void cdClicked();
    void upClicked();
    void getClicked();

    void selectionChanged();

    void ftpFinished(int,bool);
    void ftpListInfo(const QUrlInfo&);
    void ftpProgress(qint64,qint64);
    void ftpAbort();
private:
    Ui::Dialog *ui;

    void getFileList();
    QFtp ftp;
    QFile *file;
    QStringList files;
    QTimer *qtimer;
};

#endif // DIALOG_H
