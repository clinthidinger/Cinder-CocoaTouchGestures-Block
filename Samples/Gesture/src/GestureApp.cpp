#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "CocoaTouchGestures.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GestureApp : public AppNative
{
    
public:
    
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
    void draw();
    
    void handleSwipeLeftGesture();
    void handleSwipeRightGesture();
    
private:
    
    std::vector<SwipeGestureRecognizerInfo *> swipeRecognizerInfos;
};

void GestureApp::setup()
{
    
    GestureRecognizerCallBack left( boost::bind( &GestureApp::handleSwipeLeftGesture, this ) );
    GestureRecognizerCallBack right( boost::bind( &GestureApp::handleSwipeRightGesture, this ) );
    
    swipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( right, true ) );
    swipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( left, false, true ) );
    
    addGestures( swipeRecognizerInfos, getWindow() );
}

void GestureApp::mouseDown( MouseEvent event )
{
}

void GestureApp::update()
{
}

void GestureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

void GestureApp::handleSwipeLeftGesture()
{
    std::cout << "Left" << endl;
}

void GestureApp::handleSwipeRightGesture()
{
    std::cout << "Right" << endl;
}

CINDER_APP_NATIVE( GestureApp, RendererGl )
