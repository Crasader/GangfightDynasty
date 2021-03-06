#ifndef BUTTONGROUPPOPUPVIEW_H_HEADER_INCLUDED_AD80AE65
#define BUTTONGROUPPOPUPVIEW_H_HEADER_INCLUDED_AD80AE65
#include "CommonButton.h"

//##ModelId=522C84B3013E
class ButtonGroupPopupView : public ViewFrame
{
  public:
    /** @brief init button group with specific row & column number that
    indicate how many buttons should be included in the group. */
    //##ModelId=526930CE038D
    void InitWithRowColumn(Uint32 row, Uint32 column);

    /** @brief set common button that is in the button group at place row -
    column
    @param[in] button the common button that is put into this group
    @param[in] row the row that the button will be placed at
    @param[in] column the column that the button will be placed at */
    //##ModelId=5269367A0307
    void SetCommonButtonAt(CommonButton* button, Uint32 row, Uint32 column);

    /**
     @brief add a new/create a new button into this button group at specific rwo - column
     @param[in] row the row that new button will be placed at
     @param[in] columen the column that new button will be place at
     @param[in] picName the button texture picture name
     @param[in] framseName=empty the button texture frames file name.
     */
    void AddCommonButtonAt(Uint32 row, Uint32 column, String picName, String framesName = String()) throw (ExceptionId);
   
    /**
     @brief set common button id for specific row and column
     */
    inline void SetButtonIdAd(Uint32 row, Uint32 column, Uint32 id)
    {
        buttonList[row*_column + column]->SetId(id);
    }
    
    /**
     @brief get specific common button by row - column
     @param[in] row specific row that button will be retrieved
     @param[in] column specific column that button will be retrieved
     @return CommonButton* the pointer of wanted button in the group.
     */
    inline CommonButton* GetCommonButtonAt(Uint32 row, Uint32 column)
    {
        assert(row>=0 && row < _row);
        assert(column>=0 && column < _column);
        return buttonList[(row*_column+column)];
    }
    
    ButtonGroupPopupView(cocos2d::CCNode* n) : ViewFrame(n), buttonList(true),
    _row(0), _column(0), menuList(true), pBackGround(NULL), ccEventProcessed(0) {}
    ButtonGroupPopupView(cocos2d::CCNode* n, Uint32 row, Uint32 column) : ViewFrame(n),
    buttonList(true), _row(row), _column(column), menuList(true), pBackGround(NULL), ccEventProcessed(0)
    {
        InitWithRowColumn(_row, _column);
    }

    inline void SetBackgroundReourceName(String picName)
    {
    	resourceName = picName;
    }

    void Dismiss();
    void Display();
    void Destory();
    ~ButtonGroupPopupView();
    
    
    /**
     * transfer CCLayer event to internal CCMenus
     **/
    inline virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
    {
        bool ret = false;
        //ccEventProcessed = 0;
        if (!menuList.Empty())
        {
            for (int i = 0; i < menuList.GetLength(); ++i)
            {
                if( menuList[i]->ccTouchBegan(pTouch, pEvent) )
                {
                    ccEventProcessed |= (0x01 << i);
                    ret = true;
                }
            }
        }
        return ret;
    }
    inline virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
    {
        if (ccEventProcessed)
        {
            for (int i = 0; i < menuList.GetLength(); ++i)
            {
                if (ccEventProcessed & (0x01<<i))
                {
                    menuList[i]->ccTouchMoved(pTouch, pEvent);
                }
            }
        }
    }
	inline virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
    {
        if (ccEventProcessed)
        {
            for (int i = 0; i < menuList.GetLength(); ++i)
            {
                if (ccEventProcessed & (0x01<<i))
                {
                    menuList[i]->ccTouchEnded(pTouch, pEvent);
                    //事件处理完，清空之前的记录
                    CLEAR_U64_BIT(ccEventProcessed, i);
                }
            }
        }
    }
	inline virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
    {
        if (ccEventProcessed)
        {
            for (int i = 0; i < menuList.GetLength(); ++i)
            {
                if (ccEventProcessed & (0x01<<i))
                {
                    menuList[i]->ccTouchCancelled(pTouch, pEvent);
                    //事件处理完，清空之前的记录
                    CLEAR_U64_BIT(ccEventProcessed, i);
                }
            }
        }
    }
    

  private:
    //##ModelId=522C84C50154
    Uint32 _row;
    //##ModelId=522C84D40002
    Uint32 _column;
    //##ModelId=522C84DD01C6
    List<CommonButton*> buttonList;
    
    //// dimension parameters: divider width & height
    String resourceName;		// background picture resource name.s
    float dividerW, dividerH;
    float buttonW, buttonH;
    static const Uint8 dividerRatioW, dividerRatioH;

    void ComputeDividerDimension();
    /**
     @brief cocos2d-x resource objects
     */
    List<CCMenu*> menuList;     //every row is in a CCMenu
    Uint64 ccEventProcessed;    //match "menuList" record, every bit represent one CCMenu need further event notify
    
    cocos2d::CCSprite* pBackGround;	// background picture.
    ButtonGroupPopupView();
};


#endif /* BUTTONGROUPPOPUPVIEW_H_HEADER_INCLUDED_AD80AE65 */
