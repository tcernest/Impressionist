
//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_file_chooser.H>		// FLTK file chooser
#include <FL/Fl_Color_Chooser.H> // FLTK color chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>

#include "Impressionist.h"
#include "OriginalView.h"
#include "PaintView.h"

#include "ImpBrush.h"

class ImpressionistUI {
public:
	ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView; 
	OriginalView*		m_origView;

	// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;

	// Add by sherry
	// Add color paint windows to choose color
	Fl_Window*			m_ColorWindow;
	Fl_Color_Chooser*	m_ColorChooser;

	// Add stroke direciton choice botton
	Fl_Choice*		m_StrokeDirectionChoice;		

	Fl_Slider*		m_PaintSpaceSlider;
	Fl_Button*		m_Paint;

	// end

	Fl_Slider*			m_BrushSizeSlider;
	Fl_Button*          m_ClearCanvasButton;

	//add by sherry
	Fl_Slider*		m_LineWidthSlider;
	Fl_Slider*		m_LineAngleSlider;
	Fl_Slider*		m_AlphaSlider;
	//end

	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute
	int		getSize();

	//add by sherry
	int			getLineWidth();				// get the Line width
	int			getLineAngle();				// get the Line angle
	double	getAlpha();					// get alpha value

	void		setSize(int size);
	void		setLineWidth(int width);		//set the Line width	
	void		setLineAngle(int angle);			//set the Linea angle

	int		getPaintSpace();			//	get the auto paint space
	//void	setPaintSpace(int spacesize);			// set the auto paint space

	// For get rgb color value
	double	getR_Color();
	double	getG_Color();
	double	getB_Color();

private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int			m_nSize;
	//add by sherry
	int			m_nWidth;
	int			m_nAngle;
	double	m_nAlpha;

	double	m_nRColor;
	double	m_nGColor;
	double	m_nBColor;

	int			m_nPaintSpace;
	//end

	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];
	static Fl_Menu_Item		strokeDirectionMenu[NUM_STROKE_DIRECTION + 1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_sizeSlides(Fl_Widget* o, void* v);

	//add by sherry
	//for control the brush stroke direciton
	static void cb_strokeDirection(Fl_Widget* o, void* v);

	// for all attribute slider
	static void cb_line_widthSlides(Fl_Widget* o, void* v);
	static void cb_line_angleSlides(Fl_Widget* o, void* v);
	static void cb_alphaSlides(Fl_Widget* o, void* v);

	// for color chooser dialog
	static void cb_color_window(Fl_Menu_* o, void* v);
	static  void cb_color_chooser(Fl_Widget* o, void* v);

	// for auto-paint 
	static void cb_autoPaint(Fl_Widget* o, void* v);
	static void cb_paintSlider(Fl_Widget* o, void* v);


};

#endif
