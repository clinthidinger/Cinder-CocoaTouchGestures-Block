
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "CocoaTouchGestures.h"

using namespace ci;
using namespace ci::app;

class GestureApp : public App
{
public:
    
	void setup() override;
    void cleanup() override;
	void draw() override;
    
    void handleSwipeLeftGesture( float x, float y );
    void handleSwipeRightGesture( float x, float y );
    void handleSwipeUpGesture( float x, float y );
    void handleSwipeDownGesture( float x, float y );
    void handleSingleTapGesture( float x, float y );
    void handleDoubleTapGesture( float x, float y );
    void handleLongPressGesture( float x, float y );
    void handlePanGesture( float x, float y );
    void handlePinchGesture( float x, float y, float scale );
    void handleRotationGesture( float x, float y, float rotation );
    void handleScreenEdgePanGesture( float x, float y );
    
private:
    std::vector<SwipeGestureRecognizerInfo *> mSwipeRecognizerInfos;
    LongPressGestureRecognizerInfo *mLongPressInfo{ nullptr };
    TapGestureRecognizerInfo *mSingleTapInfo{ nullptr };
    TapGestureRecognizerInfo *mDoubleTapInfo{ nullptr };
    PanGestureRecognizerInfo *mPanInfo{ nullptr };
    PinchGestureRecognizerInfo *mPinchInfo{ nullptr };
    RotationGestureRecognizerInfo *mRotationInfo{ nullptr };
    ScreenEdgePanGestureRecognizerInfo *mSEPanInfo{ nullptr };
};

void GestureApp::setup()
{
    auto window = getWindow();
    
    auto left = [this] ( float x, float y ) { GestureApp::handleSwipeLeftGesture( x, y ); };
    auto right = [this] ( float x, float y ) { GestureApp::handleSwipeRightGesture( x, y ); };
    auto up = [this] ( float x, float y ) { GestureApp::handleSwipeUpGesture( x, y ); };
    auto down = [this] ( float x, float y ) { GestureApp::handleSwipeDownGesture( x, y ); };
    
    mSwipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( right, true ) );
    mSwipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( left, false, true ) );
    mSwipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( up, false, false, true ) );
    mSwipeRecognizerInfos.push_back( new SwipeGestureRecognizerInfo( down, false, false, false, true ) );
    
    //!!! Who cleans up dynamic mem???
    addSwipeGestures( mSwipeRecognizerInfos, window );
    
    mSingleTapInfo = new TapGestureRecognizerInfo( [this]( float x, float y ) {
        handleSingleTapGesture( x, y ); } );
    mDoubleTapInfo = new TapGestureRecognizerInfo( [this]( float x, float y ) {
        handleDoubleTapGesture( x, y ); } );
    addTapGestures( mSingleTapInfo, mDoubleTapInfo, window );
    
    mPanInfo = new PanGestureRecognizerInfo([this]( float x, float y ) {
        handlePanGesture( x, y ); } );
    addPanGestures( mPanInfo, window );
    
    mPinchInfo = new PinchGestureRecognizerInfo([this]( float x, float y, float scale ) {
        handlePinchGesture( x, y, scale ); } );
    addPinchGestures( mPinchInfo, window );
    
    mRotationInfo = new RotationGestureRecognizerInfo([this]( float x, float y, float rot ) {
        handleRotationGesture( x, y, rot ); }  );
    addRotationGestures( mRotationInfo, window );
    
    mLongPressInfo = new LongPressGestureRecognizerInfo([this]( float x, float y ) {
        handleLongPressGesture( x, y ); } );
    addLongPressGestures( mLongPressInfo, window );
    
    mSEPanInfo = new ScreenEdgePanGestureRecognizerInfo([this]( float x, float y ) {
        handleScreenEdgePanGesture( x, y ); } );
    addScreenEdgePanGestures( mSEPanInfo, window );
}

void GestureApp::cleanup()
{
    std::for_each(mSwipeRecognizerInfos.begin(), mSwipeRecognizerInfos.end(),
                  [] (SwipeGestureRecognizerInfo *i) { delete i;} );
    
    if( mLongPressInfo != nullptr )
    {
        delete mLongPressInfo;
    }
    if( mSingleTapInfo != nullptr )
    {
        delete mSingleTapInfo;
    }
    if( mDoubleTapInfo != nullptr )
    {
        delete mDoubleTapInfo;
    }
    if( mPanInfo != nullptr )
    {
        delete mPanInfo;
    }
    if( mPinchInfo != nullptr )
    {
        delete mPinchInfo;
    }
    if( mRotationInfo != nullptr )
    {
        delete mRotationInfo;
    }
    if( mSEPanInfo != nullptr )
    {
        delete mSEPanInfo;
    }
}

void GestureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0.25f ) );
}

void GestureApp::handleSwipeLeftGesture( float x, float y )
{
    std::cout << "Swipe Left" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handleSwipeRightGesture( float x, float y )
{
    std::cout << "Swipe Right" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handleSwipeUpGesture( float x, float y )
{
    std::cout << "Swipe Up" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handleSwipeDownGesture( float x, float y )
{
    std::cout << "Swipe Down" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handleSingleTapGesture( float x, float y )
{
    std::cout << "Single Tap" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handleDoubleTapGesture( float x, float y )
{
    std::cout << "Double Tap" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handleLongPressGesture( float x, float y )
{
    std::cout << "Long press" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handlePanGesture( float x, float y )
{
    std::cout << "Pan" <<  ci::vec2( x, y ) << "\n";
}

void GestureApp::handlePinchGesture( float x, float y, float scale )
{
    std::cout << "Pinch" <<  ci::vec2( x, y ) << ", " << scale << "\n";
}

void GestureApp::handleRotationGesture( float x, float y, float rot )
{
    std::cout << "Rotation" <<  ci::vec2( x, y ) << ", " << rot << "\n";
}

void GestureApp::handleScreenEdgePanGesture( float x, float y )
{
    std::cout << "ScreenEdgePan" <<  ci::vec2( x, y ) << "\n";
}

CINDER_APP( GestureApp, RendererGl( RendererGl::Options().stencil().msaa( 0 ) ), [] ( App::Settings *settings )
{
    //settings->setHighDensityDisplayEnabled();
    settings->setMultiTouchEnabled( true );
} )

