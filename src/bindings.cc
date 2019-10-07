#include <string>
#include <iostream>

#include <Application.h>
#include <Archivable.h>
#include <Window.h>
#include <Alert.h>
#include <Notification.h>
#include <View.h>
#include <InterfaceKit.h>
#include <Message.h>
#include <Control.h>
#include <ScrollView.h>
#include <ListView.h>
#include <StringItem.h>
#include <Invoker.h>
#include <Notification.h>

#include "nbind/nbind.h"
#include "nbind/api.h"

#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <MenuField.h>
#include <SplitView.h>
#include <StatusBar.h>

#include <ListItem.h>
#include <List.h>

// Layouts
#include <LayoutBuilder.h>

// New Additions

#include <Box.h>
#include <Slider.h>
#include <OptionControl.h>
#include <StringItem.h>
#include <TabView.h>
#include <RadioButton.h>
#include <CheckBox.h>
#include <Font.h>

// Storage 
#include <FilePanel.h>

// Classes

class BArchivable;

class BApplication;
class BRect;
class BWindow;
class BStringView;
class BButton;
class BControl;

class BMessage;
class BFont;

class BListView;
class BStringItem;
class BScrollView;
class BLooper;

class BSplitView;

class BMenu;
class BMenuBar;
class BMenuItem;
class BStatusBar;
class BHandler;
class BMessenger;
class BListItem;
class BNotification;
class BLayout;


// New Additions
class BBox;
class BSlider;
class BOptionControl;
class BTabView;
class BRadioButton;
class BFilePanel;
class BCheckBox;
class BFont;

// Utility Classes
class BString;
class BPoint;


// Haiku Constants exposed from C++ to JavaScript via V8

// Constants end

class BeNotification : public BNotification {
  public:  
          BeNotification(uint32 type);
          ~BeNotification();
  private:
    BNotification* notif;

};

BeNotification::BeNotification(uint32 type) 
: BNotification((notification_type)type)
{

  notification_type p_type;
  
  switch(type) {
    case 0:
      p_type = B_INFORMATION_NOTIFICATION;
    break;
    case 1:
      p_type = B_IMPORTANT_NOTIFICATION;
    break;
    case 2:
      p_type = B_ERROR_NOTIFICATION;
    break;
    case 3:
      p_type = B_PROGRESS_NOTIFICATION;
    break;
  }
 
  notif = new BNotification(p_type);
}

BeNotification::~BeNotification(){

}





/// BeMessage Class //
class BeMessage : public BMessage {
    public:
      BeMessage(); // { this = new BMessage(); }
      ~BeMessage();
      BeMessage(uint32 what);   //{ this = new BMessage(what); }
      // BeMessage(const BMessage& other);
      uint32 what_id();
    private:
      uint32 what2;
};


BeMessage::BeMessage() 
: BMessage()
{

}

BeMessage::BeMessage(uint32 what)
: BMessage(what)
{
  this->what2 = what;
}

BeMessage::~BeMessage()
{
}

unsigned int BeMessage::what_id() {
  std::cout << this->what2 << std::endl;
  return this->what2;
}



class BeApplication : public BApplication {
                                    
  public:
        BeApplication();
        BeApplication(const char * sig);
        ~BeApplication();
      thread_id			run();
	  	void				  quit();


		  // virtual void				ReadyToRun();
		  // virtual void				AboutRequested();
		  // virtual void				AppActivated(bool active);
	  	void				MessageReceived(BMessage* message);
      long        Post(uint32 cmd);
			bool				isLaunching() const;
			const char*	signature() const;
      void onMessageReceived(nbind::cbFunction &cb);
      void onQuit(nbind::cbFunction &cb);
      
      BApplication* App() const;
      BMessenger AppMessenger() const;

  private:
     BApplication* BApp;
     BeMessage * msg;
     //BeMessage * msg;

     // The Event Paramenter
     //std::unique_ptr<nbind::cbFunction> *BMessageCB = NULL;
     nbind::cbFunction *BMessageCB = NULL;
};

// Set default Signature
BeApplication::BeApplication()
            : BApplication("application/x-vnd.dw-MyApp")
{
}

BeApplication::BeApplication(const char * sig)
              : BApplication(sig)
{
}
BeApplication::~BeApplication(){}

thread_id BeApplication::run() {
  return this->Run();
}

void BeApplication::quit() {
  return this->Quit();
}

const char* BeApplication::signature() const {
  return this->Signature();
}

bool BeApplication::isLaunching() const {
  return this->IsLaunching();
}

long BeApplication::Post(uint32 cmd) {
  return be_app->PostMessage(cmd);
}


BApplication* BeApplication::App() const {
  return be_app;
}

BMessenger BeApplication::AppMessenger() const {
  return be_app_messenger;
}


void BeApplication::onMessageReceived(nbind::cbFunction &cb) {
  // Save the callback in the Application object to be used later //
  this->BMessageCB = new nbind::cbFunction(cb);
}

void BeApplication::onQuit(nbind::cbFunction &cb){
  // Save the callback in the Application object to be used later //
  this->BMessageCB = new nbind::cbFunction(cb);
}

void BeApplication::MessageReceived(BMessage * msg) {
  // Implement Event to JS here //

  // this->Lock();

  if(this->BMessageCB == NULL){
    // Don't call it.
    BApplication::MessageReceived(msg);
  } else {
    //msg->PrintToStream();
    (*BMessageCB)(msg->what);
  }

  // this->Unlock();
}


class BeWindow {
  public:
      BeWindow(const char * name, float left, float top, float right, int bottom, uint32 type, uint32 flags);
      ~BeWindow();
      void AddChild(BView* view);
      void Hide();
      void Show();
    	bool IsHidden() const;
			bool IsMinimized() const;
			const char*			Title() const;
			void				SetTitle(const char* title);   
      thread_id			Run();
      void Quit();
      void Close();
      status_t SetFlags(uint32);
      uint32 Flags();
      BRect	Bounds() const;
			BRect	Frame() const;
      BWindow* GetWindow() const;

  private:
      BWindow * win;
};

BeWindow::BeWindow(const char * name, float left, float top, float right, int bottom, uint32 type, uint32 flags)
{
      enum window_type value;

      switch(type){
        case 0:
            value = B_UNTYPED_WINDOW;
            break;
        case 1:
            value = B_TITLED_WINDOW;
            break;
        case 3:
            value = B_MODAL_WINDOW;
            break;
        case 11:
            value = B_DOCUMENT_WINDOW;
            break;
        case 20:
            value = B_BORDERED_WINDOW;
            break;
        case 21:
            value = B_FLOATING_WINDOW;
            break;
        default:
            value = B_UNTYPED_WINDOW;
            break;
      }

      win = new BWindow(BRect(left, top, right, bottom), name, value, B_ASYNCHRONOUS_CONTROLS | flags);
};


BeWindow::~BeWindow(){
};

void BeWindow::AddChild(BView* child){
  win->AddChild(child);
}

void BeWindow::Quit(){
  win->Quit();
}

void BeWindow::Show(){
  win->Show();
}

void BeWindow::Hide(){
  win->Hide();
}

bool BeWindow::IsHidden() const {
  return win->IsHidden();
}

bool BeWindow::IsMinimized() const {
  return win->IsMinimized();
}

const char* BeWindow::Title() const {
  return win->Title();
}

void BeWindow::SetTitle(const char* title){
  win->SetTitle(title);
}  

status_t BeWindow::SetFlags(uint32 flags){
  return win->SetFlags(flags);
}

uint32 BeWindow::Flags() {
  return win->Flags();
}

thread_id BeWindow::Run() {
  return win->Run();
}

void BeWindow::Close() {
  win->Quit();
}

BRect BeWindow::Frame() const {
  return win->Frame();
}

BRect BeWindow::Bounds() const {
  return win->Bounds();
}

BWindow* BeWindow::GetWindow() const {
  return this->win;
}


NBIND_CLASS(BString){
  construct<>();
  construct<const char*>();
}


NBIND_CLASS(BMessage) {
  construct<>();
  construct<unsigned int>();

  multimethod(GetUInt32, args(const char*, uint32));
  method(IsEmpty);
  // construct<BMessage&>();

  method(SetBool);
  method(SetInt8);
  method(SetUInt8);
  method(SetInt16);
  method(SetUInt16);
  method(SetInt32);
  method(SetUInt32);
  method(SetInt64);
  method(SetUInt64);

  method(SetColor);
  method(SetPointer);
  multimethod(SetString, args(const char*, const char*));
  multimethod(SetString, args(const char*,const BString&));
  method(SetFloat);
  method(SetDouble);
  // method(SetAlignment);
  method(SetPoint);
  method(SetRect);
  method(SetSize);
  method(SetData);
  method(WasDelivered);

  // Adding
  method(AddBool);
  method(AddInt8);
  method(AddUInt8);
  method(AddInt16);
  method(AddUInt16);
  method(AddInt32);
  method(AddUInt32);
  method(AddInt64);
  method(AddUInt64);
}


NBIND_CLASS(BeMessage) {
  inherit(BMessage);
  construct<>();
  construct<unsigned int>();
  method(what_id);
}



NBIND_CLASS(BView) {
  inherit(BHandler);
  construct<const char *,  unsigned int>();
  construct<BRect,const char *,  unsigned int,  unsigned int>();

  multimethod(AddChild, args(BView*, BView*), nbind::Nullable() );
  multimethod(AddChild, args(BLayoutItem*));
  method(RemoveChild);
  method(Show);
	method(Hide);

  multimethod(MoveTo, args(BPoint));
  multimethod(MoveTo, args(float, float));

  // multimethod(SetViewColor,args(rgb_color));
  multimethod(SetViewColor, args(unsigned char, unsigned char, unsigned char, unsigned char));
  // multimethod(SetViewColor, args(unsigned char, unsigned char, unsigned char, unsigned char));

  method(FindView);
	method(Parent);
	method(Bounds);
	method(Frame);

}


NBIND_CLASS(BStringView) {
  inherit(BView);

  construct<BRect, const char *, const char *>();
  construct<const char *, const char *>();

	method(SetText);
	method(Text);

	method(SetAlignment);
	method(Alignment);
	
  method(SetTruncation);
	method(Truncation);

  method(SetFont);
  method(Draw);
  method(MessageReceived);
  method(ResizeToPreferred);
}


NBIND_CLASS(BInvoker) {
  construct<BMessage*, BHandler*>();

  multimethod(SetTarget, args(BMessenger));
}

// Abstract Class //
NBIND_CLASS(BListItem) {
}

NBIND_CLASS(BListView) {
  inherit(BInvoker);
  inherit(BView);

  construct<BRect, const char *>();
  construct<const char *>();
	multimethod(AddItem, args(BListItem*));
  multimethod(AddList, args(BList*));
  
  multimethod(RemoveItem, args(int32));
  multimethod(RemoveItem, args(BListItem*));
  method(SetSelectionMessage);
}


NBIND_CLASS(BList) {
  construct<>();
  construct<BList&>();
}


NBIND_CLASS(BStringItem){
  inherit(BListItem);

  construct<const char*>();
  method(SetText);
}


NBIND_CLASS(BSplitView){
  inherit(BView);
  construct<>();
  construct<BMessage*>();

  multimethod(SetInsets, args(float, float, float, float));
  multimethod(SetInsets, args(float, float));
  multimethod(SetInsets, args(float));
  method(GetInsets);

  method(Spacing);
  method(SetSpacing);

  method(Orientation);
  method(SetOrientation);

  method(SplitterSize);
  method(SetSplitterSize);

  method(CountItems);

  method(IsCollapsible);

  multimethod(SetCollapsible, args(bool));
  multimethod(SetCollapsible, args(int32, bool));
  multimethod(SetCollapsible, args(int32, int32, bool));

  method(IsItemCollapsed); 
  method(SetItemCollapsed);

  multimethod(AddChild, args(BLayoutItem*));
  multimethod(AddChild, args(BView*, float));
  multimethod(AddChild, args(int32, BView*, float));

  multimethod(AddChild, args(BLayoutItem*, float));
  multimethod(AddChild, args(int32, BLayoutItem*, float));
}


NBIND_CLASS(BMessenger){
  construct<>();
  construct<const char*>();
}

NBIND_CLASS(BArchivable){
  construct<>();
  construct<BMessage*>();
  multimethod(Archive, args(BMessage*, bool));
}

NBIND_CLASS(BMenu) {
  inherit(BView);
  construct<const char*>();
  construct<const char*, float, float>();

  method(AddSeparatorItem);
  multimethod(AddItem, args(BMenuItem*), nbind::Nullable());
}


NBIND_CLASS(BMenuItem) {
  inherit(BArchivable);
  inherit(BInvoker);

  construct<const char*, BMessage*>(nbind::Nullable());
  construct<BMenu*>(nbind::Nullable());

  method(SetLabel);
  method(SetEnabled);
  method(SetMarked);
  method(SetTrigger);
  method(SetShortcut);

  method(Label);
  method(IsEnabled);
  method(IsMarked);
  method(Trigger);
  method(Shortcut);

  method(Submenu);
  method(Menu);
  method(Frame);
}

NBIND_CLASS(BMenuBar) {
  inherit(BMenu);
  construct<const char*>();
  construct<BRect, const char*>();
}

NBIND_CLASS(BStatusBar) {
  inherit(BView);

  construct<BRect, const char*>();
  construct<const char*>();
  construct<const char*, const char*>();
  construct<const char*, const char*, const char*>();

  method(SetBarColor);
  method(SetBarHeight);

  method(SetText);
  method(SetTrailingText);
  method(SetMaxValue);
}

NBIND_CLASS(BControl){
  inherit(BView);
  inherit(BInvoker);
  construct<BRect, const char *, const char *, BMessage*, uint32, uint32>();
  construct<const char *, const char *, BMessage*, uint32>();
  construct<BMessage*>();

  method(Label);
  method(Value);
  method(IsEnabled);
  method(ResizeToPreferred);
  method(SetLabel);
}

NBIND_CLASS(BButton) {
  inherit(BControl);
  construct<const char *>();
  construct<const char *, const char *, BMessage*>();
  construct<const char *, const char *, BMessage*, uint32>();
  construct<BRect, const char *, const char *, BMessage*>();

  construct<BMessage*>();
  method(SetPopUpMessage);

  method(SetIcon);
  method(KeyDown);
	
  method(SetBehavior);
  method(SetPopUpMessage);

  method(MessageReceived);
  method(WindowActivated);
  method(MouseDown);
  method(MakeDefault);
}


NBIND_CLASS(BHandler){
  inherit(BArchivable);
  construct<const char *>();
  construct<BMessage*>();

  method(Name);
  method(SetName);
  method(SetNextHandler);
  method(NextHandler);
  method(Looper);

  method(AddFilter);
  method(RemoveFilter);
  method(SetFilterList);
  method(FilterList);
}


NBIND_CLASS(BLooper){
  inherit(BHandler);
}


NBIND_CLASS(BApplication){
  inherit(BLooper);

  construct<const char *>();
}


NBIND_CLASS(BeApplication) {
  inherit(BApplication);

  construct<const char *>();

  method(run);
  method(quit);

  method(isLaunching);
  method(signature);
  method(onMessageReceived);
  method(Post);
  method(App);
  method(AppMessenger);
}

NBIND_CLASS(BeWindow) {
  construct<const char *, float, float, float, int, uint32, uint32>();

  multimethod(AddChild, args(BView*));
  method(Show);
  method(Bounds);
  method(Frame);
  method(GetWindow);
}

NBIND_CLASS(BPoint){
  construct<>();
  construct<float, float>();
  method(Set);
}

NBIND_CLASS(BRect) {
	construct<>();
	construct<BRect&>();
	construct<float, float, float, float>();
	construct<float>();

	method(Set);
	method(IsValid);
	method(Width);
	method(IntegerWidth);
	method(Height);
	method(IntegerHeight);

	method(LeftTop);
	method(RightBottom);
	method(LeftBottom);
	method(RightTop);

	method(SetLeftTop);
	method(SetRightBottom);
	method(SetLeftBottom);
	method(SetRightTop);

	multimethod(InsetBy, args(BPoint));
	multimethod(InsetBy, args(float, float));
	multimethod(OffsetBy, args(BPoint));
	multimethod(OffsetBy, args(float, float));
	multimethod(OffsetTo, args(BPoint));
	multimethod(OffsetTo, args(float, float));

	multimethod(OffsetToCopy, args(float, float));
	multimethod(InsetByCopy, args(float, float));
}


NBIND_CLASS(BAlert) {
  construct<const char *, const char *, const char *>();
  construct<const char *, const char *, const char *, const char *, const char *>();
  construct<const char *, const char *, const char *, const char *, const char *, button_width, alert_type >();

  method(SetText);
  multimethod(Go, args());
}

NBIND_CLASS(BNotification){
    inherit(BArchivable);
	
	construct<notification_type>();
    construct<BMessage*>();
    
    multimethod(Archive, args(BMessage*, bool));

    method(SourceSignature);
    method(SourceName);
    method(Type);
    method(Group);
    method(SetGroup);
    method(Title);
    method(SetTitle);
    method(Content);
    method(SetContent);
    method(MessageID);
    method(SetMessageID);
    method(Progress);
    method(SetProgress);
    method(OnClickApp);
    method(SetOnClickApp);
    method(OnClickFile);
    method(SetOnClickFile);

    method(AddOnClickRef);
    method(CountOnClickRefs);
    method(OnClickRefAt);

    method(AddOnClickArg);
    method(CountOnClickArgs);
    method(OnClickArgAt);
    method(Icon);
    method(SetIcon);
    method(Send);
}

NBIND_CLASS(BScrollView){
    inherit(BView);
    construct<const char*, BView*, uint32, uint32, bool, bool>();
    construct<const char*, BView*, uint32, bool, bool>();
    method(SetTarget);   
}

NBIND_CLASS(BFont){
	construct<>();

	method(SetSize);
	method(SetShear);
	method(SetRotation);
	method(SetSpacing);
	method(SetEncoding);
	method(SetFace);
	method(SetFlags);
}

NBIND_CLASS(BTextView){
  inherit(BView);

  construct<BRect, const char *, BRect, uint32>();
  construct<const char *>();
  //construct<const char*, uint32>();

  multimethod(SetText, args(const char*, const text_run_array*), nbind::Nullable());
  //multimethod(SetText, args(const char*, int32));
  // multimethod(Insert, args(const char*));
  
  method(Text);
  method(TextLength);

  method(CountLines);
  method(CurrentLine);
  method(GoToLine);

  // method(MakeSelectable);
  method(MakeEditable);
  // method(SetWordWrap);
  multimethod(Delete, args());
  method(Clear);
  method(SelectAll);
}

/// New Additions 

NBIND_CLASS(BBox){
  inherit(BView);
  construct<BRect>();
  construct<const char*>();

  multimethod(SetLabel, args(const char*));
  multimethod(SetLabel, args(BView*));
  method(InnerFrame);
}

NBIND_CLASS(BSlider){
    inherit(BControl);
    construct<BRect, const char*, const char*, BMessage*, int32, int32>();
    method(SetLimitLabels);
    method(SetLabel);
    method(SetPosition);
    method(SetEnabled);
    method(Position);
}
NBIND_CLASS(BOptionControl){

}

NBIND_CLASS(BTabView){

}
NBIND_CLASS(BRadioButton){

}

NBIND_CLASS(BFilePanel){
		construct<>();
    method(Show);
    method(Hide);
    method(IsShowing);
    method(SetTarget);
    method(HidesWhenDone);
    method(SetSaveText);
}

NBIND_CLASS(BCheckBox){
    inherit(BControl);
    construct<const char*>();
    method(SetPartialStateToOff);
}
