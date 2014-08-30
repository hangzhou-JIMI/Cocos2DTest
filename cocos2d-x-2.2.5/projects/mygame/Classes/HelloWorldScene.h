#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h";

class HelloWorld
: public cocos2d::CCLayer
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCNodeLoaderListener
{
public:
    HelloWorld();
    ~HelloWorld();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(HelloWorld, create);
    
    virtual bool onAssignCCBMemberVariable( cocos2d::CCObject * pTarget ,
                                           const char * pMemberVariableName ,
                                           cocos2d::CCNode * pNode );
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector( cocos2d::CCObject * pTarget ,
                                                                    const char * pSelectorName);
    
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    
    //loaded event
    virtual void onNodeLoaded(cocos2d::CCNode * pNode , cocos2d::extension::CCNodeLoader * pNodeLoader);
    
    //on button test event
    void onButtonTest( cocos2d::CCObject * pSender ,
                      cocos2d::extension::CCControlEvent pCCControlEvent );
    
    void OnImgButtonTest( cocos2d::CCObject * psender , cocos2d::extension::CCControlEvent pEvent );
    
    // a selector callback
    void menuCloseCallback(cocos2d::CCObject * pSender , cocos2d::extension::CCControlEvent pCCControlEvent );
    
    // implement the "static node()" method manually
    //CREATE_FUNC(HelloWorld);
    
private:
    cocos2d::CCLabelTTF * helloLabel;
    cocos2d::CCMenuItemImage * itemImg;
};

//
class HelloWorldLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HelloWorldLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
