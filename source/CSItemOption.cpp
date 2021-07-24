/*+++++++++++++++++++++++++++++++++++++
    INCLUDE.
+++++++++++++++++++++++++++++++++++++*/
#include "stdafx.h"
#include "ZzzOpenglUtil.h"
#include "zzzInfomation.h"
#include "zzzBmd.h"
#include "zzzObject.h"
#include "zzztexture.h"
#include "zzzCharacter.h"
#include "zzzscene.h"
#include "zzzInterface.h"
#include "zzzinventory.h"
#include "dsplaysound.h"
#include "CSItemOption.h"
#include "UIControls.h"
#include "NewUISystem.h"

/*+++++++++++++++++++++++++++++++++++++
    Extern.
+++++++++++++++++++++++++++++++++++++*/
extern	char TextList[30][100];
extern	int  TextListColor[30];
extern	int  TextBold[30];
extern float g_fScreenRate_x;	// ��
extern float g_fScreenRate_y;


/*+++++++++++++++++++++++++++++++++++++
    Global.
+++++++++++++++++++++++++++++++++++++*/
static  CSItemOption csItemOption;

//static	const	BYTE g_bySetOptionListValue[35] = {  2,  2, 15,  5,  5,  5, 10, 20, 10, 20, 10, 20, 10, 20, 40, 80, 40, 80,  
//													 5, 10,  5, 60, 50, 70, 20,  3, 50, 40, 10, 10, 10, 10, 10, 10, 10 };

/*+++++++++++++++++++++++++++++++++++++
    FUNCTIONS.
+++++++++++++++++++++++++++++++++++++*/
static BYTE bBuxCode[3] = {0xfc,0xcf,0xab};

static void BuxConvert(BYTE *Buffer,int Size)
{
	for(int i=0;i<Size;i++)
		Buffer[i] ^= bBuxCode[i%3];
}


bool CSItemOption::OpenItemSetScript ( bool bTestServer )
{
#ifdef LJH_ADD_SUPPORTING_MULTI_LANGUAGE
	string strFileName = "";
	string strTest = (bTestServer) ? "Test" : "";

	strFileName = "Data\\Local\\ItemSetType" + strTest + ".bmd";
	if ( !OpenItemSetType(strFileName.c_str()) )		return false;

	strFileName = "Data\\Local\\" + g_strSelectedML + "\\ItemSetOption" + strTest + "_" + g_strSelectedML + ".bmd";
	if ( !OpenItemSetOption(strFileName.c_str()) )	 	return false;

#else  //LJH_ADD_SUPPORTING_MULTI_LANGUAGE
	if ( bTestServer )
	{
		if ( !OpenItemSetType( "Data\\Local\\ItemSetTypeTest.bmd" ) )		return false;
		if ( !OpenItemSetOption( "Data\\Local\\ItemSetOptionTest.bmd" ) ) 	return false;
	}
	else
	{
		if ( !OpenItemSetType( "Data\\Local\\ItemSetType.bmd" ) )		return false;
		if ( !OpenItemSetOption( "Data\\Local\\ItemSetOption.bmd" ) ) 	return false;
	}
#endif //LJH_ADD_SUPPORTING_MULTI_LANGUAGE

	return true;
}

bool	CSItemOption::OpenItemSetType ( const char* filename )
{
	FILE* fp = fopen ( filename, "rb" );
	if(fp != NULL)
	{
		int Size = sizeof(ITEM_SET_TYPE);
		BYTE *Buffer = new BYTE [Size*MAX_ITEM];
		fread(Buffer,Size*MAX_ITEM,1,fp);

		DWORD dwCheckSum;
		fread(&dwCheckSum,sizeof ( DWORD),1,fp);
		fclose(fp);

		if ( dwCheckSum != GenerateCheckSum2( Buffer, Size*MAX_ITEM, 0xE5F1))
		{
			char Text[256];
    		sprintf(Text,"%s - File corrupted.",filename);
			g_ErrorReport.Write( Text);
			MessageBox(g_hWnd,Text,NULL,MB_OK);
			SendMessage(g_hWnd,WM_DESTROY,0,0);
		}
		else
		{
			BYTE *pSeek = Buffer;
			for(int i=0;i<MAX_ITEM;i++)
			{
				BuxConvert(pSeek,Size);
				memcpy(&m_ItemSetType[i],pSeek,Size);

				pSeek += Size;
			}
		}
		delete [] Buffer;
	}
	else
	{
		char Text[256];
    	sprintf(Text,"%s - File not exist.",filename);
		g_ErrorReport.Write( Text);
		MessageBox(g_hWnd,Text,NULL,MB_OK);
		SendMessage(g_hWnd,WM_DESTROY,0,0);
	}

	return true;
}

bool	CSItemOption::OpenItemSetOption ( const char* filename )
{
	FILE* fp = fopen ( filename, "rb" );
	if(fp != NULL)
	{
		int Size = sizeof(ITEM_SET_OPTION);
		BYTE *Buffer = new BYTE [Size*MAX_SET_OPTION];
		fread(Buffer,Size*MAX_SET_OPTION,1,fp);

		DWORD dwCheckSum;
		fread(&dwCheckSum,sizeof ( DWORD),1,fp);
		fclose(fp);

		if ( dwCheckSum != GenerateCheckSum2( Buffer, Size*MAX_SET_OPTION, 0xA2F1))
		{
			char Text[256];
    		sprintf(Text,"%s - File corrupted.",filename);
			g_ErrorReport.Write( Text);
			MessageBox(g_hWnd,Text,NULL,MB_OK);
			SendMessage(g_hWnd,WM_DESTROY,0,0);
		}
		else
		{
			BYTE *pSeek = Buffer;
			for(int i=0;i<MAX_SET_OPTION;i++)
			{
				BuxConvert(pSeek,Size);
				memcpy(&m_ItemSetOption[i],pSeek,Size);

				pSeek += Size;
			}
		}
		delete [] Buffer;
	}
	else
	{
		char Text[256];
    	sprintf(Text,"%s - File not exist.",filename);
		g_ErrorReport.Write( Text);
		MessageBox(g_hWnd,Text,NULL,MB_OK);
		SendMessage(g_hWnd,WM_DESTROY,0,0);
	}

	return true;
}

bool CSItemOption::IsDisableSkill ( int Type, int Energy, int Charisma )
{

	int SkillEnergy = 20+SkillAttribute[Type].Energy*(SkillAttribute[Type].Level)*4/100;

	if( Type == AT_SKILL_SUMMON_EXPLOSION || Type == AT_SKILL_SUMMON_REQUIEM ) {
		SkillEnergy = 20+SkillAttribute[Type].Energy*(SkillAttribute[Type].Level)*3/100;
	}

#ifdef PSW_BUGFIX_CLASS_KNIGHT_REQUIRESKILL
	if( GetBaseClass ( Hero->Class ) == CLASS_KNIGHT ) {
		SkillEnergy = 10+SkillAttribute[Type].Energy*(SkillAttribute[Type].Level)*4/100;
	}
#endif //PSW_BUGFIX_CLASS_KNIGHT_REQUIRESKILL
    
    switch ( Type )
    {
    case 17:SkillEnergy = 0;break;
	case 30:SkillEnergy = 30;break;
	case 31:SkillEnergy = 60;break;
	case 32:SkillEnergy = 90;break;
	case 33:SkillEnergy = 130;break;
	case 34:SkillEnergy = 170;break;
	case 35:SkillEnergy = 210;break;
	case 36:SkillEnergy = 300;break;
#ifdef ADD_ELF_SUMMON
	case 37:SkillEnergy = 500;break;
#endif // ADD_ELF_SUMMON
    case 60:SkillEnergy = 15; break;
	case AT_SKILL_ASHAKE_UP:
	case AT_SKILL_ASHAKE_UP+1:
	case AT_SKILL_ASHAKE_UP+2:
	case AT_SKILL_ASHAKE_UP+3:
	case AT_SKILL_ASHAKE_UP+4:
    case AT_SKILL_DARK_HORSE:    SkillEnergy = 0; break;  
    case AT_PET_COMMAND_DEFAULT: SkillEnergy = 0; break; 
    case AT_PET_COMMAND_RANDOM:  SkillEnergy = 0; break;
    case AT_PET_COMMAND_OWNER:   SkillEnergy = 0; break; 
    case AT_PET_COMMAND_TARGET:  SkillEnergy = 0; break; 
	case AT_SKILL_PLASMA_STORM_FENRIR: SkillEnergy = 0; break;
	case AT_SKILL_INFINITY_ARROW: SkillEnergy = 0; 
		break;	// ���Ǵ�Ƽ �ַο�
		
#ifdef CSK_ADD_SKILL_BLOWOFDESTRUCTION
	case AT_SKILL_BLOW_OF_DESTRUCTION: SkillEnergy = 0;
#endif // CSK_ADD_SKILL_BLOWOFDESTRUCTION

#ifdef PJH_SEASON4_SPRITE_NEW_SKILL_RECOVER
	case AT_SKILL_RECOVER:
#endif //PJH_SEASON4_SPRITE_NEW_SKILL_RECOVER
#ifdef PJH_SEASON4_DARK_NEW_SKILL_CAOTIC
	case AT_SKILL_GAOTIC:
#endif //PJH_SEASON4_DARK_NEW_SKILL_CAOTIC
#ifdef PJH_SEASON4_SPRITE_NEW_SKILL_MULTI_SHOT
	case AT_SKILL_MULTI_SHOT:
#endif //PJH_SEASON4_SPRITE_NEW_SKILL_MULTI_SHOT
#ifdef PJH_SEASON4_MASTER_RANK4
	case AT_SKILL_FIRE_SCREAM_UP:
	case AT_SKILL_FIRE_SCREAM_UP+1:
	case AT_SKILL_FIRE_SCREAM_UP+2:
	case AT_SKILL_FIRE_SCREAM_UP+3:
	case AT_SKILL_FIRE_SCREAM_UP+4:
#endif //PJH_SEASON4_MASTER_RANK4
	case AT_SKILL_DARK_SCREAM: 
		SkillEnergy = 0; 
		break;

	case AT_SKILL_EXPLODE:	
		SkillEnergy = 0; 
		break;
    }

	/*
    AT_SKILL_STUN               , 
    AT_SKILL_REMOVAL_STUN       , 
    AT_SKILL_MANA               ,  
    AT_SKILL_INVISIBLE          ,   
    AT_SKILL_REMOVAL_INVISIBLE  ,     
    AT_SKILL_REMOVAL_BUFF       ,   
	*/

	if(Type >= AT_SKILL_STUN && Type <= AT_SKILL_REMOVAL_BUFF)
	{
		SkillEnergy = 0;
	}
	else
    //  17, 18, 19, 20, 21, 22, 23, 41, 47, 49, 48, 43, 42, 24, 52, 51, 30, 31, 32, 33, 34, 35, 36, 55, 56
#ifdef KJH_FIX_SKILL_REQUIRE_ENERGY
	if ( ( Type>=18 && Type<=23 ) || ( Type>=41 && Type<=43 ) || ( Type>=47 && Type<=49 ) || Type==24 || Type==51 || Type==52 || Type==55 || Type==56 )
#else // KJH_FIX_SKILL_REQUIRE_ENERGY
	if ( ( Type>=18 && Type<23 ) || ( Type>=41 && Type<=43 ) || ( Type>=47 && Type<=49 ) || Type==24 || Type==51 || Type==52 || Type==55 || Type==56 )
#endif // KJH_FIX_SKILL_REQUIRE_ENERGY
    {
        SkillEnergy = 0;
    }
    else if ( Type==44 || Type==45 || Type==46 || Type==57 || Type==73 || Type==74 )
    {	
        SkillEnergy = 0;
    }
	
	if(Charisma > 0)
	{
		int SkillCharisma = SkillAttribute[Type].Charisma;
		if(Charisma < SkillCharisma)
		{
			return true;
		}
	}


    if( Energy < SkillEnergy )
	{
        return true;
	}

    return false;
}

BYTE CSItemOption::IsChangeSetItem ( const int Type, const int SubType=-1 )
{
	ITEM_SET_TYPE& itemSType = m_ItemSetType[Type];

    if ( SubType==-1 )
    {
        if ( itemSType.byOption[0]==255 && itemSType.byOption[1]==255 )
            return 0;
        return 255;
    }
    else
    {
        if ( itemSType.byOption[SubType]==255 )
            return 0;

        return SubType+1;
    }
}

WORD CSItemOption::GetMixItemLevel ( const int Type )
{
    if ( Type<0 ) return 0;

    WORD MixLevel = 0;
    ITEM_SET_TYPE& itemSType = m_ItemSetType[Type];

    MixLevel = MAKEWORD ( itemSType.byMixItemLevel[0], itemSType.byMixItemLevel[1] );

    return MixLevel;
}

bool	CSItemOption::GetSetItemName( char* strName, const int iType, const int setType )
{
    int setItemType = (setType%0x04);

	if ( setItemType>0 )
	{
		ITEM_SET_TYPE& itemSType = m_ItemSetType[iType];
		if ( itemSType.byOption[setItemType-1]!=255 && itemSType.byOption[setItemType-1]!=0 )
		{
			ITEM_SET_OPTION& itemOption = m_ItemSetOption[itemSType.byOption[setItemType-1]];

#ifdef KJH_MOD_NATION_LANGUAGE_REDEFINE
#ifdef _LANGUAGE_JPN
			memcpy ( strName, itemOption.strSetName, sizeof( char )*64 );
#else // _LANGUAGE_JPN
			memcpy ( strName, itemOption.strSetName, sizeof( char )*32 );
#endif // _LANGUAGE_JPN
#else // KJH_MOD_NATION_LANGUAGE_REDEFINE
#if SELECTED_LANGUAGE == LANGUAGE_JAPANESE
            memcpy ( strName, itemOption.strSetName, sizeof( char )*64 );
#else
			memcpy ( strName, itemOption.strSetName, sizeof( char )*32 );
#endif// SELECTED_LANGUAGE == LANGUAGE_JAPANESE
#endif // KJH_MOD_NATION_LANGUAGE_REDEFINE
            int length = strlen ( strName );
            strName[length] = ' ';
            strName[length+1]= 0;
			return true;
		}
	}
	return false;
}

void CSItemOption::checkItemType ( BYTE* optionList, const int iType, const int setType )
{
	int setItemType = (setType%0x04);

    if ( setItemType>0 )
	{
		ITEM_SET_TYPE& itemSType = m_ItemSetType[iType];

		if ( itemSType.byOption[setItemType-1]!=255 && itemSType.byOption[setItemType-1]!=0 )
		{
#ifdef YDG_FIX_OVER_5_SETITEM_TOOLTIP_BUG
			for (int i = 0; i < 30; i += 3)
#else	// YDG_FIX_OVER_5_SETITEM_TOOLTIP_BUG
#ifdef PBG_FIX_SETITEM_4OVER
			for ( int i=0; i<13; i+=3 )
#else //PBG_FIX_SETITEM_4OVER
			for ( int i=0; i<10; i+=3 )
#endif //PBG_FIX_SETITEM_4OVER
#endif	// YDG_FIX_OVER_5_SETITEM_TOOLTIP_BUG
			{
				if ( optionList[i]==0 )
				{
					optionList[i] = itemSType.byOption[setItemType-1];
					optionList[i+1]++;
                    optionList[i+2] = setItemType-1;
					break;
				}
				else if ( optionList[i]==itemSType.byOption[setItemType-1] )
				{
					optionList[i+1]++;
                    optionList[i+2] = setItemType-1;
					break;
				}
			}
		}
	}
}

void	CSItemOption::calcSetOptionList ( BYTE* optionList )
{
    int Class = GetBaseClass ( Hero->Class );
	int ExClass = IsSecondClass(Hero->Class);

	BYTE    bySetOptionListTmp[2][16];
    BYTE    bySetOptionListTmp2[2][16];
    int     iSetOptionListValue[2][16];

#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
	unsigned int    
			arruiSetItemTypeSequence[2][16];
	memset( arruiSetItemTypeSequence, 0, sizeof( unsigned int ) * 32 );
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

    BYTE    optionCount[2] = { 0, 0 };  //  
    BYTE    setType = 0;

    m_bySameSetItem = 0;
#ifdef KJH_MOD_NATION_LANGUAGE_REDEFINE
#ifdef _LANGUAGE_JPN
    ZeroMemory ( m_strSetName, sizeof(char)*2*64 );
#else // _LANGUAGE_JPN
    ZeroMemory ( m_strSetName, sizeof(char)*2*32 );
#endif // _LANGUAGE_JPN
#else // KJH_MOD_NATION_LANGUAGE_REDEFINE
#if SELECTED_LANGUAGE == LANGUAGE_JAPANESE
    ZeroMemory ( m_strSetName, sizeof(char)*2*64 );
#else
    ZeroMemory ( m_strSetName, sizeof(char)*2*32 );
#endif// SELECTED_LANGUAGE == LANGUAGE_JAPANESE
#endif // KJH_MOD_NATION_LANGUAGE_REDEFINE

    m_bySetOptionIndex[0] = 0;
    m_bySetOptionIndex[1] = 0;
	m_bySetOptionANum = 0;
	m_bySetOptionBNum = 0;
    Hero->ExtendState = 0;

#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
	unsigned int iSetItemTypeSequence = 0, iCurrentSetItemTypeSequence = 0;

	m_mapEquippedSetItemName.clear();
	m_mapEquippedSetItemSequence.clear();
#endif //LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

#ifdef YDG_FIX_OVER_5_SETITEM_TOOLTIP_BUG
	for (int i = 0; i < 30; i += 3)
#else	// YDG_FIX_OVER_5_SETITEM_TOOLTIP_BUG
#ifdef PBG_FIX_SETITEM_4OVER
	for ( int i=0; i<13; i+=3 )
#else //PBG_FIX_SETITEM_4OVER
	for ( int i=0; i<10; i+=3 )
#endif //PBG_FIX_SETITEM_4OVER
#endif	// YDG_FIX_OVER_5_SETITEM_TOOLTIP_BUG
	{
		if ( optionList[i+1]>=2 )
		{
			int count = optionList[i+1]-1;
			int standardCount = min ( count, 6 );
			ITEM_SET_OPTION& itemOption = m_ItemSetOption[optionList[i]];		

            BYTE RequireClass = 0;
            if ( itemOption.byRequireClass[0]==1 && Class==CLASS_WIZARD ) RequireClass = 1;
            if ( itemOption.byRequireClass[0]==2 && Class==CLASS_WIZARD && ExClass ) RequireClass = 1;
            if ( itemOption.byRequireClass[1]==1 && Class==CLASS_KNIGHT ) RequireClass = 1;
            if ( itemOption.byRequireClass[1]==2 && Class==CLASS_KNIGHT && ExClass ) RequireClass = 1;
            if ( itemOption.byRequireClass[2]==1 && Class==CLASS_ELF    ) RequireClass = 1;
            if ( itemOption.byRequireClass[2]==2 && Class==CLASS_ELF    && ExClass ) RequireClass = 1;
            if ( itemOption.byRequireClass[3]==1 && Class==CLASS_DARK   ) RequireClass = 1;
#ifdef PJH_ADD_SET_NEWJOB
            if ( itemOption.byRequireClass[3]==1 && Class==CLASS_DARK && ExClass) RequireClass = 1;
            if ( itemOption.byRequireClass[4]==1 && Class==CLASS_DARK_LORD ) RequireClass = 1;
			if ( itemOption.byRequireClass[4]==1 && Class==CLASS_DARK_LORD && ExClass) RequireClass = 1;
            if ( itemOption.byRequireClass[5]==1 && Class==CLASS_SUMMONER ) RequireClass = 1;
			if ( itemOption.byRequireClass[5]==1 && Class==CLASS_SUMMONER && ExClass) RequireClass = 1;
#endif //PJH_ADD_SET_NEWJOB
#ifdef PBG_ADD_NEWCHAR_MONK
			if ( itemOption.byRequireClass[6]==1 && Class==CLASS_RAGEFIGHTER ) RequireClass = 1;
			if ( itemOption.byRequireClass[6]==1 && Class==CLASS_RAGEFIGHTER && ExClass) RequireClass = 1;
#endif //PBG_ADD_NEWCHAR_MONK
            setType = optionList[i+2];
            m_bySetOptionIndex[setType] = optionList[i];
            if ( m_strSetName[setType][0]!=0 && strcmp( m_strSetName[setType], itemOption.strSetName )!=NULL )
            {
                if ( m_strSetName[0][0]==0 )
                    strcpy ( m_strSetName[0], itemOption.strSetName );
                else
                    strcpy ( m_strSetName[1], itemOption.strSetName );
                m_bySameSetItem = count;
            }
            else
            {
                strcpy ( m_strSetName[setType], itemOption.strSetName );
            }


#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
			
			bool	bFind	=	false;
			for( m_iterESIN = m_mapEquippedSetItemName.begin(); m_iterESIN != m_mapEquippedSetItemName.end(); ++m_iterESIN )
			{
				std::string strCur = m_iterESIN->second;
				
				if( strcmp( itemOption.strSetName, strCur.c_str() ) == 0 )
				{
					bFind = true;
					break;
				}
			}

			if( false == bFind )
			{
				iCurrentSetItemTypeSequence = iSetItemTypeSequence++;
				m_mapEquippedSetItemName.insert( pair<int, string>(iCurrentSetItemTypeSequence, itemOption.strSetName) );
			}
			
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE


			BYTE option[2];
            int  value[2];
			for ( int j=0; j<count; ++j )
			{
				option[0] = 255; option[1] = 255;
				if ( j<standardCount )
				{
					option[0] = itemOption.byStandardOption[j][0];
                    value[0]  = itemOption.byStandardOptionValue[j][0];
					option[1] = itemOption.byStandardOption[j][1];
                    value[1]  = itemOption.byStandardOptionValue[j][1];
				}
				else if ( j<(count-standardCount) )
				{
					option[0] = itemOption.byExtOption[j];
                    value[0]  = itemOption.byExtOptionValue[j];
				}

				if ( option[0]!=255 )
				{
                    if ( option[0]<MASTERY_OPTION )
                    {
						
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
						arruiSetItemTypeSequence[setType][optionCount[setType]] = 
																			iCurrentSetItemTypeSequence;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

                        bySetOptionListTmp[setType][optionCount[setType]] = option[0];
                        bySetOptionListTmp2[setType][optionCount[setType]]= RequireClass;
                        iSetOptionListValue[setType][optionCount[setType]]= value[0];
                        optionCount[setType]++;
						
                    }
                    else
                    {
			            if ( itemOption.byRequireClass[Class] && ExClass>=itemOption.byRequireClass[Class]-1 )
                        {
							
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
							arruiSetItemTypeSequence[setType][optionCount[setType]] = 
																			iCurrentSetItemTypeSequence;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
							
                            bySetOptionListTmp[setType][optionCount[setType]] = option[0];
                            bySetOptionListTmp2[setType][optionCount[setType]]= RequireClass;
                            iSetOptionListValue[setType][optionCount[setType]]= value[0];
                            optionCount[setType]++;
                        }
                    }
				}
				if ( option[1]!=255 )
				{
                    if ( option[1]<MASTERY_OPTION )
                    {
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
						arruiSetItemTypeSequence[setType][optionCount[setType]] = 
																	iCurrentSetItemTypeSequence;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

                        bySetOptionListTmp[setType][optionCount[setType]] = option[1];
                        bySetOptionListTmp2[setType][optionCount[setType]]= RequireClass;
                        iSetOptionListValue[setType][optionCount[setType]]= value[1];
                        optionCount[setType]++;
                    }
                    else
                    {
			            if ( itemOption.byRequireClass[Class] && ExClass>=itemOption.byRequireClass[Class]-1 )
                        {
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
							arruiSetItemTypeSequence[setType][optionCount[setType]] = 
																	iCurrentSetItemTypeSequence;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

                            bySetOptionListTmp[setType][optionCount[setType]] = option[1];
                            bySetOptionListTmp2[setType][optionCount[setType]]= RequireClass;
                            iSetOptionListValue[setType][optionCount[setType]]= value[1];
                            optionCount[setType]++;
                        }
                    }
				}
			}

			if ( count>=itemOption.byOptionCount-2 )
			{
				for (int j=0; j<5; ++j )
				{
					option[0] = itemOption.byFullOption[j];
                    value[0]  = itemOption.byFullOptionValue[j];
                    if ( option[0]!=255 )
                    {
                        if ( option[0]<MASTERY_OPTION )
                        {
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
							arruiSetItemTypeSequence[setType][optionCount[setType]] = 
															iCurrentSetItemTypeSequence;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
                            bySetOptionListTmp[setType][optionCount[setType]] = option[0];
                            bySetOptionListTmp2[setType][optionCount[setType]]= RequireClass;
                            iSetOptionListValue[setType][optionCount[setType]]= value[0];
                            optionCount[setType]++;

                            if ( m_bySameSetItem!=0 ) m_bySameSetItem++;
                        }
                        else
                        {
                            if ( itemOption.byRequireClass[Class] && ExClass>=itemOption.byRequireClass[Class]-1 )
                            {
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
								arruiSetItemTypeSequence[setType][optionCount[setType]] = 
															iCurrentSetItemTypeSequence;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
								
                                bySetOptionListTmp[setType][optionCount[setType]] = option[0];
                                bySetOptionListTmp2[setType][optionCount[setType]]= RequireClass;
                                iSetOptionListValue[setType][optionCount[setType]]= value[0];
                                optionCount[setType]++;

                                if ( m_bySameSetItem!=0 ) m_bySameSetItem++;
                            }
                        }
                    }
				}

                Hero->ExtendState = 1;
			}
		}
	}

	for (int i=0; i<2; ++i )
    {
        for ( int j=0; j<optionCount[i]; ++j )
        {
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
			m_mapEquippedSetItemSequence.insert( pair<BYTE, int>((i*optionCount[0])+j, arruiSetItemTypeSequence[i][j]) );
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
            m_bySetOptionList[(i*optionCount[0])+j][0] = bySetOptionListTmp[i][j];
            m_bySetOptionList[(i*optionCount[0])+j][1] = bySetOptionListTmp2[i][j];	
            m_iSetOptionListValue[(i*optionCount[0])+j][0] = iSetOptionListValue[i][j];
            m_iSetOptionListValue[(i*optionCount[0])+j][1] = iSetOptionListValue[i][j];
        }
    }
    m_bySetOptionANum = optionCount[0];
    m_bySetOptionBNum = optionCount[1];
}


void CSItemOption::getExplainText ( char* text, const BYTE option, const BYTE value, const BYTE SetIndex )
{
	switch ( option+AT_SET_OPTION_IMPROVE_STRENGTH )
	{
    case AT_SET_OPTION_IMPROVE_MAGIC_POWER:
    	sprintf( text, GlobalText[632], value );
        break;

	case AT_SET_OPTION_IMPROVE_STRENGTH: 
	case AT_SET_OPTION_IMPROVE_DEXTERITY:
	case AT_SET_OPTION_IMPROVE_ENERGY:	                 
	case AT_SET_OPTION_IMPROVE_VITALITY:
    case AT_SET_OPTION_IMPROVE_CHARISMA:
    case AT_SET_OPTION_IMPROVE_ATTACK_MIN:
    case AT_SET_OPTION_IMPROVE_ATTACK_MAX:
		sprintf( text, GlobalText[950+option], value );
        break;

    case AT_SET_OPTION_IMPROVE_DAMAGE:
	case AT_SET_OPTION_IMPROVE_ATTACKING_PERCENT: 
	case AT_SET_OPTION_IMPROVE_DEFENCE:	 
	case AT_SET_OPTION_IMPROVE_MAX_LIFE:
	case AT_SET_OPTION_IMPROVE_MAX_MANA:
	case AT_SET_OPTION_IMPROVE_MAX_AG:		             
    case AT_SET_OPTION_IMPROVE_ADD_AG:
    case AT_SET_OPTION_IMPROVE_CRITICAL_DAMAGE_PERCENT:
    case AT_SET_OPTION_IMPROVE_CRITICAL_DAMAGE:
    case AT_SET_OPTION_IMPROVE_EXCELLENT_DAMAGE_PERCENT:
    case AT_SET_OPTION_IMPROVE_EXCELLENT_DAMAGE:
    case AT_SET_OPTION_IMPROVE_SKILL_ATTACK:
    case AT_SET_OPTION_DOUBLE_DAMAGE:
		sprintf( text, GlobalText[949+option], value );
		break;					    					

    case AT_SET_OPTION_DISABLE_DEFENCE:
		sprintf( text, GlobalText[970], value );
		break;					    					

	case AT_SET_OPTION_TWO_HAND_SWORD_IMPROVE_DAMAGE: 
		sprintf( text, GlobalText[983], value );        
        break;

	case AT_SET_OPTION_IMPROVE_SHIELD_DEFENCE:	 
		sprintf( text, GlobalText[984], value );        
        break;


	case AT_SET_OPTION_IMPROVE_ATTACK_1:
	case AT_SET_OPTION_IMPROVE_ATTACK_2:
	case AT_SET_OPTION_IMPROVE_MAGIC: 
//	case AT_SET_OPTION_IMPROVE_DEFENCE_1:
//	case AT_SET_OPTION_IMPROVE_DEFENCE_2:
	case AT_SET_OPTION_IMPROVE_DEFENCE_3:
	case AT_SET_OPTION_IMPROVE_DEFENCE_4:
	case AT_SET_OPTION_FIRE_MASTERY:	 
	case AT_SET_OPTION_ICE_MASTERY:	 
	case AT_SET_OPTION_THUNDER_MASTERY: 
	case AT_SET_OPTION_POSION_MASTERY:		 
	case AT_SET_OPTION_WATER_MASTERY:	 
	case AT_SET_OPTION_WIND_MASTERY:	 
	case AT_SET_OPTION_EARTH_MASTERY:	 
        sprintf ( text, GlobalText[971+(option+AT_SET_OPTION_IMPROVE_STRENGTH-AT_SET_OPTION_IMPROVE_ATTACK_2)], value );
		break;						
	}
}

void CSItemOption::PlusSpecial ( WORD* Value, int Special )
{
	Special -= AT_SET_OPTION_IMPROVE_STRENGTH;
	int optionValue = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]==Special && m_bySetOptionListOnOff[i]==0 )
		{
			optionValue += m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
		}
	}

	if ( optionValue )
	{
		*Value += optionValue;
	}
}

void CSItemOption::PlusSpecialPercent ( WORD* Value, int Special )
{
	Special -= AT_SET_OPTION_IMPROVE_STRENGTH;
	int optionValue = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]==Special && m_bySetOptionListOnOff[i]==0 )
		{
			optionValue += m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
		}
	}

	if ( optionValue )
	{
		*Value += ((*Value)*optionValue)/100;
	}
}


void CSItemOption::PlusSpecialLevel ( WORD* Value, const WORD SrcValue, int Special )
{
	Special -= AT_SET_OPTION_IMPROVE_STRENGTH;
	int optionValue = 0;
	int count = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]==Special && m_bySetOptionList[i][1]!=0 && m_bySetOptionListOnOff[i]==0 )
		{
			optionValue = m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
			count++;
		}
	}

	if ( optionValue )
	{
		optionValue = SrcValue*optionValue/100;
		*Value += (optionValue*count);
	}
}

void CSItemOption::PlusMastery ( int* Value, const BYTE MasteryType )
{
    int optionValue = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]>=MASTERY_OPTION && (m_bySetOptionList[i][0]-MASTERY_OPTION-5)==MasteryType && m_bySetOptionList[i][1]!=0 && m_bySetOptionListOnOff[i]==0 )
		{
            optionValue += m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
		}
	}

	if ( optionValue )
	{
		*Value += optionValue;
	}
}

void CSItemOption::MinusSpecialPercent ( int* Value, int Special )
{
	Special -= AT_SET_OPTION_IMPROVE_STRENGTH;
	int optionValue = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]==Special && m_bySetOptionList[i][1]!=0 && m_bySetOptionListOnOff[i]==0 )
		{
			optionValue += m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
		}
	}

	if ( optionValue )
	{
		*Value -= *Value*optionValue/100;
	}
}

void CSItemOption::GetSpecial ( WORD* Value, int Special )
{
	Special -= AT_SET_OPTION_IMPROVE_STRENGTH;
	int optionValue = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]==Special && m_bySetOptionListOnOff[i]==0 )
		{
			optionValue += m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
		}
	}

	if ( optionValue )
	{
		*Value += optionValue;
	}
}

void	CSItemOption::GetSpecialPercent ( WORD* Value, int Special )
{
	Special -= AT_SET_OPTION_IMPROVE_STRENGTH;
	int optionValue = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]==Special && m_bySetOptionListOnOff[i]==0 )
		{
			optionValue += m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
		}
	}

	if ( optionValue )
	{
		*Value += *Value*optionValue/100;
	}
}

void	CSItemOption::GetSpecialLevel ( WORD* Value, const WORD SrcValue, int Special )
{
	Special -= AT_SET_OPTION_IMPROVE_STRENGTH;
	int optionValue = 0;
	int count = 0;
	for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
	{
		if ( m_bySetOptionList[i][0]==Special && m_bySetOptionList[i][1]!=0 && m_bySetOptionListOnOff[i]==0 )
		{
			optionValue = m_iSetOptionListValue[i][0];
            m_bySetOptionListOnOff[i] = 1;
			count++;
		}
	}

	if ( optionValue )
	{
		optionValue = SrcValue*optionValue/100;
		*Value += (optionValue*count);
	}
}

int CSItemOption::GetDefaultOptionValue ( ITEM* ip, WORD* Value )
{
    *Value = ((ip->ExtOption>>2)%0x04);

    ITEM_ATTRIBUTE* p = &ItemAttribute[ip->Type];

    return p->AttType;
}

bool CSItemOption::GetDefaultOptionText ( const ITEM* ip, char* Text )
{
    if ( ((ip->ExtOption>>2)%0x04)<=0 ) return false;

    switch ( ItemAttribute[ip->Type].AttType )
    {
    case SET_OPTION_STRENGTH:
        sprintf ( Text, GlobalText[950], ((ip->ExtOption>>2)%0x04)*5 );
        break;

    case SET_OPTION_DEXTERITY:
        sprintf ( Text, GlobalText[951], ((ip->ExtOption>>2)%0x04)*5 );
        break;

    case SET_OPTION_ENERGY:
        sprintf ( Text, GlobalText[952], ((ip->ExtOption>>2)%0x04)*5 );
        break;

    case SET_OPTION_VITALITY:
        sprintf ( Text, GlobalText[953], ((ip->ExtOption>>2)%0x04)*5 );
        break;

    default:
        return false;
    }
    return true;
}


#ifdef PJH_FIX_4_BUGFIX_33
bool CSItemOption::Special_Option_Check(int Kind)
{
	int i,j;
	for(i = 0; i < 2; i++)
	{
		ITEM* item = NULL;
		item = &CharacterMachine->Equipment[EQUIPMENT_WEAPON_RIGHT + i];
		if(item == NULL || item->Type <= -1)
			continue;

		if(Kind == 0)
		{
			for(j=0;j<item->SpecialNum;j++)
			{
				if(item->Special[j] == AT_SKILL_ICE_BLADE)
					return true;
			}
		}
		else
		if(Kind == 1)
		{
			for(j=0;j<item->SpecialNum;j++)
			{
				if(item->Special[j] == AT_SKILL_CROSSBOW)
					return true;
			}
		}
	}
	return false;
}
#endif //PJH_FIX_4_BUGFIX_33

int CSItemOption::RenderDefaultOptionText ( const ITEM* ip, int TextNum )
{
    int TNum = TextNum;
    if ( GetDefaultOptionText( ip, TextList[TNum] ) )
    {
        TextListColor[TNum] = TEXT_COLOR_BLUE;
        TNum++;

        if ( ( ip->Type>=ITEM_HELPER+8 && ip->Type<=ITEM_HELPER+9 ) || ( ip->Type>=ITEM_HELPER+12 && ip->Type<=ITEM_HELPER+13 ) || ( ip->Type>=ITEM_HELPER+21 && ip->Type<=ITEM_HELPER+27 ) )
        {
            sprintf ( TextList[TNum], GlobalText[1165] );
            TextListColor[TNum] = TEXT_COLOR_BLUE;
            TNum++;
        }
    }

    return TNum;
}

#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION 
void CSItemOption::getAllAddState ( WORD* Strength, WORD* Dexterity, WORD* Energy, WORD* Vitality, WORD* Charisma )
#else // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
void CSItemOption::getAllAddState ( WORD* Strength, WORD* Dexterity, WORD* Energy, WORD* Vitality )
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
{
    for ( int i=EQUIPMENT_WEAPON_RIGHT; i<MAX_EQUIPMENT; ++i )
    {
		ITEM* item = &CharacterMachine->Equipment[i];
		
        if ( item->Durability<=0 
#ifdef PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM
			|| ( IsRequireEquipItem( item ) == false )
#endif //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM
			)
        {
            continue;
        }
		
        WORD Result = 0;
        switch ( GetDefaultOptionValue( item, &Result ) )
        {
        case SET_OPTION_STRENGTH:
            *Strength += Result*5;
            break;
			
        case SET_OPTION_DEXTERITY:
            *Dexterity += Result*5;
            break;
			
        case SET_OPTION_ENERGY:
            *Energy += Result*5;
            break;
			
        case SET_OPTION_VITALITY:
            *Vitality += Result*5;
            break;
        }
    }

	GetSpecial ( Strength,  AT_SET_OPTION_IMPROVE_STRENGTH );
	GetSpecial ( Dexterity, AT_SET_OPTION_IMPROVE_DEXTERITY );
	GetSpecial ( Energy,    AT_SET_OPTION_IMPROVE_ENERGY );
	GetSpecial ( Vitality,  AT_SET_OPTION_IMPROVE_VITALITY );
#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION 
	GetSpecial ( Charisma,  AT_SET_OPTION_IMPROVE_CHARISMA );
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
}

#ifdef LDS_FIX_WRONG_CALCULATEEQUIPEDITEMOPTIONVALUE

#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	void CSItemOption::getAllAddStateOnlyAddValue ( WORD* AddStrength, WORD* AddDexterity, WORD* AddEnergy, WORD* AddVitality, WORD* AddCharisma )
	{
		*AddStrength = *AddDexterity = *AddEnergy = *AddVitality = *AddCharisma = 0;
		memset ( m_bySetOptionListOnOff, 0, sizeof( BYTE )* 16 );
		
		getAllAddState( AddStrength, AddDexterity, AddEnergy, AddVitality, AddCharisma );
	}	
#else // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	void CSItemOption::getAllAddStateOnlyAddValue ( WORD* AddStrength, WORD* AddDexterity, WORD* AddEnergy, WORD* AddVitality )
	{
		*AddStrength = *AddDexterity = *AddEnergy = *AddVitality = 0;
		memset ( m_bySetOptionListOnOff, 0, sizeof( BYTE )* 16 );
		
		getAllAddState( AddStrength, AddDexterity, AddEnergy, AddVitality );
	}
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION

#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION
void CSItemOption::getAllAddOptionStatesbyCompare ( WORD* Strength, WORD* Dexterity, WORD* Energy, WORD* Vitality, WORD* Charisma,
													  WORD iCompareStrength, WORD iCompareDexterity, WORD iCompareEnergy, WORD iCompareVitality, WORD iCompareCharisma )
#else // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
void CSItemOption::getAllAddOptionStatesbyCompare ( WORD* Strength, WORD* Dexterity, WORD* Energy, WORD* Vitality,
													  WORD iCompareStrength, WORD iCompareDexterity, WORD iCompareEnergy, WORD iCompareVitality )
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
{	
    for ( int i=EQUIPMENT_WEAPON_RIGHT; i<MAX_EQUIPMENT; ++i )
    {
		ITEM* item = &CharacterMachine->Equipment[i];
		
		if( item->RequireStrength > iCompareStrength || 
			item->RequireDexterity > iCompareDexterity || 
			item->RequireEnergy > iCompareEnergy )
		{
			continue;
		}
		
        if ( item->Durability<=0 
#ifdef PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM
			|| ( IsRequireEquipItem( item ) == false )
#endif //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM
			)
        {
            continue;
        }
		
        WORD Result = 0;
        switch ( GetDefaultOptionValue( item, &Result ) )
        {
        case SET_OPTION_STRENGTH:
            *Strength += Result*5;
            break;
			
        case SET_OPTION_DEXTERITY:
            *Dexterity += Result*5;
            break;
			
        case SET_OPTION_ENERGY:
            *Energy += Result*5;
            break;
			
        case SET_OPTION_VITALITY:
            *Vitality += Result*5;
            break;
        }
    }

	memset ( m_bySetOptionListOnOff, 0, sizeof( BYTE )* 16 );
	
	GetSpecial ( Strength,  AT_SET_OPTION_IMPROVE_STRENGTH );
	GetSpecial ( Dexterity, AT_SET_OPTION_IMPROVE_DEXTERITY );
	GetSpecial ( Energy,    AT_SET_OPTION_IMPROVE_ENERGY );
	GetSpecial ( Vitality,  AT_SET_OPTION_IMPROVE_VITALITY );
	
#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	GetSpecial ( Charisma,  AT_SET_OPTION_IMPROVE_CHARISMA );
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
}
#endif // LDS_FIX_WRONG_CALCULATEEQUIPEDITEMOPTIONVALUE


void CSItemOption::CheckItemSetOptions ( void )
{
	BYTE byOptionList[30] = { 0, };
    ITEM itemTmp;

    memset ( m_bySetOptionList, 0, sizeof( BYTE ) * 16 );

#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	for ( int i=0; i<MAX_EQUIPMENT_INDEX; ++i )
#else // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	for ( int i=0; i<12; ++i )
#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	{	
		if ( i==EQUIPMENT_WING || i==EQUIPMENT_HELPER ) continue;

		ITEM *ip = &CharacterMachine->Equipment[i];

#ifdef LJH_FIX_ITEM_CANNOT_BE_EQUIPPED_AFTER_LOGOUT
		if( ip->Durability <= 0 ) {
			continue;
		}
#else	//LJH_FIX_ITEM_CANNOT_BE_EQUIPPED_AFTER_LOGOUT
#if defined PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM || defined YDG_FIX_SETITEM_REQUIRED_STATUS_BUG
		if( ip->Durability <= 0 || IsRequireEquipItem( ip ) == false ) {
			continue;
		}
#endif //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM
#endif	//LJH_FIX_ITEM_CANNOT_BE_EQUIPPED_AFTER_LOGOUT

        if ( ( i==EQUIPMENT_WEAPON_LEFT || i==EQUIPMENT_RING_LEFT ) && itemTmp.Type==ip->Type && itemTmp.ExtOption==(ip->ExtOption%0x04) )
        {
            continue;
        }

		if ( ip->Type>-1 )
		{
			checkItemType( byOptionList, ip->Type, ip->ExtOption );
		}

        if ( i==EQUIPMENT_WEAPON_RIGHT || i==EQUIPMENT_RING_RIGHT )
        {
            itemTmp.Type = ip->Type;
            itemTmp.ExtOption = (ip->ExtOption%0x04);
        }
	}

	calcSetOptionList( byOptionList );

#ifdef LJH_FIX_ITEM_CANNOT_BE_EQUIPPED_AFTER_LOGOUT

#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	getAllAddStateOnlyAddValue ( &CharacterAttribute->AddStrength,	&CharacterAttribute->AddDexterity, 
								 &CharacterAttribute->AddEnergy,	&CharacterAttribute->AddVitality, 
								 &CharacterAttribute->AddCharisma 
							   );
#else // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
    getAllAddStateOnlyAddValue ( &CharacterAttribute->AddStrength,	&CharacterAttribute->AddDexterity, 
								 &CharacterAttribute->AddEnergy,	&CharacterAttribute->AddVitality 
							   );
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION

#if defined PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM || defined LDK_FIX_USE_SECRET_ITEM_TO_SETITEM_OPTION_BUG

    WORD AllStrength  = CharacterAttribute->Strength + CharacterAttribute->AddStrength;
    WORD AllDexterity = CharacterAttribute->Dexterity + CharacterAttribute->AddDexterity;
    WORD AllEnergy    = CharacterAttribute->Energy + CharacterAttribute->AddEnergy;
    WORD AllVitality  = CharacterAttribute->Vitality + CharacterAttribute->AddVitality;
	WORD AllCharisma  = CharacterAttribute->Charisma + CharacterAttribute->AddCharisma;
	WORD AllLevel     = CharacterAttribute->Level;
#else //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM

    WORD AllStrength = CharacterAttribute->Strength;
    WORD AllDexterity = CharacterAttribute->Dexterity;
    WORD AllEnergy = CharacterAttribute->Energy;
    WORD AllVitality = CharacterAttribute->Vitality;
#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	WORD AllCharisma  =CharacterAttribute->Charisma;
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	
#endif //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM

#else //LJH_FIX_ITEM_CANNOT_BE_EQUIPPED_AFTER_LOGOUT
#if defined PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM || defined LDK_FIX_USE_SECRET_ITEM_TO_SETITEM_OPTION_BUG

    WORD AllStrength  = CharacterAttribute->Strength + CharacterAttribute->AddStrength;
    WORD AllDexterity = CharacterAttribute->Dexterity + CharacterAttribute->AddDexterity;
    WORD AllEnergy    = CharacterAttribute->Energy + CharacterAttribute->AddEnergy;
    WORD AllVitality  = CharacterAttribute->Vitality + CharacterAttribute->AddVitality;
	WORD AllCharisma  = CharacterAttribute->Charisma + CharacterAttribute->AddCharisma;
	WORD AllLevel     = CharacterAttribute->Level;
#else //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM

    WORD AllStrength = CharacterAttribute->Strength;
    WORD AllDexterity = CharacterAttribute->Dexterity;
    WORD AllEnergy = CharacterAttribute->Energy;
    WORD AllVitality = CharacterAttribute->Vitality;
#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	WORD AllCharisma  =CharacterAttribute->Charisma;
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	
#endif //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM


#ifdef LDS_ADD_CHARISMAVALUE_TOITEMOPTION
	getAllAddState ( &AllStrength, &AllDexterity, &AllEnergy, &AllVitality, &AllCharisma );
#else // LDS_ADD_CHARISMAVALUE_TOITEMOPTION
    getAllAddState ( &AllStrength, &AllDexterity, &AllEnergy, &AllVitality );
#endif // LDS_ADD_CHARISMAVALUE_TOITEMOPTION

#endif	//LJH_FIX_ITEM_CANNOT_BE_EQUIPPED_AFTER_LOGOUT


    memset ( byOptionList, 0, sizeof( BYTE ) * 30 );
    memset ( m_bySetOptionList, 255, sizeof( BYTE ) * 16 );


#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	for (int i=0; i<MAX_EQUIPMENT_INDEX; ++i )
#else // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	for ( i=0; i<12; ++i )
#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	{
		if ( i==EQUIPMENT_WING || i==EQUIPMENT_HELPER ) continue;

		ITEM *ip = &CharacterMachine->Equipment[i];

        if ( ip->RequireDexterity>AllDexterity || ip->RequireEnergy>AllEnergy || ip->RequireStrength>AllStrength 
#if defined PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM || defined YDG_FIX_SETITEM_REQUIRED_STATUS_BUG
			|| ip->RequireLevel > AllLevel || ip->RequireCharisma > AllCharisma || ip->Durability <= 0 || ( IsRequireEquipItem( ip ) == false )
#endif //PSW_BUGFIX_REQUIREEQUIPITEM_SETITEM
			)
        {
            continue;
        }

        if ( ( i==EQUIPMENT_WEAPON_LEFT || i==EQUIPMENT_RING_LEFT ) && itemTmp.Type==ip->Type && itemTmp.ExtOption==(ip->ExtOption%0x04) )
        {
            continue;
        }

		if ( ip->Type>-1 )
		{
			checkItemType( byOptionList, ip->Type, ip->ExtOption );
		}

        if ( i==EQUIPMENT_WEAPON_RIGHT || i==EQUIPMENT_RING_RIGHT )
        {
            itemTmp.Type = ip->Type;
            itemTmp.ExtOption = (ip->ExtOption%0x04);
        }
	}

#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	UpdateCount_SetOptionPerEquippedSetItem( byOptionList, m_arLimitSetItemOptionCount, CharacterMachine->Equipment );
#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE

	calcSetOptionList( byOptionList );
}

void CSItemOption::MoveSetOptionList ( const int StartX, const int StartY )
{
    int x,y,Width,Height;
	
	Width=162; Height=20; x=StartX+14; y=StartY+22;
	if ( MouseX>=x && MouseX<x+Width && MouseY>=y && MouseY<y+Height )
	{
		m_bViewOptionList = true;

		MouseLButtonPush = false;
		MouseUpdateTime = 0;
		MouseUpdateTimeMax = 6;
	}
}

void CSItemOption::RenderSetOptionButton ( const int StartX, const int StartY )
{
    float x,y,Width,Height;
    char  Text[100];

	Width=162.f;Height=20.f; x=(float)StartX+14;y=(float)StartY+22;
	RenderBitmap(BITMAP_INTERFACE_EX+21,x,y,Width,Height,0.f,0.f,Width/256.f,Height/32.f);

	g_pRenderText->SetFont(g_hFontBold);
	g_pRenderText->SetTextColor(0, 0, 0, 255);
	g_pRenderText->SetBgColor(100, 0, 0, 0);
	sprintf ( Text, "[%s]", GlobalText[989] );
    g_pRenderText->RenderText(StartX+96, (int)(y+3), Text, 0, 0, RT3_WRITE_CENTER);

	g_pRenderText->SetTextColor(0xffffffff);
	if ( m_bySetOptionANum>0 || m_bySetOptionBNum>0 )
		g_pRenderText->SetTextColor(255, 204, 25, 255);
    else
		g_pRenderText->SetTextColor(128, 128, 128, 255);
    g_pRenderText->RenderText(StartX+95, (int)(y+2), Text, 0, 0, RT3_WRITE_CENTER);
	g_pRenderText->SetTextColor(255, 255, 255, 255);
}

void CSItemOption::RenderSetOptionList ( const int StartX, const int StartY )
{
	if ( m_bViewOptionList && ( m_bySetOptionANum>0 || m_bySetOptionBNum>0 ) )
	{
		g_pRenderText->SetTextColor(255, 255, 255, 255);
		g_pRenderText->SetBgColor(100, 0, 0, 0);

        int PosX, PosY;

        PosX = StartX+95;
        PosY = StartY+40;

        BYTE TextNum = 0;
        BYTE SkipNum = 0;
        BYTE setIndex = 0;

        sprintf ( TextList[TextNum], "\n" ); TextListColor[TextNum] = 0; TextBold[TextNum] = false; TextNum++; SkipNum++;
        sprintf ( TextList[TextNum], "\n" ); TextListColor[TextNum] = 0; TextBold[TextNum] = false; TextNum++; SkipNum++;
        sprintf ( TextList[TextNum], "\n" ); TextListColor[TextNum] = 0; TextBold[TextNum] = false; TextNum++; SkipNum++;

#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
		int		iCurSetItemTypeSequence = 0, iCurSetItemType = -1;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

		for ( int i=0; i<m_bySetOptionANum+m_bySetOptionBNum; ++i )
		{
#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
			std::string	strCurrent;

			m_iterESIS = m_mapEquippedSetItemSequence.find( i );

			if( m_mapEquippedSetItemSequence.end() != m_iterESIS )
			{
				iCurSetItemTypeSequence = m_iterESIS->second;
			}
			else
			{
				iCurSetItemTypeSequence = -1;
			}

			if( iCurSetItemType != iCurSetItemTypeSequence )
			{
				iCurSetItemType = iCurSetItemTypeSequence;

				m_iterESIN = m_mapEquippedSetItemName.find( iCurSetItemTypeSequence );

				if( m_iterESIN != m_mapEquippedSetItemName.end() )
				{
					strCurrent = m_iterESIN->second;
					
					sprintf ( TextList[TextNum], "%s %s", strCurrent.c_str(), GlobalText[1089] );
					TextListColor[TextNum] = 3;
					TextBold[TextNum] = true;
					TextNum++;
				}
			}
			
#else // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
            if ( i==0 && m_bySetOptionANum>0 )
            {
                sprintf ( TextList[TextNum], "%s %s", m_strSetName[0], GlobalText[1089] );
       		    TextListColor[TextNum] = 3;
			    TextBold[TextNum] = true;
                TextNum++;
            }
            else if ( i==m_bySetOptionANum && m_bySetOptionBNum>0 )
            {
                setIndex = 1;

                sprintf ( TextList[TextNum], "\n" );
       		    TextListColor[TextNum] = 0;
			    TextBold[TextNum] = false;
                TextNum++; SkipNum++;

                sprintf ( TextList[TextNum], "%s %s", m_strSetName[1], GlobalText[1089] );
       		    TextListColor[TextNum] = 3;
			    TextBold[TextNum] = true;
                TextNum++;
            }
            else if ( m_bySameSetItem!=0 && m_bySetOptionANum>0 && (m_bySetOptionANum-m_bySameSetItem)==i )
            {
                sprintf ( TextList[TextNum], "\n" );
       		    TextListColor[TextNum] = 0;
			    TextBold[TextNum] = false;
                TextNum++; SkipNum++;

                sprintf ( TextList[TextNum], "%s %s", m_strSetName[1], GlobalText[1089] );
       		    TextListColor[TextNum] = 3;
			    TextBold[TextNum] = true;
                TextNum++;
            }
            else if ( m_bySameSetItem!=0 && m_bySetOptionBNum>0 && (m_bySetOptionBNum-m_bySameSetItem)==i )
            {
                sprintf ( TextList[TextNum], "\n" );
       		    TextListColor[TextNum] = 0;
			    TextBold[TextNum] = false;
                TextNum++; SkipNum++;

                sprintf ( TextList[TextNum], "%s %s", m_strSetName[0], GlobalText[1089] );
       		    TextListColor[TextNum] = 3;
			    TextBold[TextNum] = true;
                TextNum++;
            }
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE
			getExplainText ( TextList[TextNum], m_bySetOptionList[i][0], m_iSetOptionListValue[i][0], setIndex );
            if ( m_bySetOptionList[i][0]>=AT_SET_OPTION_IMPROVE_ATTACK_1 && m_bySetOptionList[i][1]==0 )
                TextListColor[TextNum] = 2;
            else
                TextListColor[TextNum] = 1;
			TextBold[TextNum] = false;
            TextNum++;
		}

		RenderTipTextList( PosX, PosY, TextNum, 120, RT3_SORT_CENTER );
        m_bViewOptionList = false;
	}
}


void CSItemOption::CheckRenderOptionHelper ( const char* FilterName )
{
    char Name[256];

    if ( FilterName[0]!='/' ) return;

    int Length1 = strlen ( FilterName );
    for ( int i=0; i<MAX_SET_OPTION; ++i )
    {
        ITEM_SET_OPTION& setOption = m_ItemSetOption[i];
        if ( setOption.byOptionCount<255 )
        {
            sprintf ( Name,"/%s", setOption.strSetName );

            int Length2 = strlen ( Name );

            //  �˻��Ѵ�.
            m_byRenderOptionList = 0;
            if ( strncmp( FilterName, Name, Length1 )==NULL && strncmp( FilterName, Name, Length2 )==NULL )
            {
				g_pNewUISystem->Hide(SEASON3B::INTERFACE_ITEM_EXPLANATION);
				g_pNewUISystem->Hide(SEASON3B::INTERFACE_HELP);
				g_pNewUISystem->Show(SEASON3B::INTERFACE_SETITEM_EXPLANATION);

                m_byRenderOptionList = i+1;
                return;
            }
        }
    }
}

void CSItemOption::RenderOptionHelper ( void )
{
    if ( m_byRenderOptionList<=0 ) return;

	int TextNum = 0;
    int sx = 0, sy = 0;
	ZeroMemory( TextListColor, 20 * sizeof ( int));
	for(int i=0;i<30;i++)
	{
		TextList[i][0] = NULL;
	}

    ITEM_SET_OPTION& setOption = m_ItemSetOption[m_byRenderOptionList-1];
    if ( setOption.byOptionCount>=255 )
    {
        m_byRenderOptionList = 0;
        return;
    }

    BYTE    option1 = 255;
    BYTE    option2 = 255;
    BYTE    value1  = 255;
    BYTE    value2  = 255;
	sprintf(TextList[TextNum],"\n");TextNum++;
    sprintf ( TextList[TextNum], "%s %s %s", setOption.strSetName, GlobalText[1089], GlobalText[159] );
    TextListColor[TextNum] = TEXT_COLOR_YELLOW; 
    TextNum++;

	sprintf(TextList[TextNum],"\n");TextNum++;
	sprintf(TextList[TextNum],"\n");TextNum++;

	for ( int i=0; i<13; ++i )
    {
        if ( i<6 )
        {
            option1 = setOption.byStandardOption[i][0];
            option2 = setOption.byStandardOption[i][1];
            value1  = setOption.byStandardOptionValue[i][0];
            value2  = setOption.byStandardOptionValue[i][1];
        }
        else if ( i<8 )
        {
            option1 = setOption.byExtOption[i-6];
            value1  = setOption.byExtOptionValue[i-6];
        }
        else
        {
            option1 = setOption.byFullOption[i-8];
            value1  = setOption.byFullOptionValue[i-8];
        }
        if ( option1!=255 )
        {
            getExplainText ( TextList[TextNum], option1, value1, 0 );
            TextListColor[TextNum] = TEXT_COLOR_BLUE; 
            TextBold[TextNum] = false; TextNum++;
        }
        if ( option2!=255 )
        {
            getExplainText ( TextList[TextNum], option2, value2, 0 );
            TextListColor[TextNum] = TEXT_COLOR_BLUE; 
            TextBold[TextNum] = false; TextNum++;
        }
    }
	sprintf(TextList[TextNum],"\n");TextNum++;
	sprintf(TextList[TextNum],"\n");TextNum++;

	SIZE TextSize = {0, 0};	
#ifdef LJH_ADD_SUPPORTING_MULTI_LANGUAGE
	g_pMultiLanguage->_GetTextExtentPoint32(g_pRenderText->GetFontDC(), TextList[0], 1, &TextSize);
#else  //LJH_ADD_SUPPORTING_MULTI_LANGUAGE
	unicode::_GetTextExtentPoint(g_pRenderText->GetFontDC(), TextList[0], 1, &TextSize);
#endif //LJH_ADD_SUPPORTING_MULTI_LANGUAGE
#ifdef KWAK_FIX_COMPILE_LEVEL4_WARNING
#else // KWAK_FIX_COMPILE_LEVEL4_WARNING
	int Height = (int)( ((TextNum ) * TextSize.cy + TextSize.cy / 2) / g_fScreenRate_y );
#endif // KWAK_FIX_COMPILE_LEVEL4_WARNING

	RenderTipTextList(sx,sy,TextNum,0);
}

int CSItemOption::GetSetItmeCount( const ITEM* pselecteditem )
{
	ITEM_SET_TYPE& itemsettype = m_ItemSetType[pselecteditem->Type];
	BYTE subtype = itemsettype.byOption[(pselecteditem->ExtOption%0x04)-1];

	int setitemcount = 0;

	for( int j = 0; j < MAX_ITEM; j++ )
	{
		ITEM_SET_TYPE& temptype = m_ItemSetType[j];
#ifdef PJH_ADD_SET_NEWJOB
		for(int i = 0; i < 2; i++)
#endif //PJH_ADD_SET_NEWJOB
		{
#ifdef PJH_ADD_SET_NEWJOB
			BYTE tempsubtype = temptype.byOption[i];
#else
		BYTE tempsubtype = temptype.byOption[(pselecteditem->ExtOption%0x04)-1];
#endif //PJH_ADD_SET_NEWJOB
			if( subtype == tempsubtype )
			{
				setitemcount++;
			}
		}
	}

	return setitemcount;
}

bool CSItemOption::isFullseteffect( const ITEM* pselecteditem )
{
	int mysetitemcount = 0;

	ITEM_SET_TYPE& selectedItemType = m_ItemSetType[pselecteditem->Type];
	BYTE selectedItemOption = selectedItemType.byOption[(pselecteditem->ExtOption%0x04)-1];
	ITEM_SET_OPTION& selecteditemoption = m_ItemSetOption[selectedItemOption];
#ifdef PJH_ADD_SET_NEWJOB
	int	Cmp_Buff[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
#endif //PJH_ADD_SET_NEWJOB
	
	for( int i = 0; i < MAX_EQUIPMENT; i++ )
	{
		ITEM *p = &CharacterMachine->Equipment[i];

		if( p )
		{
#ifdef PJH_ADD_SET_NEWJOB
			bool Continue_Set = false;
			for(int ipjh = 0; ipjh < mysetitemcount; ipjh++)
			{
				if(p->Type == Cmp_Buff[ipjh])
				{
					Continue_Set = true;
					break;
				}
			}
			if(Continue_Set == true)
				continue;
#endif //#ifdef PJH_ADD_SET_NEWJOB
			ITEM_SET_TYPE& myitemSType = m_ItemSetType[p->Type];
			BYTE myItemOption = myitemSType.byOption[(p->ExtOption%0x04)-1];
			ITEM_SET_OPTION& setOption = m_ItemSetOption[myItemOption];

			if ( strcmp( selecteditemoption.strSetName, setOption.strSetName ) == NULL )
			{
#ifdef PJH_ADD_SET_NEWJOB
				Cmp_Buff[mysetitemcount] = p->Type;
#endif //#ifdef PJH_ADD_SET_NEWJOB
				mysetitemcount++;
			}
		}
	}

	if( mysetitemcount == GetSetItmeCount( pselecteditem ) )
		return true;
	else
		return false;
}

#ifdef LDS_FIX_SETITEM_OUTPUTOPTION_WHICH_LOCATED_INVENTORY
int     CSItemOption::RenderSetOptionListInItem ( const ITEM* ip, int TextNum, bool bIsEquippedItem )
#else // LDS_FIX_SETITEM_OUTPUTOPTION_WHICH_LOCATED_INVENTORY
int     CSItemOption::RenderSetOptionListInItem ( const ITEM* ip, int TextNum )
#endif // LDS_FIX_SETITEM_OUTPUTOPTION_WHICH_LOCATED_INVENTORY
{
    ITEM_SET_TYPE& itemSType= m_ItemSetType[ip->Type];

    m_bySelectedItemOption = itemSType.byOption[(ip->ExtOption%0x04)-1];

    if ( m_bySelectedItemOption<=0 || m_bySelectedItemOption==255 ) return TextNum;

    int TNum = TextNum;

    ITEM_SET_OPTION& setOption = m_ItemSetOption[m_bySelectedItemOption];
    if ( setOption.byOptionCount>=255 )
    {
        m_bySelectedItemOption = 0;
        return TNum;
    }

    BYTE    option1 = 255;
    BYTE    option2 = 255;
    BYTE    value1  = 255;
    BYTE    value2  = 255;
    BYTE    count1  = 0;

    BYTE    byLimitOptionNum;
#ifdef PJH_ADD_SET_NEWJOB
	if(m_bySetOptionANum > 0)
		byLimitOptionNum = m_bySetOptionANum-m_bySameSetItem;//m_bySetOptionANum-1;
	else
		byLimitOptionNum = 0;

	if(m_bySetOptionBNum > 0)
		byLimitOptionNum += m_bySetOptionBNum-m_bySameSetItem;//m_bySetOptionANum-1;
#else
	byLimitOptionNum = m_bySetOptionANum-m_bySameSetItem;//m_bySetOptionANum-1;
#endif

#ifdef LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

	count1 = Search_From_EquippedSetItemNameSequence( setOption.strSetName );

	if( BYTE_MAX == count1 )
	{
		byLimitOptionNum = 0;
	}	
	else
	{
		byLimitOptionNum = abs( (m_bySetOptionANum + m_bySetOptionBNum) - m_bySameSetItem);
	}

#else  // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE	
    int     length1 = strlen ( setOption.strSetName );
    int     length2 = strlen ( m_strSetName[1] );
    int     length3 = strlen ( m_strSetName[0] );
    if ( !strncmp( setOption.strSetName, m_strSetName[1], length1 ) &&  !strncmp( m_strSetName[1], setOption.strSetName, length2 ) )
    {
        count1 = m_bySetOptionANum-m_bySameSetItem;
#ifdef PJH_ADD_SET_NEWJOB
		if(m_bySetOptionANum-m_bySameSetItem < 0)
			count1 = 0;
#else
        byLimitOptionNum = count1+m_bySameSetItem;
#endif //PJH_ADD_SET_NEWJOB
    }
    else
#ifdef PJH_ADD_SET_NEWJOB		
		if ( !strncmp( setOption.strSetName, m_strSetName[0], length1 ) && !strncmp( m_strSetName[0], setOption.strSetName, length3 ) )
#else
		if ( strncmp( setOption.strSetName, m_strSetName[0], length1 ) && strncmp( m_strSetName[0], setOption.strSetName, length3 ) )
#endif //#ifdef PJH_ADD_SET_NEWJOB
    {
#ifdef PJH_ADD_SET_NEWJOB
			if(m_bySetOptionANum > 0)
				count1 = 0;
			else
				count1 = (m_bySetOptionANum + m_bySetOptionBNum) -m_bySameSetItem;

			byLimitOptionNum = abs(m_bySetOptionANum - m_bySameSetItem);
#else
		byLimitOptionNum = 0;
#endif //PJH_ADD_SET_NEWJOB
    }
#ifdef PJH_ADD_SET_NEWJOB
	else
		byLimitOptionNum = 0;
#endif // LDS_FIX_OUTPUT_EQUIPMENTSETITEMOPTIONVALUE

	
#endif //PJH_ADD_SET_NEWJOB
	sprintf ( TextList[TNum], "\n" ); TNum += 1;
    sprintf ( TextList[TNum], "%s %s", GlobalText[1089], GlobalText[159] );
    TextListColor[TNum] = TEXT_COLOR_YELLOW; 
    TNum++;

	sprintf(TextList[TNum],"\n");TNum++;
	sprintf(TextList[TNum],"\n");TNum++;

	bool isfulloption = isFullseteffect( ip );
#ifdef PJH_ADD_SET_NEWJOB
	if( isfulloption )
	{
		byLimitOptionNum = 13;
	}
#endif //#ifdef PJH_ADD_SET_NEWJOB


#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE

#ifdef LDS_FIX_OUTPUT_WRONG_EQUIPPEDSETITEMOPTION_BY_WRONG_SLOTINDEX

	BYTE byCurrentSelectedSlotIndex = ip->bySelectedSlotIndex;

	int iLimitOptionCount = m_arLimitSetItemOptionCount[byCurrentSelectedSlotIndex]-1;
#else // LDS_FIX_OUTPUT_WRONG_EQUIPPEDSETITEMOPTION_BY_WRONG_SLOTINDEX
	int iLimitOptionCount = m_arLimitSetItemOptionCount[ip->bySelectedSlotIndex]-1;
#endif // LDS_FIX_OUTPUT_WRONG_EQUIPPEDSETITEMOPTION_BY_WRONG_SLOTINDEX

#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
	
#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
#ifdef LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
	for ( int i=0; i<=MAX_SETITEM_OPTIONS; ++i )	// ������ �߰��ɼ� ���� ���� ��ġ �ݿ�
#else // LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
	for ( int i=0; i<=MAX_EQUIPMENT_INDEX; ++i )
#endif // LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
#else // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
    for ( int i=0; i<13; ++i )
#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE	
    {
        if ( i<6 )
        {
            option1 = setOption.byStandardOption[i][0];
            option2 = setOption.byStandardOption[i][1];
            value1  = setOption.byStandardOptionValue[i][0];
            value2  = setOption.byStandardOptionValue[i][1];
        }
        else if ( i<8 )
        {
#ifdef PJH_ADD_SET_NEWJOB
			if(((ip->ExtOption%0x04)-1) == 0)
#endif //PJH_ADD_SET_NEWJOB
			{
				option1 = setOption.byExtOption[i-6];
				value1  = setOption.byExtOptionValue[i-6];
			}
#ifdef PJH_ADD_SET_NEWJOB
			else
			{
				option2 = setOption.byExtOption[i-6];
				value2  = setOption.byExtOptionValue[i-6];
			}
#endif //PJH_ADD_SET_NEWJOB
        }
        else
        {
#ifdef PJH_ADD_SET_NEWJOB
			if(((ip->ExtOption%0x04)-1) == 0)
#endif //PJH_ADD_SET_NEWJOB
			{
				option1 = setOption.byFullOption[i-8];
				value1  = setOption.byFullOptionValue[i-8];
			}
#ifdef PJH_ADD_SET_NEWJOB
			else
			{
				option2 = setOption.byFullOption[i-8];
				value2  = setOption.byFullOptionValue[i-8];
			}
#endif //PJH_ADD_SET_NEWJOB

			if( isfulloption )
			{
				byLimitOptionNum = 13;
			}
			else
			{
				byLimitOptionNum = 255;
			}
        }

        if ( option1!=255 )
        {
            getExplainText ( TextList[TNum], option1, value1, 0 );


#ifdef LDS_FIX_OUTPUT_WRONG_EQUIPPEDSETITEMOPTION_BY_WRONG_SLOTINDEX
            if ( m_bySetOptionList[count1][0]==option1 
				&& byLimitOptionNum!=255
#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
				&& iLimitOptionCount > i
#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
#ifdef LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
				&& byLimitOptionNum!=0			
#endif // LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
#ifdef LDS_FIX_SETITEM_OUTPUTOPTION_WHICH_LOCATED_INVENTORY
#ifdef PBG_FIX_SETITEMTOOLTIP
				&& bIsEquippedItem == false
#else //PBG_FIX_SETITEMTOOLTIP
				&& bIsEquippedItem == true
#endif //PBG_FIX_SETITEMTOOLTIP
#endif // LDS_FIX_SETITEM_OUTPUTOPTION_WHICH_LOCATED_INVENTORY
				)
#else // LDS_FIX_OUTPUT_WRONG_EQUIPPEDSETITEMOPTION_BY_WRONG_SLOTINDEX
				
			if ( m_bySetOptionList[count1][0]==option1 
					&& i<byLimitOptionNum 
					&& byLimitOptionNum!=255
#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
					&& iLimitOptionCount > i
#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
#ifdef LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
					&& byLimitOptionNum!=0
#endif // LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
				)
#endif // LDS_FIX_OUTPUT_WRONG_EQUIPPEDSETITEMOPTION_BY_WRONG_SLOTINDEX
            {
                TextListColor[TNum] = TEXT_COLOR_BLUE; 
                count1++;
            }
            else
            {
                TextListColor[TNum] = TEXT_COLOR_GRAY; 
            }
            TextBold[TNum] = false; TNum++;
        }
        if ( option2!=255 )
        {
            getExplainText ( TextList[TNum], option2, value2, 0 );
#ifdef LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
            if ( m_bySetOptionList[count1][0]==option2 
				&& byLimitOptionNum!=255
				&& iLimitOptionCount > i
#ifdef LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
				&& byLimitOptionNum!=0
#endif // LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
				)
#else // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
			if ( m_bySetOptionList[count1][0]==option2 
				&& i<byLimitOptionNum 
				&& byLimitOptionNum!=255
#ifdef LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
				&& byLimitOptionNum!=0
#endif // LDS_FIX_WRONG_QUANTITY_SETITEMOPTION_WHEN_RENDER_SETITEMTOOTIP_IN_INVENTORY
				)
#endif // LDS_FIX_OUTPUT_WRONG_COUNT_EQUIPPEDSETITEMOPTIONVALUE
            {
                TextListColor[TNum] = TEXT_COLOR_BLUE; 
                count1++;
            }
            else
            {
                TextListColor[TNum] = TEXT_COLOR_GRAY; 
            }
            TextBold[TNum] = false; TNum++;
        }
    }
	sprintf(TextList[TNum],"\n");TNum++;
	sprintf(TextList[TNum],"\n");TNum++;

    return TNum;
}

BYTE CSItemOption::GetSetOptionANum()
{
	return m_bySetOptionANum;
}

BYTE CSItemOption::GetSetOptionBNum()
{
	return m_bySetOptionBNum;
}

void CSItemOption::SetViewOptionList(bool bView)
{
	m_bViewOptionList = bView;
}

bool CSItemOption::IsViewOptionList()
{
	return m_bViewOptionList;
}