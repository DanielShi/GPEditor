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
#include "gpproject.h"

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

        m_project->NewProject(_filePath);
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
        m_project->OpenProject(_filePath);
    }
}

void GPEditor::DoCloseProject()
{
    m_project->CloseProject();
}

void GPEditor::DoSaveProject()
{
    m_project->SaveProject();
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

    this->tabifyDockWidget(_projectViewer,_sceneViewer);

    _projectViewer->raise();

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

    // create an empty project model
    this->m_project = new GPProject();

    return true;
}
