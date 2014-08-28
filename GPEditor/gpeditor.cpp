#include <QDebug>
#include <QFlags>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTabWidget>
#include "gpeditor.h"
#include "ui_gpeditor.h"
#include "gpprojectviewer.h"
#include "gpscenegraphviewer.h"
#include "gpconsole.h"
#include "gppropertyviewer.h"
#include "gpsceneeditor.h"
#include "gpgamepreviewer.h"
#include "gpproject.h"
#include "gplogmanager.h"

GPEditor::GPEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GPEditor),
    m_project(NULL)
{
    ui->setupUi(this);

    if( !InitOnLaunch() )
    {
       qDebug("failed to init on launch");
    }
}

GPEditor::~GPEditor()
{
    delete ui;
    delete m_project;
}

///////////////////////////////////////////////////////////////////////////////
// define slots
///////////////////////////////////////////////////////////////////////////////

void GPEditor::DoNewProject()
{
    QString _filePath = QFileDialog::getSaveFileName(
                this,
                tr("New Project"),
                tr(""),
                tr("GP Project Files (*.gpproj)")
                );

    if( !_filePath.isEmpty() )
    {
        if( !_filePath.endsWith(tr(".gpproj"),Qt::CaseInsensitive) )
                _filePath.append(tr(".gpproj"));

        QFile _file(_filePath);

        if( _file.open(QIODevice::WriteOnly|QIODevice::Text) )
        {
            // TODO: put down some config here

            _file.close();

            emit OnProjectOpen(_filePath);
        }
        else
        {
            QMessageBox::information(this,tr("Info"),
                                     tr("Failed to create new project!"));
        }
    }
}

void GPEditor::DoOpenProject()
{
    QString _filePath = QFileDialog::getOpenFileName(
                this,
                tr("Open Project"),
                tr(""),
                tr("GP Project Files (*.gpproj)")
                );

    if( !_filePath.isEmpty() )
    {
        emit OnProjectOpen(_filePath);
    }
}

void GPEditor::DoCloseProject()
{
    emit OnProjectClose();
}

void GPEditor::DoSaveProject()
{
}

//////////////////////////////////////////////////////////////////////////////

bool GPEditor::InitOnLaunch()
{
    // set dock options
    QFlags<DockOption> _options = this->dockOptions();

    _options |= QMainWindow::ForceTabbedDocks;

    this->setDockOptions(_options);

    // init project viewer
    GPProjectViewer * _projectViewer = new GPProjectViewer(this);

    this->addDockWidget(Qt::LeftDockWidgetArea,_projectViewer);

    connect(this,SIGNAL(OnProjectOpen(QString)),_projectViewer,SLOT(DoLoadProject(QString)));

    connect(this,SIGNAL(OnProjectClose()),_projectViewer,SLOT(DoCloseProject()));

    // init scene graph viewer
    GPSceneGraphViewer * _sceneViewer = new GPSceneGraphViewer(this);

    this->addDockWidget(Qt::LeftDockWidgetArea,_sceneViewer);

    this->tabifyDockWidget(_projectViewer,_sceneViewer);

    _projectViewer->raise();

    // init console
    GPConsole * _console = new GPConsole(this);

    this->addDockWidget(Qt::BottomDockWidgetArea,_console);

    connect(GPLogManager::getInstance(),SIGNAL(OnError(QString)),_console, SLOT(DoError(QString)));

    connect(GPLogManager::getInstance(),SIGNAL(OnInfo(QString)),_console, SLOT(DoInfo(QString)));

    GPLogManager::getInstance()->Error(tr("Testing Testing"));

    // init property pane
    GPPropertyViewer * _propertyViewer = new GPPropertyViewer(this);

    this->addDockWidget(Qt::RightDockWidgetArea,_propertyViewer);

    // init central content widget
    QTabWidget * _centralTabWidget = new QTabWidget(this);

    this->setCentralWidget(_centralTabWidget);

    // init scene editor
    GPSceneEditor * _sceneEditor = new GPSceneEditor(_centralTabWidget);

    _centralTabWidget->addTab(_sceneEditor,_sceneEditor->windowTitle());

    // init game previewer
    GPGamePreviewer * _gamePreviewer = new GPGamePreviewer(_centralTabWidget);

    _centralTabWidget->addTab(_gamePreviewer,_gamePreviewer->windowTitle());

    // create an empty project model
    this->m_project = new GPProject(this);

    return true;
}
