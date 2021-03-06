#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "../src/View/TextView.h"
#include "../src/View/PictureView.h"
#include "../src/View/CommonButton.h"
#include "../src/View/PureColorBar.h"
#include "../src/View/ButtonGroupPopupView.h"
#include "../src/View/RichTextView.h"
#include "../src/View/TabView.h"
#include "../src/View/TabGroupView.h"
#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void OnExit();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
