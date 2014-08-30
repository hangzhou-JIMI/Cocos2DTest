#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "CCLuaEngine.h"
#include "Lua_Utils.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    //runapp();
    runlua();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AppDelegate::runapp()
{
    CCDirector * pDirector = CCDirector::sharedDirector();

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);
}

void AppDelegate::runlua()
{
    CCLuaEngine * luaEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(luaEngine);
    CCLuaStack * pStack = luaEngine->getLuaStack();
    lua_State * tolua_s = pStack->getLuaState();
    tolua_luagame_open(tolua_s);
    
    std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("hello.lua");
    luaEngine->executeScriptFile(path.c_str());
}
