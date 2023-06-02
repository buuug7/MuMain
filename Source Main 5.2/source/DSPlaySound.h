#ifndef __DSPLAYSOUND_H__
#define __DSPLAYSOUND_H__

#define MAX_CHANNEL 4

#define SOUND_WIND01               0
#define SOUND_RAIN01               1
#define SOUND_FOREST01             2
#define SOUND_DUNGEON01            3
#define SOUND_TITLE01              4
#define SOUND_TOWER01              5
#define SOUND_WATER01              6
#define SOUND_DESERT01             7

#define SOUND_HUMAN_WALK_GROUND    8
#define SOUND_HUMAN_WALK_GRASS     9
#define SOUND_HUMAN_WALK_SNOW      10
#define SOUND_HUMAN_WALK_SWIM      11

#define SOUND_BIRD01               12
#define SOUND_BIRD02               13
#define SOUND_BAT01                14
#define SOUND_RAT01                15
#define SOUND_TRAP01               16
#define SOUND_DOOR01               17
#define SOUND_DOOR02               18
#define SOUND_ASSASSIN             19

#define SOUND_HEAVEN01             20
#define SOUND_THUNDERS01           21
#define SOUND_THUNDERS02           22
#define SOUND_THUNDERS03           23

//interface
#define SOUND_CLICK01              25
#define SOUND_ERROR01              26
#define SOUND_MENU01               27
#define SOUND_INTERFACE01          28
#define SOUND_GET_ITEM01           29
#define SOUND_DROP_ITEM01          30
#define SOUND_DROP_GOLD01          31
#define SOUND_DRINK01              32
#define SOUND_EAT_APPLE01          33
#define SOUND_HEART                34
#define SOUND_GET_ENERGY           35
#define SOUND_SHOUT01              36
#define SOUND_REPAIR               37
#define SOUND_WHISPER              38
#define SOUND_ALERT                39
#define SOUND_FRIEND_CHAT_ALERT    40
#define SOUND_FRIEND_MAIL_ALERT    41
#define SOUND_FRIEND_LOGIN_ALERT   42

//attack
#define SOUND_BRANDISH_SWORD01     60
#define SOUND_BRANDISH_SWORD02     61
#define SOUND_BRANDISH_SWORD03     62
#define SOUND_BRANDISH_SWORD04     63
#define SOUND_EXPLOTION01          64
#define SOUND_EXPLOTION02          65
#define SOUND_METEORITE01          66
#define SOUND_METEORITE02          67
#define SOUND_BREAK01              68
#define SOUND_JEWEL01              69
#define SOUND_ATTACK01             70

//effect
#define SOUND_THUNDER01            80
#define SOUND_OPEN_DOOR01          81
#define SOUND_OPEN_DOOR02          82
#define SOUND_LEVEL_UP01           83
#define SOUND_HEALING01            84
#define SOUND_BOW01                85
#define SOUND_CROSSBOW01           86
#define SOUND_MIX01                87
#define SOUND_FIRECRACKER1         88
#define SOUND_FIRECRACKER2         89
#define SOUND_MEDAL			       90
#define SOUND_RING_EVENT_READY	   91
#define SOUND_RING_EVENT_START	   92
#define SOUND_RING_EVENT_END	   93
#define SOUND_CHAOS_MOB_BOOM01     94
#define SOUND_CHAOS_MOB_BOOM02     95
#define SOUND_CHAOS_FALLING        96
#define SOUND_CHAOS_FALLING_STONE  97

#define SOUND_CHANGE_UP            102

#define SOUND_PHOENIXEXP			103

//player
#define SOUND_HUMAN_SCREAM01       105
#define SOUND_HUMAN_SCREAM02       106
#define SOUND_HUMAN_SCREAM03       107
#define SOUND_HUMAN_SCREAM04       108
#define SOUND_FEMALE_SCREAM01      109
#define SOUND_FEMALE_SCREAM02     110

//skill
#define SOUND_SKILL_DEFENSE       111
#define SOUND_SKILL_SWORD1        112
#define SOUND_SKILL_SWORD2        113
#define SOUND_SKILL_SWORD3        114
#define SOUND_SKILL_SWORD4        115
#define SOUND_STORM               116
#define SOUND_EVIL                117
#define SOUND_MAGIC               118
#define SOUND_HELLFIRE            119
#define SOUND_ICE                 120
#define SOUND_FLAME               121
#define SOUND_FLASH               122
#define SOUND_BONE1               123
#define SOUND_BONE2               124

#define SOUND_RIDINGSPEAR			125
#define SOUND_RAIDSHOOT				126
#define SOUND_SWELLLIFE				127
#define SOUND_FURY					128
#define SOUND_PIERCING				129
#define SOUND_ICEARROW				130
#define SOUND_TELEKINESIS			131
#define SOUND_SOULBARRIER			132
#define SOUND_BLOODATTACK			133

#define SOUND_HIT_GATE              134
#define SOUND_HIT_GATE2             135
#define SOUND_HIT_CRISTAL           136
#define SOUND_DOWN_GATE             137
#define SOUND_CROW                  138
#define SOUND_BLOODCASTLE           139

#ifdef DUEL_SYSTEM
#define SOUND_OPEN_DUELWINDOW		140
#define SOUND_START_DUEL			141
#endif // DUEL_SYSTEM

#define SOUND_DEATH_POISON1	142
#define SOUND_DEATH_POISON2	143
#define SOUND_SUDDEN_ICE1   144
#define SOUND_SUDDEN_ICE2   145
#define SOUND_NUKE1			146
#define SOUND_NUKE2			147
#define SOUND_COMBO			148
#define SOUND_FURY_STRIKE1	149
#define SOUND_FURY_STRIKE2	150
#define SOUND_FURY_STRIKE3	151
#define SOUND_LEVEL_UP		152
#define SOUND_CHAOSCASTLE   153

#define SOUND_CHAOS_THUNDER01   156
#define SOUND_CHAOS_THUNDER02   157
#define SOUND_CHAOS_ENVIR       158
#define SOUND_CHAOS_END         159

//npc
#define SOUND_NPC                  160
#define SOUND_NPC_END              210

//monster
#define SOUND_MONSTER              210
#define SOUND_MONSTER_END          450

enum
{
    SOUND_EXPAND_START = SOUND_MONSTER_END,
    SOUND_RUN_DARK_HORSE_1,
    SOUND_RUN_DARK_HORSE_2,
    SOUND_RUN_DARK_HORSE_3,
    SOUND_DARKLORD_PAIN,
    SOUND_DARKLORD_DEAD,
    SOUND_ATTACK_SPEAR,
    SOUND_ATTACK_FIRE_BUST,
    SOUND_ATTACK_FIRE_BUST_EXP,
    SOUND_PART_TELEPORT,
    SOUND_ELEC_STRIKE_READY,
    SOUND_ELEC_STRIKE,
    SOUND_EARTH_QUAKE,
    SOUND_CRITICAL,
    SOUND_DSPIRIT_MISSILE,
    SOUND_DSPIRIT_SHOUT,
    SOUND_DSPIRIT_RUSH,

    SOUND_KALIMA_AMBIENT,
    SOUND_KALIMA_AMBIENT2,
    SOUND_KALIMA_AMBIENT3,
    SOUND_KALIMA_WATER_FALL,
    SOUND_KALIMA_FALLING_STONE,
    SOUND_DEATH_BUBBLE,

    SOUND_KUNDUN_AMBIENT1,
    SOUND_KUNDUN_AMBIENT2,
    SOUND_KUNDUN_ROAR,
    SOUND_KUNDUN_SIGHT,
    SOUND_KUNDUN_SHUDDER,
    SOUND_KUNDUN_DESTROY,

    SOUND_SKILL_SKULL,
    SOUND_GREAT_POISON,
    SOUND_GREAT_SHIELD,

    SOUND_BC_AMBIENT,
    SOUND_BC_AMBIENT_BATTLE1,
    SOUND_BC_AMBIENT_BATTLE2,
    SOUND_BC_AMBIENT_BATTLE3,
    SOUND_BC_AMBIENT_BATTLE4,
    SOUND_BC_AMBIENT_BATTLE5,
    SOUND_BC_GUARD_STONE_DIS,
    SOUND_BC_SHIELD_SPACE_DIS,
    SOUND_BC_CATAPULT_ATTACK,
    SOUND_BC_CATAPULT_HIT,
    SOUND_BC_WALL_HIT,
    SOUND_BC_GATE_OPEN,
    SOUND_BC_GUARDIAN_ATTACK,

    SOUND_BC_HUNTINGGROUND_AMBIENT,
    SOUND_BC_AXEWARRIOR_MOVE1,
    SOUND_BC_AXEWARRIOR_MOVE2,
    SOUND_BC_AXEWARRIOR_ATTACK1,
    SOUND_BC_AXEWARRIOR_ATTACK2,
    SOUND_BC_AXEWARRIOR_DIE,
    SOUND_BC_LIZARDWARRIOR_MOVE1,
    SOUND_BC_LIZARDWARRIOR_MOVE2,
    SOUND_BC_LIZARDWARRIOR_ATTACK1,
    SOUND_BC_LIZARDWARRIOR_ATTACK2,
    SOUND_BC_LIZARDWARRIOR_DIE,
    SOUND_BC_POISONGOLEM_MOVE1,
    SOUND_BC_POISONGOLEM_MOVE2,
    SOUND_BC_POISONGOLEM_ATTACK1,
    SOUND_BC_POISONGOLEM_ATTACK2,
    SOUND_BC_POISONGOLEM_ATTACK3,
    SOUND_BC_POISONGOLEM_DIE,
    SOUND_BC_QUEENBEE_MOVE1,
    SOUND_BC_QUEENBEE_MOVE2,
    SOUND_BC_QUEENBEE_ATTACK1,
    SOUND_BC_QUEENBEE_ATTACK2,
    SOUND_BC_QUEENBEE_DIE,
    SOUND_BC_FIREGOLEM_MOVE1,
    SOUND_BC_FIREGOLEM_MOVE2,
    SOUND_BC_FIREGOLEM_ATTACK1,
    SOUND_BC_FIREGOLEM_ATTACK2,
    SOUND_BC_FIREGOLEM_DIE,
    SOUND_BC_EROHIM_ENTER,
    SOUND_BC_EROHIM_ATTACK1,
    SOUND_BC_EROHIM_ATTACK2,
    SOUND_BC_EROHIM_ATTACK3,
    SOUND_BC_EROHIM_DIE,
    SOUND_CRY1ST_AMBIENT,
    SOUND_CRY1ST_WWOLF_MOVE1,
    SOUND_CRY1ST_WWOLF_MOVE2,
    SOUND_CRY1ST_WWOLF_ATTACK1,
    SOUND_CRY1ST_WWOLF_ATTACK2,
    SOUND_CRY1ST_WWOLF_DIE,

    SOUND_CRY1ST_SCOUT1_MOVE1,
    SOUND_CRY1ST_SCOUT1_MOVE2,
    SOUND_CRY1ST_SCOUT1_ATTACK1,
    SOUND_CRY1ST_SCOUT1_ATTACK2,
    SOUND_CRY1ST_SCOUT1_DIE,

    SOUND_CRY1ST_SCOUT2_MOVE1,
    SOUND_CRY1ST_SCOUT2_MOVE2,
    SOUND_CRY1ST_SCOUT2_ATTACK1,
    SOUND_CRY1ST_SCOUT2_ATTACK2,
    SOUND_CRY1ST_SCOUT2_DIE,

    SOUND_CRY1ST_SCOUT3_MOVE1,
    SOUND_CRY1ST_SCOUT3_MOVE2,
    SOUND_CRY1ST_SCOUT3_ATTACK1,
    SOUND_CRY1ST_SCOUT3_ATTACK2,
    SOUND_CRY1ST_SCOUT3_DIE,

    SOUND_CRY1ST_SORAM_MOVE1,
    SOUND_CRY1ST_SORAM_MOVE2,
    SOUND_CRY1ST_SORAM_ATTACK1,
    SOUND_CRY1ST_SORAM_ATTACK2,
    SOUND_CRY1ST_SORAM_DIE,

    SOUND_CRY1ST_BALRAM_MOVE1,
    SOUND_CRY1ST_BALRAM_MOVE2,
    SOUND_CRY1ST_BALRAM_ATTACK1,
    SOUND_CRY1ST_BALRAM_ATTACK2,
    SOUND_CRY1ST_BALRAM_DIE,

    SOUND_CRY1ST_BALGAS_MOVE1,
    SOUND_CRY1ST_BALGAS_MOVE2,
    SOUND_CRY1ST_BALGAS_ATTACK1,
    SOUND_CRY1ST_BALGAS_ATTACK2,
    SOUND_CRY1ST_BALGAS_DIE,
    SOUND_CRY1ST_BALGAS_SKILL1,
    SOUND_CRY1ST_BALGAS_SKILL2,

    SOUND_CRY1ST_DARKELF_MOVE1,
    SOUND_CRY1ST_DARKELF_MOVE2,
    SOUND_CRY1ST_DARKELF_ATTACK1,
    SOUND_CRY1ST_DARKELF_ATTACK2,
    SOUND_CRY1ST_DARKELF_DIE,
    SOUND_CRY1ST_DARKELF_SKILL1,
    SOUND_CRY1ST_DARKELF_SKILL2,

    SOUND_CRY1ST_DEATHSPIRIT_MOVE1,
    SOUND_CRY1ST_DEATHSPIRIT_MOVE2,
    SOUND_CRY1ST_DEATHSPIRIT_ATTACK1,
    SOUND_CRY1ST_DEATHSPIRIT_ATTACK2,
    SOUND_CRY1ST_DEATHSPIRIT_DIE,

    SOUND_CRY1ST_TANKER_ATTACK1,
    SOUND_CRY1ST_TANKER_DIE,
    SOUND_CRY1ST_SUMMON,
    SOUND_CRY1ST_SUCCESS,
    SOUND_CRY1ST_FAILED,
    SOUND_AIDA_AMBIENT,
    SOUND_AIDA_BLUEGOLEM_MOVE1,
    SOUND_AIDA_BLUEGOLEM_MOVE2,
    SOUND_AIDA_BLUEGOLEM_ATTACK1,
    SOUND_AIDA_BLUEGOLEM_ATTACK2,
    SOUND_AIDA_BLUEGOLEM_DIE,
    SOUND_AIDA_DEATHRAIDER_MOVE1,
    SOUND_AIDA_DEATHRAIDER_MOVE2,
    SOUND_AIDA_DEATHRAIDER_ATTACK1,
    SOUND_AIDA_DEATHRAIDER_ATTACK2,
    SOUND_AIDA_DEATHRAIDER_DIE,
    SOUND_AIDA_DEATHTREE_MOVE1,
    SOUND_AIDA_DEATHTREE_MOVE2,
    SOUND_AIDA_DEATHTREE_ATTACK1,
    SOUND_AIDA_DEATHTREE_ATTACK2,
    SOUND_AIDA_DEATHTREE_DIE,
    SOUND_AIDA_FORESTORC_MOVE1,
    SOUND_AIDA_FORESTORC_MOVE2,
    SOUND_AIDA_FORESTORC_ATTACK1,
    SOUND_AIDA_FORESTORC_ATTACK2,
    SOUND_AIDA_FORESTORC_DIE,
    SOUND_AIDA_HELL_MOVE1,
    SOUND_AIDA_HELL_MOVE2,
    SOUND_AIDA_HELL_ATTACK1,
    SOUND_AIDA_HELL_ATTACK2,
    SOUND_AIDA_HELL_ATTACK3,
    SOUND_AIDA_HELL_DIE,
    SOUND_AIDA_WITCHQUEEN_MOVE1,
    SOUND_AIDA_WITCHQUEEN_MOVE2,
    SOUND_AIDA_WITCHQUEEN_ATTACK1,
    SOUND_AIDA_WITCHQUEEN_ATTACK2,
    SOUND_AIDA_WITCHQUEEN_DIE,

    SOUND_KANTURU_1ST_BG_WATERFALL,
    SOUND_KANTURU_1ST_BG_ELEC,
    SOUND_KANTURU_1ST_BG_WHEEL,
    SOUND_KANTURU_1ST_BG_PLANT,
    SOUND_KANTURU_1ST_BG_GLOBAL,

    SOUND_KANTURU_1ST_BER_MOVE1,
    SOUND_KANTURU_1ST_BER_MOVE2,
    SOUND_KANTURU_1ST_BER_ATTACK1,
    SOUND_KANTURU_1ST_BER_ATTACK2,
    SOUND_KANTURU_1ST_BER_DIE,
    SOUND_KANTURU_1ST_GIGAN_MOVE1,
    SOUND_KANTURU_1ST_GIGAN_ATTACK1,
    SOUND_KANTURU_1ST_GIGAN_ATTACK2,
    SOUND_KANTURU_1ST_GIGAN_DIE,
    SOUND_KANTURU_1ST_GENO_MOVE1,
    SOUND_KANTURU_1ST_GENO_MOVE2,
    SOUND_KANTURU_1ST_GENO_ATTACK1,
    SOUND_KANTURU_1ST_GENO_ATTACK2,
    SOUND_KANTURU_1ST_GENO_DIE,

    SOUND_KANTURU_1ST_KENTA_MOVE1,
    SOUND_KANTURU_1ST_KENTA_MOVE2,
    SOUND_KANTURU_1ST_KENTA_ATTACK1,
    SOUND_KANTURU_1ST_KENTA_ATTACK2,
    SOUND_KANTURU_1ST_KENTA_DIE,
    SOUND_KANTURU_1ST_BLADE_MOVE1,
    SOUND_KANTURU_1ST_BLADE_MOVE2,
    SOUND_KANTURU_1ST_BLADE_ATTACK1,
    SOUND_KANTURU_1ST_BLADE_ATTACK2,
    SOUND_KANTURU_1ST_BLADE_DIE,
    SOUND_KANTURU_1ST_SATI_MOVE1,
    SOUND_KANTURU_1ST_SATI_MOVE2,
    SOUND_KANTURU_1ST_SATI_ATTACK1,
    SOUND_KANTURU_1ST_SATI_ATTACK2,
    SOUND_KANTURU_1ST_SATI_DIE,

    SOUND_KANTURU_1ST_SWOLF_MOVE1,
    SOUND_KANTURU_1ST_SWOLF_MOVE2,
    SOUND_KANTURU_1ST_SWOLF_ATTACK1,
    SOUND_KANTURU_1ST_SWOLF_ATTACK2,
    SOUND_KANTURU_1ST_SWOLF_DIE,

    SOUND_KANTURU_1ST_IR_MOVE1,
    SOUND_KANTURU_1ST_IR_MOVE2,
    SOUND_KANTURU_1ST_IR_ATTACK1,
    SOUND_KANTURU_1ST_IR_ATTACK2,
    SOUND_KANTURU_1ST_IR_DIE,

    SOUND_KANTURU_2ND_MAPSOUND_GEAR,
    SOUND_KANTURU_2ND_MAPSOUND_INCUBATOR,
    SOUND_KANTURU_2ND_MAPSOUND_HOLE,
    SOUND_KANTURU_2ND_MAPSOUND_GLOBAL,
    SOUND_KANTURU_2ND_PERSO_MOVE1,
    SOUND_KANTURU_2ND_PERSO_MOVE2,
    SOUND_KANTURU_2ND_PERSO_ATTACK1,
    SOUND_KANTURU_2ND_PERSO_ATTACK2,
    SOUND_KANTURU_2ND_PERSO_DIE,
    SOUND_KANTURU_2ND_TWIN_MOVE1,
    SOUND_KANTURU_2ND_TWIN_MOVE2,
    SOUND_KANTURU_2ND_TWIN_ATTACK1,
    SOUND_KANTURU_2ND_TWIN_ATTACK2,
    SOUND_KANTURU_2ND_TWIN_DIE,
    SOUND_KANTURU_2ND_DRED_MOVE1,
    SOUND_KANTURU_2ND_DRED_MOVE2,
    SOUND_KANTURU_2ND_DRED_ATTACK1,
    SOUND_KANTURU_2ND_DRED_ATTACK2,
    SOUND_KANTURU_2ND_DRED_DIE,
    SOUND_BMS_STUN,
    SOUND_BMS_STUN_REMOVAL,
    SOUND_BMS_MANA,
    SOUND_BMS_INVISIBLE,
    SOUND_BMS_VISIBLE,
    SOUND_BMS_MAGIC_REMOVAL,
    SOUND_BCS_RUSH,
    SOUND_BCS_JAVELIN,
    SOUND_BCS_DEEP_IMPACT,
    SOUND_BCS_DEATH_CANON,
    SOUND_BCS_ONE_FLASH,
    SOUND_BCS_SPACE_SPLIT,
    SOUND_BCS_BRAND_OF_SKILL,

    SOUND_FENRIR_RUN_1,
    SOUND_FENRIR_RUN_2,
    SOUND_FENRIR_RUN_3,
    SOUND_FENRIR_WALK_1,
    SOUND_FENRIR_WALK_2,
    SOUND_FENRIR_DEATH,
    SOUND_FENRIR_IDLE_1,
    SOUND_FENRIR_IDLE_2,
    SOUND_FENRIR_DAMAGE_1,
    SOUND_FENRIR_DAMAGE_2,
    SOUND_FENRIR_SKILL,

    SOUND_KANTURU_3RD_MAYA_INTRO,
    SOUND_KANTURU_3RD_MAYA_END,
    SOUND_KANTURU_3RD_MAYA_STORM,
    SOUND_KANTURU_3RD_NIGHTMARE_INTRO,
    SOUND_KANTURU_3RD_MAYAHAND_ATTACK1,
    SOUND_KANTURU_3RD_MAYAHAND_ATTACK2,
    SOUND_KANTURU_3RD_MAP_SOUND01,
    SOUND_KANTURU_3RD_MAP_SOUND02,
    SOUND_KANTURU_3RD_MAP_SOUND03,
    SOUND_KANTURU_3RD_MAP_SOUND04,
    SOUND_KANTURU_3RD_MAP_SOUND05,
    SOUND_KANTURU_3RD_AMBIENT,
    SOUND_KANTURU_3RD_NIGHTMARE_ATT1,
    SOUND_KANTURU_3RD_NIGHTMARE_ATT2,
    SOUND_KANTURU_3RD_NIGHTMARE_ATT3,
    SOUND_KANTURU_3RD_NIGHTMARE_ATT4,
    SOUND_KANTURU_3RD_NIGHTMARE_DIE,
    SOUND_KANTURU_3RD_NIGHTMARE_IDLE1,
    SOUND_KANTURU_3RD_NIGHTMARE_IDLE2,
    SOUND_KANTURU_3RD_NIGHTMARE_TELE,
    SOUND_JEWEL02,

    SOUND_XMAS_JUMP_SANTA,
    SOUND_XMAS_JUMP_DEER,
    SOUND_XMAS_JUMP_SNOWMAN,
    SOUND_XMAS_TURN,

    SOUND_NEWYEARSDAY_DIE,
    SOUND_KUNDUN_ITEM_SOUND,
    SOUND_SHIELDCLASH,
    SOUND_INFINITYARROW,
    SOUND_FIRE_SCREAM,

    SOUND_3RD_CHANGE_UP_BG_CAGE1,
    SOUND_3RD_CHANGE_UP_BG_CAGE2,
    SOUND_3RD_CHANGE_UP_BG_VOLCANO,
    SOUND_3RD_CHANGE_UP_BG_FIREPILLAR,

    SOUND_CURSEDTEMPLE_GAMESYSTEM1,
    SOUND_CURSEDTEMPLE_GAMESYSTEM2,
    SOUND_CURSEDTEMPLE_GAMESYSTEM3,
    SOUND_CURSEDTEMPLE_GAMESYSTEM4,
    SOUND_CURSEDTEMPLE_GAMESYSTEM5,

    SOUND_CURSEDTEMPLE_MONSTER1_IDLE,
    SOUND_CURSEDTEMPLE_MONSTER_MOVE,
    SOUND_CURSEDTEMPLE_MONSTER1_DAMAGE,
    SOUND_CURSEDTEMPLE_MONSTER1_DEATH,

    SOUND_CURSEDTEMPLE_MONSTER2_IDLE,
    SOUND_CURSEDTEMPLE_MONSTER2_ATTACK,
    SOUND_CURSEDTEMPLE_MONSTER2_DAMAGE,
    SOUND_CURSEDTEMPLE_MONSTER2_DEATH,

    SOUND_MOONRABBIT_WALK,
    SOUND_MOONRABBIT_DAMAGE,
    SOUND_MOONRABBIT_DEAD,
    SOUND_MOONRABBIT_EXPLOSION,

    SOUND_ELBELAND_RABBITSTRANGE_ATTACK01,
    SOUND_ELBELAND_RABBITSTRANGE_DEATH01,
    SOUND_ELBELAND_RABBITUGLY_BREATH01,
    SOUND_ELBELAND_RABBITUGLY_ATTACK01,
    SOUND_ELBELAND_RABBITUGLY_DEATH01,
    SOUND_ELBELAND_WOLFHUMAN_MOVE02,
    SOUND_ELBELAND_WOLFHUMAN_ATTACK01,
    SOUND_ELBELAND_WOLFHUMAN_DEATH01,
    SOUND_ELBELAND_BUTTERFLYPOLLUTION_MOVE01,
    SOUND_ELBELAND_BUTTERFLYPOLLUTION_DEATH01,
    SOUND_ELBELAND_CURSERICH_MOVE01,
    SOUND_ELBELAND_CURSERICH_ATTACK01,
    SOUND_ELBELAND_CURSERICH_DEATH01,
    SOUND_ELBELAND_TOTEMGOLEM_MOVE01,
    SOUND_ELBELAND_TOTEMGOLEM_MOVE02,
    SOUND_ELBELAND_TOTEMGOLEM_ATTACK01,
    SOUND_ELBELAND_TOTEMGOLEM_ATTACK02,
    SOUND_ELBELAND_TOTEMGOLEM_DEATH01,
    SOUND_ELBELAND_BEASTWOO_MOVE01,
    SOUND_ELBELAND_BEASTWOO_ATTACK01,
    SOUND_ELBELAND_BEASTWOO_DEATH01,
    SOUND_ELBELAND_BEASTWOOLEADER_MOVE01,
    SOUND_ELBELAND_BEASTWOOLEADER_ATTACK01,
    SOUND_ELBELAND_VILLAGEPROTECTION01,
    SOUND_ELBELAND_WATERFALLSMALL01,
    SOUND_ELBELAND_WATERWAY01,
    SOUND_ELBELAND_ENTERDEVIAS01,
    SOUND_ELBELAND_WATERSMALL01,
    SOUND_ELBELAND_RAVINE01,
    SOUND_ELBELAND_ENTERATLANCE01,

    SOUND_SWAMPOFQUIET_SAPI_UNUS_ATTACK01,
    SOUND_SWAMPOFQUIET_SAPI_DEATH01,
    SOUND_SWAMPOFQUIET_SAPI_TRES_ATTACK01,
    SOUND_SWAMPOFQUIET_SHADOW_PAWN_ATTACK01,
    SOUND_SWAMPOFQUIET_SHADOW_KNIGHT_ATTACK01,
    SOUND_SWAMPOFQUIET_SHADOW_ROOK_ATTACK01,
    SOUND_SWAMPOFQUIET_SHADOW_DEATH01,
    SOUND_SWAMPOFQUIET_THUNDER_NAIPIN_BREATH01,
    SOUND_SWAMPOFQUIET_GHOST_NAIPIN_BREATH01,
    SOUND_SWAMPOFQUIET_BLAZE_NAIPIN_BREATH01,
    SOUND_SWAMPOFQUIET_NAIPIN_ATTACK01,
    SOUND_SWAMPOFQUIET_NAIPIN_DEATH01,

    SOUND_SUMMON_CASTING,
    SOUND_SUMMON_SAHAMUTT,
    SOUND_SUMMON_EXPLOSION,
    SOUND_SUMMON_NEIL,
    SOUND_SUMMON_REQUIEM,
    SOUND_SUMMOM_RARGLE,
    SOUND_SUMMON_SKILL_LIGHTORB,
    SOUND_SUMMON_SKILL_SLEEP,
    SOUND_SUMMON_SKILL_BLIND,
    SOUND_SUMMON_SKILL_THORNS,
    SOUND_SKILL_CHAIN_LIGHTNING,
    SOUND_SKILL_DRAIN_LIFE,
    SOUND_SKILL_WEAKNESS,
    SOUND_SKILL_ENERVATION,
    SOUND_SKILL_BERSERKER,
    SOUND_CHERRYBLOSSOM_EFFECT0,
    SOUND_CHERRYBLOSSOM_EFFECT1,

    SOUND_RAKLION_ICEWALKER_ATTACK,
    SOUND_RAKLION_ICEWALKER_MOVE,

    SOUND_RAKLION_ICEGIANT_MOVE,
    SOUND_RAKLION_ICEGIANT_DEATH,

    SOUND_RAKLION_COOLERTIN_ATTACK,
    SOUND_RAKLION_COOLERTIN_MOVE,

    SOUND_RAKLION_IRON_KNIGHT_MOVE,
    SOUND_RAKLION_IRON_KNIGHT_ATTACK,

    SOUND_RAKLION_GIANT_MAMUD_MOVE,
    SOUND_RAKLION_GIANT_MAMUD_ATTACK,
    SOUND_RAKLION_GIANT_MAMUD_DEATH,

    SOUND_RAKLION_SERUFAN_ATTACK1,
    SOUND_RAKLION_SERUFAN_ATTACK2,
    SOUND_RAKLION_SERUFAN_CURE,
    SOUND_RAKLION_SERUFAN_RAGE,
    SOUND_RAKLION_SERUFAN_WORD1,
    SOUND_RAKLION_SERUFAN_WORD2,
    SOUND_RAKLION_SERUFAN_WORD3,
    SOUND_RAKLION_SERUFAN_WORD4,

    SOUND_SKILL_BLOWOFDESTRUCTION,
    SOUND_SKILL_FLAME_STRIKE,
    SOUND_SKILL_GIGANTIC_STORM,
    SOUND_SKILL_LIGHTNING_SHOCK,
    SOUND_SKILL_SWELL_OF_MAGICPOWER,
    SOUND_SKILL_MULTI_SHOT,
    SOUND_SKILL_RECOVER,
    SOUND_SKILL_CAOTIC,

    SOUND_XMAS_FIRECRACKER,
    SOUND_XMAS_SANTA_IDLE_1,
    SOUND_XMAS_SANTA_IDLE_2,
    SOUND_XMAS_SANTA_WALK_1,
    SOUND_XMAS_SANTA_WALK_2,
    SOUND_XMAS_SANTA_ATTACK_1,
    SOUND_XMAS_SANTA_DAMAGE_1,
    SOUND_XMAS_SANTA_DAMAGE_2,
    SOUND_XMAS_SANTA_DEATH_1,

    SOUND_XMAS_SNOWMAN_WALK_1,
    SOUND_XMAS_SNOWMAN_ATTACK_1,
    SOUND_XMAS_SNOWMAN_ATTACK_2,
    SOUND_XMAS_SNOWMAN_DAMAGE_1,
    SOUND_XMAS_SNOWMAN_DEATH_1,

    SOUND_DUEL_NPC_IDLE_1,

    SOUND_PKFIELD_ZOMBIEWARRIOR_ATTACK,
    SOUND_PKFIELD_ZOMBIEWARRIOR_DAMAGE01,
    SOUND_PKFIELD_ZOMBIEWARRIOR_DAMAGE02,
    SOUND_PKFIELD_ZOMBIEWARRIOR_MOVE01,
    SOUND_PKFIELD_ZOMBIEWARRIOR_MOVE02,
    SOUND_PKFIELD_ZOMBIEWARRIOR_DEATH,

    SOUND_PKFIELD_RAISEDGLADIATOR_ATTACK,
    SOUND_PKFIELD_RAISEDGLADIATOR_DAMAGE01,
    SOUND_PKFIELD_RAISEDGLADIATOR_DAMAGE02,
    SOUND_PKFIELD_RAISEDGLADIATOR_DEATH,
    SOUND_PKFIELD_RAISEDGLADIATOR_MOVE01,
    SOUND_PKFIELD_RAISEDGLADIATOR_MOVE02,

    SOUND_PKFIELD_ASHESBUTCHER_ATTACK,
    SOUND_PKFIELD_ASHESBUTCHER_DAMAGE01,
    SOUND_PKFIELD_ASHESBUTCHER_DAMAGE02,
    SOUND_PKFIELD_ASHESBUTCHER_DEATH,
    SOUND_PKFIELD_ASHESBUTCHER_MOVE01,
    SOUND_PKFIELD_ASHESBUTCHER_MOVE02,

    SOUND_PKFIELD_BLOODASSASSIN_ATTACK,
    SOUND_PKFIELD_BLOODASSASSIN_DAMAGE01,
    SOUND_PKFIELD_BLOODASSASSIN_DAMAGE02,
    SOUND_PKFIELD_BLOODASSASSIN_DEDTH,
    SOUND_PKFIELD_BLOODASSASSIN_MOVE01,
    SOUND_PKFIELD_BLOODASSASSIN_MOVE02,

    SOUND_PKFIELD_BURNINGLAVAGOLEM_ATTACK01,
    SOUND_PKFIELD_BURNINGLAVAGOLEM_ATTACK02,
    SOUND_PKFIELD_BURNINGLAVAGOLEM_DAMAGE01,
    SOUND_PKFIELD_BURNINGLAVAGOLEM_DAMAGE02,
    SOUND_PKFIELD_BURNINGLAVAGOLEM_DEATH,
    SOUND_PKFIELD_BURNINGLAVAGOLEM_MOVE01,
    SOUND_PKFIELD_BURNINGLAVAGOLEM_MOVE02,

    SOUND_UMBRELLA_MONSTER_WALK1,
    SOUND_UMBRELLA_MONSTER_WALK2,
    SOUND_UMBRELLA_MONSTER_DAMAGE,
    SOUND_UMBRELLA_MONSTER_DEAD,

    SOUND_DOPPELGANGER_SLIME_ATTACK,
    SOUND_DOPPELGANGER_SLIME_DEATH,
    SOUND_DOPPELGANGER_BUGBEAR_ATTACK,
    SOUND_DOPPELGANGER_BUGBEAR_DEATH,
    SOUND_DOPPELGANGER_RED_BUGBEAR_ATTACK,
    SOUND_DOPPELGANGER_RED_BUGBEAR_DEATH,
    SOUND_DOPPELGANGER_LUGARD_BREATH,
    SOUND_DOPPELGANGER_JEWELBOX_OPEN,

    SOUND_EMPIREGUARDIAN_WEATHER_RAIN,					// ImperialGuardianFort_out1.wav
    SOUND_EMPIREGUARDIAN_WEATHER_FOG,					// ImperialGuardianFort_out2.wav
    SOUND_EMPIREGUARDIAN_WEATHER_STORM,					// ImperialGuardianFort_out3.wav

    SOUND_EMPIREGUARDIAN_INDOOR_SOUND,					// ImperialGuardianFort_in.wav

    SOUND_EMPIREGUARDIAN_BOSS_GAION_MONSTER_MOVE,		// GaionKalein_move.wav
    SOUND_EMPIREGUARDIAN_BOSS_GAION_MONSTER_RAGE,		// GaionKalein_rage.wav
    SOUND_EMPIREGUARDIAN_BOSS_GAION_MONSTER_DEATH,		// GrandWizard_death.wav

    SOUND_EMPIREGUARDIAN_JERINT_MONSTER_ATTACK01,		// Jelint_attack1.wav
    SOUND_EMPIREGUARDIAN_JERINT_MONSTER_ATTACK03,		// Jelint_attack3.wav
    SOUND_EMPIREGUARDIAN_JERINT_MONSTER_MOVE01,			// Jelint_move01.wav
    SOUND_EMPIREGUARDIAN_JERINT_MONSTER_MOVE02,			// Jelint_move02.wav
    SOUND_EMPIREGUARDIAN_JERINT_MONSTER_RAGE,			// Jelint_rage.wav
    SOUND_EMPIREGUARDIAN_JERINT_MONSTER_DEATH,			// Jelint_death.wav

    SOUND_EMPIREGUARDIAN_RAYMOND_MONSTER_ATTACK02,		// Raymond_attack2.wav
    SOUND_EMPIREGUARDIAN_RAYMOND_MONSTER_RAGE,			// Raymond_rage.wav

    SOUND_EMPIREGUARDIAN_ERCANNE_MONSTER_ATTACK03,		// Ercanne_attack3.wav

    SOUND_EMPIREGUARDIAN_1CORP_DEASULER_MONSTER_ATTACK02,// 1Deasuler_attack2.wav
    SOUND_EMPIREGUARDIAN_1CORP_DEASULER_MONSTER_ATTACK03,// 1Deasuler_attack3.wav

    SOUND_EMPIREGUARDIAN_2CORP_VERMONT_MONSTER_ATTACK01,// 2Vermont_attack1.wav
    SOUND_EMPIREGUARDIAN_2CORP_VERMONT_MONSTER_ATTACK02,// 2Vermont_attack2.wav
    SOUND_EMPIREGUARDIAN_2CORP_VERMONT_MONSTER_DEATH,	// 2Vermont_death.wav

    SOUND_EMPIREGUARDIAN_3CORP_CATO_ATTACK02,			// 3Cato_attack2.wav
    SOUND_EMPIREGUARDIAN_3CORP_CATO_MOVE,				// 3Cato_move.wav

    SOUND_EMPIREGUARDIAN_4CORP_GALLIA_ATTACK02,			// 4Gallia_attack2.wav

    SOUND_EMPIREGUARDIAN_QUATERMASTER_ATTACK02,			// QuaterMaster_attack2.wav

    SOUND_EMPIREGUARDIAN_COMBATMASTER_ATTACK01,			// CombatMaster_attack1.wav
    SOUND_EMPIREGUARDIAN_COMBATMASTER_ATTACK02,			// CombatMaster_attack2.wav
    SOUND_EMPIREGUARDIAN_COMBATMASTER_ATTACK03,			// CombatMaster_attack3.wav

    SOUND_EMPIREGUARDIAN_GRANDWIZARD_DEATH,				// GrandWizard_death.wav

    SOUND_EMPIREGUARDIAN_ASSASSINMASTER_DEATH,			// AssassinMaster_Death.wav

    SOUND_EMPIREGUARDIAN_CAVALRYLEADER_ATTACK01,		// CavalryLeader_attack1.wav
    SOUND_EMPIREGUARDIAN_CAVALRYLEADER_ATTACK02,		// CavalryLeader_attack2.wav
    SOUND_EMPIREGUARDIAN_CAVALRYLEADER_MOVE01,			// CavalryLeader_move01.wav
    SOUND_EMPIREGUARDIAN_CAVALRYLEADER_MOVE02,			// CavalryLeader_move02.wav

    SOUND_EMPIREGUARDIAN_DEFENDER_ATTACK02,				// Defender_attack2.wav

    SOUND_EMPIREGUARDIAN_PRIEST_STOP,					// Priest_stay.wav

    SOUND_RAGESKILL_THRUST,								// 레이지 파이터스킬 사운드
    SOUND_RAGESKILL_THRUST_ATTACK,
    SOUND_RAGESKILL_STAMP,
    SOUND_RAGESKILL_STAMP_ATTACK,
    SOUND_RAGESKILL_GIANTSWING,
    SOUND_RAGESKILL_GIANTSWING_ATTACK,
    SOUND_RAGESKILL_DARKSIDE,
    SOUND_RAGESKILL_DARKSIDE_ATTACK,
    SOUND_RAGESKILL_DRAGONLOWER,
    SOUND_RAGESKILL_DRAGONLOWER_ATTACK,
    SOUND_RAGESKILL_DRAGONKICK,
    SOUND_RAGESKILL_DRAGONKICK_ATTACK,
    SOUND_RAGESKILL_BUFF_1,
    SOUND_RAGESKILL_BUFF_2,

#ifdef ASG_ADD_KARUTAN_MONSTERS
    SOUND_KARUTAN_TCSCORPION_ATTACK,					// ToxyChainScorpion_attack.wav
    SOUND_KARUTAN_TCSCORPION_DEATH,						// ToxyChainScorpion_death.wav
    SOUND_KARUTAN_TCSCORPION_HIT,						// ToxyChainScorpion_hit.wav

    SOUND_KARUTAN_BONESCORPION_ATTACK,					// BoneScorpion_attack.wav
    SOUND_KARUTAN_BONESCORPION_DEATH,					// BoneScorpion_death.wav
    SOUND_KARUTAN_BONESCORPION_HIT,						// BoneScorpion_hit.wav

    SOUND_KARUTAN_ORCUS_MOVE1,							// Orcus_move1.wav
    SOUND_KARUTAN_ORCUS_MOVE2,							// Orcus_move2.wav
    SOUND_KARUTAN_ORCUS_ATTACK1,						// Orcus_attack_1.wav
    SOUND_KARUTAN_ORCUS_ATTACK2,						// Orcus_attack_2.wav
    SOUND_KARUTAN_ORCUS_DEATH,							// Orcus_death.wav

    SOUND_KARUTAN_GOLOCH_MOVE1,							// Goloch_move1.wav
    SOUND_KARUTAN_GOLOCH_MOVE2,							// Goloch_move2.wav
    SOUND_KARUTAN_GOLOCH_ATTACK,						// Goloch_attack.wav
    SOUND_KARUTAN_GOLOCH_DEATH,							// Goloch_death.wav

    SOUND_KARUTAN_CRYPTA_MOVE1,							// Crypta_move1.wav
    SOUND_KARUTAN_CRYPTA_MOVE2,							// Crypta_move2.wav
    SOUND_KARUTAN_CRYPTA_ATTACK,						// Crypta_attack.wav
    SOUND_KARUTAN_CRYPTA_DEATH,							// Crypta_death.wav

    SOUND_KARUTAN_CRYPOS_MOVE1,							// Crypos_move1.wav
    SOUND_KARUTAN_CRYPOS_MOVE2,							// Crypos_move2.wav
    SOUND_KARUTAN_CRYPOS_ATTACK1,						// Crypos_attack_1.wav
    SOUND_KARUTAN_CRYPOS_ATTACK2,						// Crypos_attack_2.wav

    SOUND_KARUTAN_CONDRA_MOVE1,							// Condra_move1.wav
    SOUND_KARUTAN_CONDRA_MOVE2,							// Condra_move2.wav
    SOUND_KARUTAN_CONDRA_ATTACK,						// Condra_attack.wav
    SOUND_KARUTAN_CONDRA_DEATH,							// Condra_death.wav

    SOUND_KARUTAN_NARCONDRA_ATTACK,						// NarCondra_attack.wav
#endif	// ASG_ADD_KARUTAN_MONSTERS

#ifdef ASG_ADD_MAP_KARUTAN
    SOUND_KARUTAN_DESERT_ENV,							// Karutan_desert_env.wav
    SOUND_KARUTAN_INSECT_ENV,							// Karutan_insect_env.wav
    SOUND_KARUTAN_KARDAMAHAL_ENV,						// Kardamahal_entrance_env.wav
#endif	// ASG_ADD_MAP_KARUTAN

    MAX_BUFFER
};

HRESULT InitDirectSound(HWND hDlg);
void    SetEnableSound(bool b);
void    FreeDirectSound();

void    LoadWaveFile(int Buffer, TCHAR* strFileName, int BufferChannel = MAX_CHANNEL, bool Enable3DSound = false);
HRESULT PlayBuffer(int Buffer, OBJECT* Object = NULL, BOOL bLooped = false);
void    StopBuffer(int Buffer, BOOL bResetPosition);
void    AllStopSound(void);
void    Set3DSoundPosition();
HRESULT ReleaseBuffer(int Buffer);
HRESULT RestoreBuffers(int Buffer, int Channel);
void	SetVolume(int Buffer, long vol);
void	SetMasterVolume(long vol);

#endif //__DSPLAYSOUND_H__