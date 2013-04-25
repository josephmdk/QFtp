#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    file = 0;
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowIcon(QIcon(":/images/logo.png"));

    connect( ui->connectButton, SIGNAL(clicked()),
    this, SLOT(connectClicked()) );
    connect( ui->DisconnectButton, SIGNAL(clicked()),
    this, SLOT(disconnectClicked()) );
    connect( ui->changeDirectoryButton, SIGNAL(clicked()),
    this, SLOT(cdClicked()) );
    connect( ui->UpButton, SIGNAL(clicked()),
    this, SLOT(upClicked()) );
    connect( ui->getFileButton, SIGNAL(clicked()),
    this, SLOT(getClicked()) );

    connect( ui->listWidget, SIGNAL(itemSelectionChanged()),
    this, SLOT(selectionChanged()) );

    connect( &ftp, SIGNAL(commandFinished(int,bool)),
    this, SLOT(ftpFinished(int,bool)) );
    connect( &ftp, SIGNAL(listInfo(QUrlInfo)),
    this, SLOT(ftpListInfo(QUrlInfo)) );
    connect( &ftp, SIGNAL(dataTransferProgress(qint64,qint64)),
    this, SLOT(ftpProgress(qint64,qint64)) );

    ui->DisconnectButton->setEnabled( false );
    ui->changeDirectoryButton->setEnabled( false );
    ui->UpButton->setEnabled( false );
    ui->getFileButton->setEnabled( false );

}

void Dialog::connectClicked(){
    ui->connectButton->setEnabled(false);
    ftp.connectToHost(ui->HostLineEdit->text());
    ui->StatusText->setText(tr("Connecting to host..."));
}

void Dialog::disconnectClicked(){

}

void Dialog::cdClicked(){

}

void Dialog::upClicked(){

}

void Dialog::getClicked(){

}

void Dialog::selectionChanged(){

}

void Dialog::ftpFinished(int,bool){

}

void Dialog::ftpListInfo(const QUrlInfo&){

}

void Dialog::ftpProgress(qint64,qint64){

}

void Dialog::getFileList(){

}

Dialog::~Dialog()
{
    delete ui;
}
