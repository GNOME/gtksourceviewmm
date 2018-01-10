// standard
#include <vector>
// glibmm
#include <glibmm.h>
// gdkmm
#include <gdkmm/pixbuf.h>
// gtkmm
#include <gtkmm.h>
// gtksourceviewmm
#include <gtksourceviewmm.h>

class TestProvider : public Glib::Object, public Gsv::CompletionProvider
{
public:
  static Glib::RefPtr<TestProvider> create();
  virtual ~TestProvider();

  void set_priority(int priority);
  void set_name(const Glib::ustring& name);

protected:
  TestProvider();

private:
  // noncopyable
  TestProvider(const TestProvider&);
  TestProvider& operator=(const TestProvider&);

  virtual Glib::ustring get_name_vfunc() const;
  virtual Glib::RefPtr<Gdk::Pixbuf> get_icon_vfunc();
  virtual Glib::RefPtr<const Gdk::Pixbuf> get_icon_vfunc() const;
  virtual void populate_vfunc(const Glib::RefPtr<Gsv::CompletionContext>& context);
  virtual bool match_vfunc(const Glib::RefPtr<const Gsv::CompletionContext>& context) const;
  //virtual Gtk::Widget* get_info_widget_vfunc(const Glib::RefPtr<const Gsv::CompletionProposal>& proposal);
  //virtual const Gtk::Widget* get_info_widget_vfunc(const Glib::RefPtr<const Gsv::CompletionProposal>& proposal) const;
  //virtual void update_info_vfunc(const Glib::RefPtr<const Gsv::CompletionProposal>& proposal, const Gsv::CompletionInfo& info);
  //virtual bool get_start_iter_vfunc(const Glib::RefPtr<const Gsv::CompletionContext>& context, const Glib::RefPtr<const Gsv::CompletionProposal>& proposal, Gtk::TextIter& iter);
  //virtual bool activate_proposal_vfunc(const Glib::RefPtr<Gsv::CompletionProposal>& proposal, const Gtk::TextIter& iter);
  virtual Gsv::CompletionActivation get_activation_vfunc() const;
  //virtual int get_interactive_delay_vfunc() const;
  virtual int get_priority_vfunc() const;

  std::vector<Glib::RefPtr<Gsv::CompletionProposal> > m_proposals;
  int m_priority;
  Glib::ustring m_name;
  Glib::RefPtr<Gdk::Pixbuf> m_pixbuf;
};

Glib::RefPtr<TestProvider> TestProvider::create()
{
  return Glib::RefPtr<TestProvider>(new TestProvider());
}

TestProvider::~TestProvider()
{}

void TestProvider::set_priority(int priority)
{
  m_priority = priority;
}

void TestProvider::set_name(const Glib::ustring& name)
{
  m_name = name;
}

TestProvider::TestProvider()
: Glib::ObjectBase(typeid(TestProvider)),
  Glib::Object(),
  Gsv::CompletionProvider()
{
  m_proposals.reserve(3);
  m_proposals.push_back( Gsv::CompletionItem::create( "Proposal 1", "Proposal 1", get_icon_vfunc(), "" ) );
  m_proposals.push_back( Gsv::CompletionItem::create( "Proposal 2", "Proposal 2", get_icon_vfunc(), "" ) );
  m_proposals.push_back( Gsv::CompletionItem::create( "Proposal 3", "Proposal 3", get_icon_vfunc(), "" ) );
}

Glib::ustring TestProvider::get_name_vfunc() const
{
  return m_name;
}

Glib::RefPtr<Gdk::Pixbuf> TestProvider::get_icon_vfunc()
{
  return m_pixbuf;
}

Glib::RefPtr<const Gdk::Pixbuf> TestProvider::get_icon_vfunc() const
{
  return const_cast<TestProvider*>(this)->get_icon_vfunc();
}

void TestProvider::populate_vfunc(const Glib::RefPtr<Gsv::CompletionContext>& context)
{
  Glib::RefPtr<TestProvider> reffed_this(this);
  reffed_this->reference();
  context->add_proposals(reffed_this, m_proposals, true);
}

bool TestProvider::match_vfunc(const Glib::RefPtr<const Gsv::CompletionContext>& /* context */) const
{
  return true;
}

Gsv::CompletionActivation TestProvider::get_activation_vfunc() const
{
  return Gsv::CompletionActivation::INTERACTIVE | Gsv::CompletionActivation::USER_REQUESTED;
}

int TestProvider::get_priority_vfunc() const
{
  return m_priority;
}

class TestWindow : public Gtk::Window
{
public:
  TestWindow();
  virtual ~TestWindow();

protected:
  void remember_toggled();
  void select_on_show_toggled();
  void show_headers_toggled();
  void show_icons_toggled();

private:
  Glib::RefPtr<Gsv::Completion> m_completion;
  Gsv::View* m_view;
  Gtk::CheckButton* m_remember;
  Gtk::CheckButton* m_select_on_show;
  Gtk::CheckButton* m_show_headers;
  Gtk::CheckButton* m_show_icons;
};

TestWindow::TestWindow()
: Gtk::Window(),
  m_completion(),
  m_view(0),
  m_remember(0),
  m_select_on_show(0),
  m_show_headers(0),
  m_show_icons(0)
{
// layout
  Gtk::Box* hbox (Gtk::manage(new Gtk::Box(Gtk::Orientation::HORIZONTAL, 1)));
  Gtk::Box* vbox (Gtk::manage(new Gtk::Box(Gtk::Orientation::VERTICAL, 1)));
  m_remember = Gtk::manage(new Gtk::CheckButton("Remember info visibility"));
  m_select_on_show = Gtk::manage(new Gtk::CheckButton("Select first on show"));
  m_show_headers = Gtk::manage(new Gtk::CheckButton("Show headers"));
  m_show_icons = Gtk::manage(new Gtk::CheckButton("Show icons"));

  resize(600, 400);

  Gtk::ScrolledWindow* scrolledwindow (Gtk::manage(new Gtk::ScrolledWindow()));
  m_view = Gtk::manage(new Gsv::View());

  scrolledwindow->add(*m_view);

  m_completion = m_view->get_completion();

  m_remember->set_active( m_completion->property_remember_info_visibility().get_value() );
  m_select_on_show->set_active( m_completion->property_select_on_show().get_value() );
  m_show_headers->set_active( m_completion->property_show_headers().get_value() );
  m_show_icons->set_active( m_completion->property_show_icons().get_value() );

  hbox->pack_start(*m_remember, false, false);
  hbox->pack_start(*m_select_on_show, false, false);
  hbox->pack_start(*m_show_headers, false, false);
  hbox->pack_start(*m_show_icons, false, false);

  vbox->pack_start(*scrolledwindow, true, true);
  vbox->pack_end(*hbox, false, false);

  m_remember->signal_toggled().connect(sigc::mem_fun(*this, &TestWindow::remember_toggled));
  m_select_on_show->signal_toggled().connect(sigc::mem_fun(*this, &TestWindow::select_on_show_toggled));
  m_show_headers->signal_toggled().connect(sigc::mem_fun(*this, &TestWindow::show_headers_toggled));
  m_show_icons->signal_toggled().connect(sigc::mem_fun(*this, &TestWindow::show_icons_toggled));

  add(*vbox);
//completion
  Glib::RefPtr<Gsv::CompletionWords> prov_words ( Gsv::CompletionWords::create("", Glib::RefPtr<Gdk::Pixbuf>()) );

  prov_words->register_provider(m_view->get_buffer());
  m_completion->add_provider(prov_words);

  prov_words->property_priority().set_value( 10 );

  Glib::RefPtr<TestProvider> tp (TestProvider::create());

  tp->set_priority(1);
  tp->set_name("Test Provider 1");
  m_completion->add_provider(tp);

  tp = TestProvider::create();

  tp->set_priority(5);
  tp->set_name("Test Provider 5");
  m_completion->add_provider(tp);
}

TestWindow::~TestWindow()
{}

void TestWindow::remember_toggled()
{
  m_completion->property_remember_info_visibility().set_value( m_remember->get_active() );
}

void TestWindow::select_on_show_toggled()
{
  m_completion->property_select_on_show().set_value( m_select_on_show->get_active() );
}

void TestWindow::show_headers_toggled()
{
  m_completion->property_show_headers().set_value( m_show_headers->get_active() );
}

void TestWindow::show_icons_toggled()
{
  m_completion->property_show_icons().set_value( m_show_icons->get_active() );
}

int
main ()
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create("org.gtksourceviewmm.test");
  Gsv::init();

  TestWindow window;

  app->run(window);
  return 0;
}
