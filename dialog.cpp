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

    qtimer = new QTimer(this);
    qtimer->setSingleShot(true);
    connect(qtimer,SIGNAL(timeout()),this,SLOT(ftpAbort()));
}

void Dialog::ftpAbort()
{

    ftp.abort();
    QMessageBox::warning( this, tr("Error"), tr("Timeout!") );
    ui->connectButton->setEnabled(true);
    ui->StatusText->setText( tr("Ready.") );
    ui->DisconnectButton->setEnabled( false );
    ui->changeDirectoryButton->setEnabled( false );
    ui->UpButton->setEnabled( false );
    ui->getFileButton->setEnabled( false );

}


void Dialog::connectClicked(){
    ui->connectButton->setEnabled(false);

    qtimer->start(1000);
    ftp.connectToHost(ui->HostLineEdit->text());


    ui->StatusText->setText(tr("Connecting to host..."));
}

void Dialog::disconnectClicked(){
    ui->DisconnectButton->setEnabled( false );
    ui->changeDirectoryButton->setEnabled( false );
    ui->UpButton->setEnabled( false );
    ui->getFileButton->setEnabled( false );
    ftp.close();
}

void Dialog::cdClicked(){

}

void Dialog::upClicked(){

}

void Dialog::getClicked(){

}

void Dialog::selectionChanged(){

}

void Dialog::ftpFinished(int request,bool error){
    // Handle errors depending on the command causing it
    qtimer->stop();
    if( error )
    {
        switch( ftp.currentCommand() )
        {
            case QFtp::ConnectToHost:
                //isAbort = false;
                QMessageBox::warning( this, tr("Error"), tr("Failed to connect to host.") );
                ui->connectButton->setEnabled( true );
            break;
            case QFtp::Login:
                QMessageBox::warning( this, tr("Error"), tr("Failed to login.") );
                ui->connectButton->setEnabled( true );
            break;
            case QFtp::List:

                QMessageBox::warning( this, tr("Error"),
                tr("Failed to get file list.\nClosing connection.") );
                ftp.close();
            break;

            default:
            break;
        }

        ui->StatusText->setText( tr("Ready.") );
     }
        // React to the current command and issue
        // more commands or update the user interface
     else{
        switch( ftp.currentCommand() )
        {
            case QFtp::ConnectToHost:

                ftp.login();

            break;
            case QFtp::Login:

                getFileList();
            break;
            case QFtp::Close:
                ui->connectButton->setEnabled( true );
                getFileList();
                break;
            case QFtp::List:

                ui->DisconnectButton->setEnabled( true );
                ui->UpButton->setEnabled( true );
                ui->StatusText->setText( tr("Ready.") );
            break;
        default:
            break;
        }
    }
}

void Dialog::ftpListInfo(const QUrlInfo& info){

    ui->listWidget->addItem( info.name() );

    if( info.isFile() )
        files << info.name();

}

void Dialog::ftpProgress(qint64,qint64){

}

void Dialog::getFileList(){
    ui->DisconnectButton->setEnabled( false );
    ui->changeDirectoryButton->setEnabled( false );
    ui->UpButton->setEnabled( false );
    ui->getFileButton->setEnabled( false );
    ui->listWidget->clear();
    files.clear();

    if( ftp.state() == QFtp::LoggedIn )
        ftp.list();
}

Dialog::~Dialog()
{
    delete ui;

}
