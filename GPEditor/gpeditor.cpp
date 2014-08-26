#include <QDebug>
#include <QFlags>
#include <QFileDialog>
#include "gpeditor.h"
#include "ui_gpeditor.h"
#include "gpprojectviewer.h"
#include "gpscenegraphviewer.h"
#include "gpconsole.h"
#include "gppropertyviewer.h"
#include "gpsceneeditor.h"
#include "gpgamepreviewer.h"

GPEditor::GPEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GPEditor)
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
}

///////////////////////////////////////////////////////////////////////////////
// define slots
///////////////////////////////////////////////////////////////////////////////

void GPEditor::DoNewProject()
{
    qDebug("do new project called");

    QString _dirPath = QFileDialog::getExistingDirectory(this,tr("New Project"));

    if( !_dirPath.isEmpty() )
    {
        qDebug(qPrintable(_dirPath));
    }
}

void GPEditor::DoOpenProject()
{
    qDebug("do Open Project called");
}

void GPEditor::DoCloseProject()
{
    qDebug("do Close project called");
}

void GPEditor::DoSaveProject()
{
    qDebug("do save project called");
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

    // init scene graph viewer
    GPSceneGraphViewer * _sceneViewer = new GPSceneGraphViewer(this);

    this->addDockWidget(Qt::LeftDockWidgetArea,_sceneViewer);

    this->tabifyDockWidget(_sceneViewer,_projectViewer);

    // init console
    GPConsole * _console = new GPConsole(this);

    this->addDockWidget(Qt::BottomDockWidgetArea,_console);

    // init property pane
    GPPropertyViewer * _propertyViewer = new GPPropertyViewer(this);

    this->addDockWidget(Qt::RightDockWidgetArea,_propertyViewer);

    // init scene editor
    GPSceneEditor * _sceneEditor = new GPSceneEditor(this);

    this->setCentralWidget(_sceneEditor);

    // init game previewer
    GPGamePreviewer * _gamePreviewer = new GPGamePreviewer(this);

    this->setCentralWidget(_gamePreviewer);

    return true;
}
