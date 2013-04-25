#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFtp>
#include <QFile>

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
    
private:
    Ui::Dialog *ui;

    void getFileList();
    QFtp ftp;
    QFile *file;
    QStringList files;
};

#endif // DIALOG_H
