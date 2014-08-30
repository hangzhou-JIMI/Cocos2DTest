#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    //HelloWorld *layer = HelloWorld::create();

    CCNodeLoaderLibrary * lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    lib->registerCCNodeLoader("HelloWorld", HelloWorldLayerLoader::loader());
    CCBReader * reader = new CCBReader(lib);
    //reader->setCCBRootPath("ccb");
    //scene = reader->createSceneWithNodeGraphFromFile("MainScene.ccbi");
    CCNode * node = reader->readNodeGraphFromFile("MainScene.ccbi");
//    CCNode * node2 = reader->readNodeGraphFromFile("ccbi/test.ccbi");
    
    //CCMenuItemImage * imgButton = (CCMenuItemImage *)node->getChildByTag(12);
    //imgButton->setTarget(imgButton, HelloWorld::onButtonTest);
    CCLabelTTF * llab = (CCLabelTTF *)node->getChildByTag(11);
    llab->setString("llab is now");
    //layer->addChild(node);
    reader->autorelease();
    
    CCLog("test3");
    
    if(node != NULL)
    {
        CCLog("test2");
        // add layer as a child to scene
        scene->addChild(node);
    }
//    if(node2 != NULL)
//    {
//        CCLog("test node2");
//        scene->addChild(node2);
//    }
    // return the scene
    return scene;
}

HelloWorld::HelloWorld()
:helloLabel(NULL)
{
    //
}

HelloWorld::~HelloWorld()
{
    CC_SAFE_DELETE(this->helloLabel);
}

bool HelloWorld::onAssignCCBMemberVariable( cocos2d::CCObject * pTarget ,
                               const char * pMemberVariableName ,
                               cocos2d::CCNode * pNode )
{
    CCLog("test4");
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "helloLabel", CCLabelTTF *, this->helloLabel);
    //this->itemImg->setTarget(this, menuCloseCallback);
    return true;
}

cocos2d::SEL_MenuHandler HelloWorld::onResolveCCBCCMenuItemSelector( cocos2d::CCObject * pTarget ,
                                                        const char * pSelectorName)
{
    CCLog("test6");
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "imgButton", HelloWorld::OnImgButtonTest);
    return NULL;
}

cocos2d::extension::SEL_CCControlHandler HelloWorld::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCLog("test5");
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "testbutton1", HelloWorld::onButtonTest);
    return NULL;
}

void HelloWorld::onNodeLoaded(cocos2d::CCNode * pNode , cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLog("test1");
    this->helloLabel->setString("it is in the loader event.");
    
}


void HelloWorld::onButtonTest(cocos2d::CCObject *pSender, cocos2d::extension::CCControlEvent pCCControlEvent)
{
    CCLog("test7");
    this->helloLabel->setString("hello this is a test label.");
    
    cocos2d::CCLabelTTF * lab = CCLabelTTF::create("test1", this->helloLabel->getFontName(), this->helloLabel->getFontSize());
    CCPoint  po = ccp(rand()%1000,rand()%1000);
    CCLog("x:%f y:%f",po.x , po.y );
    lab->setPosition( po );
    this->addChild(lab);
}

//// on "init" you need to initialize your instance
//bool HelloWorld::init()
//{
//    //////////////////////////////
//    // 1. super init first
//    if ( !CCLayer::init() )
//    {
//        return false;
//    }
//    
//    //this->helloLabel->setString("ok this is a name.");
//    
//    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
//
//    //CCBReader::readNodeGraphFromFile("");
//    
//    /////////////////////////////
//    // 2. add a menu item with "X" image, which is clicked to quit the program
//    //    you may modify it.
//
//    // add a "close" icon to exit the progress. it's an autorelease object
//    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
//                                        "CloseNormal.png",
//                                        "CloseSelected.png",
//                                        this,
//                                        menu_selector(HelloWorld::menuCloseCallback));
//    
//	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
//                                origin.y + pCloseItem->getContentSize().height/2));
//
//    // create menu, it's an autorelease object
//    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
//    pMenu->setPosition(CCPointZero);
//    this->addChild(pMenu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//    
//    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
//    
//    // position the label on the center of the screen
//    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - pLabel->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
//
//    // add "HelloWorld" splash screen"
//    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(pSprite, 0);
//    
//    return true;
//}

void HelloWorld::OnImgButtonTest( cocos2d::CCObject * psender , cocos2d::extension::CCControlEvent pEvent )
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    
    CCNodeLoaderLibrary * lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader * reader = new CCBReader(lib);
    CCNode * node2 = reader->readNodeGraphFromFile("ccbi/test.ccbi",this);
    reader->release();
    //cocos2d::CCScene * scene = CCScene::create();
    CCLog("test img button 1 ===================");
    if(node2 != NULL)
    {
        CCLog("test node2");
        //scene->addChild(node2);
        node2->setPosition(ccp(rand()%400,rand()%500));
    }
    
    CCScene * curScene = pDirector->getRunningScene();
    //curScene->removeChild(this, true);
    this->removeFromParent();
    curScene->addChild(node2, rand()%100);
    CCLabelTTF * lab1 = CCLabelTTF::create();
    lab1->setString("test1");
    CCLabelTTF * lab2 = CCLabelTTF::create();
    lab2->setString("test2");
    //
    //curScene->addChild(node2);
    //pDirector->replaceScene(scene);
    
    CCLog("test img button");
    
    //this->setParent(NULL);
    //this->release();
}

void HelloWorld::menuCloseCallback( cocos2d::CCObject * pSender , cocos2d::extension::CCControlEvent pCCControlEvent )
{
    //if(pCCControlEvent->)
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
