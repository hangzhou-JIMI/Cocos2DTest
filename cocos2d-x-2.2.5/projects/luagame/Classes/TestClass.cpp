
#include "TestClass.h"

USING_NS_CC;


void TestClass::TestLog()
{
	CCLog("This is in the cpp.");
	CCScene * scene = CCScene::create();
	CCLabelTTF * label = CCLabelTTF::create();
	label->setString("ok.when you see this , you win.");
	label->setPosition(ccp(200,500));
	scene->addChild(label);

	CCDirector * pd = CCDirector::sharedDirector();
	pd->runWithScene(scene);
}