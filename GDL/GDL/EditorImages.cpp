/** \file
 *  Game Develop
 *  2008-2011 Florian Rival (Florian.Rival@gmail.com)
 */

#if defined(GD_IDE_ONLY)

#include "GDL/EditorImages.h"
#ifdef __WXMSW__
#include <wx/msw/winundef.h>
#endif

//(*InternalHeaders(EditorImages)
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <wx/toolbar.h>
#include <wx/config.h>
#include <wx/aui/aui.h>
#include <wx/log.h>
#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/imaglist.h>
#include <wx/textdlg.h>
#include <wx/help.h>
#include <wx/file.h>
#include <wx/dcbuffer.h>
#include <wx/dnd.h>
#include <wx/ribbon/bar.h>
#include <wx/ribbon/buttonbar.h>
#include <wx/ribbon/gallery.h>
#include <wx/ribbon/toolbar.h>
#include "GDL/HelpFileAccess.h"

#include "GDL/Game.h"
#include "GDL/CommonTools.h"
#include "GDL/MemTrace.h"
#include "GDL/ChoixDossier.h"
#include "GDL/PropImage.h"
#include "GDL/BitmapGUIManager.h"
#include "GDL/gdTreeItemStringData.h"

#ifdef __WXGTK__
#include <gtk/gtk.h>
#endif

//(*IdInit(EditorImages)
const long EditorImages::ID_PANEL2 = wxNewId();
const long EditorImages::ID_TREECTRL1 = wxNewId();
const long EditorImages::ID_PANEL3 = wxNewId();
const long EditorImages::ID_SPLITTERWINDOW1 = wxNewId();
const long EditorImages::ID_PANEL1 = wxNewId();
const long EditorImages::idMenuModProp = wxNewId();
const long EditorImages::idMenuMod = wxNewId();
const long EditorImages::idMenuModFile = wxNewId();
const long EditorImages::idMenuAjouter = wxNewId();
const long EditorImages::idMenuDel = wxNewId();
const long EditorImages::idMoveUp = wxNewId();
const long EditorImages::idMoveDown = wxNewId();
const long EditorImages::ID_MENUITEM1 = wxNewId();
const long EditorImages::ID_MENUITEM2 = wxNewId();
const long EditorImages::ID_MENUITEM3 = wxNewId();
const long EditorImages::ID_MENUITEM5 = wxNewId();
const long EditorImages::ID_MENUITEM6 = wxNewId();
const long EditorImages::ID_MENUITEM4 = wxNewId();
const long EditorImages::ID_MENUITEM7 = wxNewId();
const long EditorImages::ID_MENUITEM8 = wxNewId();
//*)
const long EditorImages::ID_BITMAPBUTTON1 = wxNewId();
const long EditorImages::ID_BITMAPBUTTON5 = wxNewId();
const long EditorImages::ID_BITMAPBUTTON4 = wxNewId();
const long EditorImages::ID_BITMAPBUTTON2 = wxNewId();
const long EditorImages::ID_BITMAPBUTTON3 = wxNewId();
const long EditorImages::ID_BITMAPBUTTON6 = wxNewId();
const long EditorImages::idRibbonAdd = wxNewId();
const long EditorImages::idRibbonModProp= wxNewId();
const long EditorImages::idRibbonMod= wxNewId();
const long EditorImages::idRibbonModFile= wxNewId();
const long EditorImages::idRibbonDel= wxNewId();
const long EditorImages::idRibbonAddDossier= wxNewId();
const long EditorImages::idRibbonRemoveDossier= wxNewId();
const long EditorImages::idRibbonUp= wxNewId();
const long EditorImages::idRibbonDown= wxNewId();
const long EditorImages::idRibbonDirectories= wxNewId();
const long EditorImages::idRibbonPaintProgram= wxNewId();
const long EditorImages::idRibbonSearch= wxNewId();
const long EditorImages::idRibbonHelp= wxNewId();
const long EditorImages::idRibbonRefresh = wxNewId();

BEGIN_EVENT_TABLE( EditorImages, wxPanel )
    //(*EventTable(EditorImages)
    //*)
END_EVENT_TABLE()

EditorImages::EditorImages( wxWindow* parent, Game & game_, MainEditorCommand & mainEditorCommand_, bool useRibbon_ ) :
game(game_),
#if defined(DESACTIVATED_FOR_WX290)
filesWatcher(game),
#endif
mainEditorCommand(mainEditorCommand_),
useRibbon(useRibbon_),
toolbar(NULL)
{
    //(*Initialize(EditorImages)
    wxFlexGridSizer* FlexGridSizer4;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem11;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenuItem* MenuItem13;
    wxMenuItem* MenuItem10;
    wxMenuItem* MenuItem12;
    wxMenuItem* MenuItem3;
    wxMenuItem* editMenuItem;
    wxMenuItem* deleteImageItem;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    Core = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer4->AddGrowableCol(0);
    FlexGridSizer4->AddGrowableRow(1);
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    toolbarPanel = new wxPanel(Core, ID_PANEL2, wxDefaultPosition, wxSize(-1,25), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    toolbarPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    if ( useRibbon ) toolbarPanel->SetSize(-1, 0);
    FlexGridSizer1->Add(toolbarPanel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer4->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SplitterWindow1 = new wxSplitterWindow(Core, ID_SPLITTERWINDOW1, wxDefaultPosition, wxSize(239,271), wxSP_3D, _T("ID_SPLITTERWINDOW1"));
    SplitterWindow1->SetMinSize(wxSize(10,10));
    SplitterWindow1->SetMinimumPaneSize(10);
    BanqueImageList = new wxTreeCtrl(SplitterWindow1, ID_TREECTRL1, wxDefaultPosition, wxSize(200,170), wxTR_EDIT_LABELS|wxTR_HIDE_ROOT|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
    BanqueImageList->SetToolTip(_("Clic droit sur une image pour acc�der aux options"));
    apercuPanel = new wxPanel(SplitterWindow1, ID_PANEL3, wxDefaultPosition, wxSize(200,120), wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    SplitterWindow1->SplitVertically(BanqueImageList, apercuPanel);
    FlexGridSizer4->Add(SplitterWindow1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Core->SetSizer(FlexGridSizer4);
    FlexGridSizer4->Fit(Core);
    FlexGridSizer4->SetSizeHints(Core);
    FlexGridSizer2->Add(Core, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(FlexGridSizer2);
    editMenuItem = new wxMenuItem((&ContextMenu), idMenuModProp, _("Modifier les propri�t�s de l\'image"), wxEmptyString, wxITEM_NORMAL);
    editMenuItem->SetBitmap(wxBitmap(wxImage(_T("res/editpropicon.png"))));
    ContextMenu.Append(editMenuItem);
    MenuItem3 = new wxMenuItem((&ContextMenu), idMenuMod, _("Modifier le nom de l\'image"), wxEmptyString, wxITEM_NORMAL);
    MenuItem3->SetBitmap(wxBitmap(wxImage(_T("res/editnom.png"))));
    ContextMenu.Append(MenuItem3);
    MenuItem4 = new wxMenuItem((&ContextMenu), idMenuModFile, _("Modifier le fichier de l\'image"), wxEmptyString, wxITEM_NORMAL);
    MenuItem4->SetBitmap(wxBitmap(wxImage(_T("res/openicon.png"))));
    ContextMenu.Append(MenuItem4);
    ContextMenu.AppendSeparator();
    MenuItem1 = new wxMenuItem((&ContextMenu), idMenuAjouter, _("Ajouter une image"), wxEmptyString, wxITEM_NORMAL);
    MenuItem1->SetBitmap(wxBitmap(wxImage(_T("res/addicon.png"))));
    ContextMenu.Append(MenuItem1);
    deleteImageItem = new wxMenuItem((&ContextMenu), idMenuDel, _("Supprimer l\'image"), wxEmptyString, wxITEM_NORMAL);
    deleteImageItem->SetBitmap(wxBitmap(wxImage(_T("res/deleteicon.png"))));
    ContextMenu.Append(deleteImageItem);
    ContextMenu.AppendSeparator();
    MenuItem7 = new wxMenuItem((&ContextMenu), idMoveUp, _("D�placer vers le haut\tCtrl-P"), _("D�placer l\'image vers le haut dans la liste"), wxITEM_NORMAL);
    MenuItem7->SetBitmap(wxBitmap(wxImage(_T("res/up.png"))));
    ContextMenu.Append(MenuItem7);
    MenuItem8 = new wxMenuItem((&ContextMenu), idMoveDown, _("D�placer vers le bas"), _("D�placer l\'image vers le bas dans la liste"), wxITEM_NORMAL);
    MenuItem8->SetBitmap(wxBitmap(wxImage(_T("res/down.png"))));
    ContextMenu.Append(MenuItem8);
    MenuItem2 = new wxMenuItem((&emptyMenu), ID_MENUITEM1, _("Ajouter une image"), wxEmptyString, wxITEM_NORMAL);
    MenuItem2->SetBitmap(wxBitmap(wxImage(_T("res/addicon.png"))));
    emptyMenu.Append(MenuItem2);
    emptyMenu.AppendSeparator();
    MenuItem6 = new wxMenuItem((&emptyMenu), ID_MENUITEM2, _("Ajouter un dossier"), wxEmptyString, wxITEM_NORMAL);
    MenuItem6->SetBitmap(wxBitmap(wxImage(_T("res/dossier.png"))));
    emptyMenu.Append(MenuItem6);
    MenuItem9 = new wxMenuItem((&folderMenu), ID_MENUITEM3, _("Renommer"), wxEmptyString, wxITEM_NORMAL);
    MenuItem9->SetBitmap(wxBitmap(wxImage(_T("res/editnom.png"))));
    folderMenu.Append(MenuItem9);
    MenuItem13 = new wxMenuItem((&folderMenu), ID_MENUITEM5, _("Supprimer"), wxEmptyString, wxITEM_NORMAL);
    MenuItem13->SetBitmap(wxBitmap(wxImage(_T("res/deleteicon.png"))));
    folderMenu.Append(MenuItem13);
    folderMenu.AppendSeparator();
    MenuItem10 = new wxMenuItem((&folderMenu), ID_MENUITEM6, _("Ajouter une image"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->SetBitmap(wxBitmap(wxImage(_T("res/addicon.png"))));
    folderMenu.Append(MenuItem10);
    folderMenu.AppendSeparator();
    MenuItem5 = new wxMenuItem((&folderMenu), ID_MENUITEM4, _("Ajouter un dossier"), wxEmptyString, wxITEM_NORMAL);
    folderMenu.Append(MenuItem5);
    folderMenu.AppendSeparator();
    MenuItem11 = new wxMenuItem((&folderMenu), ID_MENUITEM7, _("D�placer vers le haut"), wxEmptyString, wxITEM_NORMAL);
    MenuItem11->SetBitmap(wxBitmap(wxImage(_T("res/up.png"))));
    folderMenu.Append(MenuItem11);
    MenuItem12 = new wxMenuItem((&folderMenu), ID_MENUITEM8, _("D�placer vers le bas"), wxEmptyString, wxITEM_NORMAL);
    MenuItem12->SetBitmap(wxBitmap(wxImage(_T("res/down.png"))));
    folderMenu.Append(MenuItem12);
    FlexGridSizer2->Fit(this);
    FlexGridSizer2->SetSizeHints(this);

    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT,(wxObjectEventFunction)&EditorImages::OnBanqueImageListBeginLabelEdit);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_END_LABEL_EDIT,(wxObjectEventFunction)&EditorImages::OnBanqueImageListEndLabelEdit);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&EditorImages::OnBanqueImageListItemActivated1);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_SEL_CHANGED,(wxObjectEventFunction)&EditorImages::OnBanqueImageListSelectionChanged);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_ITEM_MENU,(wxObjectEventFunction)&EditorImages::OnBanqueImageListItemMenu);
    apercuPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&EditorImages::OnapercuPanelPaint,0,this);
    Core->Connect(wxEVT_SIZE,(wxObjectEventFunction)&EditorImages::OnResize,0,this);
    Connect(idMenuModProp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnModPropSelected);
    Connect(idMenuMod,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnModNameImageBtClick);
    Connect(idMenuModFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnModFileImage);
    Connect(idMenuAjouter,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnAddImageBtClick);
    Connect(idMenuDel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnDelImageBtClick);
    Connect(idMoveUp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnMoveUpSelected);
    Connect(idMoveDown,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnMoveDownSelected);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnAddImageBtClick);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnAddFolderSelected);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnModNameImageBtClick);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnRemoveFolderSelected);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnAddImageBtClick);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnAddFolderSelected);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnMoveUpSelected);
    Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EditorImages::OnMoveDownSelected);
    //*)

    //EditorImages can be used without ribbon
    if ( !useRibbon )
        CreateToolbar();
    else
        ConnectEvents();

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&EditorImages::OnRefreshBtClick);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&EditorImages::OnOpenPaintProgramClick);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&EditorImages::OnMoreOptions);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&EditorImages::DossierBt);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&EditorImages::OnChercherBtClick);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&EditorImages::OnAideBtClick);

    Refresh();

    SplitterWindow1->Unsplit(BanqueImageList);
    SplitterWindow1->Unsplit(apercuPanel);
    if ( GetSize().GetWidth() > 350 )
        SplitterWindow1->SplitVertically(BanqueImageList, apercuPanel);
    else
        SplitterWindow1->SplitHorizontally(BanqueImageList, apercuPanel);
}

/**
 * Adapt splitterwindow and toolbar when resizing
 */
void EditorImages::OnResize(wxSizeEvent& event)
{
    if ( !useRibbon )
    {
        toolbarPanel->SetSize(event.GetSize().GetWidth(), toolbar->GetSize().GetHeight());
        toolbar->SetSize(toolbarPanel->GetSize().x, -1);
    }

    SplitterWindow1->Unsplit(BanqueImageList);
    SplitterWindow1->Unsplit(apercuPanel);
    if ( GetSize().GetWidth() > 350 )
        SplitterWindow1->SplitVertically(BanqueImageList, apercuPanel);
    else
        SplitterWindow1->SplitHorizontally(BanqueImageList, apercuPanel);

    SplitterWindow1->SetSize(event.GetSize());
}

EditorImages::~EditorImages()
{
    //(*Destroy(EditorImages)
    //*)
}

void EditorImages::ConnectEvents()
{
    if ( !useRibbon ) return;

    mainEditorCommand.GetMainEditor()->Connect(idRibbonAdd, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnAddImageBtClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonDel, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnDelImageBtClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonModProp, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnModPropSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonMod, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnModNameImageBtClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonModFile, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnModFileImage, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonAddDossier, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnMenuItem5Selected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonRemoveDossier, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnMenuItem6Selected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonUp, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnMoveUpSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonDown, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnMoveDownSelected, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonDirectories, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::DossierBt, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonPaintProgram, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnOpenPaintProgramClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonSearch, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnChercherBtClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonHelp, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnAideBtClick, NULL, this);
    mainEditorCommand.GetMainEditor()->Connect(idRibbonRefresh, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, (wxObjectEventFunction)&EditorImages::OnRefreshBtClick, NULL, this);
}

/**
 * Static method for creating the ribbon's page used by Images Editors
 */
void EditorImages::CreateRibbonPage(wxRibbonPage * page)
{
    wxConfigBase *pConfig = wxConfigBase::Get();
    bool hideLabels = false;
    pConfig->Read( _T( "/Skin/HideLabels" ), &hideLabels );

    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Liste d'images"), wxBitmap("res/list24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonAdd, !hideLabels ? _("Ajouter une image") : "", wxBitmap("res/add24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonDel, !hideLabels ? _("Supprimer") : "", wxBitmap("res/delete24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonUp, !hideLabels ? _("D�placer vers le haut") : "", wxBitmap("res/up24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonDown, !hideLabels ? _("D�placer vers le bas") : "", wxBitmap("res/down24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonSearch, !hideLabels ? _("Rechercher") : "", wxBitmap("res/search24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonRefresh, !hideLabels ? _("Rafraichir") : "", wxBitmap("res/refreshicon24.png", wxBITMAP_TYPE_ANY));
    }

    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Image s�lectionn�e"), wxBitmap("res/edit24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonMod, !hideLabels ? _("Nom") : "", wxBitmap("res/editname24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonModFile, !hideLabels ? _("Modifier le fichier") : "", wxBitmap("res/openicon24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonModProp, !hideLabels ? _("Propri�t�s") : "", wxBitmap("res/editprop24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonPaintProgram, !hideLabels ? _("Editer") : "", wxBitmap("res/paint24.png", wxBITMAP_TYPE_ANY));
    }

    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Dossiers"), wxBitmap("res/dossier24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonDirectories, !hideLabels ? _("Choisir") : "", wxBitmap("res/dossier24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonAddDossier, !hideLabels ? _("Ajouter au dossier") : "", wxBitmap("res/add24.png", wxBITMAP_TYPE_ANY));
        ribbonBar->AddButton(idRibbonRemoveDossier, !hideLabels ? _("Enlever") : "", wxBitmap("res/remove24.png", wxBITMAP_TYPE_ANY));
    }

    {
        wxRibbonPanel *ribbonPanel = new wxRibbonPanel(page, wxID_ANY, _("Aide"), wxBitmap("res/helpicon24.png", wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE);
        wxRibbonButtonBar *ribbonBar = new wxRibbonButtonBar(ribbonPanel, wxID_ANY);
        ribbonBar->AddButton(idRibbonHelp, !hideLabels ? _("Aide") : "", wxBitmap("res/helpicon24.png", wxBITMAP_TYPE_ANY));
    }

}

////////////////////////////////////////////////////////////
/// Cr�ation de la toolbar
////////////////////////////////////////////////////////////
void EditorImages::CreateToolbar()
{
    //Barre d'outils
    toolbar = new wxToolBar( toolbarPanel, -1, wxDefaultPosition, wxDefaultSize,
                                    wxTB_FLAT /*| wxTB_NODIVIDER*/ );

    toolbar->SetToolBitmapSize( wxSize( 16, 16 ) );
    toolbar->AddTool( ID_BITMAPBUTTON1, wxT( "Rafraichir" ), wxBitmap( wxImage( "res/refreshicon.png" ) ), _("Rafraichir la liste d'images") );
    toolbar->AddSeparator();
    toolbar->AddTool( idMenuAjouter, wxT( "Ajouter une image" ), wxBitmap( wxImage( "res/addicon.png" ) ), _("Ajouter une image") );
    toolbar->AddTool( idMenuDel, wxT( "Supprimer l'image selectionn�e" ), wxBitmap( wxImage( "res/deleteicon.png" ) ), _("Supprimer l'image selectionn�e") );
    toolbar->AddTool( idMenuModProp, wxT( "Modifier les propri�t�s de l'image" ), wxBitmap( wxImage( "res/editpropicon.png" ) ), _("Modifier les propri�t�s de l'image") );
    toolbar->AddTool( ID_BITMAPBUTTON6, wxT( "Plus d'options d'�dition ( clic droit sur la liste )" ), wxBitmap( wxImage( "res/moreicon.png" ) ), _("Plus d'options d'�dition ( clic droit sur la liste )") );
    toolbar->AddSeparator();
    toolbar->AddTool( ID_BITMAPBUTTON5, wxT( "Ouvrir l'image avec un �diteur" ), wxBitmap( wxImage( "res/paint.png" ) ), _("Ouvrir l'image avec un �diteur") );
    toolbar->AddTool( ID_BITMAPBUTTON4, wxT( "Naviguer dans les dossiers" ), wxBitmap( wxImage( "res/dossier.png" ) ), _("Naviguer dans les dossiers") );
    toolbar->AddTool( ID_BITMAPBUTTON2, wxT( "Rechercher une image" ), wxBitmap( wxImage( "res/searchicon.png" ) ), _("Rechercher une image") );
    toolbar->AddSeparator();
    toolbar->AddTool( ID_BITMAPBUTTON3, wxT( "Aide de l'�diteur de la banque d'images" ), wxBitmap( wxImage( "res/helpicon.png" ) ), _("Aide de l'�diteur de la banque d'images") );
    toolbar->Realize();

    //Obligatoire avec wxGTK, sinon la toolbar ne s'affiche pas
#ifdef __WXGTK__
    wxSize tbSize = toolbar->GetSize();
    gtk_widget_set_usize( toolbar->m_widget, tbSize.GetWidth(), tbSize.GetHeight() );
#endif
}

wxTreeItemId EditorImages::GetSelectedFolderItem()
{
    wxTreeItemId item = m_itemSelected;

    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(item));
    while ( item.IsOk() && data && data->GetString() != "Folder" && data->GetString() != "BaseFolder" )
    {
        item = BanqueImageList->GetItemParent(item);
        data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(item));
    }

    return item.IsOk() ? item : BanqueImageList->GetRootItem();
}

/**
 * Add a new image
 */
void EditorImages::OnAddImageBtClick( wxCommandEvent& event )
{
    wxFileDialog FileDialog( this, _("Choisissez une ou plusieurs images � ajouter"), "", "", _("Images support�es|*.bmp;*.gif;*.jpg;*.png;*.tga;*.dds|Tous les fichiers|*.*"), wxFD_MULTIPLE );

    if ( FileDialog.ShowModal() == wxID_OK )
    {
        wxLogStatus( _( "Ajout des images" ) );

        wxArrayString files;
        wxArrayString names;
        FileDialog.GetFilenames( names );
        FileDialog.GetPaths( files );
        string imageNonAjoutees;

        //Find current folder, if any.
        Dossier * currentFolder = NULL;
        wxTreeItemId currentFolderItem = GetSelectedFolderItem();
        gdTreeItemStringData * currentFolderData = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData( currentFolderItem ));
        if ( currentFolderData && currentFolderData->GetString() == "Folder" )
        {
            for (unsigned int i = 0;i< game.imagesFolders.size();++i)
            {
                if ( game.imagesFolders[i].nom == currentFolderData->GetSecondString() )
                    currentFolder = &game.imagesFolders[i];
            }
        }

        //Add each image to images list and to folder if any
        for ( unsigned int i = 0; i < files.GetCount();++i )
        {
            wxLogStatus( _( "Ajout de l'image " ) + names[i] );

            if ( FindImage(game.images, string(names[i])) == -1 )
            {
                Image image;
                image.file = string(files[i].mb_str());
                image.nom = string(names[i].mb_str());

                game.images.push_back(image);
                game.imagesChanged.push_back(image.nom);
                if ( currentFolder ) //Add image to folder if a folder is selected
                {
                    currentFolder->contenu.push_back(image.nom);
                    BanqueImageList->AppendItem( currentFolderItem, names[i], -1, -1, new gdTreeItemStringData("Image", image.nom));
                }

                BanqueImageList->AppendItem( allImagesItem, names[i], -1, -1, new gdTreeItemStringData("Image", image.nom));
            }
            else
                imageNonAjoutees += "\n"+string(names[i].mb_str());

        }

        if ( !imageNonAjoutees.empty() )
            wxLogMessage(wxString(_("Des images portant le m�me nom sont d�j� pr�sentes, et n'ont pas �t� ajout�es :")+imageNonAjoutees));

        wxLogStatus( _( "L'image a �t� correctement ajout�e � la banque d'image" ) );
    }

}

/**
 * Tool function
 */
void EditorImages::RemoveImageFromTree(wxTreeItemId parent, std::string imageName)
{
    void * cookie;
    wxTreeItemId item = BanqueImageList->GetFirstChild( parent, cookie );
    while ( item.IsOk() )
    {
        //Recurse if needed
        if ( BanqueImageList->ItemHasChildren(item) )
            RemoveImageFromTree(item, imageName);

        //Delete item if needed
        gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(item));
        if ( data && data->GetSecondString() == imageName && data->GetString() == "Image")
        {
            wxTreeItemId next = BanqueImageList->GetNextSibling( item );
            BanqueImageList->Delete(item);
            item = next;
        }
        else
            item = BanqueImageList->GetNextSibling( item );
    }
}

/**
 * Delete an image from folder/all images
 */
void EditorImages::OnDelImageBtClick( wxCommandEvent& event )
{
    gdTreeItemStringData * itemData = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(m_itemSelected));
    if ( itemData && itemData->GetString() == "Image" )
    {
        std::string imageName = ( string ) BanqueImageList->GetItemText( m_itemSelected );

        int i = FindImage( game.images, imageName );
        if ( i != -1 )
        {
            game.imagesChanged.push_back(game.images[i].nom);
            game.images.erase( game.images.begin() + i );
            Dossier::RemoveImage(&game.imagesFolders, imageName );
        }

        RemoveImageFromTree( BanqueImageList->GetRootItem(), imageName );

        return;

    }
    else
    {
        wxLogStatus( _( "Aucune image s�lectionn�e" ) );
    }
}

////////////////////////////////////////////////////////////
/// Modification d'une image d�j� existante
////////////////////////////////////////////////////////////
void EditorImages::OnModNameImageBtClick( wxCommandEvent& event )
{
    wxTreeItemId Item = m_itemSelected;
    wxTreeItemId ItemNul = NULL;
    if ( Item != ItemNul && BanqueImageList->GetChildrenCount( m_itemSelected ) == 0 )
    {
        BanqueImageList->EditLabel( m_itemSelected );
    }
    else
    {
        wxLogStatus( _( "Aucune image s�lectionn�e" ) );
    }
}

////////////////////////////////////////////////////////////
/// Affichage du menu
////////////////////////////////////////////////////////////
void EditorImages::OnBanqueImageListItemMenu( wxTreeEvent& event )
{
    //Editor have focus
    wxFocusEvent unusedEvent;
    OnSetFocus(unusedEvent);

    m_itemSelected = event.GetItem();

    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(event.GetItem()));
    if ( data && data->GetString() == "Image" )
        PopupMenu( &ContextMenu );
    else if ( data && data->GetString() == "Folder" )
        PopupMenu( &folderMenu);
    else
        PopupMenu( &emptyMenu );
}

////////////////////////////////////////////////////////////
/// Affichage du menu ( plus d'options )
////////////////////////////////////////////////////////////
void EditorImages::OnMoreOptions( wxCommandEvent& event )
{
    PopupMenu( &ContextMenu );
}

////////////////////////////////////////////////////////////
/// Clic sur le bouton de rafraichissement
////////////////////////////////////////////////////////////
void EditorImages::OnRefreshBtClick( wxCommandEvent& event )
{
    Refresh();
}

/**
 * Selecting an image
 */
void EditorImages::OnBanqueImageListSelectionChanged( wxTreeEvent& event )
{
    //Editor have focus
    wxFocusEvent unusedEvent;
    OnSetFocus(unusedEvent);

    string nom = ( string ) BanqueImageList->GetItemText( event.GetItem() );
    //Changement de l'item s�lectionn�
    m_itemSelected = event.GetItem();

    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(event.GetItem()));
    if ( data && data->GetString() == "Image" )
    {
        //Zone d'aper�u de l'image
        int i = FindImage( game.images, nom );
        if ( i != -1 )
        {
            fileImageSelected = game.images.at( i ).file;
            apercuPanel->Refresh();
            apercuPanel->Update();
        }
    }

}

/**
 * Tool function
 */
void EditorImages::RenameInTree(wxTreeItemId parent, std::string oldName, std::string newName, std::string type)
{
    void * cookie;
    wxTreeItemId item = BanqueImageList->GetFirstChild( parent, cookie );
    while ( item.IsOk() )
    {
        //Recurse if needed
        if ( BanqueImageList->ItemHasChildren(item) )
            RenameInTree(item, oldName, newName, type);

        //Delete item if needed
        gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(item));
        if ( data && data->GetSecondString() == oldName && data->GetString() == type)
        {
            BanqueImageList->SetItemText(item, newName);
            data->SetSecondString(newName);
        }

        item = BanqueImageList->GetNextSibling( item );
    }
}

/**
 * End renaming something
 */
void EditorImages::OnBanqueImageListEndLabelEdit( wxTreeEvent& event )
{
    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(event.GetItem()));
    if ( !event.IsEditCancelled() && data )
    {
        std::string newName = string(event.GetLabel().mb_str());

        if ( data->GetString() == "Folder" )
        {
            for (unsigned int i = 0;i<game.imagesFolders.size();++i)
            {
                if ( newName == game.imagesFolders[i].nom )
                {
                    wxLogWarning( _( "Impossible de renommer le dossier : un autre dossier porte d�j� ce nom." ) );
                    event.Veto();
                    return;
                }
            }

            for (unsigned int i = 0;i<game.imagesFolders.size();++i)
            {
                if ( renamedItemOldName == game.imagesFolders[i].nom )
                    game.imagesFolders[i].nom = newName;
            }
            RenameInTree(BanqueImageList->GetRootItem(), renamedItemOldName, newName, "Folder");
        }
        else if ( data->GetString() == "Image" )
        {
            if ( FindImage( game.images, newName ) != -1 )
            {
                wxLogWarning( _( "Impossible de renommer l'image : une autre image porte d�j� ce nom." ) );
                Refresh();
                return;
            }

            int i = FindImage( game.images, renamedItemOldName );
            if ( i != -1 )
            {
                game.imagesChanged.push_back(game.images.at( i ).nom);
                game.imagesChanged.push_back(newName);

                game.images.at( i ).nom = newName;
                Dossier::ReplaceNomImage(&game.imagesFolders, renamedItemOldName, newName);

                RenameInTree(BanqueImageList->GetRootItem(), renamedItemOldName, newName, "Image");

                return;
            }
        }
    }
}

/**
 * Rename something
 */
void EditorImages::OnBanqueImageListBeginLabelEdit( wxTreeEvent& event )
{
    if ( gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(event.GetItem())) )
    {
        if ( data->GetString() == "BaseFolder" )
            BanqueImageList->EndEditLabel( event.GetItem(), true );
        else
            renamedItemOldName = BanqueImageList->GetItemText( event.GetItem() );
    }
    else
        BanqueImageList->EndEditLabel( event.GetItem(), true );
}

/**
 * Refresh images lists
 */
void EditorImages::Refresh()
{
    BanqueImageList->DeleteAllItems();
    BanqueImageList->AddRoot( "ImagesBank" );

    //Folders
    for (unsigned int i = 0;i< game.imagesFolders.size() ;++i)
    {
        wxTreeItemId folderItem = BanqueImageList->AppendItem( BanqueImageList->GetRootItem(), game.imagesFolders[i].nom, -1, -1, new gdTreeItemStringData("Folder", game.imagesFolders[i].nom ));
        for (unsigned int j=0;j<game.imagesFolders[i].contenu.size();++j)
            BanqueImageList->AppendItem( folderItem, game.imagesFolders[i].contenu[j], -1,-1, new gdTreeItemStringData("Image", game.imagesFolders[i].contenu[j] ));
    }

    //All images
    allImagesItem = BanqueImageList->AppendItem( BanqueImageList->GetRootItem(), _("Toutes les images"), -1,-1, new gdTreeItemStringData("BaseFolder", "" ));
    for ( unsigned int i = 0;i < game.images.size();i++ )
        BanqueImageList->AppendItem( allImagesItem, game.images[i].nom, -1, -1, new gdTreeItemStringData("Image", game.images[i].nom ));

    BanqueImageList->Expand( allImagesItem );

    #if defined(DESACTIVATED_FOR_WX290)
    filesWatcher.RemoveAll();
    for ( unsigned int i = 0;i < game.images.size();i++ )
        filesWatcher.Add(wxFileName(game.images[i].file).GetPath());
    #endif
}

////////////////////////////////////////////////////////////
/// Modifier le fichier d'une image
////////////////////////////////////////////////////////////
void EditorImages::OnModFileImage( wxCommandEvent& event )
{
    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(m_itemSelected));
    if ( !data || data->GetString() != "Image" ) return;

    int i = FindImage( game.images, data->GetSecondString() );
    if ( i == -1 )
    {
        wxLogStatus( _( "L'image � modifier n'a pas �t� trouv�e." ) );
        return;
    }

    //Boite de dialogue d'ajout d'une image
    wxFileDialog FileDialog( this, _( "Choisissez le fichier de l'image" ), "", "", _("Images support�es|*.bmp;*.gif;*.jpg;*.png;*.tga;*.dds|Tous les fichiers|*.*"), wxFD_OPEN );
    if ( FileDialog.ShowModal() == wxID_OK )
    {
        wxLogStatus( _( "Changement du fichier de l'image..." ) );

        string newFile = string(FileDialog.GetPath().mb_str());

        game.images.at( i ).file = newFile;
        //Ne concerne pas les dossiers

        game.imagesChanged.push_back(game.images.at( i ).nom);
        wxLogStatus( _( "Changement du fichier de l'image effectu�" ) );
    }

}

void EditorImages::OnChercherBtClick( wxCommandEvent& event )
{
    string name = static_cast<string>( wxGetTextFromUser( _( "Entrez le nom de l'image � rechercher" ), _( "Chercher une image" ) ) );
    if ( name == "" ) return;

    int i = FindImage( game.images, name );
    if ( i != -1 )
    {
        //On en a trouv� un, on le s�lectionne.
        void * rien;
        wxTreeItemId item = BanqueImageList->GetFirstChild( BanqueImageList->GetRootItem(), rien );
        while ( BanqueImageList->GetItemText( item ) != name )
        {
            item = BanqueImageList->GetNextSibling( item );
        }

        BanqueImageList->SelectItem( item );

        return;
    }
    else { wxLogMessage( "Aucune image de ce nom trouv�e !" ); }
}

void EditorImages::OnAideBtClick( wxCommandEvent& event )
{
    HelpFileAccess * helpFileAccess = HelpFileAccess::GetInstance();
    helpFileAccess->DisplaySection(9);
}

void EditorImages::DossierBt( wxCommandEvent& event )
{
}


/**
 * Add an image to the folder
 */
void EditorImages::OnMenuItem5Selected(wxCommandEvent& event)
{
}

/**
 * Suppress an image only from the current folder
 */
void EditorImages::OnMenuItem6Selected(wxCommandEvent& event)
{
}

/**
 * Modify image properties
 */
void EditorImages::OnModPropSelected(wxCommandEvent& event)
{
    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(m_itemSelected));
    if ( !data || data->GetString() != "Image" ) return;

    int i = FindImage( game.images, data->GetSecondString() );
    if ( i == -1 )
    {
        wxLogStatus( _( "L'image � modifier n'a pas �t� trouv�e." ) );
        return;
    }

    PropImage dialog(this, game.images.at(i));
    if ( dialog.ShowModal() == 1 )
        game.imagesChanged.push_back(game.images.at(i).nom);
}
void EditorImages::OnBanqueImageListItemActivated1(wxTreeEvent& event)
{
    wxFocusEvent unusedEvent;
    OnSetFocus(unusedEvent);

    wxCommandEvent eventUseless;
    OnModPropSelected( eventUseless );
}

/**
 * Open an external image edition program
 */
void EditorImages::OnOpenPaintProgramClick(wxCommandEvent& event)
{
    wxConfigBase *pConfig = wxConfigBase::Get();
    wxString result;
    pConfig->Read( _T( "/EditeursExternes/Image" ), &result );

    if ( result.empty() )
    {
        wxFileDialog dialog(this, _("Choisissez le programme d'�dition d'images ( fichier exe )"), "", "", _("Programmes (*.exe)|*.exe"));
        dialog.ShowModal();

        pConfig->Write( _T( "/EditeursExternes/Image" ), dialog.GetPath() );
        pConfig->Read( _T( "/EditeursExternes/Image" ), &result );
    }

    if ( !result.empty() )
    {
        gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(m_itemSelected));
        if ( !data || data->GetString() != "Image" ) return;

        int i = FindImage( game.images, data->GetSecondString() );
        if ( i == -1 )
        {
            wxExecute(result);
            return;
        }

        wxExecute(result+" \""+game.images.at(i).file+"\"");
    }
}

/**
 * Display a preview of the selected image
 */
void EditorImages::OnapercuPanelPaint(wxPaintEvent& event)
{
    wxPaintDC dc( apercuPanel ); //Cr�ation obligatoire du wxBufferedPaintDC

    wxSize size = apercuPanel->GetSize();

    BitmapGUIManager * bitmapGUIManager = BitmapGUIManager::GetInstance();

    //Fond en damier
    dc.SetBrush(bitmapGUIManager->transparentBg);
    dc.DrawRectangle(0,0, size.GetWidth(), size.GetHeight());

    if ( !wxFile::Exists(fileImageSelected) )
        return;

    wxBitmap bmp( fileImageSelected, wxBITMAP_TYPE_ANY);
    if ( bmp.GetWidth() > 120 || bmp.GetHeight() > 120 )
    {
        //R�duction � l'�chelle
        int max = bmp.GetWidth() > bmp.GetHeight() ? bmp.GetWidth() : bmp.GetHeight();
        float factor = 120.f/max;

        wxImage image = bmp.ConvertToImage();
        bmp = wxBitmap(image.Scale(bmp.GetWidth()*factor, bmp.GetHeight()*factor));
    }

    //Display image in the center
    if ( bmp.IsOk() )
        dc.DrawBitmap(bmp,
                      (size.GetWidth() - bmp.GetWidth()) / 2,
                      (size.GetHeight() - bmp.GetHeight()) / 2,
                      true /* use mask */);
}

/**
 * Tool function
 */
void EditorImages::ShiftUpElementOfTree()
{
    wxTreeItemId previous = BanqueImageList->GetPrevSibling(m_itemSelected);
    wxString oldText = BanqueImageList->GetItemText( m_itemSelected );
    wxTreeItemData * oldData = BanqueImageList->GetItemData( m_itemSelected );

    BanqueImageList->SetItemText( m_itemSelected, BanqueImageList->GetItemText(previous) );
    BanqueImageList->SetItemData( m_itemSelected, BanqueImageList->GetItemData(previous) );
    BanqueImageList->SetItemText( previous, oldText );
    BanqueImageList->SetItemData( previous, oldData );

    BanqueImageList->SelectItem(previous);
}

/**
 * Move up an image
 */
void EditorImages::OnMoveUpSelected(wxCommandEvent& event)
{
    string name = static_cast< string > ( BanqueImageList->GetItemText( m_itemSelected ));
    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(m_itemSelected));
    if ( !data ) return;

    //Move an image
    if ( data->GetString() == "Image" )
    {
        gdTreeItemStringData * parentFolderData = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(GetSelectedFolderItem()));

        //Move image from base folder
        if ( !parentFolderData || parentFolderData->GetString() == "BaseFolder" )
        {
            int i = FindImage( game.images, name );
            if ( i == -1 )
            {
                wxLogStatus( _( "L'image � d�placer n'a pas �t� trouv�e." ) );
                return;
            }
            else if ( i > 0 )
            {
                swap (game.images[i], game.images[i-1]);
                ShiftUpElementOfTree();
            }
        }
        //Move an image of a folder
        else if ( parentFolderData && parentFolderData->GetString() == "Folder" )
        {
            for (unsigned int i = 0;i< game.imagesFolders.size();++i)
            {
                if ( game.imagesFolders[i].nom == parentFolderData->GetSecondString() )
                {
                    for (unsigned int j = 1;j<game.imagesFolders[i].contenu.size();++j)
                    {
                        if ( game.imagesFolders[i].contenu[j] == name )
                        {
                            std::swap(game.imagesFolders[i].contenu[j], game.imagesFolders[i].contenu[j-1]);
                            ShiftUpElementOfTree();

                            return;
                        }
                    }
                }
            }
        }

    }
    //Move a folder
    else if ( data->GetString() == "Folder" )
    {
        for (unsigned int i =1;i<game.imagesFolders.size();++i)
        {
        	if ( game.imagesFolders[i].nom == name )
            {
                std::swap(game.imagesFolders[i], game.imagesFolders[i-1]);
                Refresh();

                return;
            }
        }
    }
}

/**
 * Tool function
 */
void EditorImages::ShiftDownElementOfTree()
{
    wxTreeItemId next = BanqueImageList->GetNextSibling(m_itemSelected);
    wxString oldText = BanqueImageList->GetItemText( m_itemSelected );
    wxTreeItemData * oldData = BanqueImageList->GetItemData( m_itemSelected );

    BanqueImageList->SetItemText( m_itemSelected, BanqueImageList->GetItemText(next) );
    BanqueImageList->SetItemData( m_itemSelected, BanqueImageList->GetItemData(next) );
    BanqueImageList->SetItemText( next, oldText );
    BanqueImageList->SetItemData( next, oldData );

    BanqueImageList->SelectItem(next);
}

/**
 * Move down an image
 */
void EditorImages::OnMoveDownSelected(wxCommandEvent& event)
{
    string name = static_cast< string > ( BanqueImageList->GetItemText( m_itemSelected ));
    gdTreeItemStringData * data = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(m_itemSelected));
    if ( !data ) return;

    //Move an image
    if ( data->GetString() == "Image" )
    {
        gdTreeItemStringData * parentFolderData = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData(GetSelectedFolderItem()));

        //Move image from base folder
        if ( !parentFolderData || parentFolderData->GetString() == "BaseFolder" )
        {
            int i = FindImage( game.images, name );
            if ( i == -1 )
            {
                wxLogStatus( _( "L'image � d�placer n'a pas �t� trouv�e." ) );
                return;
            }
            else if ( i+1 < game.images.size() )
            {
                swap (game.images[i], game.images[i+1]);
                ShiftDownElementOfTree();

                return;
            }
        }
        //Move an image of a folder
        else if ( parentFolderData && parentFolderData->GetString() == "Folder" )
        {
            for (unsigned int i = 0;i< game.imagesFolders.size();++i)
            {
                if ( game.imagesFolders[i].nom == parentFolderData->GetSecondString() )
                {
                    for (unsigned int j = 0;j<game.imagesFolders[i].contenu.size()-1;++j)
                    {
                        if ( game.imagesFolders[i].contenu[j] == name )
                        {
                            std::swap(game.imagesFolders[i].contenu[j], game.imagesFolders[i].contenu[j+1]);
                            ShiftDownElementOfTree();

                            return;
                        }
                    }
                }
            }
        }

    }
    //Move a folder
    else if ( data->GetString() == "Folder" )
    {
        for (unsigned int i =0;i<game.imagesFolders.size()-1;++i)
        {
        	if ( game.imagesFolders[i].nom == name )
            {
                std::swap(game.imagesFolders[i], game.imagesFolders[i+1]);
                Refresh();

                return;
            }
        }
    }
}

/**
 * Begin dragging image ( can be dropped in a Objects Editor so as to create easily an object )
 */
void EditorImages::OnBanqueImageListBeginDrag(wxTreeEvent& event)
{
    if ( event.GetItem().IsOk() && event.GetItem() != BanqueImageList->GetRootItem() )
    {
        wxTextDataObject name(BanqueImageList->GetItemText(event.GetItem()));
        wxDropSource dragSource( this );
        dragSource.SetData( name );
        dragSource.DoDragDrop( true );
    }
}

/**
 * Show appropriate ribbon page when get focus.
 */
void EditorImages::OnSetFocus(wxFocusEvent& event)
{
    ForceRefreshRibbonAndConnect();
}

void EditorImages::ForceRefreshRibbonAndConnect()
{
    if ( useRibbon )
    {
        mainEditorCommand.GetRibbon()->SetActivePage(2);
        ConnectEvents();
    }
}

void EditorImages::OnAddFolderSelected(wxCommandEvent& event)
{
    wxTreeItemId newFolderItem = BanqueImageList->AppendItem(BanqueImageList->GetRootItem(), _("Nouveau dossier"), -1, -1, new gdTreeItemStringData("Folder", string(_("Nouveau dossier").mb_str())));

    Dossier newFolder;
    newFolder.nom = _("Nouveau dossier");
    game.imagesFolders.push_back(newFolder);

    BanqueImageList->EditLabel(newFolderItem);
}

void EditorImages::OnRemoveFolderSelected(wxCommandEvent& event)
{
    wxTreeItemId currentFolderItem = GetSelectedFolderItem();
    gdTreeItemStringData * currentFolderData = dynamic_cast<gdTreeItemStringData*>(BanqueImageList->GetItemData( currentFolderItem ));
    if ( currentFolderData && currentFolderData->GetString() == "Folder" )
    {
        for (unsigned int i = 0;i< game.imagesFolders.size();++i)
        {
            if ( game.imagesFolders[i].nom == currentFolderData->GetSecondString() )
                game.imagesFolders.erase(game.imagesFolders.begin()+i);
        }
        BanqueImageList->Delete(currentFolderItem);
    }

}

#endif
