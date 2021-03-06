#ifndef EVENT_H_HEADER_INCLUDED_AC6D0545
#define EVENT_H_HEADER_INCLUDED_AC6D0545

#include "../Common/types.h"
#include "../Common/List.h"
#include "Army.h"
#include "Leader.h"
#include "GameDate.h"

//##ModelId=522B225F0105
class Event
{
    //##ModelId=522B25ED0174
    EventType type;
    /** List<Army*> */
    //##ModelId=522B273D0302
    List<Army*> executeArmies;
    //##ModelId=522B275F0376
    Uint32 targetCityId;
    //##ModelId=522B289103B9
    Uint32 targetArmyId;
    //##ModelId=522B28C10012
    List<Leader*> executeLeaders;
    //##ModelId=522B28F50036
    Uint32 upgradeResult;
    //##ModelId=522B29780244
    GameDate deadLine;
    
public:
    Event() : type(Event_Upgrade_Done), executeArmies(true),
    targetArmyId(GAME_INVALID_ID), targetCityId(GAME_INVALID_ID),
    executeLeaders(true), upgradeResult(0), deadLine(GameDate::upgradeNeedDays)
    {}
    
    void SetType(EventType t);
    EventType GetType();

    void SetArmies(List<Army*> armies);
    List<Army*> GetArmies();

    void SetTargetCityId(Uint32 id);
    Uint32 GetTargetCityId();

    void SetExecuteLeaders(List<Leader*> leaders);
    List<Leader*> GetExecuteLeaders();

    void SetUpgradeResult(Uint32 result);
    Uint32 GetUpgradeResult();

    void SetDeadLine(GameDate date);
    GameDate GetDeadLine();

};



#endif /* EVENT_H_HEADER_INCLUDED_AC6D0545 */
