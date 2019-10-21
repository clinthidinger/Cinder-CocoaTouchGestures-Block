
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "CocoaTouchGestures.h"

using namespace ci;
using namespace ci::app;

class GestureApp : public App
{
public:
    
	void setup();
	void draw();
    
    void handleSwipeLeftGesture();
    void handleSwipeRightGesture();
    void handleSwipeUpGesture();
    void handleSwipeDownGesture();
    void handleSingleTapGesture();
    void handleDoubleTapGesture();
    void handlePanGesture();
    void handlePinchGesture();
    void handleRotationGesture();
    
private:
    std::vector<SwipeGestureRecognizerInfo *> swipeRecognizerInfos;
};

void GestureApp::setup()
{
    auto left = [this] () { GestureApp::handleSwipeLeftGesture(); };
    auto right = [this] () { GestureApp::handleSwipeRightGesture(); };
    auto up = [this] () { GestureApp::handleSwipeUpGesture(); };
    auto down = [this] () { GestureApp::handleSwipeDownGesture(); };
    
    swipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( right, true ) );
    swipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( left, false, true ) );
    swipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( up, false, false, true ) );
    swipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( down, false, false, false, true ) );
    
    
    //!!! Who cleans up dynamic mem???
    
    
    auto window = getWindow();
    addSwipeGestures( swipeRecognizerInfos, window );
    
    auto *singleTapInfo = new TapGestureRecognizerInfo( [this]() { handleSingleTapGesture(); } );
    auto *doubleTapInfo = new TapGestureRecognizerInfo([this]() { handleDoubleTapGesture(); });
    addTapGestures( singleTapInfo, doubleTapInfo, window );
    

    auto *panInfo = new PanGestureRecognizerInfo([this]() { handlePanGesture(); });
    //addPanGestures( panInfo, window );
    
    auto *pinchInfo = new PinchGestureRecognizerInfo([this]() { handlePinchGesture(); });
    addPinchGestures( pinchInfo, window );
    
    auto *rotationInfo = new RotationGestureRecognizerInfo([this]() { handleRotationGesture(); });
    addRotationGestures( rotationInfo, window );
}

void GestureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0.25f ) );
}

void GestureApp::handleSwipeLeftGesture()
{
    std::cout << "Swipe Left\n";
}

void GestureApp::handleSwipeRightGesture()
{
    std::cout << "Swipe Right\n";
}

void GestureApp::handleSwipeUpGesture()
{
    std::cout << "Swipe Up\n";
}

void GestureApp::handleSwipeDownGesture()
{
    std::cout << "Swipe Down\n";
}

void GestureApp::handleSingleTapGesture()
{
    std::cout << "Single Tap\n";
}

void GestureApp::handleDoubleTapGesture()
{
    std::cout << "Double Tap\n";
}

void GestureApp::handlePanGesture()
{
    std::cout << "Pan\n";
}

void GestureApp::handlePinchGesture()
{
    std::cout << "Pinch\n";
}

void GestureApp::handleRotationGesture()
{
    std::cout << "Rotation\n";
}

CINDER_APP( GestureApp, RendererGl( RendererGl::Options().stencil().msaa(0) ), [] ( App::Settings *settings )
{
    //settings->setHighDensityDisplayEnabled();
    settings->setMultiTouchEnabled( true );
} )

