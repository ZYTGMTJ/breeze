 
#ifndef _PROTOSCENECOMMON_H_ 
#define _PROTOSCENECOMMON_H_ 
 
 
enum SceneType : unsigned short 
{ 
    SCENE_NONE = 0, //无效  
    SCENE_HOME = 1, //主城  
    SCENE_MELEE = 2, //乱斗场  
    SCENE_ARENA = 3, //竞技场  
    SCENE_GUILD = 4, //公会  
    SCENE_MASTER_INSTANCING = 5, //主线副本  
    SCENE_BRANCH_INSTANCING = 6, //支线副本  
    SCENE_MAX = 7, //最大类型数值. 扩展类型在该枚举之前插入新类型.  
}; 
 
enum SceneState : unsigned short 
{ 
    SCENE_STATE_NONE = 0, //不存在  
    SCENE_STATE_MATCHING = 1, //匹配中  
    SCENE_STATE_CHOISE = 2, //选择英雄  
    SCENE_STATE_ALLOCATE = 3, //服务器分配场景中  
    SCENE_STATE_WAIT = 4, //等待玩家加入战场  
    SCENE_STATE_ACTIVE = 5, //战斗中  
}; 
 
enum PropType : unsigned short 
{ 
    PROP_FIXED = 0,  
    PROP_FIXED_GROW = 1,  
    PROP_GROWTH = 2,  
}; 
 
struct EntityProp 
{ 
    static const unsigned short getProtoID() { return 10016;} 
    static const std::string getProtoName() { return "EntityProp";} 
    inline std::vector<std::string>  getDBBuild(); 
    inline std::string  getDBInsert(); 
    inline std::string  getDBDelete(); 
    inline std::string  getDBUpdate(); 
    inline std::string  getDBSelect(); 
    inline std::string  getDBSelectPure(); 
    inline bool fetchFromDBResult(zsummer::mysql::DBResult &result); 
    unsigned long long id;  
    unsigned long long modelID;  
    unsigned short propType; //0 fixed, 1 grow fixed, 2 growth PropType  
    double hp; //血量值  
    double hpRegen; //每秒血量值恢复  
    double attack; //伤害  
    double defense; //防御  
    double crit; //暴击  
    double toughness; //韧性  
    double moveSpeed; //移动速度  
    double attackSpeed; //攻击速度  
    double vampirk; //吸血  
    EntityProp() 
    { 
        id = 0; 
        modelID = 0; 
        propType = 0; 
        hp = 0.0; 
        hpRegen = 0.0; 
        attack = 0.0; 
        defense = 0.0; 
        crit = 0.0; 
        toughness = 0.0; 
        moveSpeed = 0.0; 
        attackSpeed = 0.0; 
        vampirk = 0.0; 
    } 
    EntityProp(const unsigned long long & id, const unsigned long long & modelID, const unsigned short & propType, const double & hp, const double & hpRegen, const double & attack, const double & defense, const double & crit, const double & toughness, const double & moveSpeed, const double & attackSpeed, const double & vampirk) 
    { 
        this->id = id; 
        this->modelID = modelID; 
        this->propType = propType; 
        this->hp = hp; 
        this->hpRegen = hpRegen; 
        this->attack = attack; 
        this->defense = defense; 
        this->crit = crit; 
        this->toughness = toughness; 
        this->moveSpeed = moveSpeed; 
        this->attackSpeed = attackSpeed; 
        this->vampirk = vampirk; 
    } 
}; 
 
std::vector<std::string>  EntityProp::getDBBuild() 
{ 
    std::vector<std::string> ret; 
    ret.push_back("CREATE TABLE IF NOT EXISTS `tb_EntityProp` (        `modelID` bigint(20) unsigned NOT NULL DEFAULT '0' ,        `propType` bigint(20) unsigned NOT NULL DEFAULT '0' ,        PRIMARY KEY(`modelID`,`propType`) ) ENGINE = MyISAM DEFAULT CHARSET = utf8"); 
    ret.push_back("alter table `tb_EntityProp` add `id`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `id`  `id`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `modelID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `modelID`  `modelID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `propType`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `propType`  `propType`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `hp`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `hp`  `hp`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `hpRegen`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `hpRegen`  `hpRegen`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `attack`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `attack`  `attack`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `defense`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `defense`  `defense`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `crit`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `crit`  `crit`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `toughness`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `toughness`  `toughness`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `moveSpeed`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `moveSpeed`  `moveSpeed`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `attackSpeed`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `attackSpeed`  `attackSpeed`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` add `vampirk`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityProp` change `vampirk`  `vampirk`  double NOT NULL DEFAULT '0' "); 
    return ret; 
} 
std::string  EntityProp::getDBSelect() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("select `id`,`modelID`,`propType`,`hp`,`hpRegen`,`attack`,`defense`,`crit`,`toughness`,`moveSpeed`,`attackSpeed`,`vampirk` from `tb_EntityProp` where `modelID` = ? and `propType` = ? "); 
    q << this->modelID; 
    q << this->propType; 
    return q.pickSQL(); 
} 
std::string  EntityProp::getDBSelectPure() 
{ 
    return "select `id`,`modelID`,`propType`,`hp`,`hpRegen`,`attack`,`defense`,`crit`,`toughness`,`moveSpeed`,`attackSpeed`,`vampirk` from `tb_EntityProp` "; 
} 
std::string  EntityProp::getDBInsert() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("insert into `tb_EntityProp`(`id`,`modelID`,`propType`,`hp`,`hpRegen`,`attack`,`defense`,`crit`,`toughness`,`moveSpeed`,`attackSpeed`,`vampirk`) values(?,?,?,?,?,?,?,?,?,?,?,?)"); 
    q << this->id; 
    q << this->modelID; 
    q << this->propType; 
    q << this->hp; 
    q << this->hpRegen; 
    q << this->attack; 
    q << this->defense; 
    q << this->crit; 
    q << this->toughness; 
    q << this->moveSpeed; 
    q << this->attackSpeed; 
    q << this->vampirk; 
    return q.pickSQL(); 
} 
std::string  EntityProp::getDBDelete() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("delete from `tb_EntityProp` where `modelID` = ?,`propType` = ? "); 
    q << this->modelID; 
    q << this->propType; 
    return q.pickSQL(); 
} 
std::string  EntityProp::getDBUpdate() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("insert into `tb_EntityProp`(modelID,propType) values(?,? ) on duplicate key update `id` = ?,`hp` = ?,`hpRegen` = ?,`attack` = ?,`defense` = ?,`crit` = ?,`toughness` = ?,`moveSpeed` = ?,`attackSpeed` = ?,`vampirk` = ? "); 
    q << this->modelID; 
    q << this->propType; 
    q << this->id; 
    q << this->hp; 
    q << this->hpRegen; 
    q << this->attack; 
    q << this->defense; 
    q << this->crit; 
    q << this->toughness; 
    q << this->moveSpeed; 
    q << this->attackSpeed; 
    q << this->vampirk; 
    return q.pickSQL(); 
} 
bool EntityProp::fetchFromDBResult(zsummer::mysql::DBResult &result) 
{ 
    if (result.getErrorCode() != zsummer::mysql::QEC_SUCCESS) 
    { 
        LOGE("error fetch EntityProp from table `tb_EntityProp` . ErrorCode="  <<  result.getErrorCode() << ", Error=" << result.getErrorMsg() << ", sql=" << result.peekSQL()); 
        return false; 
    } 
    try 
    { 
        if (result.haveRow()) 
        { 
            result >> this->id; 
            result >> this->modelID; 
            result >> this->propType; 
            result >> this->hp; 
            result >> this->hpRegen; 
            result >> this->attack; 
            result >> this->defense; 
            result >> this->crit; 
            result >> this->toughness; 
            result >> this->moveSpeed; 
            result >> this->attackSpeed; 
            result >> this->vampirk; 
            return true;  
        } 
    } 
    catch(const std::exception & e) 
    { 
        LOGE("catch one except error when fetch EntityProp from table `tb_EntityProp` . what=" << e.what() << "  ErrorCode="  <<  result.getErrorCode() << ", Error=" << result.getErrorMsg() << ", sql=" << result.peekSQL()); 
        return false; 
    } 
    return false; 
} 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const EntityProp & data) 
{ 
    ws << data.id;  
    ws << data.modelID;  
    ws << data.propType;  
    ws << data.hp;  
    ws << data.hpRegen;  
    ws << data.attack;  
    ws << data.defense;  
    ws << data.crit;  
    ws << data.toughness;  
    ws << data.moveSpeed;  
    ws << data.attackSpeed;  
    ws << data.vampirk;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, EntityProp & data) 
{ 
    rs >> data.id;  
    rs >> data.modelID;  
    rs >> data.propType;  
    rs >> data.hp;  
    rs >> data.hpRegen;  
    rs >> data.attack;  
    rs >> data.defense;  
    rs >> data.crit;  
    rs >> data.toughness;  
    rs >> data.moveSpeed;  
    rs >> data.attackSpeed;  
    rs >> data.vampirk;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const EntityProp & info) 
{ 
    stm << "["; 
    stm << "id=" << info.id << ","; 
    stm << "modelID=" << info.modelID << ","; 
    stm << "propType=" << info.propType << ","; 
    stm << "hp=" << info.hp << ","; 
    stm << "hpRegen=" << info.hpRegen << ","; 
    stm << "attack=" << info.attack << ","; 
    stm << "defense=" << info.defense << ","; 
    stm << "crit=" << info.crit << ","; 
    stm << "toughness=" << info.toughness << ","; 
    stm << "moveSpeed=" << info.moveSpeed << ","; 
    stm << "attackSpeed=" << info.attackSpeed << ","; 
    stm << "vampirk=" << info.vampirk << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<EntityProp> EntityPropArray;  
 
 
typedef std::map<unsigned long long, EntityProp> EntityPropMap;  
 
struct EntityBase 
{ 
    static const unsigned short getProtoID() { return 10017;} 
    static const std::string getProtoName() { return "EntityBase";} 
    inline std::vector<std::string>  getDBBuild(); 
    inline std::string  getDBInsert(); 
    inline std::string  getDBDelete(); 
    inline std::string  getDBUpdate(); 
    inline std::string  getDBSelect(); 
    inline std::string  getDBSelectPure(); 
    inline bool fetchFromDBResult(zsummer::mysql::DBResult &result); 
    unsigned long long eid;  
    unsigned long long modelID;  
    std::string modelName;  
    unsigned long long avatarID;  
    std::string avatarName;  
    unsigned long long iconID; //头像  
    double level; //等级  
    double exp; //经验  
    double gold; //金币  
    unsigned short camp;  
    unsigned short etype;  
    unsigned short state;  
    EntityBase() 
    { 
        eid = 0; 
        modelID = 0; 
        avatarID = 0; 
        iconID = 0; 
        level = 0.0; 
        exp = 0.0; 
        gold = 0.0; 
        camp = 0; 
        etype = 0; 
        state = 0; 
    } 
    EntityBase(const unsigned long long & eid, const unsigned long long & modelID, const std::string & modelName, const unsigned long long & avatarID, const std::string & avatarName, const unsigned long long & iconID, const double & level, const double & exp, const double & gold, const unsigned short & camp, const unsigned short & etype, const unsigned short & state) 
    { 
        this->eid = eid; 
        this->modelID = modelID; 
        this->modelName = modelName; 
        this->avatarID = avatarID; 
        this->avatarName = avatarName; 
        this->iconID = iconID; 
        this->level = level; 
        this->exp = exp; 
        this->gold = gold; 
        this->camp = camp; 
        this->etype = etype; 
        this->state = state; 
    } 
}; 
 
std::vector<std::string>  EntityBase::getDBBuild() 
{ 
    std::vector<std::string> ret; 
    ret.push_back("CREATE TABLE IF NOT EXISTS `tb_EntityBase` (        `modelID` bigint(20) unsigned NOT NULL DEFAULT '0' ,        PRIMARY KEY(`modelID`) ) ENGINE = MyISAM DEFAULT CHARSET = utf8"); 
    ret.push_back("alter table `tb_EntityBase` add `eid`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `eid`  `eid`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `modelID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `modelID`  `modelID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `modelName`  varchar(255) NOT NULL DEFAULT '' "); 
    ret.push_back("alter table `tb_EntityBase` change `modelName`  `modelName`  varchar(255) NOT NULL DEFAULT '' "); 
    ret.push_back("alter table `tb_EntityBase` add `avatarID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `avatarID`  `avatarID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `avatarName`  varchar(255) NOT NULL DEFAULT '' "); 
    ret.push_back("alter table `tb_EntityBase` change `avatarName`  `avatarName`  varchar(255) NOT NULL DEFAULT '' "); 
    ret.push_back("alter table `tb_EntityBase` add `iconID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `iconID`  `iconID`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `level`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `level`  `level`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `exp`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `exp`  `exp`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `gold`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `gold`  `gold`  double NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `camp`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `camp`  `camp`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `etype`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `etype`  `etype`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` add `state`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    ret.push_back("alter table `tb_EntityBase` change `state`  `state`  bigint(20) unsigned NOT NULL DEFAULT '0' "); 
    return ret; 
} 
std::string  EntityBase::getDBSelect() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("select `eid`,`modelID`,`modelName`,`avatarID`,`avatarName`,`iconID`,`level`,`exp`,`gold`,`camp`,`etype`,`state` from `tb_EntityBase` where `modelID` = ? "); 
    q << this->modelID; 
    return q.pickSQL(); 
} 
std::string  EntityBase::getDBSelectPure() 
{ 
    return "select `eid`,`modelID`,`modelName`,`avatarID`,`avatarName`,`iconID`,`level`,`exp`,`gold`,`camp`,`etype`,`state` from `tb_EntityBase` "; 
} 
std::string  EntityBase::getDBInsert() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("insert into `tb_EntityBase`(`eid`,`modelID`,`modelName`,`avatarID`,`avatarName`,`iconID`,`level`,`exp`,`gold`,`camp`,`etype`,`state`) values(?,?,?,?,?,?,?,?,?,?,?,?)"); 
    q << this->eid; 
    q << this->modelID; 
    q << this->modelName; 
    q << this->avatarID; 
    q << this->avatarName; 
    q << this->iconID; 
    q << this->level; 
    q << this->exp; 
    q << this->gold; 
    q << this->camp; 
    q << this->etype; 
    q << this->state; 
    return q.pickSQL(); 
} 
std::string  EntityBase::getDBDelete() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("delete from `tb_EntityBase` where `modelID` = ? "); 
    q << this->modelID; 
    return q.pickSQL(); 
} 
std::string  EntityBase::getDBUpdate() 
{ 
    zsummer::mysql::DBQuery q; 
    q.init("insert into `tb_EntityBase`(modelID) values(? ) on duplicate key update `eid` = ?,`modelName` = ?,`avatarID` = ?,`avatarName` = ?,`iconID` = ?,`level` = ?,`exp` = ?,`gold` = ?,`camp` = ?,`etype` = ?,`state` = ? "); 
    q << this->modelID; 
    q << this->eid; 
    q << this->modelName; 
    q << this->avatarID; 
    q << this->avatarName; 
    q << this->iconID; 
    q << this->level; 
    q << this->exp; 
    q << this->gold; 
    q << this->camp; 
    q << this->etype; 
    q << this->state; 
    return q.pickSQL(); 
} 
bool EntityBase::fetchFromDBResult(zsummer::mysql::DBResult &result) 
{ 
    if (result.getErrorCode() != zsummer::mysql::QEC_SUCCESS) 
    { 
        LOGE("error fetch EntityBase from table `tb_EntityBase` . ErrorCode="  <<  result.getErrorCode() << ", Error=" << result.getErrorMsg() << ", sql=" << result.peekSQL()); 
        return false; 
    } 
    try 
    { 
        if (result.haveRow()) 
        { 
            result >> this->eid; 
            result >> this->modelID; 
            result >> this->modelName; 
            result >> this->avatarID; 
            result >> this->avatarName; 
            result >> this->iconID; 
            result >> this->level; 
            result >> this->exp; 
            result >> this->gold; 
            result >> this->camp; 
            result >> this->etype; 
            result >> this->state; 
            return true;  
        } 
    } 
    catch(const std::exception & e) 
    { 
        LOGE("catch one except error when fetch EntityBase from table `tb_EntityBase` . what=" << e.what() << "  ErrorCode="  <<  result.getErrorCode() << ", Error=" << result.getErrorMsg() << ", sql=" << result.peekSQL()); 
        return false; 
    } 
    return false; 
} 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const EntityBase & data) 
{ 
    ws << data.eid;  
    ws << data.modelID;  
    ws << data.modelName;  
    ws << data.avatarID;  
    ws << data.avatarName;  
    ws << data.iconID;  
    ws << data.level;  
    ws << data.exp;  
    ws << data.gold;  
    ws << data.camp;  
    ws << data.etype;  
    ws << data.state;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, EntityBase & data) 
{ 
    rs >> data.eid;  
    rs >> data.modelID;  
    rs >> data.modelName;  
    rs >> data.avatarID;  
    rs >> data.avatarName;  
    rs >> data.iconID;  
    rs >> data.level;  
    rs >> data.exp;  
    rs >> data.gold;  
    rs >> data.camp;  
    rs >> data.etype;  
    rs >> data.state;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const EntityBase & info) 
{ 
    stm << "["; 
    stm << "eid=" << info.eid << ","; 
    stm << "modelID=" << info.modelID << ","; 
    stm << "modelName=" << info.modelName << ","; 
    stm << "avatarID=" << info.avatarID << ","; 
    stm << "avatarName=" << info.avatarName << ","; 
    stm << "iconID=" << info.iconID << ","; 
    stm << "level=" << info.level << ","; 
    stm << "exp=" << info.exp << ","; 
    stm << "gold=" << info.gold << ","; 
    stm << "camp=" << info.camp << ","; 
    stm << "etype=" << info.etype << ","; 
    stm << "state=" << info.state << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<EntityBase> EntityBaseArray;  
 
 
typedef std::map<unsigned long long, EntityBase> EntityBaseMap;  
 
struct SceneGroupAvatarInfo 
{ 
    static const unsigned short getProtoID() { return 10000;} 
    static const std::string getProtoName() { return "SceneGroupAvatarInfo";} 
    unsigned long long areaID; //考虑混服情况,必须指定该玩家来自哪个当前区  
    EntityBase baseInfo; //玩家基础数据  
    EntityProp fixedProps; //基础固定属性  
    EntityProp growthProps; //成长基础属性  
    EntityProp growths; //成长系数  
    unsigned short powerType; //组队权限: 0普通,1leader,2master  
    std::string token; //scene服务器的口令, 该字段在广播给客户端时需要清空非自己所属的token,否则将会造成token公开.  
    SceneGroupAvatarInfo() 
    { 
        areaID = 0; 
        powerType = 0; 
    } 
    SceneGroupAvatarInfo(const unsigned long long & areaID, const EntityBase & baseInfo, const EntityProp & fixedProps, const EntityProp & growthProps, const EntityProp & growths, const unsigned short & powerType, const std::string & token) 
    { 
        this->areaID = areaID; 
        this->baseInfo = baseInfo; 
        this->fixedProps = fixedProps; 
        this->growthProps = growthProps; 
        this->growths = growths; 
        this->powerType = powerType; 
        this->token = token; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SceneGroupAvatarInfo & data) 
{ 
    ws << data.areaID;  
    ws << data.baseInfo;  
    ws << data.fixedProps;  
    ws << data.growthProps;  
    ws << data.growths;  
    ws << data.powerType;  
    ws << data.token;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SceneGroupAvatarInfo & data) 
{ 
    rs >> data.areaID;  
    rs >> data.baseInfo;  
    rs >> data.fixedProps;  
    rs >> data.growthProps;  
    rs >> data.growths;  
    rs >> data.powerType;  
    rs >> data.token;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SceneGroupAvatarInfo & info) 
{ 
    stm << "["; 
    stm << "areaID=" << info.areaID << ","; 
    stm << "baseInfo=" << info.baseInfo << ","; 
    stm << "fixedProps=" << info.fixedProps << ","; 
    stm << "growthProps=" << info.growthProps << ","; 
    stm << "growths=" << info.growths << ","; 
    stm << "powerType=" << info.powerType << ","; 
    stm << "token=" << info.token << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<SceneGroupAvatarInfo> SceneGroupAvatarInfoArray;  
 
 
typedef std::map<unsigned long long, SceneGroupAvatarInfo> SceneGroupAvatarInfoMap;  
 
struct SceneGroupInfo //编队数据  
{ 
    static const unsigned short getProtoID() { return 10001;} 
    static const std::string getProtoName() { return "SceneGroupInfo";} 
    unsigned long long groupID;  
    unsigned short sceneType; //场景类型  
    unsigned short sceneState; //状态  
    unsigned long long mapID;  
    unsigned long long lineID; //分线ID  
    unsigned long long sceneID; //场景实例ID  
    std::string host; //服务器host  
    unsigned short port; //服务器port  
    SceneGroupAvatarInfoMap members; //队友数据  
    ServiceIDMap invitees; //邀请列表, 如果需要丰富该功能可扩展类型信息  
    SceneGroupInfo() 
    { 
        groupID = 0; 
        sceneType = 0; 
        sceneState = 0; 
        mapID = 0; 
        lineID = 0; 
        sceneID = 0; 
        port = 0; 
    } 
    SceneGroupInfo(const unsigned long long & groupID, const unsigned short & sceneType, const unsigned short & sceneState, const unsigned long long & mapID, const unsigned long long & lineID, const unsigned long long & sceneID, const std::string & host, const unsigned short & port, const SceneGroupAvatarInfoMap & members, const ServiceIDMap & invitees) 
    { 
        this->groupID = groupID; 
        this->sceneType = sceneType; 
        this->sceneState = sceneState; 
        this->mapID = mapID; 
        this->lineID = lineID; 
        this->sceneID = sceneID; 
        this->host = host; 
        this->port = port; 
        this->members = members; 
        this->invitees = invitees; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SceneGroupInfo & data) 
{ 
    ws << data.groupID;  
    ws << data.sceneType;  
    ws << data.sceneState;  
    ws << data.mapID;  
    ws << data.lineID;  
    ws << data.sceneID;  
    ws << data.host;  
    ws << data.port;  
    ws << data.members;  
    ws << data.invitees;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SceneGroupInfo & data) 
{ 
    rs >> data.groupID;  
    rs >> data.sceneType;  
    rs >> data.sceneState;  
    rs >> data.mapID;  
    rs >> data.lineID;  
    rs >> data.sceneID;  
    rs >> data.host;  
    rs >> data.port;  
    rs >> data.members;  
    rs >> data.invitees;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SceneGroupInfo & info) 
{ 
    stm << "["; 
    stm << "groupID=" << info.groupID << ","; 
    stm << "sceneType=" << info.sceneType << ","; 
    stm << "sceneState=" << info.sceneState << ","; 
    stm << "mapID=" << info.mapID << ","; 
    stm << "lineID=" << info.lineID << ","; 
    stm << "sceneID=" << info.sceneID << ","; 
    stm << "host=" << info.host << ","; 
    stm << "port=" << info.port << ","; 
    stm << "members=" << info.members << ","; 
    stm << "invitees=" << info.invitees << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<SceneGroupInfo> SceneGroupInfoArray;  
 
 
typedef std::map<unsigned long long, SceneGroupInfo> SceneGroupInfoMap;  
 
 
typedef std::vector<unsigned long long> EntityIDArray;  
 
struct EPosition 
{ 
    static const unsigned short getProtoID() { return 10002;} 
    static const std::string getProtoName() { return "EPosition";} 
    double x;  
    double y;  
    EPosition() 
    { 
        x = 0.0; 
        y = 0.0; 
    } 
    EPosition(const double & x, const double & y) 
    { 
        this->x = x; 
        this->y = y; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const EPosition & data) 
{ 
    ws << data.x;  
    ws << data.y;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, EPosition & data) 
{ 
    rs >> data.x;  
    rs >> data.y;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const EPosition & info) 
{ 
    stm << "["; 
    stm << "x=" << info.x << ","; 
    stm << "y=" << info.y << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<EPosition> EPositionArray;  
 
 
typedef std::vector<unsigned long long> SkillIDArray; //技能ID数组  
 
 
typedef std::vector<unsigned long long> BuffIDArray; //buff ID 数组  
 
enum EntityState : unsigned short 
{ 
    ENTITY_STATE_NONE = 0, //无效  
    ENTITY_STATE_FREEZING = 1, //冻结, 不可被攻击,不可主动移动,攻击等  
    ENTITY_STATE_ACTIVE = 2, //活跃状态  
    ENTITY_STATE_LIE = 3, //跪, 不计死亡次数  
    ENTITY_STATE_DIED = 4, //死, 记死亡次数  
}; 
 
enum EntityType : unsigned short 
{ 
    ENTITY_NONE = 0,  
    ENTITY_PLAYER = 1,  
    ENTITY_AI = 2,  
    ENTITY_FLIGHT = 3, //飞行道具  
}; 
 
enum EntityCampType : unsigned long long 
{ 
    ENTITY_CAMP_NONE = 0,  
    ENTITY_CAMP_RED = 1, //红方  
    ENTITY_CAMP_BLUE = 2, //蓝方  
    ENTITY_CAMP_NEUTRAL = 1000, //[0~ENTITY_CAMP_NEUTRAL)阵营相互敌对, [ENTITY_CAMP_NEUTRAL~)中立温和阵营  
}; 
 
enum MoveAction : unsigned short 
{ 
    MOVE_ACTION_IDLE = 0, //空闲  
    MOVE_ACTION_FOLLOW = 1, //跟随  
    MOVE_ACTION_PATH = 2, //路径  
    MOVE_ACTION_PASV_PATH = 3, //不可取消, 直线移动一次.  
    MOVE_ACTION_FORCE_PATH = 4, //不可取消&穿越地形, 直线移动一次  
}; 
 
enum SearchMethodType : unsigned short 
{ 
    SEARCH_METHOD_SEACTOR = 0, //org 扇形  
    SEARCH_METHOD_RECT = 1, //org 矩形  
}; 
 
enum SearchCampType : unsigned long long 
{ 
    SEARCH_CAMP_NONE = 0,  
    SEARCH_CAMP_SELF = 1, //自身  
    SEARCH_CAMP_SAME_WITHOUT_SELF = 2, //同阵营非自己  
    SEARCH_CAMP_ALIEN = 3, //非己方阵营  
}; 
 
enum SkillType : unsigned long long 
{ 
    SKILL_NONE = 0,  
    SKILL_AUTO = 1, //自动循环攻击  
    SKILL_PASSIVE = 2, //被动技能  
    SKILL_CAN_BREAK = 3, //可被中断  
    SKILL_CAN_MOVE = 4, //可移动  
    SKILL_PHYSICAL = 5, //物理攻击  
    SKILL_MAGIC = 6, //魔法攻击  
}; 
 
enum SkillBehaviourType : unsigned long long 
{ 
    SKILL_BEHAVIOUR_NONE = 0,  
    SKILL_BEHAVIOUR_HIT = 1, //攻击  
    SKILL_BEHAVIOUR_TELEPORT_TARGET = 2, //瞬移到目标  
    SKILL_BEHAVIOUR_BREAK_MOVE = 3, //打断移动  
    SKILL_BEHAVIOUR_BREAK_SKILL = 4, //打断技能  
    SKILL_BEHAVIOUR_REMOVE_DEBUFF = 5, //驱散减益BUFF  
    SKILL_BEHAVIOUR_REMOVE_BUFF = 6, //驱散增益BUFF  
    SKILL_BEHAVIOUR_TRIGGER_BUFF = 7, //触发buff  
    SKILL_BEHAVIOUR_TRIGGER_SKILL = 8, //触发技能  
}; 
 
enum BuffType : unsigned long long 
{ 
    BUFF_HALO = 1, //非表达可检索类型: 光环  
    BUFF_BUFF = 2, //非表达可检索类型: 增益buff  
    BUFF_DEBUFF = 3, //非表达可检索类型: 减益BUFF  
    BUFF_HIDE = 4, //非表达可检索类型: 客户端不表现  
    BUFF_SNEAK = 5, //潜行类型: 潜行 不会被非己方阵营的任何AOE技能搜索到  
    BUFF_HOLD_MOVE = 15, //控制: 禁止移动  
    BUFF_REVERSE_MOVE = 16, //控制: 移动反向  
    BUFF_SILENCE_AUTO_ATTACK = 17, //控制: 沉默普攻  
    BUFF_SILENCE_WITHOUT_AUTO_ATTACK = 18, //控制: 沉默非普攻技能  
    BUFF_SILENCE_PHYSICAL = 19, //控制: 沉默物理攻击  
    BUFF_SILENCE_MAGIC = 20, //控制: 沉默魔法攻击  
    BUFF_IMMUNE_MOVE = 25, //免疫: 免疫移动类控制  
    BUFF_IMMUNE_SILENCE = 26, //免疫: 免疫沉默  
    BUFF_IMMUNE_DEBUFF = 27, //免疫: 免疫添加DEBUFF, 指被地方添加不利buff  
    BUFF_IMMUNE_REMOVE_BUFF = 28, //免疫: 免疫驱散BUFF,指被敌方移除有益buff  
    BUFF_IMMUNE_PHYSICAL = 29, //免疫: 物攻免疫  
    BUFF_IMMUNE_MAGIC = 30, //免疫: 法攻免疫  
    BUFF_INC_HARM = 35, //属性加成: 最终扣血加成, value1加法, value2乘法  
    BUFF_INC_DAMAGE = 36, //属性加成: 伤害加成, value1加法, value2乘法  
    BUFF_INC_SPEED = 37, //属性加成: 速度加成, value1加法, value2乘法  
    BUFF_INC_SUCK_BLOOD = 38, //属性加成: 吸血加成 value1加法  
    BUFF_LIGHT_SKILL = 50, //持续性触发: value1为技能ID, value2为间隔, 用于光环类,持续触发类buff实现  
}; 
 
struct SearchInfo 
{ 
    static const unsigned short getProtoID() { return 10003;} 
    static const std::string getProtoName() { return "SearchInfo";} 
    unsigned short etype; //实体类型, 玩家/AI 或者是NONE忽略该选项  
    unsigned long long camp; //0忽略改选项, 1位标识自己, 2位标识同阵营非自己, 3其他阵营,   逗号分割 多选 SearchCampType  
    unsigned short method; //0扇形, 1矩形 SearchMethodType  
    double distance; //伤害距离  
    double radian; //弧度或者宽度  
    double offsetX; //坐标偏移量, 以caster为原点, 朝向为y轴  
    double offsetY; //坐标偏移量, 以caster为原点, 朝向为y轴  
    unsigned long long limitEntitys; //最大目标数  
    SearchInfo() 
    { 
        etype = 0; 
        camp = 0; 
        method = 0; 
        distance = 0.0; 
        radian = 0.0; 
        offsetX = 0.0; 
        offsetY = 0.0; 
        limitEntitys = 0; 
    } 
    SearchInfo(const unsigned short & etype, const unsigned long long & camp, const unsigned short & method, const double & distance, const double & radian, const double & offsetX, const double & offsetY, const unsigned long long & limitEntitys) 
    { 
        this->etype = etype; 
        this->camp = camp; 
        this->method = method; 
        this->distance = distance; 
        this->radian = radian; 
        this->offsetX = offsetX; 
        this->offsetY = offsetY; 
        this->limitEntitys = limitEntitys; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SearchInfo & data) 
{ 
    ws << data.etype;  
    ws << data.camp;  
    ws << data.method;  
    ws << data.distance;  
    ws << data.radian;  
    ws << data.offsetX;  
    ws << data.offsetY;  
    ws << data.limitEntitys;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SearchInfo & data) 
{ 
    rs >> data.etype;  
    rs >> data.camp;  
    rs >> data.method;  
    rs >> data.distance;  
    rs >> data.radian;  
    rs >> data.offsetX;  
    rs >> data.offsetY;  
    rs >> data.limitEntitys;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SearchInfo & info) 
{ 
    stm << "["; 
    stm << "etype=" << info.etype << ","; 
    stm << "camp=" << info.camp << ","; 
    stm << "method=" << info.method << ","; 
    stm << "distance=" << info.distance << ","; 
    stm << "radian=" << info.radian << ","; 
    stm << "offsetX=" << info.offsetX << ","; 
    stm << "offsetY=" << info.offsetY << ","; 
    stm << "limitEntitys=" << info.limitEntitys << ","; 
    stm << "]"; 
    return stm; 
} 
 
struct SkillBehaviour //技能触发行为  
{ 
    static const unsigned short getProtoID() { return 10004;} 
    static const std::string getProtoName() { return "SkillBehaviour";} 
    unsigned long long behaviour;  
    double delay;  
    SearchInfo search;  
    SkillIDArray skills;  
    BuffIDArray buffs;  
    SkillBehaviour() 
    { 
        behaviour = 0; 
        delay = 0.0; 
    } 
    SkillBehaviour(const unsigned long long & behaviour, const double & delay, const SearchInfo & search, const SkillIDArray & skills, const BuffIDArray & buffs) 
    { 
        this->behaviour = behaviour; 
        this->delay = delay; 
        this->search = search; 
        this->skills = skills; 
        this->buffs = buffs; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SkillBehaviour & data) 
{ 
    ws << data.behaviour;  
    ws << data.delay;  
    ws << data.search;  
    ws << data.skills;  
    ws << data.buffs;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SkillBehaviour & data) 
{ 
    rs >> data.behaviour;  
    rs >> data.delay;  
    rs >> data.search;  
    rs >> data.skills;  
    rs >> data.buffs;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SkillBehaviour & info) 
{ 
    stm << "["; 
    stm << "behaviour=" << info.behaviour << ","; 
    stm << "delay=" << info.delay << ","; 
    stm << "search=" << info.search << ","; 
    stm << "skills=" << info.skills << ","; 
    stm << "buffs=" << info.buffs << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<SkillBehaviour> SkillBehaviourArray;  
 
struct SkillData //技能  
{ 
    static const unsigned short getProtoID() { return 10005;} 
    static const std::string getProtoName() { return "SkillData";} 
    unsigned long long skillID; //skillID  
    unsigned long long skillType; //SkillType  
    SkillBehaviourArray behaviours;  
    double cd;  
    SkillData() 
    { 
        skillID = 0; 
        skillType = 0; 
        cd = 0.0; 
    } 
    SkillData(const unsigned long long & skillID, const unsigned long long & skillType, const SkillBehaviourArray & behaviours, const double & cd) 
    { 
        this->skillID = skillID; 
        this->skillType = skillType; 
        this->behaviours = behaviours; 
        this->cd = cd; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SkillData & data) 
{ 
    ws << data.skillID;  
    ws << data.skillType;  
    ws << data.behaviours;  
    ws << data.cd;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SkillData & data) 
{ 
    rs >> data.skillID;  
    rs >> data.skillType;  
    rs >> data.behaviours;  
    rs >> data.cd;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SkillData & info) 
{ 
    stm << "["; 
    stm << "skillID=" << info.skillID << ","; 
    stm << "skillType=" << info.skillType << ","; 
    stm << "behaviours=" << info.behaviours << ","; 
    stm << "cd=" << info.cd << ","; 
    stm << "]"; 
    return stm; 
} 
 
struct BuffData //buff  
{ 
    static const unsigned short getProtoID() { return 10006;} 
    static const std::string getProtoName() { return "BuffData";} 
    unsigned long long buffID;  
    unsigned long long buffType; //buff类型  
    double piletime; //最大叠加时间  
    double keepTime; //保持时间  
    double value1;  
    double value2;  
    BuffData() 
    { 
        buffID = 0; 
        buffType = 0; 
        piletime = 0.0; 
        keepTime = 0.0; 
        value1 = 0.0; 
        value2 = 0.0; 
    } 
    BuffData(const unsigned long long & buffID, const unsigned long long & buffType, const double & piletime, const double & keepTime, const double & value1, const double & value2) 
    { 
        this->buffID = buffID; 
        this->buffType = buffType; 
        this->piletime = piletime; 
        this->keepTime = keepTime; 
        this->value1 = value1; 
        this->value2 = value2; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const BuffData & data) 
{ 
    ws << data.buffID;  
    ws << data.buffType;  
    ws << data.piletime;  
    ws << data.keepTime;  
    ws << data.value1;  
    ws << data.value2;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, BuffData & data) 
{ 
    rs >> data.buffID;  
    rs >> data.buffType;  
    rs >> data.piletime;  
    rs >> data.keepTime;  
    rs >> data.value1;  
    rs >> data.value2;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const BuffData & info) 
{ 
    stm << "["; 
    stm << "buffID=" << info.buffID << ","; 
    stm << "buffType=" << info.buffType << ","; 
    stm << "piletime=" << info.piletime << ","; 
    stm << "keepTime=" << info.keepTime << ","; 
    stm << "value1=" << info.value1 << ","; 
    stm << "value2=" << info.value2 << ","; 
    stm << "]"; 
    return stm; 
} 
 
enum SceneEvent : unsigned short 
{ 
    SCENE_EVENT_LIE = 0,  
    SCENE_EVENT_DIED = 1,  
    SCENE_EVENT_FREEZE = 2,  
    SCENE_EVENT_REBIRTH = 3,  
    SCENE_EVENT_HARM_ATTACK = 4,  
    SCENE_EVENT_HARM_HILL = 5,  
    SCENE_EVENT_HARM_MISS = 6,  
    SCENE_EVENT_HARM_CRITICAL = 7,  
}; 
 
struct SceneEventInfo //伤害数据  
{ 
    static const unsigned short getProtoID() { return 10015;} 
    static const std::string getProtoName() { return "SceneEventInfo";} 
    unsigned long long src; //eid  
    unsigned long long dst; //eid  
    unsigned short ev; //事件类型  
    double val; //数值  
    std::string mix; //数值  
    SceneEventInfo() 
    { 
        src = 0; 
        dst = 0; 
        ev = 0; 
        val = 0.0; 
    } 
    SceneEventInfo(const unsigned long long & src, const unsigned long long & dst, const unsigned short & ev, const double & val, const std::string & mix) 
    { 
        this->src = src; 
        this->dst = dst; 
        this->ev = ev; 
        this->val = val; 
        this->mix = mix; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SceneEventInfo & data) 
{ 
    ws << data.src;  
    ws << data.dst;  
    ws << data.ev;  
    ws << data.val;  
    ws << data.mix;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SceneEventInfo & data) 
{ 
    rs >> data.src;  
    rs >> data.dst;  
    rs >> data.ev;  
    rs >> data.val;  
    rs >> data.mix;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SceneEventInfo & info) 
{ 
    stm << "["; 
    stm << "src=" << info.src << ","; 
    stm << "dst=" << info.dst << ","; 
    stm << "ev=" << info.ev << ","; 
    stm << "val=" << info.val << ","; 
    stm << "mix=" << info.mix << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<SceneEventInfo> SceneEventInfoArray;  
 
struct SkillInfo 
{ 
    static const unsigned short getProtoID() { return 10008;} 
    static const std::string getProtoName() { return "SkillInfo";} 
    unsigned long long skillID;  
    double startTime;  
    EPosition dst; //目标位置  
    unsigned long long foe; //锁定的目标  
    SkillData data; //配置数据  
    SkillInfo() 
    { 
        skillID = 0; 
        startTime = 0.0; 
        foe = 0; 
    } 
    SkillInfo(const unsigned long long & skillID, const double & startTime, const EPosition & dst, const unsigned long long & foe, const SkillData & data) 
    { 
        this->skillID = skillID; 
        this->startTime = startTime; 
        this->dst = dst; 
        this->foe = foe; 
        this->data = data; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SkillInfo & data) 
{ 
    ws << data.skillID;  
    ws << data.startTime;  
    ws << data.dst;  
    ws << data.foe;  
    ws << data.data;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SkillInfo & data) 
{ 
    rs >> data.skillID;  
    rs >> data.startTime;  
    rs >> data.dst;  
    rs >> data.foe;  
    rs >> data.data;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SkillInfo & info) 
{ 
    stm << "["; 
    stm << "skillID=" << info.skillID << ","; 
    stm << "startTime=" << info.startTime << ","; 
    stm << "dst=" << info.dst << ","; 
    stm << "foe=" << info.foe << ","; 
    stm << "data=" << info.data << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<SkillInfo> SkillInfoArray;  
 
struct BuffInfo 
{ 
    static const unsigned short getProtoID() { return 10009;} 
    static const std::string getProtoName() { return "BuffInfo";} 
    unsigned long long eid; //施放该buff的entity id  
    unsigned long long skillID; //如果该buff是被技能触发的 则记录该技能, 被动技能是0  
    unsigned long long buffID;  
    double start; //start (server)tick  
    double lastTrigerTick; //lastTrigerTick  
    BuffData data; //配置数据  
    BuffInfo() 
    { 
        eid = 0; 
        skillID = 0; 
        buffID = 0; 
        start = 0.0; 
        lastTrigerTick = 0.0; 
    } 
    BuffInfo(const unsigned long long & eid, const unsigned long long & skillID, const unsigned long long & buffID, const double & start, const double & lastTrigerTick, const BuffData & data) 
    { 
        this->eid = eid; 
        this->skillID = skillID; 
        this->buffID = buffID; 
        this->start = start; 
        this->lastTrigerTick = lastTrigerTick; 
        this->data = data; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const BuffInfo & data) 
{ 
    ws << data.eid;  
    ws << data.skillID;  
    ws << data.buffID;  
    ws << data.start;  
    ws << data.lastTrigerTick;  
    ws << data.data;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, BuffInfo & data) 
{ 
    rs >> data.eid;  
    rs >> data.skillID;  
    rs >> data.buffID;  
    rs >> data.start;  
    rs >> data.lastTrigerTick;  
    rs >> data.data;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const BuffInfo & info) 
{ 
    stm << "["; 
    stm << "eid=" << info.eid << ","; 
    stm << "skillID=" << info.skillID << ","; 
    stm << "buffID=" << info.buffID << ","; 
    stm << "start=" << info.start << ","; 
    stm << "lastTrigerTick=" << info.lastTrigerTick << ","; 
    stm << "data=" << info.data << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<BuffInfo> BuffInfoArray;  
 
struct EntityInfo //EntityInfo  
{ 
    static const unsigned short getProtoID() { return 10010;} 
    static const std::string getProtoName() { return "EntityInfo";} 
    unsigned long long eid; //eid  
    unsigned short camp; //阵营  
    unsigned long long groupID; //组队ID  
    unsigned short etype; //实体类型  
    unsigned short state; //状态  
    unsigned long long foe; //锁定的敌人  
    unsigned long long leader; //实体的老大, 如果是飞行道具 这个指向施放飞行道具的人  
    double curHP; //当前的血量  
    EntityInfo() 
    { 
        eid = 0; 
        camp = 0; 
        groupID = 0; 
        etype = 0; 
        state = 0; 
        foe = 0; 
        leader = 0; 
        curHP = 0.0; 
    } 
    EntityInfo(const unsigned long long & eid, const unsigned short & camp, const unsigned long long & groupID, const unsigned short & etype, const unsigned short & state, const unsigned long long & foe, const unsigned long long & leader, const double & curHP) 
    { 
        this->eid = eid; 
        this->camp = camp; 
        this->groupID = groupID; 
        this->etype = etype; 
        this->state = state; 
        this->foe = foe; 
        this->leader = leader; 
        this->curHP = curHP; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const EntityInfo & data) 
{ 
    ws << data.eid;  
    ws << data.camp;  
    ws << data.groupID;  
    ws << data.etype;  
    ws << data.state;  
    ws << data.foe;  
    ws << data.leader;  
    ws << data.curHP;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, EntityInfo & data) 
{ 
    rs >> data.eid;  
    rs >> data.camp;  
    rs >> data.groupID;  
    rs >> data.etype;  
    rs >> data.state;  
    rs >> data.foe;  
    rs >> data.leader;  
    rs >> data.curHP;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const EntityInfo & info) 
{ 
    stm << "["; 
    stm << "eid=" << info.eid << ","; 
    stm << "camp=" << info.camp << ","; 
    stm << "groupID=" << info.groupID << ","; 
    stm << "etype=" << info.etype << ","; 
    stm << "state=" << info.state << ","; 
    stm << "foe=" << info.foe << ","; 
    stm << "leader=" << info.leader << ","; 
    stm << "curHP=" << info.curHP << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<EntityInfo> EntityInfoArray;  
 
struct EntityMove //EntityMove  
{ 
    static const unsigned short getProtoID() { return 10011;} 
    static const std::string getProtoName() { return "EntityMove";} 
    unsigned long long eid; //eid  
    EPosition position; //当前坐标  
    unsigned short action; //移动状态  
    double realSpeed; //实时速度  
    double expectSpeed; //期望速度  
    EPositionArray waypoints; //移动路点  
    unsigned long long follow; //eid  
    EntityMove() 
    { 
        eid = 0; 
        action = 0; 
        realSpeed = 0.0; 
        expectSpeed = 0.0; 
        follow = 0; 
    } 
    EntityMove(const unsigned long long & eid, const EPosition & position, const unsigned short & action, const double & realSpeed, const double & expectSpeed, const EPositionArray & waypoints, const unsigned long long & follow) 
    { 
        this->eid = eid; 
        this->position = position; 
        this->action = action; 
        this->realSpeed = realSpeed; 
        this->expectSpeed = expectSpeed; 
        this->waypoints = waypoints; 
        this->follow = follow; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const EntityMove & data) 
{ 
    ws << data.eid;  
    ws << data.position;  
    ws << data.action;  
    ws << data.realSpeed;  
    ws << data.expectSpeed;  
    ws << data.waypoints;  
    ws << data.follow;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, EntityMove & data) 
{ 
    rs >> data.eid;  
    rs >> data.position;  
    rs >> data.action;  
    rs >> data.realSpeed;  
    rs >> data.expectSpeed;  
    rs >> data.waypoints;  
    rs >> data.follow;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const EntityMove & info) 
{ 
    stm << "["; 
    stm << "eid=" << info.eid << ","; 
    stm << "position=" << info.position << ","; 
    stm << "action=" << info.action << ","; 
    stm << "realSpeed=" << info.realSpeed << ","; 
    stm << "expectSpeed=" << info.expectSpeed << ","; 
    stm << "waypoints=" << info.waypoints << ","; 
    stm << "follow=" << info.follow << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<EntityMove> EntityMoveArray;  
 
struct EntityReport //EntityReport  
{ 
    static const unsigned short getProtoID() { return 10012;} 
    static const std::string getProtoName() { return "EntityReport";} 
    unsigned long long eid; //eid  
    unsigned long long killOtherCount; //杀死其他玩家次数  
    unsigned long long killOtherTime; //杀死其他玩家的时间  
    unsigned long long diedCount; //死亡次数  
    unsigned long long topMultiKills; //最高连杀次数  
    unsigned long long curMultiKills; //当前连杀次数  
    EntityReport() 
    { 
        eid = 0; 
        killOtherCount = 0; 
        killOtherTime = 0; 
        diedCount = 0; 
        topMultiKills = 0; 
        curMultiKills = 0; 
    } 
    EntityReport(const unsigned long long & eid, const unsigned long long & killOtherCount, const unsigned long long & killOtherTime, const unsigned long long & diedCount, const unsigned long long & topMultiKills, const unsigned long long & curMultiKills) 
    { 
        this->eid = eid; 
        this->killOtherCount = killOtherCount; 
        this->killOtherTime = killOtherTime; 
        this->diedCount = diedCount; 
        this->topMultiKills = topMultiKills; 
        this->curMultiKills = curMultiKills; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const EntityReport & data) 
{ 
    ws << data.eid;  
    ws << data.killOtherCount;  
    ws << data.killOtherTime;  
    ws << data.diedCount;  
    ws << data.topMultiKills;  
    ws << data.curMultiKills;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, EntityReport & data) 
{ 
    rs >> data.eid;  
    rs >> data.killOtherCount;  
    rs >> data.killOtherTime;  
    rs >> data.diedCount;  
    rs >> data.topMultiKills;  
    rs >> data.curMultiKills;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const EntityReport & info) 
{ 
    stm << "["; 
    stm << "eid=" << info.eid << ","; 
    stm << "killOtherCount=" << info.killOtherCount << ","; 
    stm << "killOtherTime=" << info.killOtherTime << ","; 
    stm << "diedCount=" << info.diedCount << ","; 
    stm << "topMultiKills=" << info.topMultiKills << ","; 
    stm << "curMultiKills=" << info.curMultiKills << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<EntityReport> EntityReportArray;  
 
struct EntityFullData //EntityFullData  
{ 
    static const unsigned short getProtoID() { return 10013;} 
    static const std::string getProtoName() { return "EntityFullData";} 
    EntityBase baseInfo; //玩家基础数据  
    EntityProp fixedProps; //基础固定属性  
    EntityProp growthProps; //成长基础属性  
    EntityProp growths; //成长系数  
    EntityProp props; //当前  
    EntityInfo info;  
    EntityMove mv;  
    EntityReport report;  
    EntityFullData() 
    { 
    } 
    EntityFullData(const EntityBase & baseInfo, const EntityProp & fixedProps, const EntityProp & growthProps, const EntityProp & growths, const EntityProp & props, const EntityInfo & info, const EntityMove & mv, const EntityReport & report) 
    { 
        this->baseInfo = baseInfo; 
        this->fixedProps = fixedProps; 
        this->growthProps = growthProps; 
        this->growths = growths; 
        this->props = props; 
        this->info = info; 
        this->mv = mv; 
        this->report = report; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const EntityFullData & data) 
{ 
    ws << data.baseInfo;  
    ws << data.fixedProps;  
    ws << data.growthProps;  
    ws << data.growths;  
    ws << data.props;  
    ws << data.info;  
    ws << data.mv;  
    ws << data.report;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, EntityFullData & data) 
{ 
    rs >> data.baseInfo;  
    rs >> data.fixedProps;  
    rs >> data.growthProps;  
    rs >> data.growths;  
    rs >> data.props;  
    rs >> data.info;  
    rs >> data.mv;  
    rs >> data.report;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const EntityFullData & info) 
{ 
    stm << "["; 
    stm << "baseInfo=" << info.baseInfo << ","; 
    stm << "fixedProps=" << info.fixedProps << ","; 
    stm << "growthProps=" << info.growthProps << ","; 
    stm << "growths=" << info.growths << ","; 
    stm << "props=" << info.props << ","; 
    stm << "info=" << info.info << ","; 
    stm << "mv=" << info.mv << ","; 
    stm << "report=" << info.report << ","; 
    stm << "]"; 
    return stm; 
} 
 
 
typedef std::vector<EntityFullData> EntityFullDataArray;  
 
struct SceneSection //场景全景切片数据  
{ 
    static const unsigned short getProtoID() { return 10014;} 
    static const std::string getProtoName() { return "SceneSection";} 
    unsigned long long sceneID;  
    unsigned short sceneType;  
    unsigned short sceneState;  
    double sceneStartTime; //服务器战场开始时间  
    double sceneEndTime; //服务器战场结束时间  
    double serverTime; //服务器当前时间  
    EntityFullDataArray entitys; //这里包含有所有当前场景下的实体属性和状态数据  
    SceneSection() 
    { 
        sceneID = 0; 
        sceneType = 0; 
        sceneState = 0; 
        sceneStartTime = 0.0; 
        sceneEndTime = 0.0; 
        serverTime = 0.0; 
    } 
    SceneSection(const unsigned long long & sceneID, const unsigned short & sceneType, const unsigned short & sceneState, const double & sceneStartTime, const double & sceneEndTime, const double & serverTime, const EntityFullDataArray & entitys) 
    { 
        this->sceneID = sceneID; 
        this->sceneType = sceneType; 
        this->sceneState = sceneState; 
        this->sceneStartTime = sceneStartTime; 
        this->sceneEndTime = sceneEndTime; 
        this->serverTime = serverTime; 
        this->entitys = entitys; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const SceneSection & data) 
{ 
    ws << data.sceneID;  
    ws << data.sceneType;  
    ws << data.sceneState;  
    ws << data.sceneStartTime;  
    ws << data.sceneEndTime;  
    ws << data.serverTime;  
    ws << data.entitys;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, SceneSection & data) 
{ 
    rs >> data.sceneID;  
    rs >> data.sceneType;  
    rs >> data.sceneState;  
    rs >> data.sceneStartTime;  
    rs >> data.sceneEndTime;  
    rs >> data.serverTime;  
    rs >> data.entitys;  
    return rs; 
} 
inline zsummer::log4z::Log4zStream & operator << (zsummer::log4z::Log4zStream & stm, const SceneSection & info) 
{ 
    stm << "["; 
    stm << "sceneID=" << info.sceneID << ","; 
    stm << "sceneType=" << info.sceneType << ","; 
    stm << "sceneState=" << info.sceneState << ","; 
    stm << "sceneStartTime=" << info.sceneStartTime << ","; 
    stm << "sceneEndTime=" << info.sceneEndTime << ","; 
    stm << "serverTime=" << info.serverTime << ","; 
    stm << "entitys=" << info.entitys << ","; 
    stm << "]"; 
    return stm; 
} 
 
#endif 
