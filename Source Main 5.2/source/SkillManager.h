// SkillManager.h: interface for the CSkillManager class.
//////////////////////////////////////////////////////////////////////
#pragma once

enum ActionSkillType
{
    AT_SKILL_POISON = 1,
    AT_SKILL_METEO = 2,
    AT_SKILL_THUNDER = 3,
    AT_SKILL_FIREBALL = 4,
    AT_SKILL_FLAME = 5,
    AT_SKILL_TELEPORT = 6,
    AT_SKILL_SLOW = 7,
    AT_SKILL_STORM = 8,
    AT_SKILL_EVIL = 9,
    AT_SKILL_HELL = 10,
    AT_SKILL_POWERWAVE = 11,
    AT_SKILL_FLASH = 12,
    AT_SKILL_BLAST = 13,
    AT_SKILL_INFERNO = 14,
    AT_SKILL_TELEPORT_B = 15,
    AT_SKILL_WIZARDDEFENSE = 16,
    AT_SKILL_ENERGYBALL = 17,
    AT_SKILL_BLAST_POISON = 38,
    AT_SKILL_BLAST_FREEZE = 39,
    AT_SKILL_BLAST_HELL = 40,
    AT_SKILL_BLAST_HELL_BEGIN = 58,
    AT_SKILL_BLOCKING = 18,
    AT_SKILL_SWORD1 = 19,
    AT_SKILL_SWORD2 = 20,
    AT_SKILL_SWORD3 = 21,
    AT_SKILL_SWORD4 = 22,
    AT_SKILL_SWORD5 = 23,
    AT_SKILL_SPEAR = 47,
    AT_SKILL_VITALITY = 48,
    AT_SKILL_RIDER = 49,
    AT_SKILL_CROSSBOW = 24,
    AT_SKILL_BOW = 25,
    AT_SKILL_HEALING = 26,
    AT_SKILL_DEFENSE = 27,
    AT_SKILL_ATTACK = 28,
    AT_SKILL_SUMMON = 30,
    AT_SKILL_PARALYZE = 51,
    AT_SKILL_PIERCING = 52,
    AT_SKILL_IMPROVE_AG = 53,
    AT_SKILL_BLAST_CROSSBOW4 = 54,
    AT_SKILL_REDUCEDEFENSE = 55,
    AT_SKILL_ICE_BLADE = 56,
    AT_SKILL_WHEEL = 41,
    AT_SKILL_FURY_STRIKE = 42,
    AT_SKILL_ONETOONE = 43,
    AT_SKILL_RUSH = 44,
    AT_SKILL_JAVELIN = 45,
    AT_SKILL_DEEPIMPACT = 46,
    AT_SKILL_ONEFLASH = 57,
    AT_SKILL_BOSS = 50,
    AT_SKILL_COMBO = 59,
    AT_SKILL_STRONG_PIER = 60,
    AT_SKILL_LONGPIER_ATTACK,
    AT_SKILL_DARK_HORSE,
    AT_SKILL_PARTY_TELEPORT,
    AT_SKILL_ADD_CRITICAL,
    AT_SKILL_THUNDER_STRIKE,
    AT_SKILL_LONG_SPEAR,
    AT_SKILL_STUN,
    AT_SKILL_REMOVAL_STUN,
    AT_SKILL_MANA,
    AT_SKILL_INVISIBLE,
    AT_SKILL_REMOVAL_INVISIBLE,
    AT_SKILL_REMOVAL_BUFF,
    AT_SKILL_DEATH_CANNON,
    AT_SKILL_SPACE_SPLIT,
    AT_SKILL_BRAND_OF_SKILL,
    AT_SKILL_PLASMA_STORM_FENRIR = 76,
    AT_SKILL_INFINITY_ARROW,
    AT_SKILL_DARK_SCREAM,
    AT_SKILL_EXPLODE,
    AT_IMPROVE_DAMAGE,
    AT_IMPROVE_MAGIC,
    AT_IMPROVE_CURSE,
    AT_IMPROVE_BLOCKING,
    AT_IMPROVE_DEFENSE,
    AT_LUCK,
    AT_LIFE_REGENERATION,
    AT_IMPROVE_LIFE,
    AT_IMPROVE_MANA,
    AT_DECREASE_DAMAGE,
    AT_REFLECTION_DAMAGE,
    AT_IMPROVE_BLOCKING_PERCENT,
    AT_IMPROVE_GAIN_GOLD,
    AT_EXCELLENT_DAMAGE,
    AT_IMPROVE_DAMAGE_LEVEL,
    AT_IMPROVE_DAMAGE_PERCENT,
    AT_IMPROVE_MAGIC_LEVEL,
    AT_IMPROVE_MAGIC_PERCENT,
    AT_IMPROVE_ATTACK_SPEED,
    AT_IMPROVE_GAIN_LIFE,
    AT_IMPROVE_GAIN_MANA,
    AT_IMPROVE_HP_MAX,
    AT_IMPROVE_MP_MAX,
    AT_ONE_PERCENT_DAMAGE,
    AT_IMPROVE_AG_MAX,
    AT_DAMAGE_ABSORB,
    AT_DAMAGE_REFLECTION,
    AT_RECOVER_FULL_LIFE,
    AT_RECOVER_FULL_MANA,
    AT_IMPROVE_CHARISMA,
    AT_IMPROVE_EVADE = 110,
    AT_SKILL_MONSTER_SUMMON = 200,
    AT_SKILL_MONSTER_MAGIC_DEF,
    AT_SKILL_MONSTER_PHY_DEF,
    AT_SKILL_HELLOWIN_EVENT_1 = 205,
    AT_SKILL_HELLOWIN_EVENT_2 = 206,
    AT_SKILL_HELLOWIN_EVENT_3 = 207,
    AT_SKILL_HELLOWIN_EVENT_4 = 208,
    AT_SKILL_HELLOWIN_EVENT_5 = 209,
    AT_SKILL_CURSED_TEMPLE_PRODECTION = 210,
    AT_SKILL_CURSED_TEMPLE_RESTRAINT = 211,
    AT_SKILL_CURSED_TEMPLE_TELEPORT = 212,
    //	AT_SKILL_CURSED_TEMPLE_QUICKNESS   = 213,
    AT_SKILL_CURSED_TEMPLE_SUBLIMATION = 213,
    AT_SKILL_ALICE_DRAINLIFE = 214,
    AT_SKILL_ALICE_CHAINLIGHTNING = 215,
    AT_SKILL_ALICE_LIGHTNINGORB = 216,
    AT_SKILL_ALICE_THORNS = 217,
    AT_SKILL_ALICE_BERSERKER = 218,
    AT_SKILL_ALICE_SLEEP = 219,
    AT_SKILL_ALICE_BLIND = 220,
    AT_SKILL_ALICE_WEAKNESS = 221,
    AT_SKILL_ALICE_ENERVATION = 222,
    AT_SKILL_SUMMON_EXPLOSION = 223,
    AT_SKILL_SUMMON_REQUIEM,
    AT_SKILL_SUMMON_POLLUTION = 225,
    AT_SKILL_LIGHTNING_SHOCK = 230,
    AT_SKILL_BLOW_OF_DESTRUCTION = 232,
    AT_SKILL_SWELL_OF_MAGICPOWER = 233,
    AT_SKILL_FLAME_STRIKE = 236,
    AT_SKILL_GIGANTIC_STORM = 237,
    AT_SKILL_RECOVER = 234,
    AT_SKILL_MULTI_SHOT = 235,
    AT_SKILL_GAOTIC = 238,
    AT_SKILL_DOPPELGANGER_SELFDESTRUCTION = 239,
    AT_SKILL_THRUST = 260,				// Rage fighter
    AT_SKILL_STAMP = 261,				// Rage fighter
    AT_SKILL_GIANTSWING = 262,			// Rage fighter
    AT_SKILL_DARKSIDE = 263,			// Rage fighter
    AT_SKILL_DRAGON_LOWER = 264,		// Rage fighter
    AT_SKILL_DRAGON_KICK = 265,			// Rage fighter
    AT_SKILL_ATT_UP_OURFORCES = 266,	// Rage fighter
    AT_SKILL_HP_UP_OURFORCES = 267,		// Rage fighter
    AT_SKILL_DEF_UP_OURFORCES = 268,	// Rage fighter
    AT_SKILL_OCCUPY = 269,				// Rage fighter
    AT_SKILL_PHOENIX_SHOT = 270,		// Rage fighter
    AT_SKILL_ATTACK_RATEUP = 300,
    AT_SKILL_TOMAN_ATTACKUP = AT_SKILL_ATTACK_RATEUP + 5,
    AT_SKILL_TOMAN_DEFENCEUP = AT_SKILL_TOMAN_ATTACKUP + 5,
    AT_SKILL_DURABLE_MINUS1 = AT_SKILL_TOMAN_DEFENCEUP + 5,
    AT_SKILL_DURABLE_MINUS2 = AT_SKILL_DURABLE_MINUS1 + 5,
    AT_SKILL_RESIST_UP_POISON = AT_SKILL_DURABLE_MINUS2 + 5,
    AT_SKILL_RESIST_UP_LIGHT = AT_SKILL_RESIST_UP_POISON + 5,
    AT_SKILL_RESIST_UP_ICE = AT_SKILL_RESIST_UP_LIGHT + 5,
    AT_SKILL_AUTO_RECOVER_LIFE = AT_SKILL_RESIST_UP_ICE + 5,
    AT_SKILL_GET_MONEY_UP = AT_SKILL_AUTO_RECOVER_LIFE + 5,
    AT_SKILL_DEF_UP = AT_SKILL_GET_MONEY_UP + 5,
    AT_SKILL_MAX_HP_UP = AT_SKILL_DEF_UP + 5,
    AT_SKILL_MAX_AG_UP = AT_SKILL_MAX_HP_UP + 5,
    AT_SKILL_MANA_RECOVER = AT_SKILL_MAX_AG_UP + 5,
    AT_SKILL_HP_RECOVER = AT_SKILL_MANA_RECOVER + 5,
    AT_SKILL_SD_RECOVER = AT_SKILL_HP_RECOVER + 5,
    AT_SKILL_EXP_UP = AT_SKILL_SD_RECOVER + 5,
    AT_SKILL_MAX_SD_UP = AT_SKILL_EXP_UP + 5,
    AT_SKILL_SD_RECOVER_SPD_UP = AT_SKILL_MAX_SD_UP + 5,
    AT_SKILL_MAX_ATTACKRATE_UP = AT_SKILL_SD_RECOVER_SPD_UP + 5,
    AT_SKILL_MIN_ATTACKRATE_UP = AT_SKILL_MAX_ATTACKRATE_UP + 5,
    AT_SKILL_MANA_MINUS_ADD = AT_SKILL_MIN_ATTACKRATE_UP + 5,
    AT_SKILL_MAX_MANA_UP = AT_SKILL_MANA_MINUS_ADD + 5,
    AT_SKILL_MIN_MANA_UP = AT_SKILL_MAX_MANA_UP + 5,
    AT_SKILL_PET_DURABLE_SPD_DN = AT_SKILL_MIN_MANA_UP + 5,
    AT_SKILL_MAX_ATT_MAGIC_UP = AT_SKILL_PET_DURABLE_SPD_DN + 5,
    AT_SKILL_MIN_ATT_MAGIC_UP = AT_SKILL_MAX_ATT_MAGIC_UP + 5,
    AT_SKILL_SOUL_UP = AT_SKILL_MIN_ATT_MAGIC_UP + 5,
    AT_SKILL_HELL_FIRE_UP = AT_SKILL_SOUL_UP + 5,
    AT_SKILL_EVIL_SPIRIT_UP = AT_SKILL_HELL_FIRE_UP + 5,
    AT_SKILL_ICE_UP = AT_SKILL_EVIL_SPIRIT_UP + 5,
    AT_SKILL_TORNADO_SWORDA_UP = AT_SKILL_ICE_UP + 5,
    AT_SKILL_BLOW_UP = AT_SKILL_TORNADO_SWORDA_UP + 5,
    AT_SKILL_ANGER_SWORD_UP = AT_SKILL_BLOW_UP + 5,
    AT_SKILL_LIFE_UP = AT_SKILL_ANGER_SWORD_UP + 5,
    AT_SKILL_HEAL_UP = AT_SKILL_LIFE_UP + 5,
    AT_SKILL_DEF_POWER_UP = AT_SKILL_HEAL_UP + 5,
    AT_SKILL_ATT_POWER_UP = AT_SKILL_DEF_POWER_UP + 5,
    AT_SKILL_MANY_ARROW_UP = AT_SKILL_ATT_POWER_UP + 5,
    AT_SKILL_TORNADO_SWORDB_UP = AT_SKILL_MANY_ARROW_UP + 5,
    AT_SKILL_BLOOD_ATT_UP = AT_SKILL_TORNADO_SWORDB_UP + 5,
    AT_SKILL_POWER_SLASH_UP = AT_SKILL_BLOOD_ATT_UP + 5,
    AT_SKILL_BLAST_UP = AT_SKILL_POWER_SLASH_UP + 5,
    AT_SKILL_ASHAKE_UP = AT_SKILL_BLAST_UP + 5,
    AT_SKILL_FIRE_BUST_UP = AT_SKILL_ASHAKE_UP + 5,
    AT_SKILL_FIRE_SCREAM_UP = AT_SKILL_FIRE_BUST_UP + 5,
    AT_SKILL_EVIL_SPIRIT_UP_M = AT_SKILL_FIRE_SCREAM_UP + 5,
    AT_SKILL_ALICE_SLEEP_UP = AT_SKILL_EVIL_SPIRIT_UP_M + 5,
    AT_SKILL_ALICE_CHAINLIGHTNING_UP = AT_SKILL_ALICE_SLEEP_UP + 5,
    AT_SKILL_LIGHTNING_SHOCK_UP = AT_SKILL_ALICE_CHAINLIGHTNING_UP + 5,
    AT_SKILL_ALICE_DRAINLIFE_UP = AT_SKILL_LIGHTNING_SHOCK_UP + 5, �
};

typedef struct DemendConditionInfo
{
    WORD SkillType;
    char SkillName[100];
    WORD SkillLevel;
    WORD SkillStrength;
    WORD SkillDexterity;
    WORD SkillVitality;
    WORD SkillEnergy;
    WORD SkillCharisma;

    DemendConditionInfo() : SkillType(0), SkillLevel(0), SkillStrength(0),
        SkillDexterity(0), SkillVitality(0), SkillEnergy(0), SkillCharisma(0)
    {
        ZeroMemory(SkillName, 100);
    }
    BOOL operator<=(const DemendConditionInfo& rhs) const
    {
        return SkillStrength <= rhs.SkillStrength && SkillDexterity <= rhs.SkillDexterity &&
            SkillVitality <= rhs.SkillVitality && SkillEnergy <= rhs.SkillEnergy && SkillCharisma <= rhs.SkillCharisma;
    }
} DemendConditionInfo;

class CSkillManager
{
public:
    CSkillManager();
    virtual ~CSkillManager();
    bool FindHeroSkill(ActionSkillType eSkillType);
    void GetSkillInformation(int iType, int iLevel, char* lpszName, int* piMana, int* piDistance, int* piSkillMana = NULL);
    void GetSkillInformation_Energy(int iType, int* piEnergy);
    void GetSkillInformation_Charisma(int iType, int* piCharisma);
    float GetSkillDistance(int Index, CHARACTER* c = NULL);
    void GetSkillInformation_Damage(int iType, int* piDamage);
    bool CheckSkillDelay(int SkillIndex);
    void CalcSkillDelay(int time);
    BYTE GetSkillMasteryType(int iType);
    int MasterSkillToBaseSkillIndex(int iMasterSkillIndex);
    bool skillVScharactorCheck(const DemendConditionInfo& basicInfo, const DemendConditionInfo& heroInfo);
    bool DemendConditionCheckSkill(WORD skilltype);
public:
};

extern CSkillManager gSkillManager;